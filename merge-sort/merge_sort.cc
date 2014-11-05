#include <fstream>
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;





//-----{ global variables }---------------------------------------------------//

string input_filename  = "IntegerArray_example.txt"; 
long   inversion_count = 0;

//----------------------------------------------------------------------------//






//-----{ function templates }-------------------------------------------------//

vector<vector<int>> get_numbers         ( string                filename    );

vector<int>         merge_sort          ( vector<vector<int>>   input       );

void                print_vector        ( vector<int>           input       );
void                print_vector_nested ( vector<int>           input       );

//----------------------------------------------------------------------------//







//---{ main }-----------------------------------------------------------------//

int main ()
{
    
    // load the numbers:
    vector<vector<int>> numbers = get_numbers( input_filename );
    
    // sort numbers:
    merge_sort(numbers);

    // print the number of inversions:
    cout << inversion_count << endl;

}

//----------------------------------------------------------------------------//











//==={ FUNCTION DEFINITIONS }=================================================//





//---{ load the data as a vector of integers }--------------------------------//

vector<vector<int>> get_numbers (string filename)
{
    ifstream file ( filename );
    vector<vector<int>> numbers;
    
    // check whether the file is open:
    if ( !file.is_open() ) 
    {
        cout << "Can't find the file \"" << filename << "\"." << endl; 
    }
    else 
    {
        int number;
        while (file >> number)              // read line from file
        {
            numbers.push_back({number});    // append to vector
        }
        
        file.close();
    }
    
    return numbers;
}

//----------------------------------------------------------------------------//










//---{ the binary merge-sort operation }--------------------------------------//

// This function takes two vectors and performs the binary merge-sort operation,
// so it returns a single sorted vector. This function forms the core of the
// algorithm.

vector<int> merge_sort_binary (vector<int> vec1, vector<int> vec2)
{
    vector<int> output;
    int i=0, j=0;                           // indices of vec1 and vec2, resp.
    int len1=vec1.size(), len2=vec2.size(); // length of vec1 and vec2
    int length = len1 + len2;               // length of the output vector
    
    
    // The condition in the following "if" clause is the only tricky bit of
    // this function. It checks whether or not the next element in output
    // should come from vec1.

    do
    {
        if ( (vec1[i]<=vec2[j] && i<len1) || j==len2 )
        {
            output.push_back(vec1[i]);  // take element from vec1
            i++;                        // advance to next entry in vec1
        }
        else 
        {
            output.push_back(vec2[j]);  // take element from vec2
            j++;                        // advance to next entry in vec1
            inversion_count += len1-i;  // increase number of inversions
        }

    }
    while ( i+j < length );
    
    
    return output;
}

//----------------------------------------------------------------------------//










//---{ the iterative merge-sort function }------------------------------------//

// This function iteratively applies the binary merge-sort operator to all 
// consecutive pairs of vectors. (the input is a vector of nested vectors)

vector<vector<int>> merge_sort_iterative (vector<vector<int>> input)
{
    
    vector<vector<int>> output;
    
    
    int length = input.size();
    
    for ( int i=0; i<length/2; i++ )
    {
        output.push_back(
            merge_sort_binary( input[2*i], input[2*i+1] )   // Append merged
        );                                                  // vector to output.
    }
    
    if ( length % 2 )                       // Append the remaining vector
        output.push_back(input[length-1]);  // in case # elements is odd.

    
    
    return output;
}

//----------------------------------------------------------------------------//









//---{ the recursive merge-sort call }----------------------------------------//

vector<int> merge_sort ( vector<vector<int>> input )
{
    inversion_count = 0;
    
    vector<vector<int>> output = input;
    
    while ( output.size() > 1 )                 // Recursively apply the 
        output = merge_sort_iterative(output);  // iterative merge-sort func.
    
    return output[0];           // return the first and only element of output
}

//----------------------------------------------------------------------------//










//---{ these functions are just printing shortcuts (unimportant) }------------//

void print_vector_base ( vector<int> input )
{
    cout << "{";
    
    for (unsigned int i=0; i<input.size(); i++)
        
        if (i<input.size()-1)
            cout << input[i] << ',';
        else
            cout << input[i];
            
    cout << "}";
}



void print_vector ( vector<int> input )
{
    print_vector_base(input);
    cout << endl;
}



void print_vector_nested ( vector<vector<int>> input )
{
    cout << "{ ";
    
    for (unsigned int i=0; i<input.size(); i++)
    {
        print_vector_base(input[i]);
        
        if (i<input.size()-1)
            cout << ", ";
        else
            cout << "";
    }

    cout << " }" << endl;
}

//----------------------------------------------------------------------------//







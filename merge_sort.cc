#include <fstream>
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;





//-----{ global variables }---------------------------------------------------//

string input_filename = "numbers.txt"; 
//string input_filename = "IntegerArray.txt"; 
long inversion_count = 0;

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





void print_vector_embedded ( vector<vector<int>> input )
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












//---{ load the data as a vector of integers }--------------------------------//

vector<int> getNumbers (string filename)
{
    ifstream file ( filename );
    vector<int> numbers;
    
    // check whether the file is open:
    if ( !file.is_open() ) 
    {
        cout << "Can't find the file \"" << filename << "\"." << endl; 
    }
    else 
    {
        int number;
        while (file >> number)
        {
            numbers.push_back(number);
        }
        
        file.close();
    }
    
    return numbers;
}

//----------------------------------------------------------------------------//












//---{ partition into a vector of ordered integer doublets }------------------//

vector<vector<int>> partition (vector<int> input)
{
    vector<vector<int>> output;
    bool odd_length = input.size() % 2;
        
    // prepend "-1" if the length of the vector is odd:
    if (odd_length)
        output.push_back( {input[0]} );
    
    // split up in terms of vector of 2D arrays:
    for (unsigned int i=odd_length; i<input.size(); i += 2)
    {
        if (input[i] > input[i+1])
        {
            output.push_back( { input[i+1], input[i] } );
            inversion_count++;
        }
        else
        {
            output.push_back( { input[i], input[i+1] } );
        }
    }

    return output;
}

//----------------------------------------------------------------------------//













//---{ the main merge_sort function }-----------------------------------------//

vector<int> merge_sort_binary (vector<int> vec1, vector<int> vec2)
{
    vector<int> output;
    int i=0, j=0;                           // indices of vec1 and vec2, resp.
    int len1=vec1.size(), len2=vec2.size(); // length of vec1 and vec2
    int length = len1 + len2;               // length of the output vector
    
    do
    {
        if ( (vec1[i]<=vec2[j] && i<len1) || j==len2 )
        {
            output.push_back(vec1[i]);
            i++;
        }
        else 
        {
            output.push_back(vec2[j]);
            j++;
            inversion_count += len1-i;
        }

    }
    while ( i+j < length );
    
    
    return output;
}

//----------------------------------------------------------------------------//













//---{ the recursive merge_sort function }------------------------------------//

vector<vector<int>> merge_sort_recursive (vector<vector<int>> input)
{
    
    vector<vector<int>> output;
    
    
    int length = input.size();
    
    for ( int i=0; i<length/2; i++ )
    {
        output.push_back(
            merge_sort_binary( input[2*i], input[2*i+1] )
        );
    }
    
    if ( length % 2 )
        output.push_back(input[length-1]);

    
    
    return output;
}

//----------------------------------------------------------------------------//













//---{ the overall wrapper }--------------------------------------------------//

vector<int> sort ( vector<int> input )
{
    inversion_count = 0;
    
    vector<vector<int>> output = partition(input);
    
    while ( output.size() > 1 )
        output = merge_sort_recursive(output);
    
    return output[0];
}

//----------------------------------------------------------------------------//











//---{ main }-----------------------------------------------------------------//

int main ()
{
    
    // load the numbers:
    vector<int> numbers = getNumbers( input_filename );
    
    // sort numbers:
    numbers = sort(numbers);

    // print the number of inversions:
    cout << inversion_count << endl;

}

//----------------------------------------------------------------------------//







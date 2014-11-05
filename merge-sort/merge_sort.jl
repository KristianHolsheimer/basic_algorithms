# coding: utf-8

## Implementation of the *quick-sort* algorithm

### Load the data:


numbers = readdlm("IntegerArray_example.txt",'\n',Int)' # notice transposition
numbers = {[n] for n=numbers}


### The functions:

function merge_sort_binary(vec1,vec2)
    i      = 1
    j      = 1
    len1   = length(vec1)
    len2   = length(vec2)
    output = Int64[]
    inversions = 0
    
    
    while i+j <= len1+len2+1
        if i<len1+1 && j<len2+1     # this avoids BoundsError()
            if vec1[i] <= vec2[j]
                output = vcat(output,vec1[i])
                i+=1
            else
                output      = vcat(output,vec2[j])
                inversions += len1-i+1
                j+=1
            end
        else                        # this takes care of boundary cases
            if j==len2+1
                output = vcat(output,vec1[i])
                i+=1
            else
                output      = vcat(output,vec2[j])
                inversions += len1-i+1
                j+=1
            end
        end
    end
    
    return inversions, output
end






function merge_sort_iterative(cellarray)
    len = length(cellarray)
    odd = len % 2
    inversions = 0
    
    output = {}
    
    for i=1:2:len-1
        newinversions, newarray  = merge_sort_binary( cellarray[i], cellarray[i+1] )
        output = vcat( output, {newarray} )
        inversions += newinversions
    end
    
    if odd == 1
        output = vcat( output, {cellarray[len]} )
    end
    
    return inversions, output
end






function merge_sort(cellarray)
    inversions = 0
    
    while length(cellarray) > 1
        newinversions, cellarray = merge_sort_iterative(cellarray)
        inversions += newinversions
    end
    
    return inversions, cellarray[1]
end



### The function call:

merge_sort(numbers)


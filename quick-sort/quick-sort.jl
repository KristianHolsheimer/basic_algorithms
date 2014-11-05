# load the txt file:
numbers = readdlm("QuickSort.txt",'\n',Int) # notice transposition

# initialize the 'count' of the number of comparisons:
count = 0


# the function that partitions an array around a pivot:
function partition(arr, func)
    
    # make sure that the function does nothing when it's given a single-element vector:
    if length(arr) == 1; return {arr}; end
        
    # get the pivot elements's position:
    pivot_position = func(arr)
    
    # set pivot and move it to the first position:
    pivot = arr[pivot_position]
    arr[[1 pivot_position]] = arr[[pivot_position 1]]
        
    # intialize pivot position index:
    i=1
    
    # if j-th element is less than pivot, swap it with the (i+1)-th element:
    for j=2:length(arr)
        if arr[j] < pivot
            arr[[(i+1) j]] = arr[[j (i+1)]]
            i+=1
        end
    end
    
    # put the pivot in its appropriate position
    arr[[1 i]] = arr[[i 1]]
    
    # count the number of comparisons made:
    global count += length(arr)-1
    
    # return the partioned array together with its pivot
    if      i == 1;             {arr[[i]], arr[i+1:end]}
    elseif  i == length(arr);   {arr[1:i-1], arr[[i]]}
    else;                       {arr[1:i-1], arr[[i]], arr[i+1:end]}
    end
    
end



# get the 'median-of-three' pivot (non-trivial):
function median_of_three(arr)
    
    # get length of the array:
    l = length(arr)
    
    # handle boundary cases:
    if l<3; return 1; end
    
    # extract triple from input array:
    idx = [1, int(l/2), l]
        
    # sort the triple:
    if arr[idx][1] > arr[idx][2]; idx[[1 2]] = idx[[2 1]]; end
    if arr[idx][2] > arr[idx][3]; idx[[2 3]] = idx[[3 2]]; end
    if arr[idx][1] > arr[idx][2]; idx[[1 2]] = idx[[2 1]]; end
    
    #take the second index:
    return idx[2]
    
end



# the main function that recusively calls the 'partition' function
function qsort(arr,func)
    
    # intitialize 'output':
    output = {arr}
    global count = 0

    # recusively call the 'partition' function:
    while length(output) < length(arr)
        output = apply(vcat, map(a -> partition(a,func), output))
    end

    # convert the output from {[1],[2],...} to [1,2,...]
    apply(vcat, output)
    
end



# take the first element as pivot:
qsort(numbers, a -> 1)
print(count, "\n")

# take the last element as pivot:
qsort(numbers, a -> length(a))
print(count, "\n")

# take the median-of-three as pivot:
qsort(numbers, median_of_three)
print(count, "\n")


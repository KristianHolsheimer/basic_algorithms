# load the txt file:
numbers = readdlm("QuickSort_example.txt",'\n',Int)' # notice transposition

# initialize the 'count' of the number of comparisons:
comparisons = 0


function partition(arr, interval)
    
    # get start and stop of the interval
    start, stop = interval
    
    # count the number of comparisons to be made:
    global comparisons += stop-start
        
    # handle boundary case:
    if stop-start == 1
        if arr[start] > arr[stop]
            arr[[start stop]] = arr[[stop start]]
        end
        return []
    end
    
    # set the pivot elements's position:
    pivot = start
    
    # move pivot to the first position (redundant if 'pivot == start'):
    #arr[[start pivot]] = arr[[pivot start]]
    
    # intialize pivot position index:
    i=start
    
    # if j-th element is less than pivot, swap it with the (i+1)-th element:
    for j=start+1:stop
        if arr[j] < arr[start]
            i+=1
            arr[[i j]] = arr[[j i]]
        end
    end
    
    # put the pivot in its appropriate position
    arr[[start i]] = arr[[i start]]
            
    # return not-yet-sorted subinterval(s):
    if     start+1 < i < stop-1; return [(start,i-1),(i+1,stop)]
    elseif start+1 < i         ; return [(start,i-1)           ]
    elseif           i < stop-1; return [            (i+1,stop)]
    else                       ; return [                      ]
    end

end


# This version of the quick-sort function returns nothing;
# it sorts the array 'in situ'.
function qsort_inplace(arr)
    intervals = [(1,length(arr))]

    while !isempty(intervals)        
        intervals = apply(vcat, map(a -> partition(arr, a), intervals))
    end
end



# call the function:
println(numbers)
qsort_inplace(numbers)
println(numbers)
println(comparisons)



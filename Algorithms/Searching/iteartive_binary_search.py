def iterative_binary_search(bin_array,start_pos,end_pos,target):

    while start_pos<=end_pos:
        index = start_pos + (end_pos - start_pos) // 2

        if bin_array[index] == target:
            return index
        elif bin_array[index] < target:
            start_pos = index + 1
        else:
            end_pos = index - 1
    return "Key not present in list"
print(iterative_binary_search([1],0,0,1))



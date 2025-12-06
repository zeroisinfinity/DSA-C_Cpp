def recursive_binary_search(bin_array, start_pos, end_pos, target):
    if end_pos >= start_pos:
        index = start_pos + (end_pos - start_pos) // 2
        if bin_array[index] == target:
            return index

        elif bin_array[index] < target:
            return recursive_binary_search(bin_array, index + 1, end_pos, target)
        else:
            return recursive_binary_search(bin_array, start_pos, index - 1, target)
    else:
        return "Key not present in list"





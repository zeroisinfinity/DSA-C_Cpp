def selection_sort(array):
     # Traverse through all elements
     for index in range(0, len(array) - 1, 1):
        current_min_index = index  # Assume the current element is the minimum
        for cf in range(index + 1, len(array)):  # Traverse the unsorted portion
            if array[cf] < array[current_min_index]:  # Find the new minimum
                current_min_index = cf
        # Swap only if the minimum is not already at the current position
        if current_min_index != index:
            array[index], array[current_min_index] = array[current_min_index], array[index]
    return array

print(selection_sort([7, 3, 2, 1, 4]))
sel_array = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
# sel_array = [9]
# sel_array = []



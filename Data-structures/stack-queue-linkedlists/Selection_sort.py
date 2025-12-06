def selection_sort(array):
    for iter in range(0, len(array), 1):
        min_index = iter
        for compare in range(iter + 1, len(array), 1):
            if array[compare] < array[min_index]:
                min_index = compare
        # Swap the found minimum element with the current element
        array[iter], array[min_index] = array[min_index], array[iter]
    return array

# Test arrays
sel_array = [9, 7, 6, 5, 4, 2, 7, 8, 9, 2, 5] + [900] * 800

print(selection_sort(sel_array))

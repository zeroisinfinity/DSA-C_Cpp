def partition(array, start_pos, end_pos):
    pivot = array[end_pos]
    minimum = start_pos - 1

    for index in range(start_pos, end_pos ):
        if array[index] <= pivot:
            minimum += 1
            array[minimum], array[index] = array[index], array[minimum]
    array[minimum + 1], array[end_pos] = array[end_pos], array[minimum + 1]

    return minimum + 1

def quick_sort(array, start_pos, end_pos):

    if start_pos < end_pos:
        current_pivot = partition(array, start_pos, end_pos)
        quick_sort(array, start_pos, current_pivot - 1)
        quick_sort(array, current_pivot + 1, end_pos)

arr = [9,7,6,5,4,2,7,8,9,2,5] + [900]*800
quick_sort(arr, 0, len(arr)-1)
print(arr)






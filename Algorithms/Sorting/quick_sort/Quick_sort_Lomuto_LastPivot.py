import sys
sys.setrecursionlimit(3000)

def partition(array, start_pos, end_pos):
    pivot = array[end_pos]
    minimum = start_pos - 1

    for indx in range(start_pos, end_pos ):
        if array[indx] < pivot:
            minimum += 1
            if indx != minimum:
                array[minimum], array[indx] = array[indx], array[minimum]
    array[minimum + 1], array[end_pos] = array[end_pos], array[minimum + 1]

    return minimum + 1

def quick_sort(array, start_pos, end_pos):

    if start_pos < end_pos:
        current_pivot = partition(array, start_pos, end_pos)
        quick_sort(array, start_pos, current_pivot - 1)
        quick_sort(array, current_pivot + 1, end_pos)

"""arr = [9, 8, 1, 0, 11, 12, 66]
quick_sort(arr, 0, len(arr)-1)
print(arr)"""






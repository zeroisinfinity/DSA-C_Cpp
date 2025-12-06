import sys
import random
import math
sys.setrecursionlimit(100000)

def quick_sort(array, start_pos, end_pos):

    if start_pos < end_pos:
        left_pivot , right_pivot = shuffle(array, start_pos, end_pos)

        quick_sort(array, start_pos, left_pivot)
        quick_sort(array, right_pivot + 1, end_pos)

def shuffle(array,start_pos,end_pos):
    sh_pivot = random.randint(start_pos,end_pos)
    array[sh_pivot] , array[start_pos] = array[start_pos] , array[sh_pivot]
    return partition(array,start_pos,end_pos)

def partition(array, start_pos, end_pos):

    pivot = array[start_pos]
    low_dyn = start_pos
    inc = start_pos
    high_dyn = end_pos

    while inc <= high_dyn:

        if array[inc] < pivot:
                array[inc], array[low_dyn] = array[low_dyn], array[inc]
                inc += 1
                low_dyn+=1

        elif array[inc] == pivot :
                inc+=1

        else:
                array[inc], array[high_dyn] = array[high_dyn], array[inc]
                high_dyn-=1

    return low_dyn , high_dyn

arr = [9,7,6,5,4,2,7,8,9,2,5]*700 + [9]*800 + [67679]*8000 +  [900]*80000 + list(range(90000,578,-96))
quick_sort(arr, 0, len(arr) - 1)
print(arr)
#print(arr[0])



import sys
import random
import math
sys.setrecursionlimit(3000)

def shuffle(array,start_pos,end_pos):
    sh_pivot = random.randint(start_pos,end_pos)
    array[sh_pivot] , array[start_pos] = array[start_pos] , array[sh_pivot]
    return partition(array,start_pos,end_pos)

def partition(array, start_pos, end_pos):
    pivot = array[end_pos]
    minimum = start_pos - 1

    for index in range(start_pos, end_pos ):
        if array[index] < pivot:
            minimum += 1
            array[minimum], array[index] = array[index], array[minimum]
    array[minimum + 1], array[end_pos] = array[end_pos], array[minimum + 1]

    return minimum + 1

def quick_sort(array, start_pos, end_pos):


    if start_pos < end_pos:
        current_pivot = shuffle(array, start_pos, end_pos)
        if start_pos - current_pivot > math.ceil(len(array)//2):
            shuffle(array, start_pos, current_pivot - 1)
        if current_pivot - end_pos > math.ceil(len(array)//2):
             shuffle(array,start_pos,current_pivot - 1)
        quick_sort(array, start_pos, current_pivot - 1)
        quick_sort(array, current_pivot + 1, end_pos)

arr = list(range(500,10,-3))
quick_sort(arr, 0, len(arr)-1)
print(arr)






import sys
import random
import math
sys.setrecursionlimit(3000)

def quick_sort(array, start_pos, end_pos):

    if start_pos < end_pos:
        new_pivot = shuffle(array, start_pos, end_pos)

        if start_pos - new_pivot > math.ceil(len(array) // 2):
            shuffle(array, start_pos, new_pivot - 1)
        if new_pivot - end_pos > math.ceil(len(array) // 2):
            shuffle(array, start_pos, new_pivot - 1)

        quick_sort(array, start_pos, new_pivot)
        quick_sort(array, new_pivot + 1, end_pos)

def shuffle(array,start_pos,end_pos):
    sh_pivot = random.randint(start_pos,end_pos)
    array[sh_pivot] , array[start_pos] = array[start_pos] , array[sh_pivot]
    return partition(array,start_pos,end_pos)

def partition(array, start_pos, end_pos):
    pivot = array[start_pos]
    inc = start_pos - 1
    dec = end_pos + 1

    while True:

        inc += 1
        while array[inc] < pivot:
            inc += 1

        dec-=1
        while array[dec] > pivot:
            dec-=1
        if inc >= dec:
            return dec
        array[inc] , array[dec] = array[dec] , array[inc]
        #print(array)



arr = [900] + [9]*2 + list(range(5,0,-1)) +  list(range(60,8,-3)) + [9]*4

quick_sort(arr, 0, len(arr) - 1)
print(arr)

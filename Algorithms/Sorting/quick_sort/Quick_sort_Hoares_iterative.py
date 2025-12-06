import random
import math

def shuffle(array,start_pos,end_pos):
    sh_pivot = random.randint(start_pos,end_pos)
    array[sh_pivot] , array[start_pos] = array[start_pos] , array[sh_pivot]
    return partition(array,start_pos,end_pos)

def quick_sort_iterative(array,start_pos,end_pos):

    records = end_pos - start_pos + 1
    stack = [0] * records

    top = start_pos - 1

    top+=1
    stack[top] = start_pos
    top+=1
    stack[top] = end_pos

    while top >= 0:

        end_pos = stack[top]
        top-=1
        start_pos = stack[top]
        top-=1

        new_pivot = partition(array,start_pos,end_pos)
        if new_pivot - start_pos + 1> math.ceil(records//2):
            shuffle(array, start_pos, new_pivot )
        elif end_pos - new_pivot > math.ceil(records//2):
            shuffle(array, new_pivot + 1, end_pos)

        if start_pos < new_pivot:
            top += 1
            stack[top] = start_pos
            top+=1
            stack[top] = new_pivot

        if end_pos > new_pivot + 1:
            top+=1
            stack[top] = new_pivot + 1
            top+=1
            stack[top] = end_pos


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


# Driver code to test above
arr = [9,7,6,5,4,2,7,8,9,2,5] + [900]*80000 + list(range(90000,578,-6))
n = len(arr)
quick_sort_iterative(arr, 0, n-1)
print(arr)





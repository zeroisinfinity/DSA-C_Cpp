import sys
sys.setrecursionlimit(1000000)

def quicksort(array, start_pos, end_pos):
    if start_pos < end_pos:
        new_pivot = partition(array, start_pos, end_pos)

        quicksort(array, start_pos, new_pivot)
        quicksort(array, new_pivot + 1, end_pos)


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



arr = [9,7,6,5,4,2,7,8,9,2,5] + [900]*80000 + list(range(90000,578,-6))

quicksort(arr,0,len(arr) - 1)
print(arr)
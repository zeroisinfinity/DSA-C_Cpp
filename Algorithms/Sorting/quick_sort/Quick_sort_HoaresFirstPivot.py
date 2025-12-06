import sys
sys.setrecursionlimit(3000)

def quicksort(array, start_pos, end_pos):
    if start_pos < end_pos:
        new_pivot = partition(array, start_pos, end_pos)

        quicksort(array, start_pos, new_pivot - 1)
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



arr = [900] + [9]*2 + list(range(5,0,-1)) +  list(range(60,8,-3)) + [9]*4

quicksort(arr,0,len(arr) - 1)
print(arr)

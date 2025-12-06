import functools
import sys
recursive_limiter = 0

sys.setrecursionlimit(1000000)
#@functools.lru_cache(maxsize=1000000)
def recursive_bubble_sort(array,start_pos,end_pos,recursive_limiter):
    if recursive_limiter <= end_pos:

        if start_pos + 1 <= (end_pos - recursive_limiter):

            if array[start_pos] > array[start_pos + 1]:

                array[start_pos] , array[start_pos + 1] = array[start_pos + 1] , array[start_pos]

                recursive_bubble_sort(array,start_pos + 1,end_pos, recursive_limiter)

        else:
            recursive_bubble_sort(array,0, end_pos, recursive_limiter + 1 )

    else:
        pass
arr = list(range(300,-1,-1))
recursive_bubble_sort(arr,0,len(arr)-1,recursive_limiter)
print(arr)


import sys


sys.setrecursionlimit(100000)

def merge_sort(array,start_pos,mid,end_pos):
    merged_arr = [0] * ( end_pos - start_pos + 1 )
    index_mrg = 0
    index_i = start_pos
    index_j = mid+1

    while index_i <= mid  and  index_j <= end_pos :
        if array[index_i] < array[index_j]:
            merged_arr[index_mrg] = array[index_i]
            index_i+=1
        else:
            merged_arr[index_mrg] = array[index_j]
            index_j+=1
        index_mrg+=1
    while index_i <= mid :
        merged_arr[index_mrg] = array[index_i]
        index_mrg+=1
        index_i+=1
    while index_j <= end_pos:
        merged_arr[index_mrg] = array[index_j]
        index_mrg += 1
        index_j += 1
    for update in range(len(merged_arr)):
        array[start_pos + update] = merged_arr[update]

tracker_A = tracker_C = tracker_B  = tracker_D = 0

def binary_cut(array,start_pos,end_pos):
    global tracker_A , tracker_B , tracker_C , tracker_D
    tracker_D += 1
    if start_pos < end_pos:
        mid = start_pos + (end_pos - start_pos)//2
        tracker_A += 1
        binary_cut(array , start_pos , mid)
        tracker_B += 1
        binary_cut(array , mid + 1 , end_pos)
        tracker_C += 1
        merge_sort(array,start_pos,mid,end_pos)
import cProfile

arr = [38, 27, 43, 3, 9, 82, 10]*800 + list(range(9000,56,-8)) + [97]*800000
binary_cut(arr,0,len(arr)-1)
print(arr,len(arr))

print(tracker_A,tracker_B,tracker_C,tracker_D, tracker_D - tracker_B)
cProfile.run("binary_cut(arr,0,len(arr)-1)")














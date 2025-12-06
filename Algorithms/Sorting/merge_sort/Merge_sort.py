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

def binary_cut(array,start_pos,end_pos):
    if start_pos<end_pos:
        mid = start_pos + (end_pos - start_pos)//2
        binary_cut(array , start_pos , mid)
        binary_cut(array , mid + 1 , end_pos)
        merge_sort(array,start_pos,mid,end_pos)
        
arr = [9,7,6,5,4,2,7,8,9,2,5]
binary_cut(arr,0,len(arr)-1)
print(arr)














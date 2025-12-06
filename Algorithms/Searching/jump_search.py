import math

def jump_search(seq_array,records,key):

    interval = math.floor(math.sqrt(records)) - 1

    start_pos = 0
    end_pos = records - 1

    if( key < seq_array[start_pos] or key > seq_array[end_pos] ):
        return -1
    global jump_history
    jump = start_pos

    while jump <= end_pos :
        #print(jump)
        if seq_array[jump] == key:
           # print("              ",jump_history)
            return jump + jump_history
        elif seq_array[jump] > key :
            #print("break")
            break
        else:
            jump += interval

    else:
            #print("rec")
            #print(seq_array[jump - interval + 1: end_pos + 1],len(seq_array[jump - interval + 1: end_pos + 1]))
            jump_history = jump - interval + 1
            return jump_search(seq_array[jump - interval + 1: end_pos + 1],len(seq_array[jump - interval + 1: end_pos + 1]), key)
    if seq_array[jump] > key :

            #print("no rec")
            start_pos = jump - interval + 1
            end_pos = jump
            #print(start_pos,end_pos)
            for lin_search in range(start_pos,end_pos,1):
                if seq_array[lin_search] == key:
                    return lin_search + jump_history
            else:
                return -1



jump_history = 0
arr = [i for i in range(0,500)]
print(jump_search(arr,len(arr),499))







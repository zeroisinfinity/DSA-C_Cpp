import math

def indexed_sequential_search(seq_array,records,key):

    interval = math.floor(math.sqrt(records))
    if interval >= 2:
        interval-=1

    index_table = [0]*(records//interval)
    elements_table = [0]*(records//interval)
    start_pos = 0
    end_pos = records - 1

    for assign in range(0,records,interval):
        index_table[assign//interval - 1] = assign
        elements_table[assign//interval - 1] = seq_array[assign]


    if (key < elements_table[0] or key > seq_array[-1]):
        return -1

    for compare in range(0,interval + 1,1):
        if key < elements_table[compare]:
            start_pos = index_table[compare - 1]
            end_pos = index_table[compare]
            break
    else:
        for search in range(start_pos, end_pos + 1, 1):
            if seq_array[search] == key:
                return search
        else:
            return -1

    for search in range(start_pos, end_pos + 1, 1):
            if seq_array[search] == key:
                return search

    else:
        return -1

arr = list(range(1, 5001))
key = 5000
# key = 5001
# key = 0
# key = 1
print(indexed_sequential_search(arr, len(arr), key))

#print(seq_array[index_table[-1] + 1 : ] )
#return indexed_sequential_search(seq_array[index_table[-1] + 1 : ] , len(seq_array[index_table[-1] + 1 : ]),key)



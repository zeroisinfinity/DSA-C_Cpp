def insertion_sort(array):
    for test_sub in range(1,len(array),1):
            sample = array[test_sub]
            cf = test_sub - 1
            while cf >= 0 and sample < array[cf]:
                array[cf + 1] = array[cf]
                cf -= 1
            array[cf+1] = sample
    return array

ins_array = [9,8,7,6,5,4,3,2,1,0]

print(insertion_sort(ins_array))

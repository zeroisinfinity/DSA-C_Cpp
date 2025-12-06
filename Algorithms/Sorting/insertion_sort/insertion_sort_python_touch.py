def insertion_sort_python_touch(array):

    if len(array) != 1 and len(array) != 0:

        for test_sub in range(1,len(array),1):
            sample = array[test_sub]
            cf = test_sub - 1
            while cf >= 0 and sample < array[cf]:
                cf -= 1
            array[cf+2:test_sub+1] = array[cf+1:test_sub]
            array[cf + 1] = sample
        return array

    else:
        if len(array)==1:
            return 'Array already sorted'
        else:
            return 'Array has no elements'

ins_array = [9,8,7,6,5,4,3,2,1,0]
#ins_array = [9]
#ins_array = []
print(insertion_sort_python_touch(ins_array))

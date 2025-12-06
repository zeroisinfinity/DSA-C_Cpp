def iterative_bubble_sort(array):
    for limiter in range(len(array)):
        swap_flag = False
        for cf in range(0, len(array) - limiter - 1):
            if array[cf] > array[cf + 1]:
                array[cf], array[cf + 1] = array[cf + 1], array[cf]
                swap_flag = True
        if not swap_flag:
            break
    return array


print(iterative_bubble_sort([9,7,6,5,4,2,7,8,9,2,5] + [900]*80000 + list(range(90000,578,-6))))




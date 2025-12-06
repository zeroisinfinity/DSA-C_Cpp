def coventional_fibonacchi_search(fib_array, records, target):
    fib_n2 = 0
    fib_n1 = 1
    fib_n = fib_n1 + fib_n2

    while fib_n < records:
        fib_n2 = fib_n1
        fib_n1 = fib_n
        fib_n = fib_n1 + fib_n2

    offset = -1
    index = min(fib_n2 + offset, records - 1)
    if fib_n == 1:
        return records - 1
    while fib_n != 1:
        if fib_array[index] < target:
            offset = index
            fib_n = fib_n1
            fib_n1 = fib_n2
            fib_n2 = fib_n - fib_n1
            index = min(fib_n2 + offset, records - 1)


        elif fib_array[index] > target:
            fib_n = fib_n2
            fib_n1 = fib_n1 - fib_n2
            fib_n2 = fib_n - fib_n1
            index = min(fib_n2 + offset, records - 1)
        #Special  Case
        if index<(records-1) and fib_array[records-1]:
            return records - 1

        else:
            return index


    else:
        return -1

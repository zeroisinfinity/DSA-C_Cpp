def hfreq(l):
    count_initial = 1  # initial count
    freq_list = []  # will store marks with freq > 1
    length = len(l)  # length of list

    if absent(l) == no_of_stud:  # Verifying if all are absent
        print("All are absent.")

    #Iterating in NESTED-FOR LOOP because we concern about the particular element and not the list as a whole
    for i in range(length):
        #Initialize count_dyn correctly it's 1 not 0
        count_dyn = 1
        if l[i]==-1: #Save nested iterations
            continue
        # to find max count of all marks
        for j in range(i + 1, length):
            # no -1
            if (l[i] == l[j]):
                count_dyn += 1

        # Updating count_dyn_list and freq_list
        # To store equal counts corresponding to marks with those counts at a given instant
        if count_dyn == count_initial:
            freq_list.append(l[i])

        #Set the bar high if higher count_dyn is found
        elif count_dyn>count_initial:
            freq_list.clear()
            count_initial = count_dyn #DON'T FORGET TO UPDATE THE count_initial
            freq_list.append(l[i])

    # To check if all got distinct marks
    if count_initial == 1 and len(freq_list) == no_of_stud:
        print("Every marks' frequency is 1.")
    # If not distinct
    else:
        for iter in range(len(freq_list)):
            print("Highest frequency marks is ", freq_list[iter], " with frequency of - ", count_initial)

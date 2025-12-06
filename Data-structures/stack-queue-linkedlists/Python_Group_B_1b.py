"""
b) Write a python program to store roll numbers of student array who attended training program in sorted order.
Write function for searching whether particular student attended training program or not,
using Binary search and Fibonacci search
"""

import sys
import random
sys.setrecursionlimit(3000)

def menu():
    print("Enter 1 for Iterative Binary search.\nEnter 2 for Recursive Binary search.\nEnter 3 for left-to-right Fibonacci search\nEnter 4 for right-to-left Fibonacci search")
menu()

#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

list_of_roll = []
strength = int(input("Enter the strength of the class - "))
key = int(input("Enter the roll no. to be searched -  "))

#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

def getroll(size):
    array = []
    assign = 0
    while assign < size:
        roll_no = int(input("Enter roll numbers of students - "))
        if roll_no in array:
            print("Roll no already in list\n------------------------------------------")
            # roll_no = int(input("Enter roll numbers of students - "))
            size += 1
        else:
            array.append(roll_no)
        assign += 1
    return array
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
def quicksort(array, start_pos, end_pos):
    if start_pos < end_pos:
        new_pivot = shuffle(array, start_pos, end_pos)
        quicksort(array, start_pos, new_pivot)
        quicksort(array, new_pivot + 1, end_pos)
def shuffle(array,start_pos,end_pos):
    sh_pivot = random.randint(start_pos,end_pos)
    array[sh_pivot] , array[start_pos] = array[start_pos] , array[sh_pivot]
    return partition(array,start_pos,end_pos)
def partition(array, start_pos, end_pos):
    pivot = array[start_pos]
    inc = start_pos - 1
    dec = end_pos + 1
    while True:
        inc += 1
        while array[inc] < pivot:
            inc += 1
        dec-=1
        while array[dec] > pivot:
            dec-=1
        if inc >= dec:
            return dec
        array[inc] , array[dec] = array[dec] , array[inc]

#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

def conventional_fibonacchi_search(fib_array, records, target):
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
        if fib_array[records-1]==target:
           return records - 1
        else:
            return -1
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
        if index<(records-1) and fib_array[records-1] == target:
            return records - 1

        else:
            return index

    else:
        return -1

#----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

def nonconventional_fibonacchi_search(fib_array, records, target):
    fib_n2 = 0
    fib_n1 = 1
    fib_n = fib_n1 + fib_n2

    while fib_n < records:
        fib_n2 = fib_n1
        fib_n1 = fib_n
        fib_n = fib_n1 + fib_n2

    offset = records
    index = min( - fib_n2 + offset , records - 1)
    if fib_n == 1:
        if fib_array[records-1]==target:
           return records - 1
        else:
            return -1
    while fib_n != 1:
        if fib_array[index] > target:
            offset = index
            fib_n = fib_n1
            fib_n1 = fib_n2
            fib_n2 = fib_n - fib_n1
            index = min(- fib_n2 + offset, records - 1)

        elif fib_array[index] < target:
            fib_n = fib_n2
            fib_n1 = fib_n1 - fib_n2
            fib_n2 = fib_n - fib_n1
            index = min(- fib_n2 + offset, records - 1)

        #Special  Case
        if index > 0 and fib_array[0] == target:
            return 0

        else:
            return index

    else:
        return -1


#----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

def iterative_binary_search(bin_array,start_pos,end_pos,target):

    while start_pos<=end_pos:
        index = start_pos + (end_pos - start_pos) // 2

        if bin_array[index] == target:
            return index
        elif bin_array[index] < target:
            start_pos = index + 1
        else:
            end_pos = index - 1
    return -1



#----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


def recursive_binary_search(bin_array, start_pos, end_pos, target):
    if end_pos >= start_pos:
        index = start_pos + (end_pos - start_pos) // 2
        if bin_array[index] == target:
            return index

        elif bin_array[index] < target:
            return recursive_binary_search(bin_array, index + 1, end_pos, target)
        else:
            return recursive_binary_search(bin_array, start_pos, index - 1, target)
    else:
        return -1

#----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

list_of_roll = getroll(strength)
roll_list_copy = list_of_roll
quicksort(list_of_roll,0,len(list_of_roll) - 1)
print(list_of_roll)
menu()
choice = int(input("Enter choice - "))
while choice not in (1, 2, 3, 4):
    print("Pls enter appropriate choice - \n----------------------------------------------")
    choice = int(input("Enter choice - "))
check = True
while check:
    if choice == 1:
        search_result = iterative_binary_search(list_of_roll,0,strength - 1, key)
        if search_result == -1:
            print("Key isn't present.")
        else:
            print("Key present at", search_result+1, "location of the list of roll numbers.")

    elif choice == 2:
        search_result = recursive_binary_search(list_of_roll,0,strength - 1, key)
        if search_result == -1:
            print("Key isn't present.")
        else:
            print("Key present at", search_result+1,"location of the list of roll numbers.")

    elif choice == 3:
        search_result = conventional_fibonacchi_search(list_of_roll,strength, key)
        if search_result == -1:
            print("Key isn't present.")
        else:
            print("Key present at", search_result+1,"location of the list of roll numbers.")

    else:
        search_result = nonconventional_fibonacchi_search(list_of_roll,strength,key)
        if search_result == -1:
            print("Key isn't present.")
        else:
            print("Key present at",search_result+1,"location of the list of roll numbers.")

    to_continue = input("Want to continue?\nyes or no - ")
    to_continue = to_continue.lower()
    while to_continue not in ("yes", "no"):
        print("ENTER ONLY YES OR NO\n--------------------------------------------------")
        to_continue = input("Want to continue?\nyes or no - ")

    if to_continue == "no":
        print("--------------------------\nThnx for using our program.")
        check = False
    else:
        menu()
        choice = int(input("Enter choice - "))
        while choice not in (1, 2, 3, 4):
            print("Pls enter appropriate choice - \n----------------------------------------------")
            choice = int(input("Enter choice - "))



#----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

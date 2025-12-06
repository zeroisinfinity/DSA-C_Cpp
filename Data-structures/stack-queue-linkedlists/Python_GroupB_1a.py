"""a) Write a python program to store roll numbers of student in array who attended training program in random order. 
Write function for searching whether particular student attended training program or not, 
using Linear search and Sentinel search."""




import sys
sys.setrecursionlimit(3000)

def menu():
    print(
        "Enter 1 for linear search without recursion.\nEnter 2 for linear search with recursion.\nEnter 3 for Sentinel search")
    # print("Enter 1 for Binary search.\nEnter 2 for Fibonacci search")

#------------------------------------------------------------------------------------------------------------------------------------------------------------------------

list_of_roll = []
strength = int(input("Enter the strength of the class - "))
while strength<1:
    print("Plss enter a valid strength of class.")
    strength = int(input("Enter the strength of the class - "))
key = int(input("Enter the roll no. to be searched -  "))

#------------------------------------------------------------------------------------------------------------------------------------------------------------------------


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

#------------------------------------------------------------------------------------------------------------------------------------------------------------------------


recursive_tracker = 0

#------------------------------------------------------------------------------------------------------------------------------------------------------------------------


def LinearSearchWithoutRecursion(case, end , recursive_tracker):
    for compare in range(0, len(case), 1):
        if end == case[compare]:
            return compare
    else:
        return -1

#------------------------------------------------------------------------------------------------------------------------------------------------------------------------


def LinearSearchWithRecursion(case_rec, end_rec, recursive_tracker):
        if recursive_tracker == len(case_rec):
            return -1
        if end_rec == case_rec[recursive_tracker]:
            return recursive_tracker
        else:
            return LinearSearchWithRecursion(case_rec, end_rec, recursive_tracker + 1)

#------------------------------------------------------------------------------------------------------------------------------------------------------------------------


def SentinelSearch(sen_array, stock, demand):
    assume = sen_array[stock - 1]
    sen_array[stock - 1] = demand
    supply = 0
    while sen_array[supply]!=demand:
           supply += 1
    sen_array[stock - 1]  = assume
    if (supply<(stock-1)) or assume == demand:
        return supply
    else:
        return -1

#------------------------------------------------------------------------------------------------------------------------------------------------------------------------


def consequence(function):
    linear_result = function(list_of_roll, key, recursive_tracker )
    if linear_result != -1:
        print("Student is present at",linear_result+1,"location in list of roll number.")
    else:
        print("Student is not present")

#------------------------------------------------------------------------------------------------------------------------------------------------------------------------


list_of_roll = getroll(strength)
menu()
choice = int(input("Enter choice - "))
while choice not in (1, 2, 3):
    print("Pls enter appropriate choice - \n----------------------------------------------")
    choice = int(input("Enter choice - "))
check = True
while check:
    if choice == 1:
        consequence(LinearSearchWithoutRecursion)

    elif choice == 2:
        consequence(LinearSearchWithRecursion)
    else:
        search_result = SentinelSearch(list_of_roll,strength,key)
        if search_result == -1:
            print("Key isn't present.")
        else:
            print("Key present at",search_result+1,"location of the list of roll numbers.")

    to_continue = input("Want to continue?\nyes or no - ")
    while to_continue.lower() not in ("yes", "no"):
        print("ENTER ONLY YES OR NO\n--------------------------------------------------")
        to_continue = input("Want to continue?\nyes or no - ")

    if to_continue.lower() == "no":
        print("--------------------------\nThnx for using our program.")
        check = False
    else:
        choice = int(input("Enter choice - "))
        while choice not in (1, 2, 3):
            print("Pls enter appropriate choice - \n----------------------------------------------")
            choice = int(input("Enter choice - "))






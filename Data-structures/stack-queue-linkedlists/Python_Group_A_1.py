"""
        Write a Python program to compute following operations on String: 
        a) To display word with the longest length
        b) To determines the frequency of occurrence of particular character in the string
        c) To check whether given string is palindrome or not 
        d) To display index of first appearance of the substring  
        e) To count the occurrences of each word in a given string


"""

cricket = []
football = []
badminton = []


def inp(l, size, sport):
    print("Students playing", sport, "- ")

    while size > 0:
        roll = input("Enter student roll number - ")
        if roll.isnumeric():
            roll = int(roll)
            if roll in l or 0 >= roll:
                print("Please enter a valid roll no.")
            else:
                l.append(roll)
                size -= 1
        else:
            print('Enter a numeric value please!')
    print(l)


strength_C = int(input("Enter the no.of students playing cricket- "))
inp(cricket, strength_C, 'C')
strength_B = int(input("Enter the no.of students playing badminton - "))
inp(badminton, strength_C, 'B')
strength_C = int(input("Enter the no.of students playing football - "))
inp(football, strength_C, 'F')
intersection_set = []


def intersection(l1, l2):
    for i in l1:
        if i in l2:
            intersection_set.append(i)


union_set = []


def union(l1, l2):
    for i in l1:
        union_set.append(i)
    for i in l2:
        if i not in l1:
            union_set.append(i)


diff_set = []


def difference(l1, l2):
    for i in l1:
        if i not in l2:
            diff_set.append(i)


flag = 1
while flag == 1:
    print("\n\n--------------------MENU--------------------\n")
    print("1. List of student who play cricket and badminton")
    print("2.List of student who play either cricket or badminton but not both ")
    print("3. Number of Students who play neither cricket nor badminton")
    print("4. Number of Students who play cricket or football but not badminton")
    print("5. Exit\n")
    choice = int(input("Enter your Choice (from 1 to 5) :"))

    if choice == 1:
        intersection_set = []
        intersection(cricket, badminton)
        print("List of student who play cricket and badminton", intersection_set)

    elif choice == 2:
        union_set = []
        union(cricket, badminton)
        intersection_set = []
        intersection(cricket, badminton)
        diff_set = []
        difference(union_set, intersection_set)
        print("List of student who play either cricket or badminton but not both", diff_set)

    elif choice == 3:
        union_set = []
        union(cricket, badminton)
        diff_set = []
        difference(football, union_set)
        num = len(diff_set)
        print("List of Students who play neither cricket nor badminton ", diff_set, " number ", num)




    elif choice == 4:
        intersection_set = []
        intersection(cricket, football)

        diff_set = []
        difference(intersection_set, badminton)
        num = len(diff_set)
        print("List of Students who play cricket and football but not badminton", diff_set, " number ", num)


    elif choice == 5:
        print("exit")
        flag = 0
        break
        

    else:
        print(" invalid choice")
        choice = int(input("Enter your Choice (from 1 to 5) :"))

    want = input("Do you want to continue (yes/no) :")
    while want.lower() not in ['no','yes']:
        print('Invalid response.')
        want = input("Do you want to continue (yes/no) :")
    if want.lower() == 'no':
        print('Thanks for using our program.')
        break






"""
        Write a Python program to compute following operations on String: 
        a) To display word with the longest length 
        b) To determines the frequency of occurrence of particular character in the string 
        c) To check whether given string is palindrome or not  
        d) To display index of first appearance of the substring 
        e) To count the occurrences of each word in a given string

"""

def palindrome(my_string):
    my_string = my_string.lower()
    length = len(my_string)
    search = 0
    while search <= length//2:
        if my_string[search] == my_string[-1 - search]:
            search += 1
        else:
            return "Given string is not a palindrome."
    else:
        return "Given string is a palindrome."

#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

def count_freq(my_string, char_freq):
    freq = 0
    my_string = my_string.lower()
    for i in range(len(my_string)):
        if my_string[i] == char_freq.lower():  # Ensure character comparison is case insensitive
            freq += 1
            
    return freq

#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

def longest_word(my_string):
    long_word = ""
    current_word = ""
    
    for char in my_string:
        if char != ' ':
            current_word += char
        else:
            if len(current_word) > len(long_word):
                long_word = current_word
            current_word = ""
    
    # Check the last word if the string doesn't end with a space
    if len(current_word) > len(long_word):
        long_word = current_word
    
    print("Longest word is:", long_word)

#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

def first_index(my_string, sub_string):
    my_string = my_string.lower()                 
    sub_string = sub_string.lower()
    len_of_substr = len(sub_string)
    len_of_mystr = len(my_string)

    for search in range(0, len_of_mystr - len_of_substr + 1, 1):
        match = True
        for sub_search in range(len_of_substr):
            if my_string[search + sub_search] != sub_string[sub_search]:
                match = False
                break
        if match:
            return search

    return "Substring not found"


# ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
def occurrence(my_string):
    my_string = my_string + " "
    current_word = ''
    process_list = []
    my_string = my_string.lower()
    for collector in range(0, len(my_string), 1):
        if my_string[collector] != " ":
            current_word += my_string[collector]
        else:
            if current_word:  # Avoid appending empty words
                process_list.append(current_word)
            current_word = ''
    process_set = set(process_list)
    final_count_list = []
    for word in process_set:
        count_word = 0
        for check in range(0, len(process_list), 1):
            if word == process_list[check]:
                count_word += 1
        final_count_list.append((word, count_word))
    return final_count_list


# ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
def menu():
    print("Enter 1 for palindrome. \nEnter 2 to check for the longest word. \nEnter 3 for index of the first occurrence of a substring. \nEnter 4 to know the occurrence of each word.\nEnter 5 to check how many times a character appeared in a string.")

test_str = input("Enter the string: ")
check = True
while check and len(test_str) != 0:
    menu()
    choice = int(input("Enter choice: "))

    while 5 < choice or choice < 1:
        print("Enter a valid choice!!!")
        choice = int(input("Enter choice: "))

    if choice == 1:
        print(palindrome(test_str))
    
    elif choice == 2:
        longest_word(test_str)
        
    elif choice == 3:
        substr = input("Enter the substring: ")
        print(first_index(test_str, substr))
        
    elif choice == 4:
        print(occurrence(test_str))

    else:
        charac = input("Enter the character: ")
        print(count_freq(test_str, charac))

    want = input("Want to continue? If yes type 'yes', otherwise type 'no':\n --- ")
    while want.lower() != "yes" and want.lower() != "no":
        print("Enter 'yes' or 'no' only.")
        want = input("Want to continue? If yes type 'yes', otherwise type 'no':\n --- ")
    if want.lower() == "no":
        print("Thank you for using our program!")
        check = False    

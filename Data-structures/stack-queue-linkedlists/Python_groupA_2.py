"""
Experiment Number 2 : Write a python program to store marks stored in subject "Fundamentals of Data Structure" by
                         N students in the class. Write functions to compute following:
                         1. The average score of the class.
                         2. Highest score and lowest score of the class.
                         3. Count of students who were absent for the test.
                         4. Display mark with highest frequency.
"""



#MENU function defined
def menu():
    print("Enter 1 for average function. \nEnter 2 for lowest mark function. \nEnter 3 for highest mark function. \nEnter 4 for highest frequency function.\nEnter 5 for absent function.\nEnter 6 to Exit.")
    
#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#Opting for exam 1)Insem - 30 , 2)Endsem - 70
print("Choose the examination - \n1)Insem\n2)Endsem\n")


#Declaring option 
option = int(input("Enter choice - "))


#While loop if choice is invalid
while option != 2 and option != 1:
    print("Enter valid choice")    
    option  = int(input("Enter choice - "))
    

#Declaring limit_of_marks as ZERO
limit_of_marks  = 0        
if option == 1:
        limit_of_marks = 30 #If insem
elif option == 2:
        limit_of_marks = 70 #If endsem

#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#Declaring no_of_stud to hold class strength
no_of_stud = int(input("Enter class strength -  "))


#While loop if entered negative .... could've affected upcoming marks filling while loop
while no_of_stud<0:
    print("Enter a valid strength.")
    no_of_stud = int(input("Enter class strength -  "))
    

#Declaring list_of_marks to hold marks
list_of_marks = []
#Defining end as no_of_stud replica to avoid confusion
end = no_of_stud


#Declaring i as to iterate loop
i = 0
while i<end:
    #Declaring marks
    marks = int(input("Enter the marks of "+str(i+1)+" student - "))
    #Imp condition to avoid invalid marks
    if marks<=limit_of_marks and marks>=0 or marks==-1:
        list_of_marks.append(marks) #Append only when valid
        i+=1 #increament i only then
    else:
        #Otherwise repeat loop for a mistake
        print("Pls enter marks in limit ",limit_of_marks)
 
#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#Defining avg function          
def avg(l):
    total = 0
    studs = no_of_stud
    for score in l:
        if score == -1:
            studs-=1
        else:
            total+=score
    #If students aren't zero
    if studs!=0:
       print("Average of class is - ",total//studs)
       
    #If all are absent so to avoid division by zero error           
    if studs==0:
       print("No average because all students are absent.")
            
#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
# Defining HIGHEST FREQUENCY FUNCTION
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
    # If not
    else:
        for iter in range(len(freq_list)):
            print("Highest frequency marks is ", freq_list[iter], " with frequency of - ", count_initial)

#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#Defining low function
def low(l):
    if l[0]!=-1: #If unfortunately first element is -1
        lowest = l[0]
    else:
        lowest = float('inf') #Standard
    for i in l:
        if i<lowest and i!= -1:
            lowest = i
    #If all are absent lowest shouldn't be -1
    if lowest == float('inf'):
        print("All are absent.")
    else:
        print("lowest marks is - ",lowest)
        
#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#Defining High function                
def high(l):
    if l[0]!=-1: #If unfortunately first element is -1
        highest = l[0]
    else:
        highest = float('-inf') #Standard
   
    for i in l:
        if i>highest and i!=-1:
           highest = i
           
    #If all are absent lowest shouldn't be -1 
    if highest == float('-inf'):
       print("All are absent.") 
    
    #If everyone have Zero marks Highest≠Lowest                      
    elif highest == 0:
       print("Everyone scored Zero marks.")       
                        
    else:
       print("Highest marks are - ",highest)

# -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   
#Defining absent function    
def absent(l):
    absenty = 0
    for i in l:
        if i == -1:
            absenty+=1
            
    return absenty
    
#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
while no_of_stud!=0:
    
    #Calling menu()
    menu()
    
    #Declaring Choice
    choice = int(input("Enter choice - "))
    while 6 < choice or choice < 1:
        print("Enter a valid choice!!!")
        choice = int(input("Enter choice - "))
    
    if choice==1:
        avg(list_of_marks)
        
    elif choice==2:
        low(list_of_marks)
        
    elif choice==3:
        high(list_of_marks)
        
    elif choice==4:
        hfreq(list_of_marks)
        
    elif choice==5:
        print("Absent no.of students - ", absent(list_of_marks))

    else:
        print("Thank you for using our program!")
        break

        
    #Wanna continue then....yes 
    want = input("Want to continue ? if yes type yes otherwise no\n --- ")
    want = want.lower()
    while want!="yes" and want!="no":
        print("Enter yes or no only")
        want = input("Want to continue ? if yes type yes otherwise no\n --- ")
        
    if want=="no":
        print("Thank you for using our program!")
        break        

#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
    

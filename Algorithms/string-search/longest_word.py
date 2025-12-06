import cProfile

def longest_word(my_string):
    start_pos = 0
    end_pos = 0
    length_holder = 0
    for iter in range(0, len(my_string), 1):
        if my_string[iter] == ' ':
            if (iter - end_pos) > length_holder:
                length_holder = (iter - end_pos)
                end_pos = iter + 1
                start_pos = end_pos - 1

            else:
                end_pos = iter + 1

    if (iter + 1) - end_pos > length_holder:
        return my_string[end_pos: iter + 1]
    else:
        return my_string[start_pos - length_holder: start_pos]

def longest_word_pure_python(my_string):
    start_pos = 0
    end_pos = 0
    length_holder = 0
    for iter in range(0, len(my_string), 1):
        if my_string[iter] == ' ':
            if (iter - end_pos) > length_holder:
                length_holder = (iter - end_pos)
                end_pos = iter + 1
                start_pos = end_pos - 1

            else:
                end_pos = iter + 1

    if (iter + 1) - end_pos > length_holder:
        ans = ""
        for i in range(end_pos,iter+1,1):
            ans+=my_string[i]
        return ans
    else:
        ans = ""
        for i in range(start_pos - length_holder, start_pos, 1):
            ans += my_string[i]
        return ans
text = "Incomprehensibilities and antidisestablishmentarianism are among the longest words, but"*8000 + " pneumonoultramicroscopicsilicovolcanoconiosis."
cProfile.run("longest_word_pure_python(text)")
print(longest_word_pure_python(text))
cProfile.run("longest_word(text)")
print(longest_word(text))



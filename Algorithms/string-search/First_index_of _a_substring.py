import cProfile

def first_index(my_string, sub_string):
    my_string = my_string.lower()                  #FOUR TIMES FASTER THAN USUAL CODE
    sub_string = sub_string.lower()
    len_of_substr = len(sub_string)
    len_of_mystr = len(my_string)
#start loop
    for search in range(0, len_of_mystr - len_of_substr + 1, 1):
        if my_string[search] == sub_string[0]:
            for sub_search in range(1, len_of_substr, 1):
                if sub_string[sub_search] == my_string[search + sub_search]:
                    continue
                else:
                    break
            else:
                return search
    return "Substring not found"
  
test_str = "a" * 1000000 + "hell" + "b" * 100000000  + 'hello' + 'z'
sub_str = "z"
cProfile.run("first_index(test_str,sub_str)")

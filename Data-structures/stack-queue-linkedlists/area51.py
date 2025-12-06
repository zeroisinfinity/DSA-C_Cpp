
def hfreq(l):
    count_ini = 1
    highest = l[0]
    for i in range(len(l)):
        count_dyn = 1
        for j in range(i+1,len(l)):
            if l[i] == l[j]:
                count_dyn += 1

        if count_ini<count_dyn:
            count_ini = count_dyn
            highest = l[j]
    return highest

print(hfreq([22,33,33,33,44,44,44,44]))


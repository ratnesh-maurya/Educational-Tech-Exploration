# *****
# *****
# *****
# *****
# *****

for i in range (0,5):
    for j in range (0,5):
        print('*',end='')
    print()
print('---------')
# *
# **
# ***
# ****
# *****
for i in range (0,5):
    for j in range(0,i+1):
        print('*',end = '')
    print()
print('---------')
# 1
# 12
# 123
# 1234
# 12345
for i in range (0,5):
    for j in range(1,i+2):
        print(f'{j}',end = '')
    print()
print('---------')
# 1
# 22
# 333
# 4444
# 55555

for i in range (1,6):
    for j in range(1,i+1):
        print(f'{i}',end = '')
    print()
print('---------')

# *****
# ****
# ***
# **
# *

for i in range (0,5):
    for j in range (5,i,-1):
        print('*',end = '')
    print()
print('---------')

# 12345
# 1234
# 123
# 12
# 1
for i in range (0,5):
    for j in range (1,6-i):
        print(f'{j}',end = '')
    print()
print('---------')

#     *
#    ***
#   ******
#  ********
# **********

for i in range (1,6):
    for j in range (5,i,-1):
        print(' ',end = '')
    for j in range(0,i):
        print('*',end = '')
    for j in range (1,i):
        print('*',end = "")
    print()

print('---------')

# *********
#  *******
#   *****
#    ***
#     *

for i in range (0,5):
    for j in range(0,i):
        print(' ',end = '')
    for j in range (5,i,-1):
        print('*',end = '')
    for j in range (4,i,-1):
        print('*',end = "")   
    print()
print('---------')
#     *
#    ***
#   ******
#  ********
# **********
# *********
#  *******
#   *****
#    ***
#     *

for i in range (1,6):
    for j in range (5,i,-1):
        print(' ',end = '')
    for j in range(0,i):
        print('*',end = '')
    for j in range (1,i):
        print('*',end = "")
    print()
for i in range (1,6):
    for j in range(0,i):
        print(' ',end = '')
    for j in range (5,i,-1):
        print('*',end = '')
    for j in range (4,i,-1):
        print('*',end = "")   
    print()
print('---------')

# *
# **
# ***
# ****
# *****
# ****
# ***
# **
# *

for i in range (0,5):
    for j in range(0,i+1):
        print('*',end = '')
    print()
for i in range (0,4):
    for j in range (4,i,-1):
        print('*',end = '')
    print()
print('---------')

# 1
# 01
# 101
# 0101
# 10101
for i in range(1, 6):
    for j in range(i, i+i):
        print(j%2, end="")
    print()
print('---------')    

# 1      1
# 12    21
# 123  321
# 12344321

for i in range (1,5):
    for j in range(1,i+1):
        print(f'{j}',end = '')
    for j in range (5,i,-1):
        print(' ',end = '')
    for j in range (4,i,-1):
        print(' ',end = "")
    for j in range(i,0,-1):
        print(f'{j}',end = '')
    print()
print('---------')

# 1
# 23
# 456
# 78910
# 1112131415
k=1
for i in range (1,6):
    for j in range(1,i+1):
        print(f'{k} ',end = '')
        k=k+1
    print()
print('---------------')

# A
# AB
# ABC
# ABCD
# ABCDE

for i in range (1,6):
    p=65
    for j in range(1,i+1):
        print(f'{chr(p)} ',end = '')
        p=p+1
    print()
print('---------------')

# ABCDE 
# ABCD 
# ABC 
# AB 
# A
 
for i in range (0,5):
    q=65
    for j in range (1,6-i):
        print(f'{chr(q)} ',end = '')
        q = q+1
    print()
print('---------------')

# A
# BB 
# CCC 
# DDDD 
# EEEEE 

q=65
for i in range (0,5):
    for j in range (1,6-i):
        print(f'{chr(q)} ',end = '')
    q = q+1
    print()
print('---------------')

#    A 
#   ABA 
#  ABCBA
# ABCDCBA
for i in range (1,5):
    p=65
    for j in range (5,i,-1):
        print(" ",end = '')
    for j in range(0,i):
        print(chr(p),end = '')
        p=p+1
    p=64+(i-1)
    for j in range (i-1,0,-1):
        print(chr(p),end = "")
        p=p-1
    print()
print('---------')

for i in range (1,6):
    q = ord('E')-(i-1)
    for j in range (0,i):
        print(f'{chr(q)} ',end = '')
        q=q+1
    print()
print('----------')

# **********
# ****  ****
# ***    ***
# **      **
# *        *
# *        *
# **      **
# ***    ***
# ****  ****
# **********

for i in range (1,6):
    for j in range (6,i,-1):
        print('*',end = '')
    for j in range(1,i):
        print(' ',end = '')
    for j in range (1,i):
        print(' ',end = "")
    for j in range (6,i,-1):
        print('*',end = '')
    print()
for i in range (1,6):
    for j in range(1,i+1):
        print('*',end = '')
    for j in range (5,i,-1):
        print(' ',end = '')
    for j in range (5,i,-1):
        print(' ',end = "")
    for j in range(i,0,-1):
        print('*',end = '')
    print()
print('---------')

# *        *
# **      **
# ***    ***
# ****  ****
# **********
# ****  ****
# ***    ***
# **      **
# *        *

for i in range (1,5):
    for j in range(1,i+1):
        print('*',end = '')
    for j in range (5,i,-1):
        print(' ',end = '')
    for j in range (5,i,-1):
        print(' ',end = "")
    for j in range(i,0,-1):
        print('*',end = '')
    print()
for i in range (1,6):
    for j in range (6,i,-1):
        print('*',end = '')
    for j in range(1,i):
        print(' ',end = '')
    for j in range (1,i):
        print(' ',end = "")
    for j in range (6,i,-1):
        print('*',end = '')
    print()
print('-----------')


# ****
# *  *
# *  *
# *  *
# ****

for i in range(0,5):
    for j in range (0,4):
        if(i==0 or j==0 or i==4 or j==3):
            print('*',end='')
        else:
            print(' ',end = '')
    print()
print('-----------') 

# 4444444
# 4333334
# 4322234
# 4321234
# 4322234
# 4333334
# 4444444

a = [0,0,0,0,0,0,0]
p= 4
for i in range (0,7):
    if i<4:
        for j in range(i,7-i):
            a[j] = p
        p=p-1
    else:
        b=[str(x) for x in a]
        b=" ".join(b)
        b=b.replace(str(p+1),str(p+2))
        a=b.split(" ")
        p=p+1
        # k=1
        # for j in range(i-k,i):
        #     a[j] = p
        #     k=k+1
        # p=p+1

    
    for i in range(0,7):
        print(a[i],end = '')
    print()
# for i in range (,4):
#     for j in range ()


    



        
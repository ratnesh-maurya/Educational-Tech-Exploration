# modified pattern.py to create triangles 
n = int(input("Enter no of rows"))

for i in range(1,n+1):
  j = i
  print(" "*(n-i+1),end="") ## to fill space in each line
  while j>=1:
    print('*',end=" ")  ## to print stars 
    j-=1
  print()  ## escape line

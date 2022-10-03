
def linear_search(array,search):
    n = len(array)
    if n == 0:
        return -1
    for i in range(n):
        if array[i] ==  search:
            return i
    return -1
array = [1,3,4,5,1,34,234,-12]
search = 5
found = linear_search(array=array,search=search)
print("Print Element found at psition ",found+1)



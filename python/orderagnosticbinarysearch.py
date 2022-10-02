def orderagnostic_binary_search(array,search):
    start = 0
    end = len(array) - 1
    is_asc = array[start] < array[end]

    while(start<=end):
        mid = start + int((end - start)/2)
        if array[mid] == search:
            print("Element found at ",mid)
            return
        if is_asc:
            if array[mid] > search:
                end = mid - 1
            else :
                start = mid + 1                
        else:
            if array[mid] < search:
                end = mid - 1
            else:
                start = mid + 1

    print("Element Not Found")
    return


array = [90,87,80,75,70,65,12]
orderagnostic_binary_search(array,90)
array = [1,3,4,5,6,7,8,9,11,34,56,100]
orderagnostic_binary_search(array,3)



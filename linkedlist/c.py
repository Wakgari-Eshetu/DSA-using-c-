def sorting(arr:list)->list:
    for i in range(len(arr)):
        for j in range(len(arr)-1):
            if arr[j]>arr[j+1]:
                arr[j],arr[j+1] = arr[j+1],arr[j]

    return arr

arr = [5,3,4,9,2]
print(sorting(arr))
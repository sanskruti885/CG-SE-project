# Write a Python program to store second year percentage of students in array. Write 
# function for sorting array of floating-point numbers in ascending order using a) 
# Insertion sort and b) Shell Sort and display top five scores. 

class Sorter:
    def insertion_sort(self,arr):
        for i in range(1,len(arr)):
            temp = arr[i]
            j = i-1
            while j>=0 and arr[j]>temp:
                arr[j+1] = arr[j] #this replaces the key element with previous
                j-=1
            arr[j+1] = temp
        for i in range(len(arr)):
            print(arr[i])

    def shell_sort(self,arr):
        n = len(arr)
        gap = n//2

        while gap>0:
            for i in range(gap,n):
                temp = arr[i]
                j = i
                while j>=gap and arr[j-gap]>temp:
                    arr[j] = arr[j-gap]
                    j-=gap
                arr[j] = temp
            gap=gap//2
        for i in range(len(arr)):
            print(arr[i])


s = Sorter()
arr =[]
k = int(input("Enter number of element: "))
print("Enter array elements")
for i in range(k):
    ele = int(input())
    arr.append(ele)

ch = "y"

while ch == "y":
    print("1. Insertion sort")
    print("2. Shell sort")
    n = int(input("Enter choice: "))

    if(n==1):
        s.insertion_sort(arr)
    elif(n==2):
        s.shell_sort(arr)
    
    ch = input("Enter 'y' to continue: ")

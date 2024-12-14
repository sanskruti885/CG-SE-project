# Write a Python program to store first year percentage of students in array. Write 
# function for sorting array of floating-point numbers in ascending order using Quick 
# sort and display top five scores.

class Sorter:

    def quicksort(self,arr,low,high,pass_num=1):
        if low<high:
            pi = self.partition(arr,low,high)
            pass_num+=1
            self.quicksort(arr,low,pi-1,pass_num)
            self.quicksort(arr,pi+1,high,pass_num)
            return arr

    def partition(self,arr,low,high):
        pi = arr[high]

        i = low-1
        for j in range(low,high):
            if(arr[j]<pi):
                i+=1
                arr[i],arr[j] = arr[j],arr[i]
        arr[i+1],arr[high] = arr[high],arr[i+1]
        return i+1 #pivot
    

s = Sorter()
data = []
n = int(input("Enter number of student: "))

for i in range(n):
    marks = float(input("Enter percentage: "))
    data.append(marks)
f = s.quicksort(data,0,n-1)

top_five = f[-5:] if len(f)>=5 else f
top_five.reverse()

print(top_five)



       
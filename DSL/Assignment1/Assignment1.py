class student:
    def get_info(self,arr):
        n = int(input("ENter number of students : "))
        for i in range(n):
            while True: 
                roll = int(input("Enter roll number: "))
                if roll not in arr:
                    arr.append(roll)
                    break
                else:
                    print("This number already exist")
       

    def display(self,arr):
        for i in range(len(arr)):
            print(arr[i]," ")

    def union(self,arr1,arr2,arr3):
        result = []
        for k in arr1:
            if k not in result:
                result.append(k)
        for i in arr2:
            if i not in result:
                result.append(i)
        for j in arr3:
            if j not in result:
                result.append(j)
        return result

    # cricket and badminton
    def cric_bad(self,arr1,arr2):
        n = []
        for i in arr1:
            if i in arr2:
                n.append(i)
        return n
    
    # cricket or badminton
    def cric_or_bad(self,arr1,arr2):
        n = []
        for i in arr1:
            if i not in arr2:
                n.append(i)
        for j in arr2:
            if j not in arr1:
                n.append(j)
        return n
    
    # not cricket nor badminton
    def cric_nor_bad(self,arr1,arr2,total):
        n = []
        for student in total:
            if student not in arr1 and student not in arr2:
                n.append(student)
        return len(n)
    # bot cricket and footbal not badminton
    def cri_foot(self,cric,bad,foot):
        n=[]
        for i in cric:
            if i in foot and i not in bad:
                n.append(i)
        return len(n)

cricket=[]
bad = []
football = []
temp = []
total_student = []
s = student()
print("Enter cricket student: ")
s.get_info(cricket)
print("Enter badminton student: ")
s.get_info(bad)
print("Enter footbal student: ")
s.get_info(football)
total_student = s.union(cricket,bad,football)
ch = "y"

while (ch=="y"):
    print("1. Student who play both cricket and badminton ")
    print("2. Play either cricket or badminton not both ")
    print("3. Neither cricket nor badminton ")
    print("4. Cricket and football not badminton ")
    n = int(input("Enter your choice: "))
    
    if n==1:
        temp = s.cric_bad(cricket,bad)
        print("Students playing both cricket and badminton")
        if(temp == []):
            print("No student")
        else:
            s.display(temp)
    elif n==2:
        temp = s.cric_or_bad(cricket,bad)
        print("Students playing cricket or badminton")
        if(temp == []):
            print("No student")
        else:
            s.display(temp)
    elif n==3:
        k = s.cric_nor_bad(cricket,bad,total_student)
        print("Number of students neither cricket or badminton: ",k)
    elif n==4:
        k = s.cri_foot(cricket,bad,football)
        print("Number of students play cricket and football but not badminton: ",k)

    print("Enter 'y' to continue again: ")
    ch = str(input())

        










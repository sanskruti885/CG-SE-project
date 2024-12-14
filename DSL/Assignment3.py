class Matrices:
    def create_matrix(self):
        row = int(input("Enter row: "))
        col = int(input("Enter col: "))
        matrix = []
        for i in range(row):
            row = []
            for j in range(col):
                ele = int(input("Enter element: "))
                row.append(ele)
            matrix.append(row)
        for i in matrix:
            print(i)
        return matrix

    def add_matrix(self,A,B):
        print('------------------------------\nADDITION OF MATRIX\n------------------------------')
        result = []
        for i in range(len(A)):
            r=[]
            for j in range(len(A[0])):
                r.append(A[i][j]+B[i][j])
            result.append(r)
        for i in result:
            print(i)

    def sub_matrix(self,A,B):
        print('------------------------------\nSUBSTRACTION OF MATRIX\n------------------------------')
        result = []
        for i in range(len(A)):
            r=[]
            for j in range(len(A[0])):
                r.append(A[i][j]-B[i][j])
            result.append(r)
        for i in result:
            print(i)
    
    def mult_matrix(self,A,B):
        print("-------------------------------------\nMULTIPLICATION OF MATRIX\n---------------------------")
        result = []
        for i in range(len(A)):
            r=[]
            for j in range(len(A[0])):
                element =0
                for k in range(len(A[0])):
                    element+=A[i][k]*B[k][j]
                r.append(element)
            result.append(r)
        
        for i in result:
            print(i)

    def transpose(self,A):
        print("-------------------------------------\nTRANSPOSE OF MATRIX\n---------------------------")
        result = []
        for i in range(len(A)):
            r=[]
            for j in range(len(A[0])):
                r.append(A[j][i])
            result.append(r)

        for i in result:
            print(i)
        

    

m = Matrices()
print("Enter matrix one")
m1 = m.create_matrix()
print("Enter matrix two")
m2 = m.create_matrix()

ch = "y"
while(ch=="y"):
    print("1.Addition")
    print("2.Substraction")
    print("3.Multiplication")
    print("4.Transpose")
    n = int(input("Enter your choice "))

    if n==1:
        m.add_matrix(m1,m2)
    elif n==2:
        m.sub_matrix(m1,m2)
    elif n==3:
        m.mult_matrix(m1,m2)
    elif n==4:
        m.transpose(m1)

    ch = input("Enter y to continue ")


            

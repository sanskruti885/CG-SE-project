# Write a Python program to compute following operations on String:  
# a) To display word with the longest length  
# b) To determines the frequency of occurrence of particular character in the string  
# c) To check whether given string is palindrome or not  
# d) To display index of first appearance of the substring  
# e) To count the occurrences of each word in a given string  
class str_op:
    def splitter(self,sen):
        string = str()
        l = []
        for i in sen:
            if i!=" ":
                string+=i
            if i == " " :
                l.append(string)
                string=""
        # for adding last word where no space 
        if string:
            l.append(string)
        return l
    
    # find the longest word
    def long_len(self,sen):
        l = self.splitter(sen)
        long =str()
        for i in l:
            if(len(i)>len(long)):
                long = i
        print("Longest word: ",long)

    # check occurence of particualr character in word or sentence
    def occurence(self,sen,char):
        count =0
        for i in sen:
            if char in i:
                count+=1
        print("Occurence of ",char," is: ",count)

    #palindrome or not
    def palindrome(self,sen):
        ori = sen
        rev = sen[::-1]
        if ori == rev:
            print("Palindrome") 
        else:
            print("Not palindrome")      

# index of substring
    def index_substr(self,sen,substr):
        l = len(substr)
        for i in range(len(sen)):
            if(sen[i:i+l] == substr):
                print("Found ",substr," at position: ",i)
                break

# occurence of word
    def freq_word(self,sen,substr):
        l = self.splitter(sen)
        count =0
        for i in l:
            if i == substr:
                count+=1
        print("Occurence of substring: ",count)
                


obj = str_op()
# obj.long_len(s)
ch = "y"

while ch=="y":
    print("1. To display word with the longest length")
    print("2. To determines the frequency of occurrence of particular character in the string")
    print("3. To check whether given string is palindrome or not  ")
    print("4. To display index of first appearance of the substring ")
    print("5. To count the occurrences of each word in a given string")
    n = int(input("Enter your choice: "))

    if(n==1):
        sen = input("Sentence: ")
        obj.long_len(sen)
    elif(n==2):
        sen = input("Sentence: ")
        char = input("Enter char: ")
        obj.occurence(sen,char)
    elif(n==3):
        sen = input("Sentence: ")
        obj.palindrome(sen)
    elif n==4:
        sen = input("Sentence: ")
        substr = input("Substr: ")
        obj.index_substr(sen,substr)
    elif n==5:
        sen = input("Sentence: ")
        substr = input("Substr: ")
        obj.freq_word(sen,substr)

    ch = input("Press y to continue: ")
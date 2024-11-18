num=int(input("Enter the number of elements in fibonacci series"))
n1,n2=0,1
count=2
print("Fibonacci Series..")
if(num<0):
    print("Enter a positive number")
elif(num==1):
    print(n1)
elif(num==2):
    print(n1)
    print(n2)
else:
    print(n1)
    print(n2)
    while(count<=num):
        new=n1+n2
        n1=n2
        n2=new
        count+=1
        print(new)

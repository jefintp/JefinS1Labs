a=int(input("Enter the number of rows"))
num=1
for i in range(1,a+1):
    for j in range(1,i+1):
             num=i*j
             print(num,end=" ")
    print()

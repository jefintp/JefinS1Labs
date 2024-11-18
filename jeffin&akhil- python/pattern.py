a=int(input("Enter the max number of star elements in a row"))
for i in range(a):
     for j in range(i):
            print("*",end="")
     print()
for i in range(a):
     for j in range(a-i):
            print("*",end="")
     print()


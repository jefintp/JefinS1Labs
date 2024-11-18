a=int(input("Enter the smallest number "))
b=int(input("Enter the largest number "))
gcd=1
for i in range(1,a+1):
    if(a%i==0 and b%i==0):
        gcd=i
print("GCD is ",gcd)
        
    

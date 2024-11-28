class bank:
    def __init__(self,accno,name,type):
        self.accno=accno
        self.name=name
        self.type=type
        self.balance=0
    def deposit(self,amount):
        self.amount=amount
        self.balance+=amount
    def withdraw(self,amount):
        if self.amount>self.balance:
            print("Insufficient balance")
        else:
            self.balance-=amount
    def displaybalance(self):
        print(f"The account balance is {self.balance}")

print("Select your bank account")
name=input("Enter your name")
accno=int(input("Enter your account number"))
type=input("Enter the type of account")
b1=bank(accno,name,type)
while 1:
    choice=int(input("Enter the choice..1.Balance Check,2.Withdrawal,3.Deposit,4.Exit"))
    if choice==1:
        b1.displaybalance()
    elif choice==2:
        amount=int(input("Enter the amount"))
        b1.withdraw(amount)
    elif choice==3:
        amount=int(input("Enter the amount"))
        b1.deposit(amount)
    else:
        exit()
 




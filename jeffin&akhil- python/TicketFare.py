#Rate of ticket based on age
age=int(input("Enter your age: "))
if age<10:
    print("Ticket fare is 7")
elif 10<=age<60:
    print("Ticket fare is 10")
else:
    print("Ticket fare is 5")

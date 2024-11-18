a=input("Enter the string:")
if a[-3:]=="ing":
    new=a+"ly"
else:
    new=a+"ing"
print("Changed word is",new)

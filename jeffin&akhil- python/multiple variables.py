#Using unpacking
name, age, city = "John",30,"New York"
print(name)
print(age)
print(city)

#Multiple assignment
a,b,c = 1,2,3
print(a,b,c)

#Print variables using f-string
name="Alice"
age=34
city="Wonderland"
message=f"Hello, my name is {name}, I am {age} years old, and I live in {city}."
print(message)

#variable names are case sensitive
a=4
A="Sally"
print(a)
print(A)

#Many values to multiple variables
x,y,z = "Orange", "Banana", "Cherry"
print(x)
print(y)
print(z)

#One value to many variables
x=y=z="Orange"
print(x)
print(y)
print(z)

#Unpack a collection
fruits=["Apple", "Banana", "Cherry"]
x,y,z=fruits
print(x)
print(y)
print(z)

#Printing to the console
print("Hello world")

#Writing to a file
with open('output.txt','w')as file:
    file.write("This is some output data")

#Using standard output stream
import sys
sys.stdout.write("This is some output data.\n")

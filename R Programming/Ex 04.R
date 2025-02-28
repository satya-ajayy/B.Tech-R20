#Exercise 4

# a) Write a program to demonstrate the Factors in R
x = c("female","male","male","female")
print(x)
gender = factor(x) 
print(gender) 
print(is.factor(gender)) 
class(gender)
gender[3]
gender[c(2,4)]
gender[-3]
gender[c(-3,-4)]


size = c("small","large","large","small","medium")
print(size)
size_factor = factor(size)
print(size_factor)
ordered_size = factor(size,levels=c("small","medium","large"),ordered = 
                        TRUE) 
print(ordered_size)
class(size_factor)
class(ordered_size)

# or

sizes = ordered(size,c("small","medium","large"))
print(sizes) 
print(is.ordered(sizes))
print(class(sizes))


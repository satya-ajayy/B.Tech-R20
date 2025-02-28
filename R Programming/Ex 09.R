# Exercise 9

# a)Write an R program to create a Matrix from vector using dim()
x = c(1:9)
print(x)
class(x)
dim(x) = c(3,3)
print(x)
class(x)


# b)Write an R program to create a List and modify components
x = list(2.7,'hello',77)
names(x) = c('float','string','integer')
print(x[1])
print(x['string'])
x[2]='world'
print(x)

# c)Write an R program to create a Data Frame
x = data.frame('R.No'=1:5,'age'=c(18,19,20,20,19),
               'name'=c('a','b','c','d','e'))
print(x)

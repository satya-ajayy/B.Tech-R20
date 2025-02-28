#Exercise 2

# a)Write a program to demonstrate the data types in R

v = TRUE
print(class(v))
v = 23.5
print(class(v))
v = 3L
print(class(v))
v = 2 + 5i
print(class(v))
v = 'Ajay'
print(class(v))

# b) Write a program to demonstrate the creating
# and naming a vector in R

remain = c(11, 12, 11, 13)
print(remain)
suits = c('spades','hearts','diamonds','clubs')
names(remain) = suits
print(remain)

# c) Write a program to demonstrate the create
# a matrix and naming matrix in R

mat_a = matrix(1:9,nrow=3,byrow=TRUE)
mat_a
rownames(mat_a) = c('a','b','c')
colnames(mat_a) = c('x','y','z')
mat_a
# or

mat_b = matrix(
  data=1:9,
  nrow=3,
  byrow=TRUE,
  dimnames = list(c('a','b','c'),c('x','y','z'))
)
mat_b



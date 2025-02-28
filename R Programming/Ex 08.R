# Exercise 8

# a)Write an R program to create a Matrix and access rows and columns using functions colnames() and rownames()

# Creation of Matrix
mat1 = matrix(1:9,nrow=3,byrow=TRUE)
vec = c(11, 13, 15, 12, 14, 16)
mat2 = matrix(vec,nrow =2, ncol =3, byrow = TRUE)  
mat2

row_names = c("row1", "row2", "row3", 'row4')
col_names = c("col1", "col2", "col3")
dim_names = list(row_names, col_names)
mat3 =  matrix(
               data = seq(1,4.3,0.3),
               nrow = 4,
               byrow = TRUE,
               dimnames = dim_names)
print(mat3)
print(mat3['row1',])

# b)Write an R Program to create a Matrix using cbind() and rbind() functions.
seq_1 = c(1,2,3)
seq_2 = c(4,5,6)
seq_3 = c(7,8,9)
m1 = rbind(seq_1,seq_2,seq_3)
m2 = cbind(seq_1,seq_2,seq_3)
m1
m2

#Exercise 3

# a)Write a program to demonstrate the Add column and
# Add a Row in Matrix in R
mat_a = matrix(1:9,nrow=3,byrow=TRUE)
mat_a
mat_b = rbind(mat_a, c(10, 11, 12))
mat_b

mat_c = cbind(mat_a, c(10, 11, 12))
mat_c

# b)Write a program to demonstrate the selection of 
# elements in Matrices in R
mat_d = matrix(1:25,ncol=5,byrow=TRUE)
mat_d
mat_d[2,3]
mat_d[2,]
mat_d[,2]

# c)Write a program to demonstrate the Performing 
# Arithmetic of Matrices
mat_e = matrix(1:4,nrow=2)
mat_e
mat_f = matrix(6:9,nrow=2)
mat_f
mat_e + mat_f
mat_e - mat_f
mat_e * mat_f
mat_e / mat_f

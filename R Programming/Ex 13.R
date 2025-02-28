# Exercise 13

require('reshape2')
require('ggplot2')

# a)Write an R program to create a scatter plot for the data frame columns.

x1 = rnorm(5)
x2 = rnorm(5)
x3 = rnorm(5)
x4 = rnorm(5)
df = data.frame(x1,x2,x3,x4)
new_df = melt(df)
ggplot(new_df,aes(variable,value))+geom_point()


# b)Write an R program to create a bar plot for the data frame columns
x1 = c(14,15,21,17,16)
x2 = c(24,21,25,18,25)
x3 = c(21,17,15,19,20)
x4 = c(19,27,24,18,20)
df = data.frame(x1,x2,x3,x4)
barplot(as.matrix(df),beside=TRUE)




# c)Write an R program to create a box plot for the data frame columns.
data = data.frame(v1=rnorm(100),v2=rnorm(100),
                  v3=rnorm(100),v4=rnorm(100))
meltData = melt(data)
boxplot(data=meltData,value~variable)

# Exercise 14

require('plotly')

# a)Write an R program to add the legend to the plot.

x = seq(1,10,0.3)
y = x^1/2
z = x^2

plot(x,y,col='blue')
lines(z,y,col='red')
legend('topleft',
       legend=c('Equation1','Equation2'),
       fill=c('blue','red'),
       cex=0.5)


# b)Write an R program to change the width, height of the plot
fig=plot_ly(x=c('Apples','Oranges','Watermelon','Pears'),
               y = c(3, 1, 2, 4),
               width = 300,
               height = 300,
               type = 'bar')
fig


# c)Write an R program to calculate mean,median,mode,sd
x = c(1,2,3,4,5,6,7,8,1,2,3,1,2,2)
x
cat('Mean :',mean(x))
cat('Median :',median(x))
cat('Mode :',names(sort(-table(x)))[1])
cat('Standard Deviation: ',sqrt(var(x)))


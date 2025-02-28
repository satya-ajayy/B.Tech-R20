# Exercise 6

# a)Write an R program to Find the Factorial of a Number

num = as.integer(readline('Enter a number : '))
fact = 1
for(i in 1:num) {
    fact = fact * i
}
print(paste("The factorial of", num ,"is",fact))


# b)Write an R program to Find the Factors of a Number
num = as.integer(readline('Enter a number : '))
for(i in 1:num) {
  if(num %% i == 0){
    print(i,)
  }
}


# c)Write an R program to Find the Fibonacci sequence Using Recursive Function

num = as.integer(readline('Enter a number : '))
fib = function(x){
  if(x == 0 || x == 1 ){
    return(x)
  } else {
    return (fib(x-1) + fib(x-2))
  }
}

for(i in 0:(num-1)){
  cat(fib(i),end = " ")
}


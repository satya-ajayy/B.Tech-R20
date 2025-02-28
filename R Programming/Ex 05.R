# Exercise 5

# a)Write an R program to take input from the user

# SINGLE VALUE
var = readline("Enter a number : ")
var = as.integer(var)
print(var)

# MULTIPLE VALUES 
{
  var1 = as.integer(readline("Enter 1st number : "))
  var2 = as.integer(readline("Enter 2nd number : "))
  var3 = as.integer(readline("Enter 3rd number : "))
}
cat(var1, var2, var3)


# b)Write an R program to Check if a Number is Odd or Even

var = as.integer(readline('Enter a number : '))
if (var %% 2 == 0){
  print('Even')
} else{
  print('Odd')
}


# c)Write an R program to check if the given number is a Prime Number

num = as.integer(readline('Enter a number : '))
flag = 0
for(i in 1:num){
    if ((num %% i) == 0) {
      flag = flag + 1
  }
}

if(flag == 2) {
  print(paste(num,'is a prime number'))
} else {
  print(paste(num,'is not a prime number'))
}


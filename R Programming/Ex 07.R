# Exercise 7

# a)Write an R program to Make a Simple Calculator
{
  a = as.integer(readline('Enter a : '))
  b = as.integer(readline('Enter b : '))
}
{
  print('1. Addition')
  print('2. Subraction')
  print('3. Multlipication')
  print('4. Divsion')
  print('5. Integer Division')
  print('6. Modulo')
}
ch = as.integer(readline('Enter choice : '))
if(ch == 1){
  print(a+b)
} else if(ch == 2){
  print(a-b)
}else if(ch == 3){
  print(a*b)
}else if(ch == 4){
  print(a/b)
}else if(ch == 5){
  print(a%/%b)
}else if(ch == 6){
  print(a%%b)
}else{
  print('choose between 1-6')
}


# b)Write an R program to Find L.C.M of two numbers
lcm <- function(x, y) {
  greater = if(x > y) x else y
  while(TRUE) {
    if((greater %% x == 0) && (greater %% y == 0)){
      lcm = greater
      break
    }
    greater = greater + 1
  }
  return(lcm)
}

a = as.integer(readline('Enter a : '))
b = as.integer(readline('Enter b : '))
print(paste('The LCM of', a,'and', b,'is', lcm(a, b)))



# c)Write an R program to create a Vector and to access elements in a Vector

# 1) Using the colon(:) operator
vec = 1:10
vec

# 2) Using the seq() function
seq_vec = seq(1,4,by=0.5)
seq_vec


# 3) Using c()
num_vec = c(10.1, 10.2, 33.2)
num_vec
char_vec = c("ajay","ram","teja","pk")
char_vec
d = 5; e = 6; f = 7
log_vec = c(d<e, d<f, e<d,e<f,f<d,f<e)
log_vec


# Accessing Vectors
char_vec = c("ajay"=22,"bhaskar"=23,"chatu"=25)
char_vec
char_vec["chatu"]
char_vec[1]
num_vec[90]
char_vec[c(1,6,2)]

# Exercise 11

# a)Write an R Program to Access and Modify Components of a Factor.

factor_data = factor(c('East','West','East','North','West',
             'South'),levels=c('East','West','South','North'))
factor_data
factor_data[c(2:5)]
factor_data[3] = 'South'
factor_data

# b)Write an R Program to create an S3 Class and S3 Objects.
x = list(name='Ajay',
         account_no=123,
         saving=1500,
         withdrawn=200)

class(x) = 'atm'
x

# c)Write an R Program for own generic function in S3 Class.
y = list(name='Ajay',
         acnt_no=15,
         savings=2000,
         withdrawn=200)
class(y) = 'bank'

print.bank <- function(obj){
  cat('Name is ',obj$name,'\n')
  cat(obj$acnt_no ,'is account number\n')
  cat(obj$savings , 'is the Savings\n')
  cat(obj$withdrawn, 'is withdrawl amount\n')
}

print.bank(y)

# Exercise 12

# a)Write an R Program to create an S4 Class and S4 Objects.
setClass('Student',slots=list(name='character',age='numeric',
                              gpa='numeric'))

s = new('Student',name='Ajay',age=19,gpa=9.4)
s


# b)Write an R Program for an own generic function in S4 Class.


setClass('Class',list(college='character',strength='numeric',
                      branch='character'))
setMethod('show','Class',function(object){
  cat('College :',object@college,'\n')
  cat('Branch :', object@branch, '\n')
  cat('Total Strength :',object@strength, '\n')
})

cl = new('Class', college='JNTUK',strength=60,branch='CSE')
cl



# c)Write an R Program to create a reference class and
# modify it's methods.
st = setRefClass('St',fields=list(name='character',age='numeric',
                                  gpa='numeric'),
                 methods=list(
                   inc_age = function(x){
                     age <<- age + x
                   },
                   dec_age = function(x){
                     age <<-age - x
                   }
                 ))

s_obj = st(name='ajay',age=19,gpa=8.5)
s_obj
s_obj$inc_age(5)
s_obj$age
s_obj$dec_age(3)
s_obj$age
s_obj$name = 'PK'
s_obj

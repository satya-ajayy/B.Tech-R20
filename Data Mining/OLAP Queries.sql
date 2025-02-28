use temp;

drop table sales;

CREATE TABLE sales (
	`Quarter` VARCHAR(3),
    `Region` VARCHAR(10),
    `Sales` INT
);

create table state_country(
	`State` Varchar(10),
	`Country` Varchar(10)
);

insert into sales values('Q1','Delhi',10);
insert into sales values('Q4','Kolkata',20);
insert into sales values('Q2','Istanbul',20);
insert into sales values('Q2','Karachi',50);
insert into sales values('Q3','Kolkata',20);
insert into sales values('Q4','Delhi',10);
insert into sales values('Q4','Istanbul',30);
insert into sales values('Q1','Karachi',40);
insert into sales values('Q1','Delhi',60);
insert into sales values('Q2','Kolkata',20);
insert into sales values('Q2','Karachi',10);
insert into sales values('Q3','Istanbul',20);
insert into sales values('Q4','Delhi',10);
insert into sales values('Q4','Karachi',40);


insert into state_country values('Delhi','India');
insert into state_country values('Kolkata','India');
insert into state_country values('Istanbul','Pakistan');
insert into state_country values('Karachi','Pakistan');
select * from sales;


-- SLICING
select `Region`,`Sales` from sales where `Quarter`='Q1';

-- DICING
select * from sales where ((`Quarter`='Q1' or `Quarter`='Q2') and 
							(`Region`='Delhi' or `Region`='Kolkata'));

-- PIVOT
select `Sales`,`Region`,`Quarter` from sales;

-- ROLLUP

select s.quarter,c.country,s.Sales  from sales s 
join state_country c where s.Region  = c.State;

select * from employee;
select Fname,Lname,Salary,Dno from employee;
select Pname,Plocation,Dnum from Project;
select  concat(Fname,' ',Lname) as `Full Name`, salary*12*0.1 as commission from employee;
select SSN,concat(Fname,' ',Lname) as `Full Name` from employee where salary > 1000;
select SSN,concat(Fname,' ',Lname) as `Full Name` from employee where salary*12  > 10000;
select Fname, Salary from employee where gender = "F";
select Dnum, Dname from departments where MGRSSN = 968574;
select Pnumber, Pname, Plocation from project where Dnum = 10;

create table dependent (
ESSN INT NOT NULL,
FOREIGN KEY (ESSN) REFERENCES employee(SSN),
DepName varchar(100) NOT NULL,
Dsex char(50) NOT NULL,
DBDate date ,
PRIMARY KEY (ESSN, DepName)
);

Drop table dependent;

INSERT INTO dependent (ESSN, DepName, Dsex, DBDate) VALUES (112233, "Hala Saied Ali", "F", 18/10/1970);
INSERT INTO dependent (ESSN, DepName, Dsex, DBDate) VALUES (223344, "Ahmed Kamel Shawki", "M", 27/3/1998);
INSERT INTO dependent (ESSN, DepName, Dsex, DBDate) VALUES (223344, "Mona Adel Mohamed", "F", 25/4/1975);
INSERT INTO dependent (ESSN, DepName, Dsex, DBDate) VALUES (321654, "Ramy Amr Omran", "M", 26/1/1990);
INSERT INTO dependent (ESSN, DepName, Dsex, DBDate) VALUES (321654, "Omar Amr Omran", "M", 30/3/1993);
INSERT INTO dependent (ESSN, DepName, Dsex, DBDate) VALUES (321654, "Sanaa Gawish", "F", 16/5/1973);
INSERT INTO dependent (ESSN, DepName, Dsex, DBDate) VALUES (512463, "Sara Edward ", "F", 15/9/2001);
INSERT INTO dependent (ESSN, DepName, Dsex, DBDate) VALUES (512463, "Nora Ghaly", "F", 22/6/1976);

select * from departments;

INSERT INTO employee (SSN, Fname, LName, Bdate, Address, gender, Salary, Superssn, Dno) VALUES (102672, "Nada", "Saeed", "1973-03-18 00:00:00.000000", "22 Sidi Bishr st Alex", "F" ,1500 , 112233, 30);
INSERT INTO employee (SSN, Fname, LName, Bdate, Address, gender, Dno) VALUES (102660, "Radwa", "Hassan", "1973-03-18 00:00:00.000000", "22 Sidi Bishr st Alex", "F" , 30);

delete from employee where SSN=102660;

INSERT INTO departments VALUES ("DEPT IT", 100, 112233, "2006-01-11 00:00:00.000000");

update departments set MGRSSN = 102672 where Dnum = 20;
update departments set MGRSSN = 968574 where Dnum = 100;



update employee set Salary = Salary*1.2 where SSN = 102672;
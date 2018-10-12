create table Student(
	ID varchar(20) primary key not null ,
	Name varchar(10) not null,
	Age int not null,
	Department varchar(30)
);
create table Course(
	CourseID varchar(15) primary key not null ,
	CourseName varchar(30) not null,
	CourseBefore varchar(15),
	foreign key(CourseBefore)references Course(CourseID)
);
create table Choose(
	ID varchar(20) not null ,
	CourseID varchar(15) not null,
	Score dec(5,2) not null,
	primary key(ID,CourseID),
	foreign key(ID)references Student(ID),
	foreign key(CourseID)references Course(CourseID)
);

insert into Student
values
('00001','张三',20,'计算机系'),
('00002','李四',19,'计算机系'),
('00003','王五',21,'计算机系');
insert into Course
values
('C1','计算机引论',null),
('C2','PASCAL语言','C1'),
('C3','数据结构','C2');
insert into Choose
values
('00001','C1',95),
('00001','C2',80),
('00001','C3',84),
('00002','C1',80),
('00002','C2',85),
('00003','C1',78),
('00003','C3',70);

select ID,Name
from Student
where Department = '计算机系';

select Student.ID 学号,Student.Name 姓名,Course.CourseName 选课名,Choose.Score 成绩
from Student,Course,Choose
where Student.ID = Choose.ID and Course.CourseID = Choose.CourseID;

select Student.ID 学号,Choose.Score 成绩
from Student,Choose
where Student.ID = Choose.ID and Choose.CourseID = 'C1' and Choose.Score < (select Score from Choose where CourseID = 'C1' and ID = (select ID from Student where Name = '张三'));

select distinct ID
from Choose
where CourseID = 'C3' and ID in (
select distinct ID
from Choose
where CourseID = 'C2' )
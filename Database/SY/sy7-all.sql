create table Exam(
	id varchar(17) primary key,
	name varchar(10),
	sex varchar(2),
	age integer,
	score numeric(6,2),
	address varchar(50),
	memo varchar(100)
);

insert into Exam
values
('A0001','赵一','男',20,580.00,'重邮宿舍12-3-5','学习委员'),
('B0002','钱二','女',19,540.00,'南福苑5-2-9','班长'),
('C0003','孙三','男',21,555.50,'学生新区21-5-15','优秀共青团员'),
('D0004','李四','男',22,480.00,'重邮宿舍8-2-22','暂无相关信息'),
('E0005','周五','女',20,495.50,'学生新区23-4-8','暂无相关信息'),
('F0006','吴六','男',19,435.00,'南福苑2-5-12','暂无相关信息');

create index IndexScore
on Exam(score asc);

create view ViewExam(ViewExam1,ViewExam2)
as select name,address from Exam;

select * from ViewExam;

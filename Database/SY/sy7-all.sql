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
('A0001','��һ','��',20,580.00,'��������12-3-5','ѧϰίԱ'),
('B0002','Ǯ��','Ů',19,540.00,'�ϸ�Է5-2-9','�೤'),
('C0003','����','��',21,555.50,'ѧ������21-5-15','���㹲����Ա'),
('D0004','����','��',22,480.00,'��������8-2-22','���������Ϣ'),
('E0005','����','Ů',20,495.50,'ѧ������23-4-8','���������Ϣ'),
('F0006','����','��',19,435.00,'�ϸ�Է2-5-12','���������Ϣ');

create index IndexScore
on Exam(score asc);

create view ViewExam(ViewExam1,ViewExam2)
as select name,address from Exam;

select * from ViewExam;

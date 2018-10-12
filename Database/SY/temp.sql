create table S(
	SNO varchar(2) primary key,
	SNAME varchar(10),
	STATUS int,
	CITY varchar(10)
);
create table P(
	PNO varchar(2) primary key,
	PNAME varchar(10),
	COLOR varchar(2),
	WEIGHT int
);
create table J(
	JNO varchar(2) primary key,
	JNAME varchar(10),
	CITY varchar(10)
);
create table SPJ(
	SNO varchar(2),
	PNO varchar(2),
	JNO varchar(2),
	QTY int,
	primary key(SNO,PNO,JNO),
	foreign key(SNO)references S(SNO),
	foreign key(PNO)references P(PNO),
	foreign key(JNO)references J(JNO),
);

insert into S
values
('S1','����',20,'���'),
('S2','ʢ��',10,'����'),
('S3','������',30,'����'),
('S4','��̩ʢ',20,'���'),
('S5','Ϊ��',30,'�Ϻ�');
insert into P
values
('P1','��ĸ','��',12),
('P2','��˨','��',17),
('P3','��˿��','��',14),
('P4','��˿��','��',14),
('P5','͹��','��',40),
('P6','����','��',30);
insert into J
values
('J1','����','����'),
('J2','һ��','����'),
('J3','���ɳ�','���'),
('J4','�촬��','���'),
('J5','������','��ɽ'),
('J6','���ߵ糧','����'),
('J7','�뵼�峧','�Ͼ�');
insert into SPJ
values
('S1','P1','J1',200),
('S1','P1','J3',100),
('S1','P1','J4',700),
('S1','P2','J2',100),
('S2','P3','J1',400),
('S2','P3','J2',200),
('S2','P3','J4',500),
('S2','P3','J5',400),
('S2','P5','J1',400),
('S2','P5','J2',100),
('S3','P1','J1',200),
('S3','P3','J1',200),
('S4','P5','J1',100),
('S4','P6','J3',300),
('S4','P6','J4',200),
('S5','P2','J4',100),
('S5','P3','J1',200),
('S5','P6','J2',200),
('S5','P6','J4',500);

select distinct SNO
from SPJ
where JNO = 'J1';
select distinct SNO
from SPJ
where JNO = 'J1' and PNO = 'P1';
select SNO
from SPJ,P
where SPJ.PNO = P.PNO and P.COLOR = '��' and SPJ.JNO = 'J1';
select distinct JNO
from SPJ,S,P
where SPJ.SNO = S.SNO and SPJ.PNO = P.PNO and S.CITY != '���' and P.COLOR != '��';
select distinct JNO
from SPJ x
where NOT EXISTS(select * from SPJ y where y.SNO = 'S1' AND NOT EXISTS(select * from SPJ z where z.PNO = y.PNO AND z.JNO = x.JNO));
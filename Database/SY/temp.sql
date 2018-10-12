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
('S1','精益',20,'天津'),
('S2','盛锡',10,'北京'),
('S3','东方红',30,'北京'),
('S4','丰泰盛',20,'天津'),
('S5','为民',30,'上海');
insert into P
values
('P1','螺母','红',12),
('P2','螺栓','绿',17),
('P3','螺丝刀','蓝',14),
('P4','螺丝刀','红',14),
('P5','凸轮','蓝',40),
('P6','齿轮','红',30);
insert into J
values
('J1','三建','北京'),
('J2','一汽','长春'),
('J3','弹簧厂','天津'),
('J4','造船厂','天津'),
('J5','机车厂','唐山'),
('J6','无线电厂','常州'),
('J7','半导体厂','南京');
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
where SPJ.PNO = P.PNO and P.COLOR = '红' and SPJ.JNO = 'J1';
select distinct JNO
from SPJ,S,P
where SPJ.SNO = S.SNO and SPJ.PNO = P.PNO and S.CITY != '天津' and P.COLOR != '红';
select distinct JNO
from SPJ x
where NOT EXISTS(select * from SPJ y where y.SNO = 'S1' AND NOT EXISTS(select * from SPJ z where z.PNO = y.PNO AND z.JNO = x.JNO));
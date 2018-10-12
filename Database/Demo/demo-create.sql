create table Student(
	Sno varchar(10),
	Sname varchar(10),
	Ssex varchar(4),
	Sage integer,
	Sdept varchar(5)
);
create table Course(
	Cno integer,
	Cname varchar(20),
	Cpno integer,
	Ccredit int
);
create table SC(
	Sno varchar(10),
	Cno integer,
	Grade int
);

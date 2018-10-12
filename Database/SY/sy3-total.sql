create table aa(
	Aa1 varchar(20),
	Aa2 int,
	Aa3 dec(10,2)
);
create table bb(
	Bb1 varchar(30),
	Bb2 int,
	Bb3 dec(6,2)
);

drop table aa;

alter table bb
add Bb4 varchar(20);

create view Viewbb(Viewbb1,Viewbb2)
as select Bb1,Bb4 from bb;

drop view Viewbb;

create unique index Indexbb
on Bb(Bb3 asc);

drop index Indexbb on bb;
create table cc(
	Cc1 varchar(20),
	Cc2 int,
	Cc3 dec(10,2),
	Cc4 varchar(60)
);

insert into cc
values
('赵一',20,580.00,'重邮宿舍12-3-5'),
('钱二',19,540.00,'南福苑5-2-9'),
('孙三',21,555.50,'学生新区21-5-15'),
('李四',22,480.00,'重邮宿舍8-2-22'),
('周五',20,495.50,'学生新区23-4-8'),
('吴六',19,435.00,'南福苑2-5-12');

select * from cc;

update cc
set Cc3 = Cc3 + 5
where Cc2 <= 20;

delete from cc
where Cc2 >= 20 or Cc3 >= 500;

delete from cc;
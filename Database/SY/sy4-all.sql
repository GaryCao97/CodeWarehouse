create table cc(
	Cc1 varchar(20),
	Cc2 int,
	Cc3 dec(10,2),
	Cc4 varchar(60)
);

insert into cc
values
('��һ',20,580.00,'��������12-3-5'),
('Ǯ��',19,540.00,'�ϸ�Է5-2-9'),
('����',21,555.50,'ѧ������21-5-15'),
('����',22,480.00,'��������8-2-22'),
('����',20,495.50,'ѧ������23-4-8'),
('����',19,435.00,'�ϸ�Է2-5-12');

select * from cc;

update cc
set Cc3 = Cc3 + 5
where Cc2 <= 20;

delete from cc
where Cc2 >= 20 or Cc3 >= 500;

delete from cc;
/*==============================================================*/
/* DBMS name:      Microsoft SQL Server 2014                    */
/* Created on:     2017/12/27 22:09:16                          */
/*==============================================================*/


if exists (select 1
            from  sysobjects
           where  id = object_id('����')
            and   type = 'U')
   drop table ����
go

if exists (select 1
            from  sysobjects
           where  id = object_id('����')
            and   type = 'U')
   drop table ����
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('���ĵ�����')
            and   name  = '���ĵ�����2_FK'
            and   indid > 0
            and   indid < 255)
   drop index ���ĵ�����.���ĵ�����2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('���ĵ�����')
            and   name  = '���ĵ�����_FK'
            and   indid > 0
            and   indid < 255)
   drop index ���ĵ�����.���ĵ�����_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('���ĵ�����')
            and   type = 'U')
   drop table ���ĵ�����
go

/*==============================================================*/
/* Table: ����                                                    */
/*==============================================================*/
create table ���� (
   ���֤��                 char(20)             not null,
   ��������                 char(10)             not null,
   ��λ                   char(256)            null,
   ��ַ                   char(256)            null,
   constraint PK_���� primary key (���֤��)
)
go

/*==============================================================*/
/* Table: ����                                                    */
/*==============================================================*/
create table ���� (
   ���ĺ�                  char(20)             not null,
   ������Ŀ                 char(30)             not null,
   �ڿ�����                 char(30)             null,
   �ڿ����                 int                  null,
   �ڿ���                  char(20)             null,
   constraint PK_���� primary key (���ĺ�)
)
go

/*==============================================================*/
/* Table: ���ĵ�����                                                 */
/*==============================================================*/
create table ���ĵ����� (
   ���ĺ�                  char(20)             not null,
   ���֤��                 char(20)             not null,
   ����˳���                int                  not null,
   constraint PK_���ĵ����� primary key (���ĺ�, ���֤��)
)
go

/*==============================================================*/
/* Index: ���ĵ�����_FK                                              */
/*==============================================================*/




create nonclustered index ���ĵ�����_FK on ���ĵ����� (���ĺ� ASC)
go

/*==============================================================*/
/* Index: ���ĵ�����2_FK                                             */
/*==============================================================*/




create nonclustered index ���ĵ�����2_FK on ���ĵ����� (���֤�� ASC)
go


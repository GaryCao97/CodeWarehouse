/*==============================================================*/
/* DBMS name:      Microsoft SQL Server 2014                    */
/* Created on:     2017/12/27 22:08:48                          */
/*==============================================================*/


if exists (select 1
            from  sysobjects
           where  id = object_id('��Ʒ')
            and   type = 'U')
   drop table ��Ʒ
go

if exists (select 1
            from  sysobjects
           where  id = object_id('����')
            and   type = 'U')
   drop table ����
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('����')
            and   name  = '����2_FK'
            and   indid > 0
            and   indid < 255)
   drop index ����.����2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('����')
            and   name  = '����_FK'
            and   indid > 0
            and   indid < 255)
   drop index ����.����_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('����')
            and   type = 'U')
   drop table ����
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('ְ��')
            and   name  = 'Ƹ��_FK'
            and   indid > 0
            and   indid < 255)
   drop index ְ��.Ƹ��_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('ְ��')
            and   type = 'U')
   drop table ְ��
go

/*==============================================================*/
/* Table: ��Ʒ                                                    */
/*==============================================================*/
create table ��Ʒ (
   ��Ʒ���                 char(20)             not null,
   ��Ʒ��                  char(20)             not null,
   ���                   char(256)            not null,
   constraint PK_��Ʒ primary key (��Ʒ���)
)
go

/*==============================================================*/
/* Table: ����                                                    */
/*==============================================================*/
create table ���� (
   �������                 char(20)             not null,
   ����                   char(30)             not null,
   ��ַ                   char(256)            not null,
   constraint PK_���� primary key (�������)
)
go

/*==============================================================*/
/* Table: ����                                                    */
/*==============================================================*/
create table ���� (
   ��Ʒ���                 char(20)             not null,
   �������                 char(20)             not null,
   �ƻ�����                 bigint               not null 
      constraint CKC_�ƻ�����_���� check (�ƻ����� >= 300),
   constraint PK_���� primary key (��Ʒ���, �������)
)
go

/*==============================================================*/
/* Index: ����_FK                                                 */
/*==============================================================*/




create nonclustered index ����_FK on ���� (��Ʒ��� ASC)
go

/*==============================================================*/
/* Index: ����2_FK                                                */
/*==============================================================*/




create nonclustered index ����2_FK on ���� (������� ASC)
go

/*==============================================================*/
/* Table: ְ��                                                    */
/*==============================================================*/
create table ְ�� (
   ְ����                  char(20)             not null,
   �������                 char(20)             not null,
   ְ������                 char(20)             not null,
   �����ȼ�                 char(256)            not null,
   Ƹ��                   char(256)            null,
   ����                   float                null,
   constraint PK_ְ�� primary key (ְ����)
)
go

/*==============================================================*/
/* Index: Ƹ��_FK                                                 */
/*==============================================================*/




create nonclustered index Ƹ��_FK on ְ�� (������� ASC)
go


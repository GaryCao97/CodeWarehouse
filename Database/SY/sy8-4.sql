/*==============================================================*/
/* DBMS name:      Microsoft SQL Server 2014                    */
/* Created on:     2017/12/27 22:03:48                          */
/*==============================================================*/


if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('�μ���Ŀ') and o.name = 'FK_�μ���Ŀ_�μ���Ŀ_������Ա')
alter table �μ���Ŀ
   drop constraint FK_�μ���Ŀ_�μ���Ŀ_������Ա
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('�μ���Ŀ') and o.name = 'FK_�μ���Ŀ_�μ���Ŀ2_������Ŀ')
alter table �μ���Ŀ
   drop constraint FK_�μ���Ŀ_�μ���Ŀ2_������Ŀ
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('������Ա') and o.name = 'FK_������Ա_����_�о���')
alter table ������Ա
   drop constraint FK_������Ա_����_�о���
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('������Ŀ') and o.name = 'FK_������Ŀ_ӵ��_�о���')
alter table ������Ŀ
   drop constraint FK_������Ŀ_ӵ��_�о���
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('�μ���Ŀ')
            and   name  = '�μ���Ŀ2_FK'
            and   indid > 0
            and   indid < 255)
   drop index �μ���Ŀ.�μ���Ŀ2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('�μ���Ŀ')
            and   name  = '�μ���Ŀ_FK'
            and   indid > 0
            and   indid < 255)
   drop index �μ���Ŀ.�μ���Ŀ_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('�μ���Ŀ')
            and   type = 'U')
   drop table �μ���Ŀ
go

if exists (select 1
            from  sysobjects
           where  id = object_id('�о���')
            and   type = 'U')
   drop table �о���
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('������Ա')
            and   name  = '����_FK'
            and   indid > 0
            and   indid < 255)
   drop index ������Ա.����_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('������Ա')
            and   type = 'U')
   drop table ������Ա
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('������Ŀ')
            and   name  = 'ӵ��_FK'
            and   indid > 0
            and   indid < 255)
   drop index ������Ŀ.ӵ��_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('������Ŀ')
            and   type = 'U')
   drop table ������Ŀ
go

/*==============================================================*/
/* Table: �μ���Ŀ                                                  */
/*==============================================================*/
create table �μ���Ŀ (
   ְ����                  char(20)             not null,
   ��Ŀ��                  char(20)             not null,
   ������                  char(20)             null,
   constraint PK_�μ���Ŀ primary key (ְ����, ��Ŀ��)
)
go

/*==============================================================*/
/* Index: �μ���Ŀ_FK                                               */
/*==============================================================*/




create nonclustered index �μ���Ŀ_FK on �μ���Ŀ (ְ���� ASC)
go

/*==============================================================*/
/* Index: �μ���Ŀ2_FK                                              */
/*==============================================================*/




create nonclustered index �μ���Ŀ2_FK on �μ���Ŀ (��Ŀ�� ASC)
go

/*==============================================================*/
/* Table: �о���                                                   */
/*==============================================================*/
create table �о��� (
   ���                   char(20)             not null,
   ����                   char(20)             not null,
   ��ַ                   char(20)             not null,
   constraint PK_�о��� primary key (���)
)
go

/*==============================================================*/
/* Table: ������Ա                                                  */
/*==============================================================*/
create table ������Ա (
   ְ����                  char(20)             not null,
   ���                   char(20)             not null,
   ����                   char(20)             not null,
   �Ա�                   char(20)             not null,
   ����                   char(20)             not null,
   ְ��                   char(20)             not null,
   constraint PK_������Ա primary key (ְ����)
)
go

/*==============================================================*/
/* Index: ����_FK                                                 */
/*==============================================================*/




create nonclustered index ����_FK on ������Ա (��� ASC)
go

/*==============================================================*/
/* Table: ������Ŀ                                                  */
/*==============================================================*/
create table ������Ŀ (
   ��Ŀ��                  char(20)             not null,
   ���                   char(20)             not null,
   ��Ŀ��                  char(20)             not null,
   ����                   char(20)             not null,
   constraint PK_������Ŀ primary key (��Ŀ��)
)
go

/*==============================================================*/
/* Index: ӵ��_FK                                                 */
/*==============================================================*/




create nonclustered index ӵ��_FK on ������Ŀ (��� ASC)
go

alter table �μ���Ŀ
   add constraint FK_�μ���Ŀ_�μ���Ŀ_������Ա foreign key (ְ����)
      references ������Ա (ְ����)
go

alter table �μ���Ŀ
   add constraint FK_�μ���Ŀ_�μ���Ŀ2_������Ŀ foreign key (��Ŀ��)
      references ������Ŀ (��Ŀ��)
go

alter table ������Ա
   add constraint FK_������Ա_����_�о��� foreign key (���)
      references �о��� (���)
go

alter table ������Ŀ
   add constraint FK_������Ŀ_ӵ��_�о��� foreign key (���)
      references �о��� (���)
go


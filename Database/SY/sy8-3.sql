/*==============================================================*/
/* DBMS name:      Microsoft SQL Server 2014                    */
/* Created on:     2017/12/27 22:04:56                          */
/*==============================================================*/


if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('�μ�') and o.name = 'FK_�μ�_�μ�_������Ŀ')
alter table �μ�
   drop constraint FK_�μ�_�μ�_������Ŀ
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('�μ�') and o.name = 'FK_�μ�_�μ�2_�˶�Ա')
alter table �μ�
   drop constraint FK_�μ�_�μ�2_�˶�Ա
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('������Ŀ') and o.name = 'FK_������Ŀ_����_�������')
alter table ������Ŀ
   drop constraint FK_������Ŀ_����_�������
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('�˶�Ա') and o.name = 'FK_�˶�Ա_���_�Ŷ�')
alter table �˶�Ա
   drop constraint FK_�˶�Ա_���_�Ŷ�
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('�μ�')
            and   name  = '�μ�2_FK'
            and   indid > 0
            and   indid < 255)
   drop index �μ�.�μ�2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('�μ�')
            and   name  = '�μ�_FK'
            and   indid > 0
            and   indid < 255)
   drop index �μ�.�μ�_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('�μ�')
            and   type = 'U')
   drop table �μ�
go

if exists (select 1
            from  sysobjects
           where  id = object_id('�Ŷ�')
            and   type = 'U')
   drop table �Ŷ�
go

if exists (select 1
            from  sysobjects
           where  id = object_id('�������')
            and   type = 'U')
   drop table �������
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('������Ŀ')
            and   name  = '����_FK'
            and   indid > 0
            and   indid < 255)
   drop index ������Ŀ.����_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('������Ŀ')
            and   type = 'U')
   drop table ������Ŀ
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('�˶�Ա')
            and   name  = '���_FK'
            and   indid > 0
            and   indid < 255)
   drop index �˶�Ա.���_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('�˶�Ա')
            and   type = 'U')
   drop table �˶�Ա
go

/*==============================================================*/
/* Table: �μ�                                                    */
/*==============================================================*/
create table �μ� (
   ��Ŀ���                 char(20)             not null,
   ���                   char(20)             not null,
   �ɼ�                   int                  null 
      constraint CKC_�ɼ�_�μ� check (�ɼ� is null or (�ɼ� between 0 and 7)),
   constraint PK_�μ� primary key (��Ŀ���, ���)
)
go

/*==============================================================*/
/* Index: �μ�_FK                                                 */
/*==============================================================*/




create nonclustered index �μ�_FK on �μ� (��Ŀ��� ASC)
go

/*==============================================================*/
/* Index: �μ�2_FK                                                */
/*==============================================================*/




create nonclustered index �μ�2_FK on �μ� (��� ASC)
go

/*==============================================================*/
/* Table: �Ŷ�                                                    */
/*==============================================================*/
create table �Ŷ� (
   �ű��                  char(20)             not null,
   ������                  char(20)             not null,
   ���                   char(20)             not null,
   constraint PK_�Ŷ� primary key (�ű��)
)
go

/*==============================================================*/
/* Table: �������                                                  */
/*==============================================================*/
create table ������� (
   �����                 char(20)             not null,
   �������                 char(20)             not null,
   ����                   char(20)             not null,
   constraint PK_������� primary key (�����)
)
go

/*==============================================================*/
/* Table: ������Ŀ                                                  */
/*==============================================================*/
create table ������Ŀ (
   ��Ŀ���                 char(20)             not null,
   �����                 char(20)             not null,
   ��Ŀ����                 char(20)             not null,
   ����ʱ��                 char(20)             not null,
   ����                   char(20)             not null,
   constraint PK_������Ŀ primary key (��Ŀ���)
)
go

/*==============================================================*/
/* Index: ����_FK                                                 */
/*==============================================================*/




create nonclustered index ����_FK on ������Ŀ (����� ASC)
go

/*==============================================================*/
/* Table: �˶�Ա                                                   */
/*==============================================================*/
create table �˶�Ա (
   ���                   char(20)             not null,
   �ű��                  char(20)             not null,
   ����                   char(20)             not null,
   ����                   char(20)             not null,
   �Ա�                   char(20)             not null,
   constraint PK_�˶�Ա primary key (���)
)
go

/*==============================================================*/
/* Index: ���_FK                                                 */
/*==============================================================*/




create nonclustered index ���_FK on �˶�Ա (�ű�� ASC)
go

alter table �μ�
   add constraint FK_�μ�_�μ�_������Ŀ foreign key (��Ŀ���)
      references ������Ŀ (��Ŀ���)
go

alter table �μ�
   add constraint FK_�μ�_�μ�2_�˶�Ա foreign key (���)
      references �˶�Ա (���)
go

alter table ������Ŀ
   add constraint FK_������Ŀ_����_������� foreign key (�����)
      references ������� (�����)
go

alter table �˶�Ա
   add constraint FK_�˶�Ա_���_�Ŷ� foreign key (�ű��)
      references �Ŷ� (�ű��)
go


/*==============================================================*/
/* DBMS name:      Microsoft SQL Server 2014                    */
/* Created on:     2017/12/27 22:02:45                          */
/*==============================================================*/


if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('��Ʒ') and o.name = 'FK_��Ʒ_������Ʒ_����')
alter table ��Ʒ
   drop constraint FK_��Ʒ_������Ʒ_����
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('�ֿ�') and o.name = 'FK_�ֿ�_ӵ�вֿ�_����')
alter table �ֿ�
   drop constraint FK_�ֿ�_ӵ�вֿ�_����
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('�����Ʒ') and o.name = 'FK_�����Ʒ_�����Ʒ_��Ʒ')
alter table �����Ʒ
   drop constraint FK_�����Ʒ_�����Ʒ_��Ʒ
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('�����Ʒ') and o.name = 'FK_�����Ʒ_�����Ʒ2_�ֿ�')
alter table �����Ʒ
   drop constraint FK_�����Ʒ_�����Ʒ2_�ֿ�
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('�������') and o.name = 'FK_�������_�������_���')
alter table �������
   drop constraint FK_�������_�������_���
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('�������') and o.name = 'FK_�������_�������2_�ֿ�')
alter table �������
   drop constraint FK_�������_�������2_�ֿ�
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('����') and o.name = 'FK_����_ӵ�й���_����')
alter table ����
   drop constraint FK_����_ӵ�й���_����
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('�������') and o.name = 'FK_�������_�������_����')
alter table �������
   drop constraint FK_�������_�������_����
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('�������') and o.name = 'FK_�������_�������2_���')
alter table �������
   drop constraint FK_�������_�������2_���
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('�����װ��') and o.name = 'FK_�����װ��_�����װ��_���')
alter table �����װ��
   drop constraint FK_�����װ��_�����װ��_���
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('�����װ��') and o.name = 'FK_�����װ��_�����װ��2_��Ʒ')
alter table �����װ��
   drop constraint FK_�����װ��_�����װ��2_��Ʒ
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('����') and o.name = 'FK_����_ӵ�г���_����')
alter table ����
   drop constraint FK_����_ӵ�г���_����
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('��Ʒ')
            and   name  = '������Ʒ_FK'
            and   indid > 0
            and   indid < 255)
   drop index ��Ʒ.������Ʒ_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('��Ʒ')
            and   type = 'U')
   drop table ��Ʒ
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('�ֿ�')
            and   name  = 'ӵ�вֿ�_FK'
            and   indid > 0
            and   indid < 255)
   drop index �ֿ�.ӵ�вֿ�_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('�ֿ�')
            and   type = 'U')
   drop table �ֿ�
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('�����Ʒ')
            and   name  = '�����Ʒ2_FK'
            and   indid > 0
            and   indid < 255)
   drop index �����Ʒ.�����Ʒ2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('�����Ʒ')
            and   name  = '�����Ʒ_FK'
            and   indid > 0
            and   indid < 255)
   drop index �����Ʒ.�����Ʒ_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('�����Ʒ')
            and   type = 'U')
   drop table �����Ʒ
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('�������')
            and   name  = '�������2_FK'
            and   indid > 0
            and   indid < 255)
   drop index �������.�������2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('�������')
            and   name  = '�������_FK'
            and   indid > 0
            and   indid < 255)
   drop index �������.�������_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('�������')
            and   type = 'U')
   drop table �������
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('����')
            and   name  = 'ӵ�й���_FK'
            and   indid > 0
            and   indid < 255)
   drop index ����.ӵ�й���_FK
go

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
           where  id    = object_id('�������')
            and   name  = '�������2_FK'
            and   indid > 0
            and   indid < 255)
   drop index �������.�������2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('�������')
            and   name  = '�������_FK'
            and   indid > 0
            and   indid < 255)
   drop index �������.�������_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('�������')
            and   type = 'U')
   drop table �������
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('�����װ��')
            and   name  = '�����װ��2_FK'
            and   indid > 0
            and   indid < 255)
   drop index �����װ��.�����װ��2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('�����װ��')
            and   name  = '�����װ��_FK'
            and   indid > 0
            and   indid < 255)
   drop index �����װ��.�����װ��_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('�����װ��')
            and   type = 'U')
   drop table �����װ��
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('����')
            and   name  = 'ӵ�г���_FK'
            and   indid > 0
            and   indid < 255)
   drop index ����.ӵ�г���_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('����')
            and   type = 'U')
   drop table ����
go

if exists (select 1
            from  sysobjects
           where  id = object_id('���')
            and   type = 'U')
   drop table ���
go

/*==============================================================*/
/* Table: ��Ʒ                                                    */
/*==============================================================*/
create table ��Ʒ (
   ��Ʒ��                  char(20)             not null,
   �����                  char(20)             null,
   �۸�2                  float                not null,
   constraint PK_��Ʒ primary key (��Ʒ��)
)
go

/*==============================================================*/
/* Index: ������Ʒ_FK                                               */
/*==============================================================*/




create nonclustered index ������Ʒ_FK on ��Ʒ (����� ASC)
go

/*==============================================================*/
/* Table: �ֿ�                                                    */
/*==============================================================*/
create table �ֿ� (
   �ֿ��                  char(20)             not null,
   ����                   char(20)             null,
   �ֿ���������               char(20)             not null,
   �绰2                  char(20)             not null,
   constraint PK_�ֿ� primary key (�ֿ��)
)
go

/*==============================================================*/
/* Index: ӵ�вֿ�_FK                                               */
/*==============================================================*/




create nonclustered index ӵ�вֿ�_FK on �ֿ� (���� ASC)
go

/*==============================================================*/
/* Table: �����Ʒ                                                  */
/*==============================================================*/
create table �����Ʒ (
   ��Ʒ��                  char(20)             not null,
   �ֿ��                  char(20)             not null,
   constraint PK_�����Ʒ primary key (��Ʒ��, �ֿ��)
)
go

/*==============================================================*/
/* Index: �����Ʒ_FK                                               */
/*==============================================================*/




create nonclustered index �����Ʒ_FK on �����Ʒ (��Ʒ�� ASC)
go

/*==============================================================*/
/* Index: �����Ʒ2_FK                                              */
/*==============================================================*/




create nonclustered index �����Ʒ2_FK on �����Ʒ (�ֿ�� ASC)
go

/*==============================================================*/
/* Table: �������                                                  */
/*==============================================================*/
create table ������� (
   �����                  char(20)             not null,
   �ֿ��                  char(20)             not null,
   constraint PK_������� primary key (�����, �ֿ��)
)
go

/*==============================================================*/
/* Index: �������_FK                                               */
/*==============================================================*/




create nonclustered index �������_FK on ������� (����� ASC)
go

/*==============================================================*/
/* Index: �������2_FK                                              */
/*==============================================================*/




create nonclustered index �������2_FK on ������� (�ֿ�� ASC)
go

/*==============================================================*/
/* Table: ����                                                    */
/*==============================================================*/
create table ���� (
   ְ����                  char(20)             not null,
   �����                  char(20)             null,
   ����                   char(20)             not null,
   ����                   int                  not null,
   �Ա�                   char(2)              not null,
   ����                   char(20)             not null,
   constraint PK_���� primary key (ְ����)
)
go

/*==============================================================*/
/* Index: ӵ�й���_FK                                               */
/*==============================================================*/




create nonclustered index ӵ�й���_FK on ���� (����� ASC)
go

/*==============================================================*/
/* Table: ����                                                    */
/*==============================================================*/
create table ���� (
   ����                   char(20)             not null,
   ������                  char(20)             not null,
   constraint PK_���� primary key (����)
)
go

/*==============================================================*/
/* Table: �������                                                  */
/*==============================================================*/
create table ������� (
   �����                  char(20)             not null,
   �����                  char(20)             not null,
   constraint PK_������� primary key (�����, �����)
)
go

/*==============================================================*/
/* Index: �������_FK                                               */
/*==============================================================*/




create nonclustered index �������_FK on ������� (����� ASC)
go

/*==============================================================*/
/* Index: �������2_FK                                              */
/*==============================================================*/




create nonclustered index �������2_FK on ������� (����� ASC)
go

/*==============================================================*/
/* Table: �����װ��                                                 */
/*==============================================================*/
create table �����װ�� (
   �����                  char(20)             not null,
   ��Ʒ��                  char(20)             not null,
   constraint PK_�����װ�� primary key (�����, ��Ʒ��)
)
go

/*==============================================================*/
/* Index: �����װ��_FK                                              */
/*==============================================================*/




create nonclustered index �����װ��_FK on �����װ�� (����� ASC)
go

/*==============================================================*/
/* Index: �����װ��2_FK                                             */
/*==============================================================*/




create nonclustered index �����װ��2_FK on �����װ�� (��Ʒ�� ASC)
go

/*==============================================================*/
/* Table: ����                                                    */
/*==============================================================*/
create table ���� (
   �����                  char(20)             not null,
   ����                   char(20)             null,
   ������������               char(20)             not null,
   ��ַ                   char(20)             not null,
   �绰1                  char(20)             not null,
   constraint PK_���� primary key (�����)
)
go

/*==============================================================*/
/* Index: ӵ�г���_FK                                               */
/*==============================================================*/




create nonclustered index ӵ�г���_FK on ���� (���� ASC)
go

/*==============================================================*/
/* Table: ���                                                    */
/*==============================================================*/
create table ��� (
   �����                  char(20)             not null,
   ����                   float                null,
   �۸�1                  float                null,
   constraint PK_��� primary key (�����)
)
go

alter table ��Ʒ
   add constraint FK_��Ʒ_������Ʒ_���� foreign key (�����)
      references ���� (�����)
go

alter table �ֿ�
   add constraint FK_�ֿ�_ӵ�вֿ�_���� foreign key (����)
      references ���� (����)
go

alter table �����Ʒ
   add constraint FK_�����Ʒ_�����Ʒ_��Ʒ foreign key (��Ʒ��)
      references ��Ʒ (��Ʒ��)
go

alter table �����Ʒ
   add constraint FK_�����Ʒ_�����Ʒ2_�ֿ� foreign key (�ֿ��)
      references �ֿ� (�ֿ��)
go

alter table �������
   add constraint FK_�������_�������_��� foreign key (�����)
      references ��� (�����)
go

alter table �������
   add constraint FK_�������_�������2_�ֿ� foreign key (�ֿ��)
      references �ֿ� (�ֿ��)
go

alter table ����
   add constraint FK_����_ӵ�й���_���� foreign key (�����)
      references ���� (�����)
go

alter table �������
   add constraint FK_�������_�������_���� foreign key (�����)
      references ���� (�����)
go

alter table �������
   add constraint FK_�������_�������2_��� foreign key (�����)
      references ��� (�����)
go

alter table �����װ��
   add constraint FK_�����װ��_�����װ��_��� foreign key (�����)
      references ��� (�����)
go

alter table �����װ��
   add constraint FK_�����װ��_�����װ��2_��Ʒ foreign key (��Ʒ��)
      references ��Ʒ (��Ʒ��)
go

alter table ����
   add constraint FK_����_ӵ�г���_���� foreign key (����)
      references ���� (����)
go


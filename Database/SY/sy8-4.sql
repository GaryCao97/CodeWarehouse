/*==============================================================*/
/* DBMS name:      Microsoft SQL Server 2014                    */
/* Created on:     2017/12/27 22:03:48                          */
/*==============================================================*/


if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('参加项目') and o.name = 'FK_参加项目_参加项目_科研人员')
alter table 参加项目
   drop constraint FK_参加项目_参加项目_科研人员
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('参加项目') and o.name = 'FK_参加项目_参加项目2_科研项目')
alter table 参加项目
   drop constraint FK_参加项目_参加项目2_科研项目
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('科研人员') and o.name = 'FK_科研人员_属于_研究所')
alter table 科研人员
   drop constraint FK_科研人员_属于_研究所
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('科研项目') and o.name = 'FK_科研项目_拥有_研究所')
alter table 科研项目
   drop constraint FK_科研项目_拥有_研究所
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('参加项目')
            and   name  = '参加项目2_FK'
            and   indid > 0
            and   indid < 255)
   drop index 参加项目.参加项目2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('参加项目')
            and   name  = '参加项目_FK'
            and   indid > 0
            and   indid < 255)
   drop index 参加项目.参加项目_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('参加项目')
            and   type = 'U')
   drop table 参加项目
go

if exists (select 1
            from  sysobjects
           where  id = object_id('研究所')
            and   type = 'U')
   drop table 研究所
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('科研人员')
            and   name  = '属于_FK'
            and   indid > 0
            and   indid < 255)
   drop index 科研人员.属于_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('科研人员')
            and   type = 'U')
   drop table 科研人员
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('科研项目')
            and   name  = '拥有_FK'
            and   indid > 0
            and   indid < 255)
   drop index 科研项目.拥有_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('科研项目')
            and   type = 'U')
   drop table 科研项目
go

/*==============================================================*/
/* Table: 参加项目                                                  */
/*==============================================================*/
create table 参加项目 (
   职工号                  char(20)             not null,
   项目号                  char(20)             not null,
   工作量                  char(20)             null,
   constraint PK_参加项目 primary key (职工号, 项目号)
)
go

/*==============================================================*/
/* Index: 参加项目_FK                                               */
/*==============================================================*/




create nonclustered index 参加项目_FK on 参加项目 (职工号 ASC)
go

/*==============================================================*/
/* Index: 参加项目2_FK                                              */
/*==============================================================*/




create nonclustered index 参加项目2_FK on 参加项目 (项目号 ASC)
go

/*==============================================================*/
/* Table: 研究所                                                   */
/*==============================================================*/
create table 研究所 (
   编号                   char(20)             not null,
   名称                   char(20)             not null,
   地址                   char(20)             not null,
   constraint PK_研究所 primary key (编号)
)
go

/*==============================================================*/
/* Table: 科研人员                                                  */
/*==============================================================*/
create table 科研人员 (
   职工号                  char(20)             not null,
   编号                   char(20)             not null,
   姓名                   char(20)             not null,
   性别                   char(20)             not null,
   年龄                   char(20)             not null,
   职称                   char(20)             not null,
   constraint PK_科研人员 primary key (职工号)
)
go

/*==============================================================*/
/* Index: 属于_FK                                                 */
/*==============================================================*/




create nonclustered index 属于_FK on 科研人员 (编号 ASC)
go

/*==============================================================*/
/* Table: 科研项目                                                  */
/*==============================================================*/
create table 科研项目 (
   项目号                  char(20)             not null,
   编号                   char(20)             not null,
   项目名                  char(20)             not null,
   经费                   char(20)             not null,
   constraint PK_科研项目 primary key (项目号)
)
go

/*==============================================================*/
/* Index: 拥有_FK                                                 */
/*==============================================================*/




create nonclustered index 拥有_FK on 科研项目 (编号 ASC)
go

alter table 参加项目
   add constraint FK_参加项目_参加项目_科研人员 foreign key (职工号)
      references 科研人员 (职工号)
go

alter table 参加项目
   add constraint FK_参加项目_参加项目2_科研项目 foreign key (项目号)
      references 科研项目 (项目号)
go

alter table 科研人员
   add constraint FK_科研人员_属于_研究所 foreign key (编号)
      references 研究所 (编号)
go

alter table 科研项目
   add constraint FK_科研项目_拥有_研究所 foreign key (编号)
      references 研究所 (编号)
go


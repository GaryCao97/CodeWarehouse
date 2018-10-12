/*==============================================================*/
/* DBMS name:      Microsoft SQL Server 2014                    */
/* Created on:     2017/12/27 22:04:56                          */
/*==============================================================*/


if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('参加') and o.name = 'FK_参加_参加_比赛项目')
alter table 参加
   drop constraint FK_参加_参加_比赛项目
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('参加') and o.name = 'FK_参加_参加2_运动员')
alter table 参加
   drop constraint FK_参加_参加2_运动员
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('比赛项目') and o.name = 'FK_比赛项目_包含_比赛类别')
alter table 比赛项目
   drop constraint FK_比赛项目_包含_比赛类别
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('运动员') and o.name = 'FK_运动员_组成_团队')
alter table 运动员
   drop constraint FK_运动员_组成_团队
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('参加')
            and   name  = '参加2_FK'
            and   indid > 0
            and   indid < 255)
   drop index 参加.参加2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('参加')
            and   name  = '参加_FK'
            and   indid > 0
            and   indid < 255)
   drop index 参加.参加_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('参加')
            and   type = 'U')
   drop table 参加
go

if exists (select 1
            from  sysobjects
           where  id = object_id('团队')
            and   type = 'U')
   drop table 团队
go

if exists (select 1
            from  sysobjects
           where  id = object_id('比赛类别')
            and   type = 'U')
   drop table 比赛类别
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('比赛项目')
            and   name  = '包含_FK'
            and   indid > 0
            and   indid < 255)
   drop index 比赛项目.包含_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('比赛项目')
            and   type = 'U')
   drop table 比赛项目
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('运动员')
            and   name  = '组成_FK'
            and   indid > 0
            and   indid < 255)
   drop index 运动员.组成_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('运动员')
            and   type = 'U')
   drop table 运动员
go

/*==============================================================*/
/* Table: 参加                                                    */
/*==============================================================*/
create table 参加 (
   项目编号                 char(20)             not null,
   编号                   char(20)             not null,
   成绩                   int                  null 
      constraint CKC_成绩_参加 check (成绩 is null or (成绩 between 0 and 7)),
   constraint PK_参加 primary key (项目编号, 编号)
)
go

/*==============================================================*/
/* Index: 参加_FK                                                 */
/*==============================================================*/




create nonclustered index 参加_FK on 参加 (项目编号 ASC)
go

/*==============================================================*/
/* Index: 参加2_FK                                                */
/*==============================================================*/




create nonclustered index 参加2_FK on 参加 (编号 ASC)
go

/*==============================================================*/
/* Table: 团队                                                    */
/*==============================================================*/
create table 团队 (
   团编号                  char(20)             not null,
   团名称                  char(20)             not null,
   领队                   char(20)             not null,
   constraint PK_团队 primary key (团编号)
)
go

/*==============================================================*/
/* Table: 比赛类别                                                  */
/*==============================================================*/
create table 比赛类别 (
   类别编号                 char(20)             not null,
   类别名称                 char(20)             not null,
   主管                   char(20)             not null,
   constraint PK_比赛类别 primary key (类别编号)
)
go

/*==============================================================*/
/* Table: 比赛项目                                                  */
/*==============================================================*/
create table 比赛项目 (
   项目编号                 char(20)             not null,
   类别编号                 char(20)             not null,
   项目名称                 char(20)             not null,
   比赛时间                 char(20)             not null,
   级别                   char(20)             not null,
   constraint PK_比赛项目 primary key (项目编号)
)
go

/*==============================================================*/
/* Index: 包含_FK                                                 */
/*==============================================================*/




create nonclustered index 包含_FK on 比赛项目 (类别编号 ASC)
go

/*==============================================================*/
/* Table: 运动员                                                   */
/*==============================================================*/
create table 运动员 (
   编号                   char(20)             not null,
   团编号                  char(20)             not null,
   姓名                   char(20)             not null,
   年龄                   char(20)             not null,
   性别                   char(20)             not null,
   constraint PK_运动员 primary key (编号)
)
go

/*==============================================================*/
/* Index: 组成_FK                                                 */
/*==============================================================*/




create nonclustered index 组成_FK on 运动员 (团编号 ASC)
go

alter table 参加
   add constraint FK_参加_参加_比赛项目 foreign key (项目编号)
      references 比赛项目 (项目编号)
go

alter table 参加
   add constraint FK_参加_参加2_运动员 foreign key (编号)
      references 运动员 (编号)
go

alter table 比赛项目
   add constraint FK_比赛项目_包含_比赛类别 foreign key (类别编号)
      references 比赛类别 (类别编号)
go

alter table 运动员
   add constraint FK_运动员_组成_团队 foreign key (团编号)
      references 团队 (团编号)
go


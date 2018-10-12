/*==============================================================*/
/* DBMS name:      Microsoft SQL Server 2014                    */
/* Created on:     2017/12/27 22:09:16                          */
/*==============================================================*/


if exists (select 1
            from  sysobjects
           where  id = object_id('作者')
            and   type = 'U')
   drop table 作者
go

if exists (select 1
            from  sysobjects
           where  id = object_id('论文')
            and   type = 'U')
   drop table 论文
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('论文的作者')
            and   name  = '论文的作者2_FK'
            and   indid > 0
            and   indid < 255)
   drop index 论文的作者.论文的作者2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('论文的作者')
            and   name  = '论文的作者_FK'
            and   indid > 0
            and   indid < 255)
   drop index 论文的作者.论文的作者_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('论文的作者')
            and   type = 'U')
   drop table 论文的作者
go

/*==============================================================*/
/* Table: 作者                                                    */
/*==============================================================*/
create table 作者 (
   身份证号                 char(20)             not null,
   作者姓名                 char(10)             not null,
   单位                   char(256)            null,
   地址                   char(256)            null,
   constraint PK_作者 primary key (身份证号)
)
go

/*==============================================================*/
/* Table: 论文                                                    */
/*==============================================================*/
create table 论文 (
   论文号                  char(20)             not null,
   论文题目                 char(30)             not null,
   期刊名称                 char(30)             null,
   期刊年份                 int                  null,
   期刊号                  char(20)             null,
   constraint PK_论文 primary key (论文号)
)
go

/*==============================================================*/
/* Table: 论文的作者                                                 */
/*==============================================================*/
create table 论文的作者 (
   论文号                  char(20)             not null,
   身份证号                 char(20)             not null,
   作者顺序号                int                  not null,
   constraint PK_论文的作者 primary key (论文号, 身份证号)
)
go

/*==============================================================*/
/* Index: 论文的作者_FK                                              */
/*==============================================================*/




create nonclustered index 论文的作者_FK on 论文的作者 (论文号 ASC)
go

/*==============================================================*/
/* Index: 论文的作者2_FK                                             */
/*==============================================================*/




create nonclustered index 论文的作者2_FK on 论文的作者 (身份证号 ASC)
go


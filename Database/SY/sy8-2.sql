/*==============================================================*/
/* DBMS name:      Microsoft SQL Server 2014                    */
/* Created on:     2017/12/27 22:08:48                          */
/*==============================================================*/


if exists (select 1
            from  sysobjects
           where  id = object_id('产品')
            and   type = 'U')
   drop table 产品
go

if exists (select 1
            from  sysobjects
           where  id = object_id('工厂')
            and   type = 'U')
   drop table 工厂
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('生产')
            and   name  = '生产2_FK'
            and   indid > 0
            and   indid < 255)
   drop index 生产.生产2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('生产')
            and   name  = '生产_FK'
            and   indid > 0
            and   indid < 255)
   drop index 生产.生产_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('生产')
            and   type = 'U')
   drop table 生产
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('职工')
            and   name  = '聘用_FK'
            and   indid > 0
            and   indid < 255)
   drop index 职工.聘用_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('职工')
            and   type = 'U')
   drop table 职工
go

/*==============================================================*/
/* Table: 产品                                                    */
/*==============================================================*/
create table 产品 (
   产品编号                 char(20)             not null,
   产品名                  char(20)             not null,
   规格                   char(256)            not null,
   constraint PK_产品 primary key (产品编号)
)
go

/*==============================================================*/
/* Table: 工厂                                                    */
/*==============================================================*/
create table 工厂 (
   工厂编号                 char(20)             not null,
   厂名                   char(30)             not null,
   地址                   char(256)            not null,
   constraint PK_工厂 primary key (工厂编号)
)
go

/*==============================================================*/
/* Table: 生产                                                    */
/*==============================================================*/
create table 生产 (
   产品编号                 char(20)             not null,
   工厂编号                 char(20)             not null,
   计划数量                 bigint               not null 
      constraint CKC_计划数量_生产 check (计划数量 >= 300),
   constraint PK_生产 primary key (产品编号, 工厂编号)
)
go

/*==============================================================*/
/* Index: 生产_FK                                                 */
/*==============================================================*/




create nonclustered index 生产_FK on 生产 (产品编号 ASC)
go

/*==============================================================*/
/* Index: 生产2_FK                                                */
/*==============================================================*/




create nonclustered index 生产2_FK on 生产 (工厂编号 ASC)
go

/*==============================================================*/
/* Table: 职工                                                    */
/*==============================================================*/
create table 职工 (
   职工号                  char(20)             not null,
   工厂编号                 char(20)             not null,
   职工姓名                 char(20)             not null,
   技术等级                 char(256)            not null,
   聘期                   char(256)            null,
   工资                   float                null,
   constraint PK_职工 primary key (职工号)
)
go

/*==============================================================*/
/* Index: 聘用_FK                                                 */
/*==============================================================*/




create nonclustered index 聘用_FK on 职工 (工厂编号 ASC)
go


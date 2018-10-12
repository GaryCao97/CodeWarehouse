/*==============================================================*/
/* DBMS name:      Microsoft SQL Server 2014                    */
/* Created on:     2017/12/27 22:02:45                          */
/*==============================================================*/


if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('产品') and o.name = 'FK_产品_生产产品_车间')
alter table 产品
   drop constraint FK_产品_生产产品_车间
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('仓库') and o.name = 'FK_仓库_拥有仓库_工厂')
alter table 仓库
   drop constraint FK_仓库_拥有仓库_工厂
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('储存产品') and o.name = 'FK_储存产品_储存产品_产品')
alter table 储存产品
   drop constraint FK_储存产品_储存产品_产品
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('储存产品') and o.name = 'FK_储存产品_储存产品2_仓库')
alter table 储存产品
   drop constraint FK_储存产品_储存产品2_仓库
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('储存零件') and o.name = 'FK_储存零件_储存零件_零件')
alter table 储存零件
   drop constraint FK_储存零件_储存零件_零件
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('储存零件') and o.name = 'FK_储存零件_储存零件2_仓库')
alter table 储存零件
   drop constraint FK_储存零件_储存零件2_仓库
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('工人') and o.name = 'FK_工人_拥有工人_车间')
alter table 工人
   drop constraint FK_工人_拥有工人_车间
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('生产零件') and o.name = 'FK_生产零件_生产零件_车间')
alter table 生产零件
   drop constraint FK_生产零件_生产零件_车间
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('生产零件') and o.name = 'FK_生产零件_生产零件2_零件')
alter table 生产零件
   drop constraint FK_生产零件_生产零件2_零件
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('组成与装配') and o.name = 'FK_组成与装配_组成与装配_零件')
alter table 组成与装配
   drop constraint FK_组成与装配_组成与装配_零件
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('组成与装配') and o.name = 'FK_组成与装配_组成与装配2_产品')
alter table 组成与装配
   drop constraint FK_组成与装配_组成与装配2_产品
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('车间') and o.name = 'FK_车间_拥有车间_工厂')
alter table 车间
   drop constraint FK_车间_拥有车间_工厂
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('产品')
            and   name  = '生产产品_FK'
            and   indid > 0
            and   indid < 255)
   drop index 产品.生产产品_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('产品')
            and   type = 'U')
   drop table 产品
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('仓库')
            and   name  = '拥有仓库_FK'
            and   indid > 0
            and   indid < 255)
   drop index 仓库.拥有仓库_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('仓库')
            and   type = 'U')
   drop table 仓库
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('储存产品')
            and   name  = '储存产品2_FK'
            and   indid > 0
            and   indid < 255)
   drop index 储存产品.储存产品2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('储存产品')
            and   name  = '储存产品_FK'
            and   indid > 0
            and   indid < 255)
   drop index 储存产品.储存产品_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('储存产品')
            and   type = 'U')
   drop table 储存产品
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('储存零件')
            and   name  = '储存零件2_FK'
            and   indid > 0
            and   indid < 255)
   drop index 储存零件.储存零件2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('储存零件')
            and   name  = '储存零件_FK'
            and   indid > 0
            and   indid < 255)
   drop index 储存零件.储存零件_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('储存零件')
            and   type = 'U')
   drop table 储存零件
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('工人')
            and   name  = '拥有工人_FK'
            and   indid > 0
            and   indid < 255)
   drop index 工人.拥有工人_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('工人')
            and   type = 'U')
   drop table 工人
go

if exists (select 1
            from  sysobjects
           where  id = object_id('工厂')
            and   type = 'U')
   drop table 工厂
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('生产零件')
            and   name  = '生产零件2_FK'
            and   indid > 0
            and   indid < 255)
   drop index 生产零件.生产零件2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('生产零件')
            and   name  = '生产零件_FK'
            and   indid > 0
            and   indid < 255)
   drop index 生产零件.生产零件_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('生产零件')
            and   type = 'U')
   drop table 生产零件
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('组成与装配')
            and   name  = '组成与装配2_FK'
            and   indid > 0
            and   indid < 255)
   drop index 组成与装配.组成与装配2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('组成与装配')
            and   name  = '组成与装配_FK'
            and   indid > 0
            and   indid < 255)
   drop index 组成与装配.组成与装配_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('组成与装配')
            and   type = 'U')
   drop table 组成与装配
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('车间')
            and   name  = '拥有车间_FK'
            and   indid > 0
            and   indid < 255)
   drop index 车间.拥有车间_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('车间')
            and   type = 'U')
   drop table 车间
go

if exists (select 1
            from  sysobjects
           where  id = object_id('零件')
            and   type = 'U')
   drop table 零件
go

/*==============================================================*/
/* Table: 产品                                                    */
/*==============================================================*/
create table 产品 (
   产品号                  char(20)             not null,
   车间号                  char(20)             null,
   价格2                  float                not null,
   constraint PK_产品 primary key (产品号)
)
go

/*==============================================================*/
/* Index: 生产产品_FK                                               */
/*==============================================================*/




create nonclustered index 生产产品_FK on 产品 (车间号 ASC)
go

/*==============================================================*/
/* Table: 仓库                                                    */
/*==============================================================*/
create table 仓库 (
   仓库号                  char(20)             not null,
   厂名                   char(20)             null,
   仓库主任姓名               char(20)             not null,
   电话2                  char(20)             not null,
   constraint PK_仓库 primary key (仓库号)
)
go

/*==============================================================*/
/* Index: 拥有仓库_FK                                               */
/*==============================================================*/




create nonclustered index 拥有仓库_FK on 仓库 (厂名 ASC)
go

/*==============================================================*/
/* Table: 储存产品                                                  */
/*==============================================================*/
create table 储存产品 (
   产品号                  char(20)             not null,
   仓库号                  char(20)             not null,
   constraint PK_储存产品 primary key (产品号, 仓库号)
)
go

/*==============================================================*/
/* Index: 储存产品_FK                                               */
/*==============================================================*/




create nonclustered index 储存产品_FK on 储存产品 (产品号 ASC)
go

/*==============================================================*/
/* Index: 储存产品2_FK                                              */
/*==============================================================*/




create nonclustered index 储存产品2_FK on 储存产品 (仓库号 ASC)
go

/*==============================================================*/
/* Table: 储存零件                                                  */
/*==============================================================*/
create table 储存零件 (
   零件号                  char(20)             not null,
   仓库号                  char(20)             not null,
   constraint PK_储存零件 primary key (零件号, 仓库号)
)
go

/*==============================================================*/
/* Index: 储存零件_FK                                               */
/*==============================================================*/




create nonclustered index 储存零件_FK on 储存零件 (零件号 ASC)
go

/*==============================================================*/
/* Index: 储存零件2_FK                                              */
/*==============================================================*/




create nonclustered index 储存零件2_FK on 储存零件 (仓库号 ASC)
go

/*==============================================================*/
/* Table: 工人                                                    */
/*==============================================================*/
create table 工人 (
   职工号                  char(20)             not null,
   车间号                  char(20)             null,
   姓名                   char(20)             not null,
   年龄                   int                  not null,
   性别                   char(2)              not null,
   工种                   char(20)             not null,
   constraint PK_工人 primary key (职工号)
)
go

/*==============================================================*/
/* Index: 拥有工人_FK                                               */
/*==============================================================*/




create nonclustered index 拥有工人_FK on 工人 (车间号 ASC)
go

/*==============================================================*/
/* Table: 工厂                                                    */
/*==============================================================*/
create table 工厂 (
   厂名                   char(20)             not null,
   厂长名                  char(20)             not null,
   constraint PK_工厂 primary key (厂名)
)
go

/*==============================================================*/
/* Table: 生产零件                                                  */
/*==============================================================*/
create table 生产零件 (
   车间号                  char(20)             not null,
   零件号                  char(20)             not null,
   constraint PK_生产零件 primary key (车间号, 零件号)
)
go

/*==============================================================*/
/* Index: 生产零件_FK                                               */
/*==============================================================*/




create nonclustered index 生产零件_FK on 生产零件 (车间号 ASC)
go

/*==============================================================*/
/* Index: 生产零件2_FK                                              */
/*==============================================================*/




create nonclustered index 生产零件2_FK on 生产零件 (零件号 ASC)
go

/*==============================================================*/
/* Table: 组成与装配                                                 */
/*==============================================================*/
create table 组成与装配 (
   零件号                  char(20)             not null,
   产品号                  char(20)             not null,
   constraint PK_组成与装配 primary key (零件号, 产品号)
)
go

/*==============================================================*/
/* Index: 组成与装配_FK                                              */
/*==============================================================*/




create nonclustered index 组成与装配_FK on 组成与装配 (零件号 ASC)
go

/*==============================================================*/
/* Index: 组成与装配2_FK                                             */
/*==============================================================*/




create nonclustered index 组成与装配2_FK on 组成与装配 (产品号 ASC)
go

/*==============================================================*/
/* Table: 车间                                                    */
/*==============================================================*/
create table 车间 (
   车间号                  char(20)             not null,
   厂名                   char(20)             null,
   车间主任姓名               char(20)             not null,
   地址                   char(20)             not null,
   电话1                  char(20)             not null,
   constraint PK_车间 primary key (车间号)
)
go

/*==============================================================*/
/* Index: 拥有车间_FK                                               */
/*==============================================================*/




create nonclustered index 拥有车间_FK on 车间 (厂名 ASC)
go

/*==============================================================*/
/* Table: 零件                                                    */
/*==============================================================*/
create table 零件 (
   零件号                  char(20)             not null,
   重量                   float                null,
   价格1                  float                null,
   constraint PK_零件 primary key (零件号)
)
go

alter table 产品
   add constraint FK_产品_生产产品_车间 foreign key (车间号)
      references 车间 (车间号)
go

alter table 仓库
   add constraint FK_仓库_拥有仓库_工厂 foreign key (厂名)
      references 工厂 (厂名)
go

alter table 储存产品
   add constraint FK_储存产品_储存产品_产品 foreign key (产品号)
      references 产品 (产品号)
go

alter table 储存产品
   add constraint FK_储存产品_储存产品2_仓库 foreign key (仓库号)
      references 仓库 (仓库号)
go

alter table 储存零件
   add constraint FK_储存零件_储存零件_零件 foreign key (零件号)
      references 零件 (零件号)
go

alter table 储存零件
   add constraint FK_储存零件_储存零件2_仓库 foreign key (仓库号)
      references 仓库 (仓库号)
go

alter table 工人
   add constraint FK_工人_拥有工人_车间 foreign key (车间号)
      references 车间 (车间号)
go

alter table 生产零件
   add constraint FK_生产零件_生产零件_车间 foreign key (车间号)
      references 车间 (车间号)
go

alter table 生产零件
   add constraint FK_生产零件_生产零件2_零件 foreign key (零件号)
      references 零件 (零件号)
go

alter table 组成与装配
   add constraint FK_组成与装配_组成与装配_零件 foreign key (零件号)
      references 零件 (零件号)
go

alter table 组成与装配
   add constraint FK_组成与装配_组成与装配2_产品 foreign key (产品号)
      references 产品 (产品号)
go

alter table 车间
   add constraint FK_车间_拥有车间_工厂 foreign key (厂名)
      references 工厂 (厂名)
go


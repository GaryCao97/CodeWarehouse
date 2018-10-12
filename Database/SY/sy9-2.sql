/*==============================================================*/
/* DBMS name:      Microsoft SQL Server 2014                    */
/* Created on:     2017/12/31 0:25:58                           */
/*==============================================================*/


if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Achievement') and o.name = 'FK_ACHIEVEM_ACHIEVEBE_GAME')
alter table Achievement
   drop constraint FK_ACHIEVEM_ACHIEVEBE_GAME
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('BG') and o.name = 'FK_BG_BGBELONG_GAME')
alter table BG
   drop constraint FK_BG_BGBELONG_GAME
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('BGInventory') and o.name = 'FK_BGINVENT_BGINVENTO_PLAYER')
alter table BGInventory
   drop constraint FK_BGINVENT_BGINVENTO_PLAYER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('BGInventory') and o.name = 'FK_BGINVENT_BGINVENTO_BG')
alter table BGInventory
   drop constraint FK_BGINVENT_BGINVENTO_BG
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('BelongTo') and o.name = 'FK_BELONGTO_BELONGTO_USERGROU')
alter table BelongTo
   drop constraint FK_BELONGTO_BELONGTO_USERGROU
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('BelongTo') and o.name = 'FK_BELONGTO_BELONGTO2_PLAYER')
alter table BelongTo
   drop constraint FK_BELONGTO_BELONGTO2_PLAYER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Card') and o.name = 'FK_CARD_CARDBELON_GAME')
alter table Card
   drop constraint FK_CARD_CARDBELON_GAME
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('CardInventory') and o.name = 'FK_CARDINVE_CARDINVEN_PLAYER')
alter table CardInventory
   drop constraint FK_CARDINVE_CARDINVEN_PLAYER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('CardInventory') and o.name = 'FK_CARDINVE_CARDINVEN_CARD')
alter table CardInventory
   drop constraint FK_CARDINVE_CARDINVEN_CARD
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('CloudSaves') and o.name = 'FK_CLOUDSAV_GAMESAVE_GAME')
alter table CloudSaves
   drop constraint FK_CLOUDSAV_GAMESAVE_GAME
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('CloudSaves') and o.name = 'FK_CLOUDSAV_UPLOADSAV_PLAYER')
alter table CloudSaves
   drop constraint FK_CLOUDSAV_UPLOADSAV_PLAYER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('CompoundEmblem') and o.name = 'FK_COMPOUND_COMPOUNDE_EMBLEM')
alter table CompoundEmblem
   drop constraint FK_COMPOUND_COMPOUNDE_EMBLEM
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('CompoundEmblem') and o.name = 'FK_COMPOUND_COMPOUNDE_CARD')
alter table CompoundEmblem
   drop constraint FK_COMPOUND_COMPOUNDE_CARD
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('DLC') and o.name = 'FK_DLC_DCLBELONG_GAME')
alter table DLC
   drop constraint FK_DLC_DCLBELONG_GAME
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('DLC') and o.name = 'FK_DLC_DEVELOPDL_DEVELOPE')
alter table DLC
   drop constraint FK_DLC_DEVELOPDL_DEVELOPE
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('DLC') and o.name = 'FK_DLC_PUBLISHDL_PUBLISHE')
alter table DLC
   drop constraint FK_DLC_PUBLISHDL_PUBLISHE
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('DLCLib') and o.name = 'FK_DLCLIB_DLCLIB_PLAYER')
alter table DLCLib
   drop constraint FK_DLCLIB_DLCLIB_PLAYER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('DLCLib') and o.name = 'FK_DLCLIB_DLCLIB2_DLC')
alter table DLCLib
   drop constraint FK_DLCLIB_DLCLIB2_DLC
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Deal') and o.name = 'FK_DEAL_DEALA_PLAYER')
alter table Deal
   drop constraint FK_DEAL_DEALA_PLAYER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Deal') and o.name = 'FK_DEAL_DEALB_PLAYER')
alter table Deal
   drop constraint FK_DEAL_DEALB_PLAYER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Deal') and o.name = 'FK_DEAL_DEALITAM1_BG')
alter table Deal
   drop constraint FK_DEAL_DEALITAM1_BG
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Deal') and o.name = 'FK_DEAL_DEALITEM2_CARD')
alter table Deal
   drop constraint FK_DEAL_DEALITEM2_CARD
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Discuss') and o.name = 'FK_DISCUSS_DISCUSSAU_PLAYER')
alter table Discuss
   drop constraint FK_DISCUSS_DISCUSSAU_PLAYER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Discuss') and o.name = 'FK_DISCUSS_DISCUSSDI_DISCUSS')
alter table Discuss
   drop constraint FK_DISCUSS_DISCUSSDI_DISCUSS
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Discuss') and o.name = 'FK_DISCUSS_DISCUSSDY_DYNAMIC')
alter table Discuss
   drop constraint FK_DISCUSS_DISCUSSDY_DYNAMIC
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Discuss') and o.name = 'FK_DISCUSS_DISCUSSEV_EVALUATI')
alter table Discuss
   drop constraint FK_DISCUSS_DISCUSSEV_EVALUATI
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Dynamic') and o.name = 'FK_DYNAMIC_CONTAINSH_STEAMCON')
alter table Dynamic
   drop constraint FK_DYNAMIC_CONTAINSH_STEAMCON
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Dynamic') and o.name = 'FK_DYNAMIC_PUBLISHDY_PLAYER')
alter table Dynamic
   drop constraint FK_DYNAMIC_PUBLISHDY_PLAYER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Emblem') and o.name = 'FK_EMBLEM_EMBLEMBEL_GAME')
alter table Emblem
   drop constraint FK_EMBLEM_EMBLEMBEL_GAME
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Evaluation') and o.name = 'FK_EVALUATI_ABOUTDLC_DLC')
alter table Evaluation
   drop constraint FK_EVALUATI_ABOUTDLC_DLC
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Evaluation') and o.name = 'FK_EVALUATI_ABOUTGAME_GAME')
alter table Evaluation
   drop constraint FK_EVALUATI_ABOUTGAME_GAME
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Evaluation') and o.name = 'FK_EVALUATI_AUTHOR_PLAYER')
alter table Evaluation
   drop constraint FK_EVALUATI_AUTHOR_PLAYER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Forum') and o.name = 'FK_FORUM_FORUMAUTH_PLAYER')
alter table Forum
   drop constraint FK_FORUM_FORUMAUTH_PLAYER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Forum') and o.name = 'FK_FORUM_OTHERTHEM_IDEAPROD')
alter table Forum
   drop constraint FK_FORUM_OTHERTHEM_IDEAPROD
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Friend') and o.name = 'FK_FRIEND_FRIEND_PLAYER')
alter table Friend
   drop constraint FK_FRIEND_FRIEND_PLAYER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Friend') and o.name = 'FK_FRIEND_FRIEND2_PLAYER')
alter table Friend
   drop constraint FK_FRIEND_FRIEND2_PLAYER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Game') and o.name = 'FK_GAME_DEVELOPGA_DEVELOPE')
alter table Game
   drop constraint FK_GAME_DEVELOPGA_DEVELOPE
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Game') and o.name = 'FK_GAME_PUBLISHGA_PUBLISHE')
alter table Game
   drop constraint FK_GAME_PUBLISHGA_PUBLISHE
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('GameLib') and o.name = 'FK_GAMELIB_GAMELIB_PLAYER')
alter table GameLib
   drop constraint FK_GAMELIB_GAMELIB_PLAYER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('GameLib') and o.name = 'FK_GAMELIB_GAMELIB2_GAME')
alter table GameLib
   drop constraint FK_GAMELIB_GAMELIB2_GAME
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('GameWish') and o.name = 'FK_GAMEWISH_GAMEWISH_PLAYER')
alter table GameWish
   drop constraint FK_GAMEWISH_GAMEWISH_PLAYER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('GameWish') and o.name = 'FK_GAMEWISH_GAMEWISH2_GAME')
alter table GameWish
   drop constraint FK_GAMEWISH_GAMEWISH2_GAME
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Guide') and o.name = 'FK_GUIDE_GAMEGUIDE_GAME')
alter table Guide
   drop constraint FK_GUIDE_GAMEGUIDE_GAME
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Guide') and o.name = 'FK_GUIDE_GUIDEAUTH_PLAYER')
alter table Guide
   drop constraint FK_GUIDE_GUIDEAUTH_PLAYER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('IdeaProduct') and o.name = 'FK_IDEAPROD_GAMEIDEA_GAME')
alter table IdeaProduct
   drop constraint FK_IDEAPROD_GAMEIDEA_GAME
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('IdeaProduct') and o.name = 'FK_IDEAPROD_IDEACREAT_PLAYER')
alter table IdeaProduct
   drop constraint FK_IDEAPROD_IDEACREAT_PLAYER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Message') and o.name = 'FK_MESSAGE_FORUMMESS_FORUM')
alter table Message
   drop constraint FK_MESSAGE_FORUMMESS_FORUM
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Message') and o.name = 'FK_MESSAGE_MESSAGEAU_PLAYER')
alter table Message
   drop constraint FK_MESSAGE_MESSAGEAU_PLAYER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('Message') and o.name = 'FK_MESSAGE_MESSAGEME_MESSAGE')
alter table Message
   drop constraint FK_MESSAGE_MESSAGEME_MESSAGE
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('News') and o.name = 'FK_NEWS_NEWSSOURC_GAME')
alter table News
   drop constraint FK_NEWS_NEWSSOURC_GAME
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('News') and o.name = 'FK_NEWS_NEWSSOURC_DEVELOPE')
alter table News
   drop constraint FK_NEWS_NEWSSOURC_DEVELOPE
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('News') and o.name = 'FK_NEWS_NEWSSOURC_PUBLISHE')
alter table News
   drop constraint FK_NEWS_NEWSSOURC_PUBLISHE
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('PlayerAchieve') and o.name = 'FK_PLAYERAC_PLAYERACH_PLAYER')
alter table PlayerAchieve
   drop constraint FK_PLAYERAC_PLAYERACH_PLAYER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('PlayerAchieve') and o.name = 'FK_PLAYERAC_PLAYERACH_ACHIEVEM')
alter table PlayerAchieve
   drop constraint FK_PLAYERAC_PLAYERACH_ACHIEVEM
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('PlayerEmblem') and o.name = 'FK_PLAYEREM_PLAYEREMB_PLAYER')
alter table PlayerEmblem
   drop constraint FK_PLAYEREM_PLAYEREMB_PLAYER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('PlayerEmblem') and o.name = 'FK_PLAYEREM_PLAYEREMB_EMBLEM')
alter table PlayerEmblem
   drop constraint FK_PLAYEREM_PLAYEREMB_EMBLEM
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('PlayerTools') and o.name = 'FK_PLAYERTO_PLAYERTOO_TOOLS')
alter table PlayerTools
   drop constraint FK_PLAYERTO_PLAYERTOO_TOOLS
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('PlayerTools') and o.name = 'FK_PLAYERTO_PLAYERTOO_PLAYER')
alter table PlayerTools
   drop constraint FK_PLAYERTO_PLAYERTOO_PLAYER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('SteamContain') and o.name = 'FK_STEAMCON_GAMECONTA_GAME')
alter table SteamContain
   drop constraint FK_STEAMCON_GAMECONTA_GAME
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('SteamContain') and o.name = 'FK_STEAMCON_OWN_PLAYER')
alter table SteamContain
   drop constraint FK_STEAMCON_OWN_PLAYER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('UserGroup') and o.name = 'FK_USERGROU_GAMEGROUP_GAME')
alter table UserGroup
   drop constraint FK_USERGROU_GAMEGROUP_GAME
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('UserGroup') and o.name = 'FK_USERGROU_GROUPCREA_PLAYER')
alter table UserGroup
   drop constraint FK_USERGROU_GROUPCREA_PLAYER
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Achievement')
            and   name  = 'AchieveBelong_FK'
            and   indid > 0
            and   indid < 255)
   drop index Achievement.AchieveBelong_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('Achievement')
            and   type = 'U')
   drop table Achievement
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('BG')
            and   name  = 'BGBelong_FK'
            and   indid > 0
            and   indid < 255)
   drop index BG.BGBelong_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('BG')
            and   type = 'U')
   drop table BG
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('BGInventory')
            and   name  = 'BGInventory2_FK'
            and   indid > 0
            and   indid < 255)
   drop index BGInventory.BGInventory2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('BGInventory')
            and   name  = 'BGInventory_FK'
            and   indid > 0
            and   indid < 255)
   drop index BGInventory.BGInventory_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('BGInventory')
            and   type = 'U')
   drop table BGInventory
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('BelongTo')
            and   name  = 'BelongTo2_FK'
            and   indid > 0
            and   indid < 255)
   drop index BelongTo.BelongTo2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('BelongTo')
            and   name  = 'BelongTo_FK'
            and   indid > 0
            and   indid < 255)
   drop index BelongTo.BelongTo_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('BelongTo')
            and   type = 'U')
   drop table BelongTo
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Card')
            and   name  = 'CardBelong_FK'
            and   indid > 0
            and   indid < 255)
   drop index Card.CardBelong_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('Card')
            and   type = 'U')
   drop table Card
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('CardInventory')
            and   name  = 'CardInventory2_FK'
            and   indid > 0
            and   indid < 255)
   drop index CardInventory.CardInventory2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('CardInventory')
            and   name  = 'CardInventory_FK'
            and   indid > 0
            and   indid < 255)
   drop index CardInventory.CardInventory_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('CardInventory')
            and   type = 'U')
   drop table CardInventory
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('CloudSaves')
            and   name  = 'GameSave_FK'
            and   indid > 0
            and   indid < 255)
   drop index CloudSaves.GameSave_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('CloudSaves')
            and   name  = 'UploadSaves_FK'
            and   indid > 0
            and   indid < 255)
   drop index CloudSaves.UploadSaves_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('CloudSaves')
            and   type = 'U')
   drop table CloudSaves
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('CompoundEmblem')
            and   name  = 'CompoundEmblem2_FK'
            and   indid > 0
            and   indid < 255)
   drop index CompoundEmblem.CompoundEmblem2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('CompoundEmblem')
            and   name  = 'CompoundEmblem_FK'
            and   indid > 0
            and   indid < 255)
   drop index CompoundEmblem.CompoundEmblem_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('CompoundEmblem')
            and   type = 'U')
   drop table CompoundEmblem
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('DLC')
            and   name  = 'DevelopDLC_FK'
            and   indid > 0
            and   indid < 255)
   drop index DLC.DevelopDLC_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('DLC')
            and   name  = 'PublishDLC_FK'
            and   indid > 0
            and   indid < 255)
   drop index DLC.PublishDLC_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('DLC')
            and   name  = 'DCLBelong_FK'
            and   indid > 0
            and   indid < 255)
   drop index DLC.DCLBelong_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('DLC')
            and   type = 'U')
   drop table DLC
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('DLCLib')
            and   name  = 'DLCLib2_FK'
            and   indid > 0
            and   indid < 255)
   drop index DLCLib.DLCLib2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('DLCLib')
            and   name  = 'DLCLib_FK'
            and   indid > 0
            and   indid < 255)
   drop index DLCLib.DLCLib_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('DLCLib')
            and   type = 'U')
   drop table DLCLib
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Deal')
            and   name  = 'DealItem2_FK'
            and   indid > 0
            and   indid < 255)
   drop index Deal.DealItem2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Deal')
            and   name  = 'DealItam1_FK'
            and   indid > 0
            and   indid < 255)
   drop index Deal.DealItam1_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Deal')
            and   name  = 'DealB_FK'
            and   indid > 0
            and   indid < 255)
   drop index Deal.DealB_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Deal')
            and   name  = 'DealA_FK'
            and   indid > 0
            and   indid < 255)
   drop index Deal.DealA_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('Deal')
            and   type = 'U')
   drop table Deal
go

if exists (select 1
            from  sysobjects
           where  id = object_id('Developers')
            and   type = 'U')
   drop table Developers
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Discuss')
            and   name  = 'DiscussDiscuss_FK'
            and   indid > 0
            and   indid < 255)
   drop index Discuss.DiscussDiscuss_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Discuss')
            and   name  = 'DiscussEvaluation_FK'
            and   indid > 0
            and   indid < 255)
   drop index Discuss.DiscussEvaluation_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Discuss')
            and   name  = 'DiscussDynamic_FK'
            and   indid > 0
            and   indid < 255)
   drop index Discuss.DiscussDynamic_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Discuss')
            and   name  = 'DiscussAuthor_FK'
            and   indid > 0
            and   indid < 255)
   drop index Discuss.DiscussAuthor_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('Discuss')
            and   type = 'U')
   drop table Discuss
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Dynamic')
            and   name  = 'ContainShare_FK'
            and   indid > 0
            and   indid < 255)
   drop index Dynamic.ContainShare_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Dynamic')
            and   name  = 'PublishDynamic_FK'
            and   indid > 0
            and   indid < 255)
   drop index Dynamic.PublishDynamic_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('Dynamic')
            and   type = 'U')
   drop table Dynamic
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Emblem')
            and   name  = 'EmblemBelong_FK'
            and   indid > 0
            and   indid < 255)
   drop index Emblem.EmblemBelong_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('Emblem')
            and   type = 'U')
   drop table Emblem
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Evaluation')
            and   name  = 'AboutDLC_FK'
            and   indid > 0
            and   indid < 255)
   drop index Evaluation.AboutDLC_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Evaluation')
            and   name  = 'AboutGame_FK'
            and   indid > 0
            and   indid < 255)
   drop index Evaluation.AboutGame_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Evaluation')
            and   name  = 'Author_FK'
            and   indid > 0
            and   indid < 255)
   drop index Evaluation.Author_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('Evaluation')
            and   type = 'U')
   drop table Evaluation
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Forum')
            and   name  = 'ForumAuthor_FK'
            and   indid > 0
            and   indid < 255)
   drop index Forum.ForumAuthor_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Forum')
            and   name  = 'OtherTheme_FK'
            and   indid > 0
            and   indid < 255)
   drop index Forum.OtherTheme_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('Forum')
            and   type = 'U')
   drop table Forum
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Friend')
            and   name  = 'Friend2_FK'
            and   indid > 0
            and   indid < 255)
   drop index Friend.Friend2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Friend')
            and   name  = 'Friend_FK'
            and   indid > 0
            and   indid < 255)
   drop index Friend.Friend_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('Friend')
            and   type = 'U')
   drop table Friend
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Game')
            and   name  = 'DevelopGame_FK'
            and   indid > 0
            and   indid < 255)
   drop index Game.DevelopGame_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Game')
            and   name  = 'PublishGame_FK'
            and   indid > 0
            and   indid < 255)
   drop index Game.PublishGame_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('Game')
            and   type = 'U')
   drop table Game
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('GameLib')
            and   name  = 'GameLib2_FK'
            and   indid > 0
            and   indid < 255)
   drop index GameLib.GameLib2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('GameLib')
            and   name  = 'GameLib_FK'
            and   indid > 0
            and   indid < 255)
   drop index GameLib.GameLib_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('GameLib')
            and   type = 'U')
   drop table GameLib
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('GameWish')
            and   name  = 'GameWish2_FK'
            and   indid > 0
            and   indid < 255)
   drop index GameWish.GameWish2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('GameWish')
            and   name  = 'GameWish_FK'
            and   indid > 0
            and   indid < 255)
   drop index GameWish.GameWish_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('GameWish')
            and   type = 'U')
   drop table GameWish
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Guide')
            and   name  = 'GuideAuthor_FK'
            and   indid > 0
            and   indid < 255)
   drop index Guide.GuideAuthor_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Guide')
            and   name  = 'GameGuide_FK'
            and   indid > 0
            and   indid < 255)
   drop index Guide.GameGuide_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('Guide')
            and   type = 'U')
   drop table Guide
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('IdeaProduct')
            and   name  = 'IdeaCreator_FK'
            and   indid > 0
            and   indid < 255)
   drop index IdeaProduct.IdeaCreator_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('IdeaProduct')
            and   name  = 'GameIdea_FK'
            and   indid > 0
            and   indid < 255)
   drop index IdeaProduct.GameIdea_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('IdeaProduct')
            and   type = 'U')
   drop table IdeaProduct
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Message')
            and   name  = 'MessageAuthor_FK'
            and   indid > 0
            and   indid < 255)
   drop index Message.MessageAuthor_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Message')
            and   name  = 'MessageMessage_FK'
            and   indid > 0
            and   indid < 255)
   drop index Message.MessageMessage_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('Message')
            and   name  = 'ForumMessage_FK'
            and   indid > 0
            and   indid < 255)
   drop index Message.ForumMessage_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('Message')
            and   type = 'U')
   drop table Message
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('News')
            and   name  = 'NewsSource3_FK'
            and   indid > 0
            and   indid < 255)
   drop index News.NewsSource3_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('News')
            and   name  = 'NewsSource2_FK'
            and   indid > 0
            and   indid < 255)
   drop index News.NewsSource2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('News')
            and   name  = 'NewsSource1_FK'
            and   indid > 0
            and   indid < 255)
   drop index News.NewsSource1_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('News')
            and   type = 'U')
   drop table News
go

if exists (select 1
            from  sysobjects
           where  id = object_id('Player')
            and   type = 'U')
   drop table Player
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('PlayerAchieve')
            and   name  = 'PlayerAchieve2_FK'
            and   indid > 0
            and   indid < 255)
   drop index PlayerAchieve.PlayerAchieve2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('PlayerAchieve')
            and   name  = 'PlayerAchieve_FK'
            and   indid > 0
            and   indid < 255)
   drop index PlayerAchieve.PlayerAchieve_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('PlayerAchieve')
            and   type = 'U')
   drop table PlayerAchieve
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('PlayerEmblem')
            and   name  = 'PlayerEmblem2_FK'
            and   indid > 0
            and   indid < 255)
   drop index PlayerEmblem.PlayerEmblem2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('PlayerEmblem')
            and   name  = 'PlayerEmblem_FK'
            and   indid > 0
            and   indid < 255)
   drop index PlayerEmblem.PlayerEmblem_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('PlayerEmblem')
            and   type = 'U')
   drop table PlayerEmblem
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('PlayerTools')
            and   name  = 'PlayerTools2_FK'
            and   indid > 0
            and   indid < 255)
   drop index PlayerTools.PlayerTools2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('PlayerTools')
            and   name  = 'PlayerTools_FK'
            and   indid > 0
            and   indid < 255)
   drop index PlayerTools.PlayerTools_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('PlayerTools')
            and   type = 'U')
   drop table PlayerTools
go

if exists (select 1
            from  sysobjects
           where  id = object_id('Publisher')
            and   type = 'U')
   drop table Publisher
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('SteamContain')
            and   name  = 'Own_FK'
            and   indid > 0
            and   indid < 255)
   drop index SteamContain.Own_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('SteamContain')
            and   name  = 'GameContain_FK'
            and   indid > 0
            and   indid < 255)
   drop index SteamContain.GameContain_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('SteamContain')
            and   type = 'U')
   drop table SteamContain
go

if exists (select 1
            from  sysobjects
           where  id = object_id('Tools')
            and   type = 'U')
   drop table Tools
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('UserGroup')
            and   name  = 'GameGroup_FK'
            and   indid > 0
            and   indid < 255)
   drop index UserGroup.GameGroup_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('UserGroup')
            and   name  = 'GroupCreate_FK'
            and   indid > 0
            and   indid < 255)
   drop index UserGroup.GroupCreate_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('UserGroup')
            and   type = 'U')
   drop table UserGroup
go

if exists(select 1 from systypes where name='DateAndTime')
   drop type DateAndTime
go

if exists(select 1 from systypes where name='RealValue')
   drop type RealValue
go

/*==============================================================*/
/* Domain: DateAndTime                                          */
/*==============================================================*/
create type DateAndTime
   from datetime not null
go

/*==============================================================*/
/* Domain: RealValue                                            */
/*==============================================================*/
create type RealValue
   from float not null
go

/*==============================================================*/
/* Table: Achievement                                           */
/*==============================================================*/
create table Achievement (
   AchieveID            char(20)             not null,
   GameID               char(20)             not null,
   AchieveName          char(20)             not null,
   AchieveIntroduce     char(256)            null,
   AchieveTarget        int                  null,
   constraint PK_ACHIEVEMENT primary key (AchieveID)
)
go

/*==============================================================*/
/* Index: AchieveBelong_FK                                      */
/*==============================================================*/




create nonclustered index AchieveBelong_FK on Achievement (GameID ASC)
go

/*==============================================================*/
/* Table: BG                                                    */
/*==============================================================*/
create table BG (
   BGID                 char(30)             not null,
   GameID               char(20)             not null,
   BGName               char(20)             not null,
   BGValue              RealValue            not null,
   constraint PK_BG primary key (BGID)
)
go

/*==============================================================*/
/* Index: BGBelong_FK                                           */
/*==============================================================*/




create nonclustered index BGBelong_FK on BG (GameID ASC)
go

/*==============================================================*/
/* Table: BGInventory                                           */
/*==============================================================*/
create table BGInventory (
   Username             char(20)             not null,
   BGID                 char(30)             not null,
   BGNum                smallint             not null,
   constraint PK_BGINVENTORY primary key (Username, BGID)
)
go

/*==============================================================*/
/* Index: BGInventory_FK                                        */
/*==============================================================*/




create nonclustered index BGInventory_FK on BGInventory (Username ASC)
go

/*==============================================================*/
/* Index: BGInventory2_FK                                       */
/*==============================================================*/




create nonclustered index BGInventory2_FK on BGInventory (BGID ASC)
go

/*==============================================================*/
/* Table: BelongTo                                              */
/*==============================================================*/
create table BelongTo (
   GroupID              char(20)             not null,
   Username             char(20)             not null,
   GroupJurisdiction    char(20)             not null default 'ÆÕÍ¨³ÉÔ±',
   constraint PK_BELONGTO primary key (GroupID, Username)
)
go

/*==============================================================*/
/* Index: BelongTo_FK                                           */
/*==============================================================*/




create nonclustered index BelongTo_FK on BelongTo (GroupID ASC)
go

/*==============================================================*/
/* Index: BelongTo2_FK                                          */
/*==============================================================*/




create nonclustered index BelongTo2_FK on BelongTo (Username ASC)
go

/*==============================================================*/
/* Table: Card                                                  */
/*==============================================================*/
create table Card (
   CardID               char(50)             not null,
   GameID               char(20)             not null,
   CardName             char(20)             not null,
   CardType             int                  not null,
   CardValue            RealValue            not null,
   constraint PK_CARD primary key (CardID)
)
go

/*==============================================================*/
/* Index: CardBelong_FK                                         */
/*==============================================================*/




create nonclustered index CardBelong_FK on Card (GameID ASC)
go

/*==============================================================*/
/* Table: CardInventory                                         */
/*==============================================================*/
create table CardInventory (
   Username             char(20)             not null,
   CardID               char(50)             not null,
   CardNum              smallint             not null,
   constraint PK_CARDINVENTORY primary key (Username, CardID)
)
go

/*==============================================================*/
/* Index: CardInventory_FK                                      */
/*==============================================================*/




create nonclustered index CardInventory_FK on CardInventory (Username ASC)
go

/*==============================================================*/
/* Index: CardInventory2_FK                                     */
/*==============================================================*/




create nonclustered index CardInventory2_FK on CardInventory (CardID ASC)
go

/*==============================================================*/
/* Table: CloudSaves                                            */
/*==============================================================*/
create table CloudSaves (
   SavesID              char(20)             not null,
   GameID               char(20)             not null,
   Username             char(20)             not null,
   SavesSaveAddr        char(256)            not null,
   SaveCreateTime       DateAndTime          not null,
   SaveUploadTime       DateAndTime          not null,
   SavesContain         char(256)            not null,
   constraint PK_CLOUDSAVES primary key (SavesID)
)
go

/*==============================================================*/
/* Index: UploadSaves_FK                                        */
/*==============================================================*/




create nonclustered index UploadSaves_FK on CloudSaves (Username ASC)
go

/*==============================================================*/
/* Index: GameSave_FK                                           */
/*==============================================================*/




create nonclustered index GameSave_FK on CloudSaves (GameID ASC)
go

/*==============================================================*/
/* Table: CompoundEmblem                                        */
/*==============================================================*/
create table CompoundEmblem (
   EmblemID             char(30)             not null,
   CardID               char(50)             not null,
   constraint PK_COMPOUNDEMBLEM primary key (EmblemID, CardID)
)
go

/*==============================================================*/
/* Index: CompoundEmblem_FK                                     */
/*==============================================================*/




create nonclustered index CompoundEmblem_FK on CompoundEmblem (EmblemID ASC)
go

/*==============================================================*/
/* Index: CompoundEmblem2_FK                                    */
/*==============================================================*/




create nonclustered index CompoundEmblem2_FK on CompoundEmblem (CardID ASC)
go

/*==============================================================*/
/* Table: DLC                                                   */
/*==============================================================*/
create table DLC (
   DLCID                char(30)             not null,
   DevelopersID         char(30)             not null,
   PublisherID          char(30)             not null,
   GameID               char(20)             not null,
   DLCName              char(20)             not null,
   DLCValue             RealValue            not null,
   PublishedDate        DateAndTime          not null,
   constraint PK_DLC primary key (DLCID)
)
go

/*==============================================================*/
/* Index: DCLBelong_FK                                          */
/*==============================================================*/




create nonclustered index DCLBelong_FK on DLC (GameID ASC)
go

/*==============================================================*/
/* Index: PublishDLC_FK                                         */
/*==============================================================*/




create nonclustered index PublishDLC_FK on DLC (PublisherID ASC)
go

/*==============================================================*/
/* Index: DevelopDLC_FK                                         */
/*==============================================================*/




create nonclustered index DevelopDLC_FK on DLC (DevelopersID ASC)
go

/*==============================================================*/
/* Table: DLCLib                                                */
/*==============================================================*/
create table DLCLib (
   Username             char(20)             not null,
   DLCID                char(30)             not null,
   DLCBuyTime           DateAndTime          not null,
   constraint PK_DLCLIB primary key (Username, DLCID)
)
go

/*==============================================================*/
/* Index: DLCLib_FK                                             */
/*==============================================================*/




create nonclustered index DLCLib_FK on DLCLib (Username ASC)
go

/*==============================================================*/
/* Index: DLCLib2_FK                                            */
/*==============================================================*/




create nonclustered index DLCLib2_FK on DLCLib (DLCID ASC)
go

/*==============================================================*/
/* Table: Deal                                                  */
/*==============================================================*/
create table Deal (
   DealID               char(20)             not null,
   BGID                 char(30)             null,
   Username             char(20)             not null,
   CardID               char(50)             null,
   Pla_Username         char(20)             not null,
   DealValue            RealValue            not null,
   constraint PK_DEAL primary key (DealID)
)
go

/*==============================================================*/
/* Index: DealA_FK                                              */
/*==============================================================*/




create nonclustered index DealA_FK on Deal (Username ASC)
go

/*==============================================================*/
/* Index: DealB_FK                                              */
/*==============================================================*/




create nonclustered index DealB_FK on Deal (Pla_Username ASC)
go

/*==============================================================*/
/* Index: DealItam1_FK                                          */
/*==============================================================*/




create nonclustered index DealItam1_FK on Deal (BGID ASC)
go

/*==============================================================*/
/* Index: DealItem2_FK                                          */
/*==============================================================*/




create nonclustered index DealItem2_FK on Deal (CardID ASC)
go

/*==============================================================*/
/* Table: Developers                                            */
/*==============================================================*/
create table Developers (
   DevelopersID         char(30)             not null,
   DevelopersName       char(20)             not null,
   constraint PK_DEVELOPERS primary key (DevelopersID)
)
go

/*==============================================================*/
/* Table: Discuss                                               */
/*==============================================================*/
create table Discuss (
   DiscussID            char(20)             not null,
   EvaluationID         char(20)             null,
   Username             char(20)             not null,
   Dis_DiscussID        char(20)             null,
   DynamicID            char(20)             null,
   DiscussComment       char(256)            not null,
   DiscussTime          DateAndTime          not null,
   constraint PK_DISCUSS primary key (DiscussID)
)
go

/*==============================================================*/
/* Index: DiscussAuthor_FK                                      */
/*==============================================================*/




create nonclustered index DiscussAuthor_FK on Discuss (Username ASC)
go

/*==============================================================*/
/* Index: DiscussDynamic_FK                                     */
/*==============================================================*/




create nonclustered index DiscussDynamic_FK on Discuss (DynamicID ASC)
go

/*==============================================================*/
/* Index: DiscussEvaluation_FK                                  */
/*==============================================================*/




create nonclustered index DiscussEvaluation_FK on Discuss (EvaluationID ASC)
go

/*==============================================================*/
/* Index: DiscussDiscuss_FK                                     */
/*==============================================================*/




create nonclustered index DiscussDiscuss_FK on Discuss (Dis_DiscussID ASC)
go

/*==============================================================*/
/* Table: Dynamic                                               */
/*==============================================================*/
create table Dynamic (
   DynamicID            char(20)             not null,
   ContainID            char(20)             null,
   Username             char(20)             not null,
   DynamicComment       char(256)            not null,
   DynamicTime          DateAndTime          not null,
   constraint PK_DYNAMIC primary key (DynamicID)
)
go

/*==============================================================*/
/* Index: PublishDynamic_FK                                     */
/*==============================================================*/




create nonclustered index PublishDynamic_FK on Dynamic (Username ASC)
go

/*==============================================================*/
/* Index: ContainShare_FK                                       */
/*==============================================================*/




create nonclustered index ContainShare_FK on Dynamic (ContainID ASC)
go

/*==============================================================*/
/* Table: Emblem                                                */
/*==============================================================*/
create table Emblem (
   EmblemID             char(30)             not null,
   GameID               char(20)             not null,
   EmblemName           char(20)             not null,
   EmblemExp            int                  null,
   constraint PK_EMBLEM primary key (EmblemID)
)
go

/*==============================================================*/
/* Index: EmblemBelong_FK                                       */
/*==============================================================*/




create nonclustered index EmblemBelong_FK on Emblem (GameID ASC)
go

/*==============================================================*/
/* Table: Evaluation                                            */
/*==============================================================*/
create table Evaluation (
   EvaluationID         char(20)             not null,
   Username             char(20)             not null,
   GameID               char(20)             null,
   DLCID                char(30)             null,
   EvaluationComment    char(256)            not null,
   EvaluationTime       DateAndTime          not null,
   EvaluationType       int                  not null 
      constraint CKC_EVALUATIONTYPE_EVALUATI check (EvaluationType in (0,1)),
   constraint PK_EVALUATION primary key (EvaluationID)
)
go

/*==============================================================*/
/* Index: Author_FK                                             */
/*==============================================================*/




create nonclustered index Author_FK on Evaluation (Username ASC)
go

/*==============================================================*/
/* Index: AboutGame_FK                                          */
/*==============================================================*/




create nonclustered index AboutGame_FK on Evaluation (GameID ASC)
go

/*==============================================================*/
/* Index: AboutDLC_FK                                           */
/*==============================================================*/




create nonclustered index AboutDLC_FK on Evaluation (DLCID ASC)
go

/*==============================================================*/
/* Table: Forum                                                 */
/*==============================================================*/
create table Forum (
   ForumID              char(20)             not null,
   Username             char(20)             not null,
   ProductID            char(20)             null,
   Title                char(30)             not null,
   Theme                char(30)             null,
   Comment              char(256)            null,
   CreateTime           DateAndTime          not null,
   constraint PK_FORUM primary key (ForumID)
)
go

/*==============================================================*/
/* Index: OtherTheme_FK                                         */
/*==============================================================*/




create nonclustered index OtherTheme_FK on Forum (ProductID ASC)
go

/*==============================================================*/
/* Index: ForumAuthor_FK                                        */
/*==============================================================*/




create nonclustered index ForumAuthor_FK on Forum (Username ASC)
go

/*==============================================================*/
/* Table: Friend                                                */
/*==============================================================*/
create table Friend (
   Username             char(20)             not null,
   Pla_Username         char(20)             not null,
   Slip                 char(20)             null,
   constraint PK_FRIEND primary key (Username, Pla_Username)
)
go

/*==============================================================*/
/* Index: Friend_FK                                             */
/*==============================================================*/




create nonclustered index Friend_FK on Friend (Username ASC)
go

/*==============================================================*/
/* Index: Friend2_FK                                            */
/*==============================================================*/




create nonclustered index Friend2_FK on Friend (Pla_Username ASC)
go

/*==============================================================*/
/* Table: Game                                                  */
/*==============================================================*/
create table Game (
   GameID               char(20)             not null,
   PublisherID          char(30)             not null,
   DevelopersID         char(30)             not null,
   GameName             char(20)             not null,
   GameKind             char(10)             not null,
   GameIntroduce        char(256)            not null,
   GameValue            RealValue            not null,
   PublishedTime        DateAndTime          not null,
   SystemRequir         char(256)            not null,
   constraint PK_GAME primary key (GameID)
)
go

/*==============================================================*/
/* Index: PublishGame_FK                                        */
/*==============================================================*/




create nonclustered index PublishGame_FK on Game (PublisherID ASC)
go

/*==============================================================*/
/* Index: DevelopGame_FK                                        */
/*==============================================================*/




create nonclustered index DevelopGame_FK on Game (DevelopersID ASC)
go

/*==============================================================*/
/* Table: GameLib                                               */
/*==============================================================*/
create table GameLib (
   Username             char(20)             not null,
   GameID               char(20)             not null,
   BuyTime              DateAndTime          not null,
   InstallStatus        int                  not null 
      constraint CKC_INSTALLSTATUS_GAMELIB check (InstallStatus in (0,1)),
   PlayGameTime         datetime             not null,
   GameGroup            char(20)             null,
   constraint PK_GAMELIB primary key (Username, GameID)
)
go

/*==============================================================*/
/* Index: GameLib_FK                                            */
/*==============================================================*/




create nonclustered index GameLib_FK on GameLib (Username ASC)
go

/*==============================================================*/
/* Index: GameLib2_FK                                           */
/*==============================================================*/




create nonclustered index GameLib2_FK on GameLib (GameID ASC)
go

/*==============================================================*/
/* Table: GameWish                                              */
/*==============================================================*/
create table GameWish (
   Username             char(20)             not null,
   GameID               char(20)             not null,
   AddTime              DateAndTime          not null,
   constraint PK_GAMEWISH primary key (Username, GameID)
)
go

/*==============================================================*/
/* Index: GameWish_FK                                           */
/*==============================================================*/




create nonclustered index GameWish_FK on GameWish (Username ASC)
go

/*==============================================================*/
/* Index: GameWish2_FK                                          */
/*==============================================================*/




create nonclustered index GameWish2_FK on GameWish (GameID ASC)
go

/*==============================================================*/
/* Table: Guide                                                 */
/*==============================================================*/
create table Guide (
   GuideID              char(20)             not null,
   Username             char(20)             not null,
   GameID               char(20)             not null,
   GuideComment         char(256)            null,
   GuideTime            DateAndTime          not null,
   constraint PK_GUIDE primary key (GuideID)
)
go

/*==============================================================*/
/* Index: GameGuide_FK                                          */
/*==============================================================*/




create nonclustered index GameGuide_FK on Guide (GameID ASC)
go

/*==============================================================*/
/* Index: GuideAuthor_FK                                        */
/*==============================================================*/




create nonclustered index GuideAuthor_FK on Guide (Username ASC)
go

/*==============================================================*/
/* Table: IdeaProduct                                           */
/*==============================================================*/
create table IdeaProduct (
   ProductID            char(20)             not null,
   Username             char(20)             not null,
   GameID               char(20)             not null,
   ProductName          char(20)             not null,
   IdeaLvl              int                  not null 
      constraint CKC_IDEALVL_IDEAPROD check (IdeaLvl between 1 and 5),
   ProductKind          char(10)             not null,
   ProductValue         RealValue            null,
   ProductIntroduce     char(256)            not null,
   ProductAddr          char(256)            not null,
   ProductCreateTime    DateAndTime          not null,
   ProductUpdateTime    DateAndTime          not null,
   constraint PK_IDEAPRODUCT primary key (ProductID)
)
go

/*==============================================================*/
/* Index: GameIdea_FK                                           */
/*==============================================================*/




create nonclustered index GameIdea_FK on IdeaProduct (GameID ASC)
go

/*==============================================================*/
/* Index: IdeaCreator_FK                                        */
/*==============================================================*/




create nonclustered index IdeaCreator_FK on IdeaProduct (Username ASC)
go

/*==============================================================*/
/* Table: Message                                               */
/*==============================================================*/
create table Message (
   MessageID            char(30)             not null,
   Mes_MessageID        char(30)             null,
   Username             char(20)             not null,
   ForumID              char(20)             null,
   MessageComment       char(256)            null,
   MessageTime          DateAndTime          not null,
   constraint PK_MESSAGE primary key (MessageID)
)
go

/*==============================================================*/
/* Index: ForumMessage_FK                                       */
/*==============================================================*/




create nonclustered index ForumMessage_FK on Message (ForumID ASC)
go

/*==============================================================*/
/* Index: MessageMessage_FK                                     */
/*==============================================================*/




create nonclustered index MessageMessage_FK on Message (Mes_MessageID ASC)
go

/*==============================================================*/
/* Index: MessageAuthor_FK                                      */
/*==============================================================*/




create nonclustered index MessageAuthor_FK on Message (Username ASC)
go

/*==============================================================*/
/* Table: News                                                  */
/*==============================================================*/
create table News (
   NewsID               char(20)             not null,
   GameID               char(20)             null,
   PublisherID          char(30)             null,
   DevelopersID         char(30)             null,
   NewsComment          char(256)            not null,
   NewsTime             DateAndTime          not null,
   constraint PK_NEWS primary key (NewsID)
)
go

/*==============================================================*/
/* Index: NewsSource1_FK                                        */
/*==============================================================*/




create nonclustered index NewsSource1_FK on News (GameID ASC)
go

/*==============================================================*/
/* Index: NewsSource2_FK                                        */
/*==============================================================*/




create nonclustered index NewsSource2_FK on News (DevelopersID ASC)
go

/*==============================================================*/
/* Index: NewsSource3_FK                                        */
/*==============================================================*/




create nonclustered index NewsSource3_FK on News (PublisherID ASC)
go

/*==============================================================*/
/* Table: Player                                                */
/*==============================================================*/
create table Player (
   Username             char(20)             not null,
   Password             char(20)             not null,
   BindingEmail         char(30)             not null,
   BindingPhone         char(12)             not null,
   Question             char(20)             not null,
   Answer               char(20)             not null,
   SteamLvl             int                  not null default 0,
   constraint PK_PLAYER primary key (Username)
)
go

/*==============================================================*/
/* Table: PlayerAchieve                                         */
/*==============================================================*/
create table PlayerAchieve (
   Username             char(20)             not null,
   AchieveID            char(20)             not null,
   AchieveStatus        int                  not null 
      constraint CKC_ACHIEVESTATUS_PLAYERAC check (AchieveStatus in (0,1)),
   AchieveNow           int                  null,
   constraint PK_PLAYERACHIEVE primary key (Username, AchieveID)
)
go

/*==============================================================*/
/* Index: PlayerAchieve_FK                                      */
/*==============================================================*/




create nonclustered index PlayerAchieve_FK on PlayerAchieve (Username ASC)
go

/*==============================================================*/
/* Index: PlayerAchieve2_FK                                     */
/*==============================================================*/




create nonclustered index PlayerAchieve2_FK on PlayerAchieve (AchieveID ASC)
go

/*==============================================================*/
/* Table: PlayerEmblem                                          */
/*==============================================================*/
create table PlayerEmblem (
   Username             char(20)             not null,
   EmblemID             char(30)             not null,
   constraint PK_PLAYEREMBLEM primary key (Username, EmblemID)
)
go

/*==============================================================*/
/* Index: PlayerEmblem_FK                                       */
/*==============================================================*/




create nonclustered index PlayerEmblem_FK on PlayerEmblem (Username ASC)
go

/*==============================================================*/
/* Index: PlayerEmblem2_FK                                      */
/*==============================================================*/




create nonclustered index PlayerEmblem2_FK on PlayerEmblem (EmblemID ASC)
go

/*==============================================================*/
/* Table: PlayerTools                                           */
/*==============================================================*/
create table PlayerTools (
   ToolsID              char(20)             not null,
   Username             char(20)             not null,
   IsCollect            bit                  not null,
   TheLastTime          DateAndTime          null,
   IsDownload           bit                  not null,
   constraint PK_PLAYERTOOLS primary key (ToolsID, Username)
)
go

/*==============================================================*/
/* Index: PlayerTools_FK                                        */
/*==============================================================*/




create nonclustered index PlayerTools_FK on PlayerTools (ToolsID ASC)
go

/*==============================================================*/
/* Index: PlayerTools2_FK                                       */
/*==============================================================*/




create nonclustered index PlayerTools2_FK on PlayerTools (Username ASC)
go

/*==============================================================*/
/* Table: Publisher                                             */
/*==============================================================*/
create table Publisher (
   PublisherID          char(30)             not null,
   PublisherName        char(20)             not null,
   constraint PK_PUBLISHER primary key (PublisherID)
)
go

/*==============================================================*/
/* Table: SteamContain                                          */
/*==============================================================*/
create table SteamContain (
   ContainID            char(20)             not null,
   Username             char(20)             not null,
   GameID               char(20)             not null,
   ContainType          int                  not null,
   ContainAddr          char(256)            not null,
   constraint PK_STEAMCONTAIN primary key (ContainID)
)
go

/*==============================================================*/
/* Index: GameContain_FK                                        */
/*==============================================================*/




create nonclustered index GameContain_FK on SteamContain (GameID ASC)
go

/*==============================================================*/
/* Index: Own_FK                                                */
/*==============================================================*/




create nonclustered index Own_FK on SteamContain (Username ASC)
go

/*==============================================================*/
/* Table: Tools                                                 */
/*==============================================================*/
create table Tools (
   ToolsID              char(20)             not null,
   ToolsNAme            char(20)             not null,
   ToolsAddr            char(256)            not null,
   constraint PK_TOOLS primary key (ToolsID)
)
go

/*==============================================================*/
/* Table: UserGroup                                             */
/*==============================================================*/
create table UserGroup (
   GroupID              char(20)             not null,
   Username             char(20)             not null,
   GameID               char(20)             null,
   GroupName            char(20)             not null,
   GroupIntroduce       char(256)            not null,
   GroupCreateTime      DateAndTime          not null,
   constraint PK_USERGROUP primary key (GroupID)
)
go

/*==============================================================*/
/* Index: GroupCreate_FK                                        */
/*==============================================================*/




create nonclustered index GroupCreate_FK on UserGroup (Username ASC)
go

/*==============================================================*/
/* Index: GameGroup_FK                                          */
/*==============================================================*/




create nonclustered index GameGroup_FK on UserGroup (GameID ASC)
go

alter table Achievement
   add constraint FK_ACHIEVEM_ACHIEVEBE_GAME foreign key (GameID)
      references Game (GameID)
go

alter table BG
   add constraint FK_BG_BGBELONG_GAME foreign key (GameID)
      references Game (GameID)
go

alter table BGInventory
   add constraint FK_BGINVENT_BGINVENTO_PLAYER foreign key (Username)
      references Player (Username)
go

alter table BGInventory
   add constraint FK_BGINVENT_BGINVENTO_BG foreign key (BGID)
      references BG (BGID)
go

alter table BelongTo
   add constraint FK_BELONGTO_BELONGTO_USERGROU foreign key (GroupID)
      references UserGroup (GroupID)
go

alter table BelongTo
   add constraint FK_BELONGTO_BELONGTO2_PLAYER foreign key (Username)
      references Player (Username)
go

alter table Card
   add constraint FK_CARD_CARDBELON_GAME foreign key (GameID)
      references Game (GameID)
go

alter table CardInventory
   add constraint FK_CARDINVE_CARDINVEN_PLAYER foreign key (Username)
      references Player (Username)
go

alter table CardInventory
   add constraint FK_CARDINVE_CARDINVEN_CARD foreign key (CardID)
      references Card (CardID)
go

alter table CloudSaves
   add constraint FK_CLOUDSAV_GAMESAVE_GAME foreign key (GameID)
      references Game (GameID)
go

alter table CloudSaves
   add constraint FK_CLOUDSAV_UPLOADSAV_PLAYER foreign key (Username)
      references Player (Username)
go

alter table CompoundEmblem
   add constraint FK_COMPOUND_COMPOUNDE_EMBLEM foreign key (EmblemID)
      references Emblem (EmblemID)
go

alter table CompoundEmblem
   add constraint FK_COMPOUND_COMPOUNDE_CARD foreign key (CardID)
      references Card (CardID)
go

alter table DLC
   add constraint FK_DLC_DCLBELONG_GAME foreign key (GameID)
      references Game (GameID)
go

alter table DLC
   add constraint FK_DLC_DEVELOPDL_DEVELOPE foreign key (DevelopersID)
      references Developers (DevelopersID)
go

alter table DLC
   add constraint FK_DLC_PUBLISHDL_PUBLISHE foreign key (PublisherID)
      references Publisher (PublisherID)
go

alter table DLCLib
   add constraint FK_DLCLIB_DLCLIB_PLAYER foreign key (Username)
      references Player (Username)
go

alter table DLCLib
   add constraint FK_DLCLIB_DLCLIB2_DLC foreign key (DLCID)
      references DLC (DLCID)
go

alter table Deal
   add constraint FK_DEAL_DEALA_PLAYER foreign key (Username)
      references Player (Username)
go

alter table Deal
   add constraint FK_DEAL_DEALB_PLAYER foreign key (Pla_Username)
      references Player (Username)
go

alter table Deal
   add constraint FK_DEAL_DEALITAM1_BG foreign key (BGID)
      references BG (BGID)
go

alter table Deal
   add constraint FK_DEAL_DEALITEM2_CARD foreign key (CardID)
      references Card (CardID)
go

alter table Discuss
   add constraint FK_DISCUSS_DISCUSSAU_PLAYER foreign key (Username)
      references Player (Username)
go

alter table Discuss
   add constraint FK_DISCUSS_DISCUSSDI_DISCUSS foreign key (Dis_DiscussID)
      references Discuss (DiscussID)
go

alter table Discuss
   add constraint FK_DISCUSS_DISCUSSDY_DYNAMIC foreign key (DynamicID)
      references Dynamic (DynamicID)
go

alter table Discuss
   add constraint FK_DISCUSS_DISCUSSEV_EVALUATI foreign key (EvaluationID)
      references Evaluation (EvaluationID)
go

alter table Dynamic
   add constraint FK_DYNAMIC_CONTAINSH_STEAMCON foreign key (ContainID)
      references SteamContain (ContainID)
go

alter table Dynamic
   add constraint FK_DYNAMIC_PUBLISHDY_PLAYER foreign key (Username)
      references Player (Username)
go

alter table Emblem
   add constraint FK_EMBLEM_EMBLEMBEL_GAME foreign key (GameID)
      references Game (GameID)
go

alter table Evaluation
   add constraint FK_EVALUATI_ABOUTDLC_DLC foreign key (DLCID)
      references DLC (DLCID)
go

alter table Evaluation
   add constraint FK_EVALUATI_ABOUTGAME_GAME foreign key (GameID)
      references Game (GameID)
go

alter table Evaluation
   add constraint FK_EVALUATI_AUTHOR_PLAYER foreign key (Username)
      references Player (Username)
go

alter table Forum
   add constraint FK_FORUM_FORUMAUTH_PLAYER foreign key (Username)
      references Player (Username)
go

alter table Forum
   add constraint FK_FORUM_OTHERTHEM_IDEAPROD foreign key (ProductID)
      references IdeaProduct (ProductID)
go

alter table Friend
   add constraint FK_FRIEND_FRIEND_PLAYER foreign key (Username)
      references Player (Username)
go

alter table Friend
   add constraint FK_FRIEND_FRIEND2_PLAYER foreign key (Pla_Username)
      references Player (Username)
go

alter table Game
   add constraint FK_GAME_DEVELOPGA_DEVELOPE foreign key (DevelopersID)
      references Developers (DevelopersID)
go

alter table Game
   add constraint FK_GAME_PUBLISHGA_PUBLISHE foreign key (PublisherID)
      references Publisher (PublisherID)
go

alter table GameLib
   add constraint FK_GAMELIB_GAMELIB_PLAYER foreign key (Username)
      references Player (Username)
go

alter table GameLib
   add constraint FK_GAMELIB_GAMELIB2_GAME foreign key (GameID)
      references Game (GameID)
go

alter table GameWish
   add constraint FK_GAMEWISH_GAMEWISH_PLAYER foreign key (Username)
      references Player (Username)
go

alter table GameWish
   add constraint FK_GAMEWISH_GAMEWISH2_GAME foreign key (GameID)
      references Game (GameID)
go

alter table Guide
   add constraint FK_GUIDE_GAMEGUIDE_GAME foreign key (GameID)
      references Game (GameID)
go

alter table Guide
   add constraint FK_GUIDE_GUIDEAUTH_PLAYER foreign key (Username)
      references Player (Username)
go

alter table IdeaProduct
   add constraint FK_IDEAPROD_GAMEIDEA_GAME foreign key (GameID)
      references Game (GameID)
go

alter table IdeaProduct
   add constraint FK_IDEAPROD_IDEACREAT_PLAYER foreign key (Username)
      references Player (Username)
go

alter table Message
   add constraint FK_MESSAGE_FORUMMESS_FORUM foreign key (ForumID)
      references Forum (ForumID)
go

alter table Message
   add constraint FK_MESSAGE_MESSAGEAU_PLAYER foreign key (Username)
      references Player (Username)
go

alter table Message
   add constraint FK_MESSAGE_MESSAGEME_MESSAGE foreign key (Mes_MessageID)
      references Message (MessageID)
go

alter table News
   add constraint FK_NEWS_NEWSSOURC_GAME foreign key (GameID)
      references Game (GameID)
go

alter table News
   add constraint FK_NEWS_NEWSSOURC_DEVELOPE foreign key (DevelopersID)
      references Developers (DevelopersID)
go

alter table News
   add constraint FK_NEWS_NEWSSOURC_PUBLISHE foreign key (PublisherID)
      references Publisher (PublisherID)
go

alter table PlayerAchieve
   add constraint FK_PLAYERAC_PLAYERACH_PLAYER foreign key (Username)
      references Player (Username)
go

alter table PlayerAchieve
   add constraint FK_PLAYERAC_PLAYERACH_ACHIEVEM foreign key (AchieveID)
      references Achievement (AchieveID)
go

alter table PlayerEmblem
   add constraint FK_PLAYEREM_PLAYEREMB_PLAYER foreign key (Username)
      references Player (Username)
go

alter table PlayerEmblem
   add constraint FK_PLAYEREM_PLAYEREMB_EMBLEM foreign key (EmblemID)
      references Emblem (EmblemID)
go

alter table PlayerTools
   add constraint FK_PLAYERTO_PLAYERTOO_TOOLS foreign key (ToolsID)
      references Tools (ToolsID)
go

alter table PlayerTools
   add constraint FK_PLAYERTO_PLAYERTOO_PLAYER foreign key (Username)
      references Player (Username)
go

alter table SteamContain
   add constraint FK_STEAMCON_GAMECONTA_GAME foreign key (GameID)
      references Game (GameID)
go

alter table SteamContain
   add constraint FK_STEAMCON_OWN_PLAYER foreign key (Username)
      references Player (Username)
go

alter table UserGroup
   add constraint FK_USERGROU_GAMEGROUP_GAME foreign key (GameID)
      references Game (GameID)
go

alter table UserGroup
   add constraint FK_USERGROU_GROUPCREA_PLAYER foreign key (Username)
      references Player (Username)
go


create database MidTest;
go

USE [MidTest]
GO
/****** Object:  Table [dbo].[dstbl_lotteryds]    Script Date: 2017/11/29 10:15:55 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[dstbl_lotteryds](
	[dslotterytimeds] [varchar](10) NOT NULL,
	[dslotteryidds] [varchar](8) NULL,
	[dsred1ds] [varchar](2) NULL,
	[dsred2ds] [varchar](2) NULL,
	[dsred3ds] [varchar](2) NULL,
	[dsred4ds] [varchar](2) NULL,
	[dsred5ds] [varchar](2) NULL,
	[dsred6ds] [varchar](2) NULL,
	[dsblueds] [varchar](2) NULL,
PRIMARY KEY CLUSTERED 
(
	[dslotterytimeds] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-02-23', N'2003001', N'10', N'11', N'12', N'13', N'26', N'28', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-02-27', N'2003002', N'04', N'09', N'19', N'20', N'21', N'26', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-03-02', N'2003003', N'01', N'07', N'10', N'23', N'28', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-03-06', N'2003004', N'04', N'06', N'07', N'10', N'13', N'25', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-03-09', N'2003005', N'04', N'06', N'15', N'17', N'30', N'31', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-03-13', N'2003006', N'01', N'03', N'10', N'21', N'26', N'27', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-03-16', N'2003007', N'01', N'09', N'19', N'21', N'23', N'26', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-03-20', N'2003008', N'05', N'08', N'09', N'14', N'17', N'23', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-03-23', N'2003009', N'05', N'09', N'18', N'20', N'22', N'30', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-03-27', N'2003010', N'01', N'02', N'08', N'13', N'17', N'24', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-03-30', N'2003011', N'04', N'05', N'11', N'12', N'30', N'32', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-04-03', N'2003012', N'02', N'12', N'16', N'17', N'27', N'30', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-04-06', N'2003013', N'08', N'13', N'17', N'21', N'23', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-04-10', N'2003014', N'03', N'05', N'07', N'08', N'21', N'31', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-04-13', N'2003015', N'04', N'11', N'19', N'25', N'26', N'32', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-04-17', N'2003016', N'11', N'17', N'28', N'30', N'31', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-04-20', N'2003017', N'05', N'08', N'18', N'23', N'25', N'31', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-04-24', N'2003018', N'05', N'16', N'19', N'20', N'25', N'28', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-04-27', N'2003019', N'04', N'08', N'12', N'13', N'16', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-05-01', N'2003020', N'07', N'10', N'25', N'26', N'27', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-05-04', N'2003021', N'14', N'15', N'18', N'25', N'26', N'30', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-05-08', N'2003022', N'02', N'07', N'11', N'12', N'14', N'32', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-05-11', N'2003023', N'01', N'10', N'20', N'22', N'26', N'31', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-05-15', N'2003024', N'02', N'07', N'15', N'17', N'22', N'30', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-05-18', N'2003025', N'01', N'05', N'11', N'13', N'14', N'27', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-05-22', N'2003026', N'08', N'13', N'15', N'26', N'29', N'31', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-05-25', N'2003027', N'01', N'11', N'14', N'17', N'27', N'28', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-05-29', N'2003028', N'06', N'13', N'16', N'20', N'28', N'32', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-06-01', N'2003029', N'02', N'07', N'15', N'26', N'29', N'32', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-06-05', N'2003030', N'02', N'06', N'13', N'14', N'23', N'27', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-06-08', N'2003031', N'11', N'17', N'20', N'22', N'28', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-06-12', N'2003032', N'04', N'11', N'25', N'27', N'29', N'30', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-06-15', N'2003033', N'01', N'07', N'14', N'20', N'27', N'30', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-06-19', N'2003034', N'08', N'13', N'14', N'16', N'23', N'25', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-06-22', N'2003035', N'03', N'04', N'05', N'08', N'10', N'11', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-06-26', N'2003036', N'07', N'21', N'24', N'25', N'27', N'28', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-06-29', N'2003037', N'09', N'14', N'17', N'18', N'26', N'32', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-07-03', N'2003038', N'05', N'07', N'08', N'24', N'25', N'27', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-07-06', N'2003039', N'03', N'05', N'23', N'24', N'27', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-07-10', N'2003040', N'04', N'05', N'06', N'12', N'14', N'23', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-07-13', N'2003041', N'02', N'03', N'17', N'18', N'24', N'25', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-07-17', N'2003042', N'03', N'05', N'07', N'10', N'15', N'20', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-07-20', N'2003043', N'02', N'08', N'10', N'19', N'20', N'32', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-07-24', N'2003044', N'02', N'05', N'09', N'16', N'32', N'33', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-07-27', N'2003045', N'03', N'07', N'14', N'15', N'17', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-07-31', N'2003046', N'07', N'08', N'10', N'11', N'17', N'26', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-08-03', N'2003047', N'03', N'17', N'26', N'28', N'32', N'33', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-08-07', N'2003048', N'10', N'12', N'20', N'28', N'30', N'31', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-08-10', N'2003049', N'03', N'06', N'07', N'13', N'24', N'25', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-08-14', N'2003050', N'02', N'08', N'17', N'23', N'24', N'26', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-08-17', N'2003051', N'04', N'13', N'15', N'17', N'24', N'27', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-08-21', N'2003052', N'01', N'12', N'13', N'23', N'30', N'31', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-08-24', N'2003053', N'15', N'19', N'20', N'21', N'28', N'29', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-08-28', N'2003054', N'02', N'05', N'09', N'21', N'31', N'33', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-08-31', N'2003055', N'06', N'13', N'16', N'21', N'28', N'31', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-09-04', N'2003056', N'08', N'17', N'21', N'26', N'28', N'29', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-09-07', N'2003057', N'18', N'19', N'24', N'25', N'30', N'31', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-09-11', N'2003058', N'09', N'11', N'16', N'28', N'32', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-09-14', N'2003059', N'02', N'03', N'05', N'06', N'18', N'30', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-09-18', N'2003060', N'02', N'04', N'06', N'17', N'21', N'28', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-09-21', N'2003061', N'03', N'05', N'20', N'21', N'28', N'32', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-09-25', N'2003062', N'01', N'06', N'12', N'19', N'20', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-09-28', N'2003063', N'05', N'08', N'09', N'14', N'21', N'33', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-10-02', N'2003064', N'04', N'06', N'08', N'12', N'15', N'30', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-10-05', N'2003065', N'06', N'15', N'16', N'17', N'30', N'33', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-10-09', N'2003066', N'03', N'07', N'08', N'20', N'24', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-10-12', N'2003067', N'05', N'11', N'12', N'13', N'27', N'31', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-10-16', N'2003068', N'09', N'19', N'25', N'27', N'32', N'33', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-10-19', N'2003069', N'07', N'11', N'16', N'19', N'26', N'28', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-10-23', N'2003070', N'01', N'02', N'04', N'17', N'18', N'19', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-10-26', N'2003071', N'09', N'11', N'12', N'14', N'15', N'33', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-10-30', N'2003072', N'03', N'06', N'08', N'11', N'19', N'27', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-11-02', N'2003073', N'02', N'12', N'14', N'21', N'23', N'30', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-11-06', N'2003074', N'02', N'12', N'19', N'22', N'27', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-11-09', N'2003075', N'16', N'17', N'19', N'22', N'31', N'33', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-11-13', N'2003076', N'01', N'13', N'16', N'18', N'20', N'29', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-11-16', N'2003077', N'04', N'12', N'16', N'22', N'24', N'25', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-11-20', N'2003078', N'07', N'12', N'23', N'26', N'29', N'30', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-11-23', N'2003079', N'12', N'15', N'22', N'23', N'26', N'31', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-11-27', N'2003080', N'09', N'20', N'24', N'25', N'28', N'30', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-11-30', N'2003081', N'01', N'02', N'14', N'26', N'29', N'30', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-12-04', N'2003082', N'07', N'17', N'18', N'19', N'30', N'31', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-12-07', N'2003083', N'01', N'03', N'14', N'18', N'26', N'28', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-12-11', N'2003084', N'02', N'06', N'07', N'10', N'17', N'33', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-12-14', N'2003085', N'01', N'04', N'11', N'12', N'19', N'27', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-12-18', N'2003086', N'05', N'12', N'16', N'18', N'26', N'30', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-12-21', N'2003087', N'02', N'03', N'04', N'05', N'24', N'28', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-12-25', N'2003088', N'03', N'10', N'21', N'22', N'24', N'33', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2003-12-28', N'2003089', N'18', N'19', N'21', N'26', N'27', N'33', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-01-01', N'2004001', N'01', N'02', N'03', N'07', N'10', N'25', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-01-04', N'2004002', N'10', N'12', N'18', N'22', N'30', N'31', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-01-08', N'2004003', N'03', N'05', N'06', N'17', N'26', N'33', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-01-11', N'2004004', N'10', N'19', N'22', N'23', N'25', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-01-15', N'2004005', N'09', N'11', N'13', N'16', N'17', N'18', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-01-18', N'2004006', N'04', N'12', N'18', N'20', N'23', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-01-29', N'2004007', N'04', N'12', N'17', N'20', N'25', N'28', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-02-01', N'2004008', N'01', N'07', N'10', N'22', N'32', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-02-05', N'2004009', N'01', N'09', N'10', N'16', N'22', N'24', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-02-08', N'2004010', N'06', N'07', N'08', N'13', N'14', N'19', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-02-12', N'2004011', N'01', N'04', N'13', N'23', N'28', N'30', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-02-15', N'2004012', N'01', N'07', N'27', N'30', N'31', N'33', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-02-19', N'2004013', N'12', N'14', N'21', N'29', N'30', N'32', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-02-22', N'2004014', N'03', N'07', N'11', N'17', N'20', N'26', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-02-26', N'2004015', N'01', N'03', N'05', N'18', N'22', N'23', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-02-29', N'2004016', N'04', N'07', N'08', N'28', N'30', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-03-04', N'2004017', N'05', N'12', N'14', N'15', N'25', N'31', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-03-07', N'2004018', N'02', N'05', N'06', N'08', N'28', N'30', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-03-11', N'2004019', N'05', N'10', N'11', N'23', N'24', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-03-14', N'2004020', N'01', N'02', N'09', N'22', N'28', N'31', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-03-18', N'2004021', N'05', N'09', N'11', N'17', N'26', N'27', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-03-21', N'2004022', N'03', N'10', N'14', N'19', N'20', N'30', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-03-25', N'2004023', N'01', N'08', N'14', N'17', N'19', N'30', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-03-28', N'2004024', N'01', N'13', N'21', N'23', N'25', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-04-01', N'2004025', N'07', N'08', N'10', N'24', N'29', N'33', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-04-04', N'2004026', N'04', N'10', N'14', N'18', N'28', N'32', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-04-08', N'2004027', N'01', N'05', N'09', N'10', N'18', N'32', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-04-11', N'2004028', N'01', N'02', N'03', N'05', N'10', N'22', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-04-15', N'2004029', N'09', N'13', N'20', N'22', N'24', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-04-18', N'2004030', N'01', N'07', N'09', N'17', N'26', N'31', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-04-22', N'2004031', N'03', N'06', N'19', N'20', N'21', N'24', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-04-25', N'2004032', N'02', N'05', N'08', N'11', N'15', N'31', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-04-29', N'2004033', N'01', N'04', N'08', N'09', N'19', N'20', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-05-02', N'2004034', N'02', N'07', N'13', N'20', N'27', N'30', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-05-06', N'2004035', N'02', N'08', N'26', N'27', N'30', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-05-09', N'2004036', N'02', N'13', N'17', N'18', N'26', N'30', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-05-13', N'2004037', N'03', N'04', N'11', N'17', N'20', N'26', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-05-16', N'2004038', N'11', N'16', N'17', N'25', N'28', N'29', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-05-20', N'2004039', N'10', N'16', N'18', N'25', N'26', N'29', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-05-23', N'2004040', N'07', N'17', N'19', N'20', N'21', N'29', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-05-27', N'2004041', N'08', N'10', N'17', N'22', N'25', N'29', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-05-30', N'2004042', N'06', N'10', N'13', N'17', N'18', N'21', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-06-03', N'2004043', N'04', N'09', N'10', N'21', N'22', N'24', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-06-06', N'2004044', N'02', N'06', N'07', N'12', N'31', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-06-10', N'2004045', N'01', N'12', N'18', N'26', N'27', N'28', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-06-13', N'2004046', N'07', N'15', N'16', N'22', N'23', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-06-17', N'2004047', N'01', N'07', N'08', N'11', N'27', N'31', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-06-20', N'2004048', N'08', N'09', N'11', N'16', N'17', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-06-24', N'2004049', N'11', N'12', N'14', N'16', N'25', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-06-27', N'2004050', N'06', N'07', N'19', N'21', N'25', N'29', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-07-01', N'2004051', N'02', N'03', N'09', N'10', N'15', N'29', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-07-04', N'2004052', N'01', N'12', N'14', N'15', N'17', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-07-08', N'2004053', N'02', N'03', N'04', N'09', N'24', N'25', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-07-11', N'2004054', N'09', N'11', N'14', N'16', N'27', N'28', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-07-15', N'2004055', N'06', N'08', N'19', N'25', N'29', N'32', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-07-18', N'2004056', N'01', N'20', N'21', N'25', N'29', N'30', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-07-22', N'2004057', N'05', N'21', N'23', N'25', N'28', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-07-25', N'2004058', N'01', N'08', N'11', N'12', N'27', N'31', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-07-29', N'2004059', N'04', N'07', N'11', N'19', N'23', N'26', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-08-01', N'2004060', N'03', N'05', N'11', N'24', N'27', N'28', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-08-05', N'2004061', N'13', N'16', N'19', N'20', N'23', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-08-08', N'2004062', N'01', N'12', N'25', N'27', N'28', N'29', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-08-12', N'2004063', N'07', N'10', N'13', N'16', N'27', N'28', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-08-15', N'2004064', N'14', N'15', N'18', N'20', N'27', N'31', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-08-19', N'2004065', N'13', N'14', N'27', N'29', N'32', N'33', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-08-22', N'2004066', N'05', N'13', N'20', N'23', N'24', N'25', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-08-24', N'2004067', N'01', N'06', N'07', N'13', N'16', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-08-26', N'2004068', N'02', N'08', N'11', N'13', N'24', N'31', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-08-29', N'2004069', N'02', N'11', N'15', N'20', N'22', N'29', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-08-31', N'2004070', N'10', N'12', N'21', N'22', N'30', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-09-02', N'2004071', N'03', N'08', N'16', N'17', N'21', N'29', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-09-05', N'2004072', N'08', N'15', N'18', N'28', N'30', N'33', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-09-07', N'2004073', N'02', N'07', N'13', N'16', N'23', N'28', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-09-09', N'2004074', N'05', N'06', N'15', N'19', N'26', N'29', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-09-12', N'2004075', N'07', N'18', N'21', N'26', N'27', N'28', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-09-14', N'2004076', N'03', N'05', N'13', N'17', N'25', N'31', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-09-16', N'2004077', N'08', N'09', N'10', N'14', N'16', N'26', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-09-19', N'2004078', N'04', N'05', N'10', N'21', N'24', N'26', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-09-21', N'2004079', N'07', N'13', N'14', N'17', N'19', N'30', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-09-24', N'2004080', N'03', N'08', N'20', N'23', N'24', N'26', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-09-26', N'2004081', N'03', N'05', N'21', N'24', N'27', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-09-28', N'2004082', N'03', N'20', N'24', N'27', N'29', N'30', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-09-30', N'2004083', N'14', N'16', N'27', N'28', N'30', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-10-03', N'2004084', N'01', N'04', N'08', N'11', N'21', N'25', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-10-05', N'2004085', N'03', N'08', N'11', N'29', N'30', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-10-07', N'2004086', N'10', N'13', N'18', N'19', N'25', N'27', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-10-10', N'2004087', N'01', N'03', N'07', N'08', N'25', N'26', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-10-12', N'2004088', N'02', N'10', N'19', N'22', N'24', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-10-14', N'2004089', N'14', N'17', N'20', N'25', N'28', N'30', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-10-17', N'2004090', N'01', N'18', N'20', N'24', N'32', N'33', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-10-19', N'2004091', N'09', N'13', N'14', N'21', N'30', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-10-21', N'2004092', N'01', N'04', N'08', N'13', N'28', N'31', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-10-24', N'2004093', N'11', N'14', N'20', N'27', N'32', N'33', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-10-26', N'2004094', N'05', N'09', N'10', N'13', N'24', N'25', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-10-28', N'2004095', N'19', N'22', N'27', N'28', N'30', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-10-31', N'2004096', N'01', N'04', N'12', N'16', N'20', N'30', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-11-02', N'2004097', N'10', N'19', N'20', N'26', N'29', N'31', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-11-04', N'2004098', N'03', N'12', N'13', N'25', N'26', N'31', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-11-07', N'2004099', N'05', N'10', N'21', N'22', N'26', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-11-09', N'2004100', N'06', N'08', N'09', N'14', N'24', N'33', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-11-11', N'2004101', N'02', N'09', N'14', N'19', N'25', N'26', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-11-14', N'2004102', N'03', N'09', N'12', N'15', N'28', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-11-16', N'2004103', N'02', N'03', N'05', N'09', N'16', N'21', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-11-18', N'2004104', N'07', N'11', N'17', N'18', N'24', N'29', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-11-21', N'2004105', N'07', N'09', N'10', N'21', N'23', N'30', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-11-23', N'2004106', N'10', N'15', N'23', N'26', N'28', N'29', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-11-25', N'2004107', N'01', N'08', N'12', N'13', N'18', N'20', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-11-28', N'2004108', N'08', N'13', N'14', N'27', N'28', N'31', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-11-30', N'2004109', N'06', N'08', N'10', N'17', N'30', N'31', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-12-02', N'2004110', N'14', N'19', N'20', N'21', N'22', N'31', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-12-05', N'2004111', N'11', N'16', N'18', N'20', N'26', N'31', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-12-07', N'2004112', N'09', N'13', N'15', N'21', N'26', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-12-09', N'2004113', N'08', N'10', N'23', N'25', N'31', N'32', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-12-12', N'2004114', N'01', N'06', N'09', N'17', N'21', N'22', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-12-14', N'2004115', N'02', N'16', N'20', N'30', N'31', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-12-16', N'2004116', N'01', N'03', N'05', N'08', N'14', N'33', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-12-19', N'2004117', N'01', N'03', N'07', N'14', N'24', N'25', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-12-21', N'2004118', N'03', N'04', N'07', N'12', N'30', N'31', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-12-23', N'2004119', N'06', N'09', N'18', N'20', N'25', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-12-26', N'2004120', N'07', N'08', N'18', N'21', N'27', N'32', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-12-28', N'2004121', N'07', N'13', N'16', N'18', N'30', N'32', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2004-12-30', N'2004122', N'03', N'11', N'14', N'22', N'24', N'31', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-01-02', N'2005001', N'01', N'07', N'08', N'23', N'27', N'28', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-01-04', N'2005002', N'06', N'09', N'20', N'26', N'28', N'33', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-01-06', N'2005003', N'09', N'12', N'15', N'19', N'22', N'31', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-01-09', N'2005004', N'01', N'04', N'08', N'09', N'22', N'23', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-01-11', N'2005005', N'05', N'09', N'20', N'26', N'28', N'33', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-01-13', N'2005006', N'02', N'04', N'05', N'15', N'21', N'31', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-01-16', N'2005007', N'07', N'15', N'17', N'20', N'23', N'33', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-01-18', N'2005008', N'11', N'19', N'22', N'27', N'32', N'33', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-01-20', N'2005009', N'02', N'17', N'22', N'27', N'29', N'31', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-01-23', N'2005010', N'08', N'10', N'11', N'18', N'25', N'26', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-01-25', N'2005011', N'09', N'11', N'13', N'15', N'22', N'30', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-01-27', N'2005012', N'02', N'03', N'06', N'16', N'22', N'31', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-01-30', N'2005013', N'07', N'08', N'16', N'19', N'20', N'24', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-02-01', N'2005014', N'13', N'19', N'21', N'23', N'30', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-02-03', N'2005015', N'04', N'08', N'09', N'16', N'17', N'29', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-02-06', N'2005016', N'01', N'05', N'06', N'12', N'16', N'30', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-02-08', N'2005017', N'02', N'06', N'10', N'25', N'27', N'31', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-02-17', N'2005018', N'01', N'03', N'06', N'22', N'23', N'25', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-02-20', N'2005019', N'06', N'11', N'12', N'13', N'19', N'22', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-02-22', N'2005020', N'14', N'16', N'19', N'20', N'25', N'29', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-02-24', N'2005021', N'02', N'06', N'24', N'26', N'30', N'31', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-02-27', N'2005022', N'08', N'10', N'12', N'21', N'32', N'33', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-03-01', N'2005023', N'10', N'15', N'19', N'20', N'21', N'25', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-03-03', N'2005024', N'05', N'09', N'14', N'27', N'31', N'32', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-03-06', N'2005025', N'01', N'07', N'10', N'11', N'13', N'32', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-03-08', N'2005026', N'06', N'12', N'14', N'20', N'25', N'26', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-03-10', N'2005027', N'01', N'03', N'04', N'06', N'21', N'32', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-03-13', N'2005028', N'04', N'09', N'22', N'25', N'26', N'32', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-03-15', N'2005029', N'02', N'14', N'21', N'22', N'27', N'30', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-03-17', N'2005030', N'01', N'05', N'09', N'14', N'22', N'28', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-03-20', N'2005031', N'04', N'10', N'16', N'20', N'23', N'32', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-03-22', N'2005032', N'05', N'15', N'19', N'20', N'25', N'29', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-03-24', N'2005033', N'07', N'08', N'12', N'14', N'19', N'20', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-03-27', N'2005034', N'05', N'17', N'18', N'25', N'28', N'32', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-03-29', N'2005035', N'12', N'16', N'21', N'28', N'29', N'30', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-03-31', N'2005036', N'12', N'19', N'20', N'21', N'26', N'31', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-04-03', N'2005037', N'07', N'12', N'14', N'22', N'24', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-04-05', N'2005038', N'04', N'07', N'11', N'20', N'27', N'28', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-04-07', N'2005039', N'02', N'16', N'18', N'19', N'21', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-04-10', N'2005040', N'01', N'12', N'21', N'24', N'30', N'32', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-04-12', N'2005041', N'02', N'11', N'16', N'23', N'24', N'29', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-04-14', N'2005042', N'11', N'16', N'21', N'26', N'27', N'30', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-04-17', N'2005043', N'04', N'05', N'06', N'07', N'08', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-04-19', N'2005044', N'01', N'06', N'16', N'17', N'18', N'22', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-04-21', N'2005045', N'01', N'07', N'10', N'15', N'18', N'20', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-04-24', N'2005046', N'09', N'16', N'18', N'20', N'22', N'24', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-04-26', N'2005047', N'02', N'03', N'05', N'07', N'08', N'27', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-04-28', N'2005048', N'06', N'07', N'08', N'10', N'16', N'28', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-05-01', N'2005049', N'02', N'03', N'08', N'10', N'25', N'27', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-05-03', N'2005050', N'02', N'09', N'12', N'20', N'26', N'32', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-05-05', N'2005051', N'03', N'06', N'14', N'19', N'20', N'21', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-05-08', N'2005052', N'01', N'02', N'14', N'17', N'30', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-05-10', N'2005053', N'04', N'07', N'10', N'14', N'27', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-05-12', N'2005054', N'05', N'13', N'17', N'18', N'21', N'29', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-05-15', N'2005055', N'05', N'20', N'22', N'30', N'32', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-05-17', N'2005056', N'12', N'17', N'19', N'27', N'29', N'31', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-05-19', N'2005057', N'05', N'06', N'10', N'15', N'30', N'31', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-05-22', N'2005058', N'04', N'06', N'10', N'21', N'25', N'26', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-05-24', N'2005059', N'07', N'11', N'14', N'18', N'24', N'29', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-05-26', N'2005060', N'09', N'12', N'21', N'25', N'31', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-05-29', N'2005061', N'05', N'09', N'14', N'21', N'23', N'24', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-05-31', N'2005062', N'02', N'07', N'11', N'12', N'20', N'23', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-06-02', N'2005063', N'02', N'11', N'13', N'18', N'22', N'30', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-06-04', N'2005064', N'10', N'18', N'23', N'27', N'30', N'32', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-06-07', N'2005065', N'12', N'16', N'17', N'21', N'22', N'23', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-06-09', N'2005066', N'02', N'04', N'10', N'11', N'25', N'28', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-06-12', N'2005067', N'03', N'12', N'16', N'20', N'21', N'26', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-06-14', N'2005068', N'01', N'08', N'10', N'13', N'25', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-06-16', N'2005069', N'07', N'09', N'21', N'24', N'31', N'33', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-06-19', N'2005070', N'03', N'04', N'08', N'14', N'16', N'26', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-06-21', N'2005071', N'04', N'08', N'12', N'14', N'16', N'22', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-06-23', N'2005072', N'06', N'10', N'19', N'20', N'24', N'33', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-06-26', N'2005073', N'01', N'06', N'08', N'09', N'18', N'20', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-06-28', N'2005074', N'06', N'09', N'18', N'20', N'26', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-06-30', N'2005075', N'11', N'13', N'14', N'16', N'18', N'31', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-07-03', N'2005076', N'04', N'09', N'11', N'22', N'25', N'28', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-07-05', N'2005077', N'08', N'17', N'22', N'24', N'32', N'33', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-07-07', N'2005078', N'03', N'11', N'15', N'20', N'26', N'32', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-07-10', N'2005079', N'03', N'09', N'20', N'24', N'25', N'28', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-07-12', N'2005080', N'01', N'12', N'14', N'26', N'27', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-07-14', N'2005081', N'02', N'04', N'10', N'12', N'26', N'30', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-07-17', N'2005082', N'01', N'07', N'11', N'14', N'19', N'20', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-07-19', N'2005083', N'03', N'05', N'09', N'14', N'16', N'30', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-07-21', N'2005084', N'01', N'02', N'07', N'15', N'19', N'20', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-07-24', N'2005085', N'08', N'09', N'13', N'14', N'20', N'22', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-07-26', N'2005086', N'07', N'11', N'12', N'24', N'27', N'29', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-07-28', N'2005087', N'08', N'09', N'15', N'16', N'23', N'26', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-07-31', N'2005088', N'01', N'03', N'07', N'18', N'20', N'24', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-08-02', N'2005089', N'05', N'19', N'20', N'23', N'26', N'31', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-08-04', N'2005090', N'01', N'09', N'21', N'25', N'29', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-08-07', N'2005091', N'01', N'11', N'12', N'15', N'26', N'27', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-08-09', N'2005092', N'08', N'13', N'19', N'26', N'28', N'31', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-08-11', N'2005093', N'04', N'06', N'17', N'23', N'25', N'29', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-08-14', N'2005094', N'03', N'05', N'09', N'23', N'27', N'33', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-08-16', N'2005095', N'09', N'12', N'18', N'21', N'28', N'29', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-08-18', N'2005096', N'04', N'05', N'17', N'18', N'26', N'33', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-08-21', N'2005097', N'05', N'10', N'23', N'27', N'28', N'30', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-08-23', N'2005098', N'12', N'15', N'19', N'22', N'31', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-08-25', N'2005099', N'10', N'13', N'16', N'22', N'24', N'31', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-08-28', N'2005100', N'02', N'04', N'09', N'14', N'16', N'31', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-08-30', N'2005101', N'09', N'16', N'19', N'21', N'22', N'24', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-09-01', N'2005102', N'02', N'05', N'06', N'14', N'24', N'31', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-09-04', N'2005103', N'04', N'07', N'16', N'18', N'23', N'30', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-09-06', N'2005104', N'02', N'04', N'21', N'23', N'30', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-09-08', N'2005105', N'04', N'15', N'23', N'30', N'32', N'33', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-09-11', N'2005106', N'01', N'11', N'13', N'24', N'26', N'31', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-09-13', N'2005107', N'09', N'10', N'20', N'24', N'25', N'26', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-09-15', N'2005108', N'03', N'10', N'12', N'24', N'29', N'30', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-09-18', N'2005109', N'03', N'05', N'13', N'15', N'17', N'31', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-09-20', N'2005110', N'07', N'10', N'16', N'19', N'24', N'25', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-09-22', N'2005111', N'03', N'07', N'15', N'16', N'19', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-09-25', N'2005112', N'04', N'12', N'22', N'28', N'29', N'30', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-09-27', N'2005113', N'15', N'18', N'20', N'22', N'26', N'27', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-09-29', N'2005114', N'06', N'07', N'10', N'15', N'21', N'27', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-10-02', N'2005115', N'03', N'12', N'18', N'23', N'30', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-10-04', N'2005116', N'04', N'06', N'08', N'14', N'15', N'30', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-10-06', N'2005117', N'06', N'17', N'22', N'27', N'28', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-10-09', N'2005118', N'04', N'09', N'12', N'15', N'26', N'31', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-10-11', N'2005119', N'01', N'07', N'11', N'18', N'20', N'22', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-10-13', N'2005120', N'01', N'06', N'13', N'18', N'30', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-10-16', N'2005121', N'01', N'07', N'20', N'25', N'31', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-10-18', N'2005122', N'01', N'04', N'07', N'14', N'30', N'32', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-10-20', N'2005123', N'11', N'12', N'13', N'17', N'18', N'25', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-10-23', N'2005124', N'05', N'06', N'10', N'19', N'31', N'33', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-10-25', N'2005125', N'06', N'14', N'18', N'28', N'31', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-10-27', N'2005126', N'02', N'08', N'13', N'19', N'25', N'26', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-10-30', N'2005127', N'04', N'06', N'11', N'14', N'23', N'25', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-11-01', N'2005128', N'02', N'04', N'14', N'23', N'29', N'33', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-11-03', N'2005129', N'05', N'10', N'14', N'20', N'27', N'33', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-11-06', N'2005130', N'03', N'05', N'09', N'15', N'20', N'25', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-11-08', N'2005131', N'02', N'07', N'10', N'11', N'12', N'24', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-11-10', N'2005132', N'02', N'04', N'10', N'18', N'27', N'29', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-11-13', N'2005133', N'01', N'07', N'14', N'16', N'18', N'25', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-11-15', N'2005134', N'04', N'13', N'14', N'18', N'26', N'30', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-11-17', N'2005135', N'01', N'05', N'13', N'15', N'21', N'25', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-11-20', N'2005136', N'05', N'14', N'16', N'18', N'25', N'27', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-11-22', N'2005137', N'03', N'09', N'15', N'23', N'25', N'33', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-11-24', N'2005138', N'03', N'05', N'06', N'11', N'20', N'22', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-11-27', N'2005139', N'02', N'07', N'20', N'23', N'32', N'33', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-11-29', N'2005140', N'04', N'06', N'07', N'08', N'12', N'17', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-12-01', N'2005141', N'03', N'05', N'08', N'12', N'16', N'19', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-12-04', N'2005142', N'07', N'10', N'12', N'17', N'22', N'29', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-12-06', N'2005143', N'03', N'10', N'15', N'17', N'20', N'32', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-12-08', N'2005144', N'01', N'08', N'14', N'15', N'19', N'27', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-12-11', N'2005145', N'03', N'07', N'08', N'17', N'20', N'28', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-12-13', N'2005146', N'07', N'11', N'19', N'20', N'24', N'28', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-12-15', N'2005147', N'06', N'07', N'15', N'27', N'28', N'30', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-12-18', N'2005148', N'03', N'15', N'17', N'23', N'24', N'29', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-12-20', N'2005149', N'11', N'16', N'21', N'23', N'25', N'32', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-12-22', N'2005150', N'03', N'07', N'10', N'14', N'18', N'20', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-12-25', N'2005151', N'04', N'11', N'12', N'13', N'19', N'30', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-12-27', N'2005152', N'01', N'05', N'12', N'14', N'21', N'27', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2005-12-29', N'2005153', N'04', N'05', N'07', N'21', N'26', N'29', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-01-01', N'2006001', N'01', N'12', N'15', N'19', N'21', N'28', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-01-03', N'2006002', N'07', N'13', N'16', N'21', N'26', N'28', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-01-05', N'2006003', N'02', N'04', N'05', N'06', N'16', N'20', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-01-08', N'2006004', N'04', N'08', N'17', N'27', N'28', N'31', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-01-10', N'2006005', N'03', N'19', N'20', N'24', N'26', N'27', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-01-12', N'2006006', N'08', N'21', N'22', N'23', N'26', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-01-15', N'2006007', N'04', N'16', N'18', N'27', N'32', N'33', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-01-17', N'2006008', N'03', N'05', N'09', N'18', N'28', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-01-19', N'2006009', N'05', N'06', N'08', N'20', N'26', N'30', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-01-22', N'2006010', N'04', N'06', N'12', N'19', N'27', N'29', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-01-24', N'2006011', N'05', N'07', N'08', N'14', N'27', N'31', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-01-26', N'2006012', N'09', N'11', N'13', N'27', N'31', N'33', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-02-05', N'2006013', N'01', N'05', N'06', N'12', N'16', N'21', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-02-07', N'2006014', N'06', N'14', N'26', N'29', N'32', N'33', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-02-09', N'2006015', N'02', N'03', N'09', N'15', N'29', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-02-12', N'2006016', N'01', N'07', N'13', N'17', N'23', N'30', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-02-14', N'2006017', N'03', N'04', N'08', N'31', N'32', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-02-16', N'2006018', N'01', N'13', N'14', N'17', N'24', N'26', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-02-19', N'2006019', N'04', N'06', N'13', N'22', N'26', N'32', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-02-21', N'2006020', N'05', N'09', N'21', N'23', N'26', N'29', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-02-23', N'2006021', N'01', N'02', N'05', N'20', N'21', N'22', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-02-26', N'2006022', N'02', N'03', N'04', N'13', N'16', N'27', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-02-28', N'2006023', N'04', N'13', N'14', N'19', N'23', N'28', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-03-02', N'2006024', N'02', N'07', N'09', N'11', N'21', N'27', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-03-05', N'2006025', N'03', N'04', N'17', N'19', N'24', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-03-07', N'2006026', N'01', N'02', N'18', N'22', N'29', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-03-09', N'2006027', N'06', N'08', N'11', N'14', N'16', N'27', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-03-12', N'2006028', N'05', N'07', N'14', N'16', N'17', N'27', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-03-14', N'2006029', N'03', N'04', N'07', N'09', N'14', N'19', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-03-16', N'2006030', N'08', N'13', N'15', N'17', N'20', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-03-19', N'2006031', N'03', N'10', N'12', N'16', N'31', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-03-21', N'2006032', N'05', N'18', N'20', N'24', N'26', N'31', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-03-23', N'2006033', N'15', N'20', N'22', N'23', N'27', N'31', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-03-26', N'2006034', N'02', N'10', N'15', N'16', N'17', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-03-28', N'2006035', N'03', N'09', N'13', N'21', N'27', N'29', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-03-30', N'2006036', N'04', N'07', N'10', N'16', N'17', N'21', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-04-02', N'2006037', N'02', N'12', N'23', N'24', N'25', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-04-04', N'2006038', N'02', N'14', N'17', N'19', N'22', N'30', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-04-06', N'2006039', N'16', N'19', N'22', N'28', N'31', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-04-09', N'2006040', N'15', N'22', N'25', N'26', N'28', N'33', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-04-11', N'2006041', N'03', N'10', N'16', N'18', N'21', N'28', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-04-13', N'2006042', N'03', N'16', N'23', N'26', N'28', N'31', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-04-16', N'2006043', N'05', N'12', N'13', N'16', N'23', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-04-18', N'2006044', N'02', N'10', N'18', N'21', N'30', N'31', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-04-20', N'2006045', N'06', N'07', N'10', N'14', N'20', N'21', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-04-23', N'2006046', N'13', N'18', N'23', N'29', N'31', N'32', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-04-25', N'2006047', N'02', N'17', N'20', N'22', N'28', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-04-27', N'2006048', N'09', N'13', N'19', N'25', N'29', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-04-30', N'2006049', N'06', N'10', N'12', N'13', N'17', N'20', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-05-01', N'2006050', N'02', N'06', N'12', N'15', N'25', N'31', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-05-04', N'2006051', N'02', N'06', N'07', N'17', N'27', N'30', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-05-07', N'2006052', N'11', N'24', N'26', N'27', N'30', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-05-09', N'2006053', N'01', N'11', N'17', N'27', N'28', N'31', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-05-11', N'2006054', N'03', N'05', N'07', N'10', N'28', N'30', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-05-14', N'2006055', N'04', N'05', N'28', N'29', N'31', N'33', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-05-16', N'2006056', N'11', N'13', N'15', N'21', N'23', N'25', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-05-18', N'2006057', N'03', N'04', N'17', N'18', N'21', N'31', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-05-21', N'2006058', N'01', N'12', N'22', N'23', N'24', N'25', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-05-23', N'2006059', N'05', N'10', N'15', N'17', N'27', N'29', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-05-25', N'2006060', N'05', N'15', N'19', N'23', N'30', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-05-28', N'2006061', N'05', N'13', N'17', N'19', N'25', N'30', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-05-30', N'2006062', N'18', N'22', N'23', N'24', N'26', N'30', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-06-01', N'2006063', N'04', N'05', N'15', N'21', N'23', N'24', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-06-04', N'2006064', N'03', N'12', N'14', N'21', N'24', N'28', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-06-06', N'2006065', N'04', N'08', N'17', N'28', N'29', N'30', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-06-08', N'2006066', N'06', N'08', N'11', N'18', N'30', N'33', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-06-11', N'2006067', N'07', N'08', N'11', N'16', N'17', N'24', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-06-13', N'2006068', N'03', N'07', N'10', N'14', N'30', N'33', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-06-15', N'2006069', N'05', N'16', N'20', N'22', N'29', N'30', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-06-18', N'2006070', N'02', N'03', N'11', N'13', N'20', N'27', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-06-20', N'2006071', N'05', N'11', N'12', N'19', N'29', N'31', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-06-22', N'2006072', N'02', N'03', N'05', N'20', N'21', N'24', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-06-25', N'2006073', N'05', N'13', N'16', N'18', N'27', N'29', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-06-27', N'2006074', N'01', N'03', N'15', N'19', N'25', N'33', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-06-29', N'2006075', N'10', N'21', N'22', N'23', N'25', N'33', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-07-02', N'2006076', N'04', N'10', N'17', N'21', N'29', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-07-04', N'2006077', N'08', N'09', N'12', N'13', N'19', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-07-06', N'2006078', N'03', N'05', N'17', N'22', N'31', N'33', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-07-09', N'2006079', N'06', N'11', N'13', N'17', N'20', N'32', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-07-11', N'2006080', N'15', N'17', N'20', N'22', N'26', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-07-13', N'2006081', N'14', N'16', N'18', N'21', N'22', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-07-16', N'2006082', N'03', N'13', N'15', N'23', N'28', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-07-18', N'2006083', N'07', N'09', N'18', N'19', N'26', N'29', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-07-20', N'2006084', N'01', N'12', N'17', N'21', N'25', N'28', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-07-23', N'2006085', N'02', N'06', N'18', N'21', N'24', N'25', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-07-25', N'2006086', N'04', N'06', N'10', N'24', N'26', N'31', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-07-27', N'2006087', N'04', N'05', N'08', N'09', N'12', N'30', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-07-30', N'2006088', N'03', N'11', N'20', N'24', N'25', N'26', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-08-01', N'2006089', N'01', N'13', N'16', N'18', N'19', N'22', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-08-03', N'2006090', N'02', N'11', N'15', N'20', N'23', N'29', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-08-06', N'2006091', N'07', N'08', N'12', N'21', N'22', N'24', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-08-08', N'2006092', N'02', N'08', N'11', N'16', N'20', N'21', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-08-10', N'2006093', N'02', N'12', N'16', N'18', N'19', N'23', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-08-13', N'2006094', N'15', N'16', N'17', N'18', N'24', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-08-15', N'2006095', N'01', N'03', N'17', N'20', N'21', N'29', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-08-17', N'2006096', N'01', N'05', N'09', N'13', N'18', N'33', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-08-20', N'2006097', N'11', N'14', N'15', N'20', N'26', N'27', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-08-22', N'2006098', N'06', N'07', N'10', N'11', N'18', N'23', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-08-24', N'2006099', N'09', N'12', N'18', N'23', N'24', N'27', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-08-27', N'2006100', N'01', N'11', N'18', N'26', N'30', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-08-29', N'2006101', N'09', N'12', N'20', N'26', N'27', N'28', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-08-31', N'2006102', N'01', N'04', N'13', N'19', N'20', N'24', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-09-03', N'2006103', N'12', N'14', N'15', N'25', N'28', N'31', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-09-05', N'2006104', N'03', N'07', N'22', N'27', N'28', N'31', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-09-07', N'2006105', N'05', N'12', N'14', N'15', N'20', N'31', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-09-10', N'2006106', N'02', N'12', N'14', N'19', N'28', N'33', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-09-12', N'2006107', N'01', N'06', N'08', N'13', N'17', N'30', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-09-14', N'2006108', N'02', N'06', N'08', N'20', N'24', N'30', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-09-17', N'2006109', N'01', N'05', N'17', N'18', N'23', N'26', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-09-19', N'2006110', N'09', N'12', N'14', N'18', N'27', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-09-21', N'2006111', N'01', N'08', N'11', N'16', N'17', N'22', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-09-24', N'2006112', N'04', N'09', N'13', N'15', N'31', N'33', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-09-26', N'2006113', N'05', N'14', N'17', N'18', N'28', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-09-28', N'2006114', N'08', N'10', N'14', N'20', N'27', N'29', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-10-01', N'2006115', N'01', N'10', N'20', N'26', N'28', N'29', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-10-03', N'2006116', N'05', N'16', N'21', N'22', N'32', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-10-05', N'2006117', N'06', N'14', N'20', N'22', N'23', N'26', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-10-08', N'2006118', N'01', N'03', N'07', N'08', N'10', N'30', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-10-10', N'2006119', N'01', N'02', N'14', N'20', N'27', N'30', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-10-12', N'2006120', N'06', N'08', N'14', N'15', N'24', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-10-15', N'2006121', N'03', N'04', N'06', N'27', N'31', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-10-17', N'2006122', N'04', N'05', N'06', N'08', N'22', N'24', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-10-19', N'2006123', N'02', N'03', N'20', N'25', N'28', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-10-22', N'2006124', N'12', N'13', N'14', N'18', N'31', N'32', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-10-24', N'2006125', N'15', N'19', N'23', N'30', N'32', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-10-26', N'2006126', N'02', N'08', N'13', N'16', N'24', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-10-29', N'2006127', N'03', N'04', N'11', N'17', N'19', N'30', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-10-31', N'2006128', N'04', N'15', N'21', N'30', N'31', N'33', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-11-02', N'2006129', N'09', N'14', N'18', N'22', N'27', N'29', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-11-05', N'2006130', N'01', N'12', N'21', N'22', N'30', N'32', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-11-07', N'2006131', N'03', N'04', N'09', N'22', N'26', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-11-09', N'2006132', N'06', N'14', N'22', N'26', N'30', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-11-12', N'2006133', N'04', N'06', N'20', N'25', N'29', N'31', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-11-14', N'2006134', N'10', N'13', N'18', N'26', N'28', N'30', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-11-16', N'2006135', N'04', N'19', N'21', N'22', N'23', N'31', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-11-19', N'2006136', N'11', N'15', N'17', N'21', N'22', N'24', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-11-21', N'2006137', N'10', N'14', N'17', N'21', N'27', N'31', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-11-23', N'2006138', N'04', N'09', N'11', N'17', N'18', N'26', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-11-26', N'2006139', N'07', N'08', N'14', N'21', N'23', N'25', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-11-28', N'2006140', N'01', N'08', N'11', N'18', N'19', N'23', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-11-30', N'2006141', N'16', N'18', N'22', N'23', N'25', N'31', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-12-03', N'2006142', N'10', N'16', N'19', N'22', N'26', N'27', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-12-05', N'2006143', N'01', N'15', N'20', N'29', N'31', N'32', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-12-07', N'2006144', N'04', N'10', N'13', N'16', N'22', N'29', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-12-10', N'2006145', N'02', N'07', N'23', N'26', N'28', N'31', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-12-12', N'2006146', N'03', N'09', N'13', N'23', N'28', N'30', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-12-14', N'2006147', N'01', N'04', N'15', N'17', N'27', N'31', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-12-17', N'2006148', N'04', N'08', N'12', N'13', N'23', N'29', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-12-19', N'2006149', N'02', N'03', N'05', N'11', N'15', N'32', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-12-21', N'2006150', N'08', N'09', N'12', N'18', N'25', N'27', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-12-24', N'2006151', N'01', N'03', N'04', N'06', N'16', N'22', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-12-26', N'2006152', N'01', N'14', N'20', N'25', N'27', N'31', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-12-28', N'2006153', N'01', N'07', N'11', N'20', N'30', N'33', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2006-12-31', N'2006154', N'07', N'14', N'18', N'20', N'30', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-01-02', N'2007001', N'02', N'04', N'09', N'10', N'20', N'26', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-01-04', N'2007002', N'05', N'06', N'14', N'20', N'21', N'22', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-01-07', N'2007003', N'05', N'09', N'11', N'12', N'22', N'27', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-01-09', N'2007004', N'03', N'07', N'10', N'13', N'25', N'33', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-01-11', N'2007005', N'01', N'05', N'06', N'16', N'24', N'30', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-01-14', N'2007006', N'06', N'10', N'14', N'22', N'26', N'27', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-01-16', N'2007007', N'04', N'12', N'15', N'17', N'22', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-01-18', N'2007008', N'01', N'04', N'05', N'18', N'19', N'25', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-01-21', N'2007009', N'02', N'04', N'14', N'15', N'25', N'27', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-01-23', N'2007010', N'03', N'08', N'14', N'17', N'30', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-01-25', N'2007011', N'03', N'10', N'15', N'25', N'28', N'33', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-01-28', N'2007012', N'03', N'05', N'07', N'21', N'26', N'28', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-01-30', N'2007013', N'05', N'15', N'18', N'27', N'29', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-02-01', N'2007014', N'01', N'13', N'16', N'20', N'24', N'26', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-02-04', N'2007015', N'03', N'04', N'08', N'18', N'22', N'30', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-02-06', N'2007016', N'01', N'18', N'20', N'22', N'26', N'33', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-02-08', N'2007017', N'05', N'09', N'10', N'24', N'25', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-02-11', N'2007018', N'01', N'12', N'18', N'20', N'21', N'26', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-02-13', N'2007019', N'04', N'11', N'16', N'23', N'29', N'31', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-02-15', N'2007020', N'05', N'10', N'16', N'20', N'28', N'31', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-02-25', N'2007021', N'03', N'06', N'09', N'11', N'25', N'31', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-02-27', N'2007022', N'02', N'04', N'07', N'10', N'18', N'27', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-03-01', N'2007023', N'03', N'07', N'13', N'17', N'32', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-03-04', N'2007024', N'08', N'09', N'17', N'25', N'27', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-03-06', N'2007025', N'03', N'16', N'18', N'22', N'23', N'26', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-03-08', N'2007026', N'01', N'04', N'14', N'16', N'26', N'29', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-03-11', N'2007027', N'02', N'03', N'09', N'22', N'24', N'27', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-03-13', N'2007028', N'03', N'08', N'13', N'20', N'29', N'30', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-03-15', N'2007029', N'06', N'08', N'09', N'11', N'19', N'21', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-03-18', N'2007030', N'03', N'16', N'21', N'22', N'27', N'30', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-03-20', N'2007031', N'04', N'06', N'10', N'12', N'19', N'31', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-03-22', N'2007032', N'04', N'08', N'16', N'24', N'30', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-03-25', N'2007033', N'03', N'04', N'11', N'17', N'18', N'28', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-03-27', N'2007034', N'02', N'09', N'12', N'14', N'23', N'25', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-03-29', N'2007035', N'01', N'04', N'08', N'12', N'29', N'31', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-04-01', N'2007036', N'03', N'14', N'21', N'23', N'30', N'31', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-04-03', N'2007037', N'10', N'11', N'16', N'23', N'31', N'33', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-04-05', N'2007038', N'03', N'11', N'14', N'19', N'21', N'30', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-04-08', N'2007039', N'06', N'07', N'19', N'24', N'27', N'29', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-04-10', N'2007040', N'13', N'14', N'15', N'19', N'24', N'30', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-04-12', N'2007041', N'01', N'03', N'09', N'11', N'26', N'31', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-04-15', N'2007042', N'03', N'13', N'16', N'19', N'32', N'33', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-04-17', N'2007043', N'03', N'08', N'10', N'11', N'14', N'30', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-04-19', N'2007044', N'09', N'13', N'20', N'21', N'24', N'32', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-04-22', N'2007045', N'01', N'12', N'18', N'21', N'28', N'30', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-04-24', N'2007046', N'02', N'06', N'07', N'09', N'19', N'26', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-04-26', N'2007047', N'02', N'04', N'16', N'18', N'23', N'30', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-04-29', N'2007048', N'02', N'11', N'12', N'15', N'17', N'28', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-05-01', N'2007049', N'04', N'14', N'18', N'19', N'31', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-05-03', N'2007050', N'01', N'05', N'08', N'13', N'18', N'25', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-05-06', N'2007051', N'03', N'14', N'16', N'26', N'27', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-05-08', N'2007052', N'02', N'03', N'07', N'08', N'26', N'29', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-05-10', N'2007053', N'10', N'13', N'16', N'17', N'18', N'27', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-05-13', N'2007054', N'01', N'03', N'16', N'18', N'23', N'28', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-05-15', N'2007055', N'02', N'06', N'11', N'22', N'28', N'29', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-05-17', N'2007056', N'14', N'17', N'21', N'29', N'31', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-05-20', N'2007057', N'05', N'11', N'18', N'19', N'20', N'21', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-05-22', N'2007058', N'07', N'08', N'10', N'13', N'25', N'27', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-05-24', N'2007059', N'01', N'03', N'04', N'06', N'07', N'29', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-05-27', N'2007060', N'01', N'02', N'08', N'16', N'19', N'29', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-05-29', N'2007061', N'01', N'06', N'07', N'11', N'20', N'23', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-05-31', N'2007062', N'08', N'17', N'20', N'29', N'30', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-06-03', N'2007063', N'10', N'15', N'17', N'24', N'26', N'28', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-06-05', N'2007064', N'02', N'06', N'09', N'16', N'21', N'23', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-06-07', N'2007065', N'04', N'07', N'19', N'21', N'25', N'31', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-06-10', N'2007066', N'05', N'11', N'16', N'24', N'32', N'33', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-06-12', N'2007067', N'06', N'11', N'13', N'17', N'21', N'23', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-06-14', N'2007068', N'11', N'18', N'19', N'22', N'23', N'28', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-06-17', N'2007069', N'03', N'04', N'11', N'12', N'14', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-06-19', N'2007070', N'06', N'08', N'15', N'17', N'18', N'30', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-06-21', N'2007071', N'01', N'06', N'14', N'21', N'30', N'31', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-06-24', N'2007072', N'02', N'04', N'08', N'13', N'14', N'33', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-06-26', N'2007073', N'05', N'09', N'11', N'19', N'28', N'31', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-06-28', N'2007074', N'08', N'13', N'15', N'25', N'27', N'28', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-07-01', N'2007075', N'13', N'16', N'17', N'22', N'30', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-07-03', N'2007076', N'06', N'12', N'15', N'16', N'20', N'31', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-07-05', N'2007077', N'06', N'08', N'14', N'21', N'28', N'29', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-07-08', N'2007078', N'04', N'06', N'07', N'23', N'25', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-07-10', N'2007079', N'03', N'04', N'14', N'20', N'21', N'25', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-07-12', N'2007080', N'01', N'08', N'16', N'18', N'19', N'29', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-07-15', N'2007081', N'09', N'14', N'15', N'19', N'24', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-07-17', N'2007082', N'05', N'15', N'17', N'18', N'25', N'32', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-07-19', N'2007083', N'11', N'14', N'18', N'20', N'21', N'26', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-07-22', N'2007084', N'06', N'10', N'12', N'14', N'20', N'27', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-07-24', N'2007085', N'02', N'12', N'17', N'19', N'29', N'30', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-07-26', N'2007086', N'05', N'08', N'14', N'22', N'27', N'29', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-07-29', N'2007087', N'01', N'03', N'04', N'05', N'08', N'21', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-07-31', N'2007088', N'02', N'04', N'10', N'28', N'29', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-08-02', N'2007089', N'03', N'07', N'08', N'15', N'19', N'28', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-08-05', N'2007090', N'05', N'11', N'13', N'27', N'30', N'31', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-08-07', N'2007091', N'02', N'11', N'17', N'30', N'31', N'32', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-08-09', N'2007092', N'14', N'18', N'22', N'23', N'24', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-08-12', N'2007093', N'05', N'10', N'13', N'15', N'19', N'29', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-08-14', N'2007094', N'03', N'05', N'18', N'19', N'24', N'32', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-08-16', N'2007095', N'01', N'06', N'08', N'18', N'29', N'32', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-08-19', N'2007096', N'09', N'10', N'20', N'22', N'30', N'32', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-08-21', N'2007097', N'04', N'08', N'13', N'18', N'26', N'30', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-08-23', N'2007098', N'02', N'03', N'05', N'11', N'19', N'20', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-08-26', N'2007099', N'03', N'04', N'14', N'27', N'31', N'33', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-08-28', N'2007100', N'08', N'18', N'27', N'29', N'30', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-08-30', N'2007101', N'15', N'16', N'18', N'21', N'22', N'30', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-09-02', N'2007102', N'04', N'06', N'08', N'18', N'20', N'33', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-09-04', N'2007103', N'07', N'09', N'25', N'27', N'30', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-09-06', N'2007104', N'02', N'08', N'12', N'14', N'20', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-09-09', N'2007105', N'02', N'07', N'10', N'17', N'23', N'29', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-09-11', N'2007106', N'12', N'18', N'21', N'24', N'25', N'29', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-09-13', N'2007107', N'02', N'08', N'09', N'18', N'24', N'28', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-09-16', N'2007108', N'03', N'07', N'12', N'13', N'20', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-09-18', N'2007109', N'01', N'04', N'07', N'08', N'13', N'14', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-09-20', N'2007110', N'02', N'04', N'07', N'15', N'24', N'28', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-09-23', N'2007111', N'02', N'09', N'10', N'12', N'13', N'17', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-09-25', N'2007112', N'07', N'11', N'14', N'16', N'25', N'32', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-09-27', N'2007113', N'04', N'18', N'23', N'25', N'26', N'31', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-09-30', N'2007114', N'05', N'12', N'15', N'24', N'27', N'33', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-10-02', N'2007115', N'01', N'05', N'10', N'16', N'20', N'26', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-10-04', N'2007116', N'03', N'05', N'07', N'11', N'17', N'27', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-10-07', N'2007117', N'03', N'07', N'09', N'10', N'26', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-10-09', N'2007118', N'04', N'10', N'16', N'18', N'25', N'32', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-10-11', N'2007119', N'03', N'08', N'11', N'13', N'25', N'31', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-10-14', N'2007120', N'06', N'07', N'11', N'12', N'18', N'25', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-10-16', N'2007121', N'03', N'10', N'21', N'22', N'27', N'28', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-10-18', N'2007122', N'04', N'07', N'19', N'24', N'26', N'32', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-10-21', N'2007123', N'01', N'13', N'15', N'23', N'28', N'32', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-10-23', N'2007124', N'03', N'07', N'13', N'16', N'19', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-10-25', N'2007125', N'03', N'05', N'18', N'20', N'27', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-10-28', N'2007126', N'09', N'10', N'19', N'23', N'26', N'31', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-10-30', N'2007127', N'06', N'09', N'13', N'16', N'24', N'28', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-11-01', N'2007128', N'09', N'10', N'19', N'21', N'27', N'31', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-11-04', N'2007129', N'05', N'07', N'20', N'21', N'22', N'30', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-11-06', N'2007130', N'03', N'05', N'09', N'11', N'27', N'31', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-11-08', N'2007131', N'03', N'05', N'07', N'16', N'22', N'27', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-11-11', N'2007132', N'01', N'09', N'16', N'21', N'22', N'23', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-11-13', N'2007133', N'03', N'06', N'07', N'11', N'13', N'33', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-11-15', N'2007134', N'01', N'04', N'10', N'13', N'18', N'25', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-11-18', N'2007135', N'01', N'11', N'16', N'26', N'31', N'33', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-11-20', N'2007136', N'01', N'02', N'18', N'21', N'25', N'29', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-11-22', N'2007137', N'03', N'07', N'08', N'18', N'20', N'22', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-11-25', N'2007138', N'02', N'03', N'15', N'17', N'19', N'25', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-11-27', N'2007139', N'06', N'10', N'12', N'14', N'16', N'22', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-11-29', N'2007140', N'01', N'05', N'16', N'21', N'22', N'26', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-12-02', N'2007141', N'02', N'03', N'04', N'06', N'17', N'31', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-12-04', N'2007142', N'11', N'20', N'25', N'26', N'27', N'30', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-12-06', N'2007143', N'01', N'06', N'22', N'23', N'24', N'26', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-12-09', N'2007144', N'08', N'14', N'23', N'25', N'28', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-12-11', N'2007145', N'08', N'09', N'11', N'12', N'25', N'31', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-12-13', N'2007146', N'04', N'18', N'22', N'24', N'26', N'30', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-12-16', N'2007147', N'03', N'07', N'18', N'24', N'26', N'27', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-12-18', N'2007148', N'03', N'09', N'16', N'17', N'23', N'28', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-12-20', N'2007149', N'01', N'17', N'19', N'22', N'28', N'30', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-12-23', N'2007150', N'03', N'05', N'11', N'13', N'19', N'24', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-12-25', N'2007151', N'01', N'06', N'10', N'11', N'23', N'25', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-12-27', N'2007152', N'11', N'17', N'21', N'29', N'30', N'33', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2007-12-30', N'2007153', N'01', N'04', N'19', N'20', N'25', N'31', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-01-01', N'2008001', N'02', N'04', N'07', N'09', N'14', N'29', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-01-03', N'2008002', N'03', N'04', N'18', N'22', N'25', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-01-06', N'2008003', N'06', N'08', N'11', N'13', N'17', N'19', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-01-08', N'2008004', N'04', N'08', N'22', N'23', N'27', N'29', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-01-10', N'2008005', N'03', N'05', N'15', N'22', N'24', N'25', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-01-13', N'2008006', N'01', N'14', N'16', N'18', N'22', N'27', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-01-15', N'2008007', N'01', N'13', N'17', N'22', N'23', N'30', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-01-17', N'2008008', N'02', N'15', N'16', N'23', N'26', N'27', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-01-20', N'2008009', N'09', N'21', N'29', N'30', N'31', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-01-22', N'2008010', N'03', N'08', N'11', N'17', N'21', N'27', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-01-24', N'2008011', N'02', N'14', N'17', N'21', N'30', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-01-27', N'2008012', N'03', N'04', N'05', N'16', N'20', N'30', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-01-29', N'2008013', N'02', N'08', N'15', N'16', N'22', N'28', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-01-31', N'2008014', N'03', N'09', N'11', N'17', N'21', N'31', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-02-03', N'2008015', N'06', N'08', N'11', N'16', N'29', N'33', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-02-05', N'2008016', N'03', N'12', N'14', N'21', N'29', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-02-14', N'2008017', N'02', N'05', N'07', N'17', N'20', N'22', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-02-17', N'2008018', N'02', N'05', N'06', N'23', N'26', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-02-19', N'2008019', N'02', N'09', N'11', N'17', N'27', N'31', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-02-21', N'2008020', N'03', N'10', N'13', N'15', N'28', N'30', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-02-24', N'2008021', N'09', N'12', N'19', N'20', N'26', N'28', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-02-26', N'2008022', N'12', N'18', N'20', N'24', N'28', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-02-28', N'2008023', N'08', N'16', N'18', N'25', N'26', N'32', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-03-02', N'2008024', N'11', N'20', N'21', N'26', N'28', N'30', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-03-04', N'2008025', N'08', N'16', N'17', N'18', N'19', N'21', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-03-06', N'2008026', N'05', N'17', N'19', N'27', N'29', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-03-09', N'2008027', N'15', N'18', N'19', N'23', N'24', N'26', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-03-11', N'2008028', N'01', N'13', N'21', N'26', N'29', N'32', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-03-13', N'2008029', N'01', N'09', N'14', N'22', N'29', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-03-16', N'2008030', N'06', N'15', N'18', N'19', N'20', N'28', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-03-18', N'2008031', N'03', N'06', N'11', N'15', N'21', N'31', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-03-20', N'2008032', N'05', N'14', N'16', N'21', N'23', N'28', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-03-23', N'2008033', N'12', N'17', N'18', N'30', N'31', N'33', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-03-25', N'2008034', N'03', N'05', N'09', N'11', N'21', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-03-27', N'2008035', N'07', N'11', N'14', N'17', N'18', N'29', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-03-30', N'2008036', N'02', N'06', N'13', N'18', N'23', N'28', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-04-01', N'2008037', N'01', N'12', N'22', N'24', N'28', N'31', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-04-03', N'2008038', N'03', N'09', N'10', N'11', N'15', N'19', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-04-06', N'2008039', N'01', N'07', N'10', N'13', N'22', N'29', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-04-08', N'2008040', N'06', N'13', N'22', N'25', N'27', N'28', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-04-10', N'2008041', N'08', N'11', N'20', N'22', N'23', N'27', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-04-13', N'2008042', N'03', N'04', N'09', N'11', N'12', N'24', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-04-15', N'2008043', N'03', N'10', N'16', N'22', N'27', N'33', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-04-17', N'2008044', N'05', N'07', N'09', N'20', N'26', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-04-20', N'2008045', N'01', N'10', N'13', N'21', N'29', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-04-22', N'2008046', N'15', N'16', N'18', N'24', N'28', N'33', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-04-24', N'2008047', N'09', N'12', N'13', N'14', N'20', N'22', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-04-27', N'2008048', N'11', N'18', N'21', N'27', N'30', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-04-29', N'2008049', N'03', N'10', N'12', N'13', N'19', N'25', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-05-01', N'2008050', N'01', N'11', N'19', N'24', N'26', N'27', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-05-04', N'2008051', N'01', N'04', N'08', N'10', N'13', N'33', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-05-06', N'2008052', N'02', N'10', N'17', N'23', N'29', N'31', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-05-08', N'2008053', N'06', N'12', N'19', N'20', N'21', N'27', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-05-11', N'2008054', N'02', N'06', N'16', N'17', N'20', N'25', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-05-13', N'2008055', N'11', N'16', N'19', N'23', N'26', N'31', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-05-15', N'2008056', N'08', N'13', N'22', N'23', N'25', N'30', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-05-18', N'2008057', N'19', N'20', N'21', N'26', N'28', N'30', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-05-20', N'2008058', N'01', N'12', N'21', N'27', N'29', N'31', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-05-22', N'2008059', N'02', N'06', N'15', N'29', N'31', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-05-25', N'2008060', N'06', N'07', N'08', N'17', N'30', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-05-27', N'2008061', N'01', N'02', N'05', N'12', N'26', N'31', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-05-29', N'2008062', N'06', N'08', N'13', N'17', N'24', N'27', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-06-01', N'2008063', N'05', N'09', N'11', N'14', N'16', N'17', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-06-03', N'2008064', N'01', N'02', N'07', N'09', N'12', N'18', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-06-05', N'2008065', N'05', N'13', N'15', N'19', N'30', N'31', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-06-08', N'2008066', N'07', N'12', N'21', N'22', N'29', N'30', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-06-10', N'2008067', N'10', N'11', N'15', N'19', N'26', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-06-12', N'2008068', N'05', N'07', N'17', N'23', N'27', N'29', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-06-15', N'2008069', N'05', N'08', N'17', N'20', N'26', N'30', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-06-17', N'2008070', N'05', N'06', N'12', N'15', N'18', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-06-19', N'2008071', N'01', N'06', N'21', N'26', N'27', N'28', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-06-22', N'2008072', N'01', N'05', N'10', N'18', N'22', N'30', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-06-24', N'2008073', N'01', N'09', N'13', N'22', N'28', N'33', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-06-26', N'2008074', N'01', N'11', N'15', N'19', N'20', N'24', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-06-29', N'2008075', N'01', N'08', N'14', N'18', N'22', N'30', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-07-01', N'2008076', N'02', N'05', N'07', N'11', N'13', N'18', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-07-03', N'2008077', N'04', N'12', N'22', N'26', N'30', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-07-06', N'2008078', N'06', N'13', N'16', N'26', N'30', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-07-08', N'2008079', N'03', N'04', N'05', N'10', N'20', N'32', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-07-10', N'2008080', N'04', N'14', N'22', N'25', N'29', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-07-13', N'2008081', N'02', N'12', N'13', N'18', N'25', N'31', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-07-15', N'2008082', N'04', N'08', N'10', N'12', N'21', N'26', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-07-17', N'2008083', N'07', N'08', N'09', N'18', N'29', N'32', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-07-20', N'2008084', N'04', N'07', N'13', N'20', N'29', N'30', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-07-22', N'2008085', N'01', N'04', N'12', N'20', N'24', N'29', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-07-24', N'2008086', N'04', N'05', N'10', N'26', N'27', N'30', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-07-27', N'2008087', N'01', N'07', N'26', N'29', N'30', N'31', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-07-29', N'2008088', N'01', N'06', N'08', N'16', N'17', N'23', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-07-31', N'2008089', N'03', N'06', N'11', N'16', N'22', N'27', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-08-03', N'2008090', N'02', N'07', N'14', N'18', N'19', N'24', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-08-05', N'2008091', N'03', N'12', N'14', N'23', N'31', N'32', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-08-07', N'2008092', N'01', N'03', N'18', N'27', N'28', N'30', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-08-10', N'2008093', N'04', N'10', N'12', N'16', N'26', N'28', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-08-12', N'2008094', N'01', N'04', N'15', N'16', N'23', N'28', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-08-14', N'2008095', N'03', N'08', N'14', N'21', N'28', N'29', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-08-17', N'2008096', N'06', N'08', N'12', N'24', N'27', N'31', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-08-19', N'2008097', N'03', N'06', N'08', N'09', N'16', N'17', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-08-21', N'2008098', N'06', N'07', N'10', N'11', N'15', N'30', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-08-24', N'2008099', N'10', N'15', N'16', N'22', N'23', N'24', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-08-26', N'2008100', N'08', N'14', N'17', N'21', N'27', N'28', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-08-28', N'2008101', N'09', N'17', N'21', N'26', N'28', N'30', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-08-31', N'2008102', N'03', N'07', N'12', N'21', N'25', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-09-02', N'2008103', N'01', N'12', N'16', N'18', N'22', N'33', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-09-04', N'2008104', N'03', N'06', N'08', N'17', N'24', N'31', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-09-07', N'2008105', N'05', N'17', N'19', N'27', N'28', N'32', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-09-09', N'2008106', N'14', N'19', N'25', N'27', N'29', N'30', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-09-11', N'2008107', N'06', N'13', N'18', N'22', N'27', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-09-14', N'2008108', N'09', N'10', N'15', N'17', N'23', N'30', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-09-16', N'2008109', N'04', N'07', N'09', N'16', N'21', N'28', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-09-18', N'2008110', N'10', N'16', N'22', N'23', N'29', N'31', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-09-21', N'2008111', N'17', N'18', N'21', N'25', N'31', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-09-23', N'2008112', N'05', N'13', N'14', N'19', N'22', N'23', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-09-25', N'2008113', N'06', N'09', N'10', N'12', N'17', N'22', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-09-28', N'2008114', N'04', N'09', N'20', N'24', N'25', N'31', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-09-30', N'2008115', N'02', N'12', N'13', N'14', N'17', N'18', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-10-02', N'2008116', N'03', N'07', N'21', N'22', N'24', N'29', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-10-05', N'2008117', N'03', N'05', N'07', N'10', N'14', N'33', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-10-07', N'2008118', N'04', N'09', N'16', N'27', N'31', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-10-09', N'2008119', N'05', N'07', N'09', N'15', N'24', N'29', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-10-12', N'2008120', N'10', N'11', N'22', N'24', N'26', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-10-14', N'2008121', N'02', N'22', N'23', N'27', N'31', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-10-16', N'2008122', N'02', N'08', N'11', N'14', N'19', N'26', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-10-19', N'2008123', N'10', N'11', N'15', N'16', N'25', N'29', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-10-21', N'2008124', N'01', N'07', N'10', N'13', N'21', N'22', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-10-23', N'2008125', N'10', N'11', N'12', N'15', N'26', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-10-26', N'2008126', N'04', N'11', N'12', N'14', N'20', N'30', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-10-28', N'2008127', N'05', N'08', N'19', N'22', N'27', N'30', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-10-30', N'2008128', N'01', N'05', N'19', N'20', N'27', N'33', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-11-02', N'2008129', N'01', N'03', N'18', N'24', N'25', N'32', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-11-04', N'2008130', N'01', N'12', N'18', N'28', N'30', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-11-06', N'2008131', N'02', N'12', N'15', N'18', N'22', N'32', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-11-09', N'2008132', N'09', N'13', N'16', N'25', N'27', N'33', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-11-11', N'2008133', N'08', N'11', N'16', N'19', N'24', N'26', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-11-13', N'2008134', N'10', N'15', N'19', N'20', N'28', N'32', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-11-16', N'2008135', N'05', N'14', N'15', N'16', N'19', N'21', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-11-18', N'2008136', N'05', N'09', N'10', N'12', N'18', N'28', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-11-20', N'2008137', N'01', N'04', N'24', N'28', N'29', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-11-23', N'2008138', N'07', N'14', N'19', N'23', N'25', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-11-25', N'2008139', N'08', N'09', N'19', N'23', N'25', N'26', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-11-27', N'2008140', N'07', N'14', N'16', N'29', N'30', N'31', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-11-30', N'2008141', N'03', N'13', N'20', N'25', N'29', N'33', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-12-02', N'2008142', N'05', N'06', N'10', N'13', N'17', N'28', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-12-04', N'2008143', N'12', N'17', N'18', N'19', N'26', N'27', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-12-07', N'2008144', N'02', N'05', N'10', N'27', N'29', N'33', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-12-09', N'2008145', N'07', N'13', N'18', N'22', N'26', N'29', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-12-11', N'2008146', N'07', N'08', N'17', N'19', N'31', N'32', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-12-14', N'2008147', N'07', N'08', N'14', N'22', N'26', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-12-16', N'2008148', N'03', N'05', N'09', N'22', N'26', N'28', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-12-18', N'2008149', N'10', N'14', N'22', N'28', N'29', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-12-21', N'2008150', N'04', N'19', N'22', N'24', N'29', N'32', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-12-23', N'2008151', N'06', N'08', N'10', N'14', N'17', N'19', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-12-25', N'2008152', N'01', N'04', N'06', N'22', N'26', N'30', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-12-28', N'2008153', N'01', N'04', N'18', N'21', N'24', N'30', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2008-12-30', N'2008154', N'02', N'05', N'07', N'21', N'22', N'26', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-01-01', N'2009001', N'04', N'21', N'23', N'24', N'30', N'31', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-01-04', N'2009002', N'10', N'14', N'17', N'25', N'29', N'33', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-01-06', N'2009003', N'02', N'03', N'06', N'15', N'25', N'30', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-01-08', N'2009004', N'03', N'11', N'13', N'17', N'28', N'31', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-01-11', N'2009005', N'01', N'03', N'08', N'15', N'17', N'21', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-01-13', N'2009006', N'06', N'12', N'18', N'20', N'26', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-01-15', N'2009007', N'01', N'05', N'12', N'23', N'25', N'26', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-01-18', N'2009008', N'04', N'15', N'16', N'22', N'32', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-01-20', N'2009009', N'08', N'15', N'21', N'30', N'31', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-01-22', N'2009010', N'03', N'10', N'17', N'19', N'20', N'24', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-02-01', N'2009011', N'02', N'04', N'13', N'14', N'18', N'23', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-02-03', N'2009012', N'05', N'11', N'14', N'17', N'18', N'28', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-02-05', N'2009013', N'04', N'08', N'09', N'21', N'26', N'27', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-02-08', N'2009014', N'03', N'06', N'09', N'14', N'15', N'18', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-02-10', N'2009015', N'02', N'04', N'06', N'15', N'17', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-02-12', N'2009016', N'02', N'07', N'13', N'16', N'20', N'33', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-02-15', N'2009017', N'06', N'14', N'15', N'19', N'25', N'26', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-02-17', N'2009018', N'02', N'05', N'06', N'19', N'27', N'30', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-02-19', N'2009019', N'06', N'17', N'19', N'20', N'26', N'27', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-02-22', N'2009020', N'03', N'05', N'07', N'10', N'19', N'23', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-02-24', N'2009021', N'01', N'04', N'05', N'17', N'24', N'27', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-02-26', N'2009022', N'05', N'08', N'09', N'10', N'11', N'18', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-03-01', N'2009023', N'01', N'06', N'07', N'15', N'24', N'30', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-03-03', N'2009024', N'01', N'03', N'17', N'23', N'30', N'33', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-03-05', N'2009025', N'10', N'20', N'22', N'23', N'26', N'33', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-03-08', N'2009026', N'11', N'15', N'17', N'18', N'20', N'30', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-03-10', N'2009027', N'02', N'07', N'11', N'16', N'27', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-03-12', N'2009028', N'03', N'06', N'12', N'15', N'23', N'26', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-03-15', N'2009029', N'12', N'13', N'15', N'22', N'23', N'29', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-03-17', N'2009030', N'08', N'14', N'24', N'26', N'28', N'32', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-03-19', N'2009031', N'01', N'02', N'03', N'15', N'30', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-03-22', N'2009032', N'09', N'11', N'12', N'19', N'27', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-03-24', N'2009033', N'07', N'08', N'13', N'14', N'29', N'30', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-03-26', N'2009034', N'09', N'12', N'18', N'21', N'22', N'26', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-03-29', N'2009035', N'06', N'15', N'21', N'26', N'29', N'31', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-03-31', N'2009036', N'06', N'09', N'18', N'23', N'32', N'33', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-04-02', N'2009037', N'02', N'06', N'15', N'18', N'20', N'31', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-04-05', N'2009038', N'12', N'13', N'15', N'23', N'28', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-04-07', N'2009039', N'05', N'12', N'14', N'15', N'21', N'27', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-04-09', N'2009040', N'04', N'07', N'10', N'20', N'26', N'30', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-04-12', N'2009041', N'01', N'08', N'23', N'26', N'28', N'33', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-04-14', N'2009042', N'08', N'16', N'22', N'23', N'27', N'30', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-04-16', N'2009043', N'04', N'09', N'10', N'15', N'18', N'26', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-04-19', N'2009044', N'11', N'14', N'16', N'18', N'26', N'30', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-04-21', N'2009045', N'03', N'04', N'06', N'23', N'30', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-04-23', N'2009046', N'16', N'20', N'21', N'26', N'29', N'30', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-04-26', N'2009047', N'06', N'08', N'11', N'15', N'21', N'22', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-04-28', N'2009048', N'03', N'07', N'11', N'15', N'17', N'31', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-04-30', N'2009049', N'09', N'12', N'14', N'20', N'30', N'31', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-05-03', N'2009050', N'13', N'21', N'24', N'29', N'30', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-05-05', N'2009051', N'06', N'10', N'13', N'16', N'21', N'23', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-05-07', N'2009052', N'09', N'11', N'15', N'19', N'21', N'30', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-05-10', N'2009053', N'07', N'12', N'18', N'19', N'22', N'28', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-05-12', N'2009054', N'16', N'17', N'23', N'26', N'31', N'32', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-05-14', N'2009055', N'03', N'04', N'18', N'22', N'24', N'29', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-05-17', N'2009056', N'04', N'09', N'10', N'18', N'29', N'32', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-05-19', N'2009057', N'05', N'07', N'10', N'14', N'17', N'25', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-05-21', N'2009058', N'05', N'08', N'10', N'15', N'23', N'26', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-05-24', N'2009059', N'03', N'07', N'13', N'23', N'27', N'30', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-05-26', N'2009060', N'07', N'13', N'17', N'26', N'32', N'33', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-05-28', N'2009061', N'10', N'11', N'13', N'16', N'19', N'30', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-05-31', N'2009062', N'10', N'19', N'20', N'21', N'23', N'32', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-06-02', N'2009063', N'02', N'05', N'11', N'26', N'30', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-06-04', N'2009064', N'01', N'02', N'14', N'23', N'28', N'29', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-06-07', N'2009065', N'08', N'12', N'20', N'22', N'30', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-06-09', N'2009066', N'02', N'15', N'19', N'24', N'31', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-06-11', N'2009067', N'04', N'10', N'16', N'23', N'28', N'30', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-06-14', N'2009068', N'06', N'11', N'18', N'20', N'25', N'30', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-06-16', N'2009069', N'03', N'05', N'12', N'18', N'21', N'23', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-06-18', N'2009070', N'01', N'02', N'09', N'10', N'21', N'31', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-06-21', N'2009071', N'04', N'05', N'23', N'26', N'31', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-06-23', N'2009072', N'01', N'03', N'12', N'20', N'21', N'29', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-06-25', N'2009073', N'09', N'16', N'17', N'18', N'22', N'27', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-06-28', N'2009074', N'05', N'10', N'16', N'19', N'23', N'28', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-06-30', N'2009075', N'01', N'13', N'15', N'17', N'20', N'30', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-07-02', N'2009076', N'09', N'18', N'19', N'25', N'28', N'31', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-07-05', N'2009077', N'01', N'09', N'14', N'16', N'28', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-07-07', N'2009078', N'05', N'07', N'12', N'14', N'15', N'20', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-07-09', N'2009079', N'02', N'09', N'16', N'21', N'30', N'31', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-07-12', N'2009080', N'01', N'11', N'13', N'25', N'32', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-07-14', N'2009081', N'04', N'05', N'06', N'25', N'29', N'30', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-07-16', N'2009082', N'11', N'15', N'18', N'21', N'27', N'29', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-07-19', N'2009083', N'02', N'08', N'12', N'18', N'24', N'28', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-07-21', N'2009084', N'04', N'09', N'11', N'20', N'32', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-07-23', N'2009085', N'04', N'08', N'12', N'17', N'20', N'30', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-07-26', N'2009086', N'11', N'12', N'13', N'18', N'23', N'32', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-07-28', N'2009087', N'06', N'11', N'13', N'20', N'28', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-07-30', N'2009088', N'04', N'07', N'11', N'15', N'16', N'17', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-08-02', N'2009089', N'02', N'03', N'07', N'11', N'19', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-08-04', N'2009090', N'07', N'09', N'14', N'20', N'23', N'30', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-08-06', N'2009091', N'03', N'08', N'11', N'14', N'25', N'29', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-08-09', N'2009092', N'02', N'06', N'07', N'14', N'18', N'31', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-08-11', N'2009093', N'01', N'11', N'20', N'31', N'32', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-08-13', N'2009094', N'03', N'16', N'22', N'25', N'26', N'33', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-08-16', N'2009095', N'08', N'09', N'14', N'28', N'31', N'33', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-08-18', N'2009096', N'01', N'26', N'27', N'31', N'32', N'33', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-08-20', N'2009097', N'07', N'13', N'24', N'26', N'28', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-08-23', N'2009098', N'03', N'14', N'15', N'20', N'23', N'30', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-08-25', N'2009099', N'08', N'09', N'18', N'20', N'25', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-08-27', N'2009100', N'02', N'11', N'17', N'27', N'30', N'33', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-08-30', N'2009101', N'01', N'02', N'05', N'10', N'19', N'24', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-09-01', N'2009102', N'03', N'05', N'07', N'08', N'14', N'31', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-09-03', N'2009103', N'06', N'11', N'17', N'20', N'23', N'24', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-09-06', N'2009104', N'20', N'22', N'26', N'29', N'30', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-09-08', N'2009105', N'02', N'08', N'10', N'16', N'27', N'30', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-09-10', N'2009106', N'01', N'02', N'15', N'18', N'20', N'29', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-09-13', N'2009107', N'07', N'08', N'20', N'23', N'28', N'29', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-09-15', N'2009108', N'04', N'10', N'17', N'28', N'32', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-09-17', N'2009109', N'05', N'06', N'07', N'14', N'25', N'28', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-09-20', N'2009110', N'04', N'10', N'13', N'15', N'19', N'30', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-09-22', N'2009111', N'02', N'04', N'07', N'14', N'15', N'25', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-09-24', N'2009112', N'06', N'07', N'18', N'24', N'30', N'32', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-09-27', N'2009113', N'04', N'12', N'20', N'25', N'28', N'29', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-09-29', N'2009114', N'03', N'05', N'11', N'12', N'31', N'32', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-10-01', N'2009115', N'02', N'09', N'13', N'15', N'19', N'24', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-10-04', N'2009116', N'05', N'17', N'21', N'25', N'27', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-10-06', N'2009117', N'05', N'09', N'15', N'21', N'26', N'31', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-10-08', N'2009118', N'12', N'16', N'25', N'26', N'27', N'31', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-10-11', N'2009119', N'06', N'07', N'10', N'12', N'15', N'21', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-10-13', N'2009120', N'01', N'02', N'08', N'12', N'16', N'30', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-10-15', N'2009121', N'02', N'04', N'06', N'10', N'25', N'30', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-10-18', N'2009122', N'07', N'14', N'16', N'27', N'29', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-10-20', N'2009123', N'09', N'13', N'20', N'22', N'25', N'28', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-10-22', N'2009124', N'03', N'04', N'22', N'23', N'28', N'30', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-10-25', N'2009125', N'06', N'07', N'08', N'22', N'26', N'27', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-10-27', N'2009126', N'03', N'05', N'06', N'10', N'19', N'23', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-10-29', N'2009127', N'02', N'11', N'12', N'14', N'15', N'16', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-11-01', N'2009128', N'05', N'08', N'15', N'16', N'26', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-11-03', N'2009129', N'06', N'07', N'16', N'17', N'24', N'25', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-11-05', N'2009130', N'02', N'03', N'07', N'12', N'13', N'30', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-11-08', N'2009131', N'16', N'23', N'25', N'26', N'32', N'33', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-11-10', N'2009132', N'04', N'14', N'15', N'21', N'23', N'30', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-11-12', N'2009133', N'05', N'09', N'13', N'18', N'20', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-11-15', N'2009134', N'03', N'05', N'12', N'15', N'28', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-11-17', N'2009135', N'01', N'03', N'14', N'19', N'30', N'33', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-11-19', N'2009136', N'01', N'04', N'14', N'22', N'30', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-11-22', N'2009137', N'08', N'12', N'14', N'15', N'17', N'21', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-11-24', N'2009138', N'04', N'07', N'14', N'26', N'32', N'33', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-11-26', N'2009139', N'01', N'05', N'15', N'17', N'27', N'29', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-11-29', N'2009140', N'04', N'05', N'11', N'18', N'22', N'33', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-12-01', N'2009141', N'02', N'13', N'21', N'28', N'29', N'31', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-12-03', N'2009142', N'07', N'11', N'15', N'19', N'20', N'24', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-12-06', N'2009143', N'05', N'09', N'11', N'17', N'23', N'28', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-12-08', N'2009144', N'01', N'05', N'10', N'17', N'18', N'29', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-12-10', N'2009145', N'03', N'05', N'11', N'15', N'26', N'33', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-12-13', N'2009146', N'03', N'09', N'16', N'20', N'22', N'33', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-12-15', N'2009147', N'06', N'08', N'10', N'18', N'22', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-12-17', N'2009148', N'06', N'12', N'15', N'22', N'29', N'32', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-12-20', N'2009149', N'01', N'03', N'16', N'18', N'22', N'29', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-12-22', N'2009150', N'04', N'06', N'07', N'16', N'19', N'20', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-12-24', N'2009151', N'06', N'08', N'10', N'16', N'25', N'30', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-12-27', N'2009152', N'03', N'04', N'19', N'21', N'27', N'28', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-12-29', N'2009153', N'06', N'07', N'08', N'20', N'21', N'25', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2009-12-31', N'2009154', N'01', N'07', N'12', N'14', N'18', N'25', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-01-03', N'2010001', N'07', N'17', N'18', N'27', N'29', N'32', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-01-05', N'2010002', N'03', N'06', N'07', N'23', N'30', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-01-07', N'2010003', N'14', N'22', N'26', N'27', N'28', N'31', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-01-10', N'2010004', N'01', N'12', N'13', N'16', N'23', N'28', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-01-12', N'2010005', N'03', N'05', N'06', N'08', N'17', N'18', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-01-14', N'2010006', N'03', N'05', N'07', N'13', N'14', N'18', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-01-17', N'2010007', N'14', N'22', N'27', N'28', N'30', N'33', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-01-19', N'2010008', N'05', N'07', N'13', N'15', N'18', N'30', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-01-21', N'2010009', N'01', N'09', N'13', N'21', N'24', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-01-24', N'2010010', N'07', N'08', N'12', N'15', N'22', N'26', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-01-26', N'2010011', N'07', N'08', N'14', N'22', N'24', N'30', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-01-28', N'2010012', N'02', N'08', N'13', N'14', N'25', N'33', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-01-31', N'2010013', N'01', N'02', N'03', N'16', N'18', N'23', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-02-02', N'2010014', N'01', N'03', N'07', N'14', N'26', N'28', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-02-04', N'2010015', N'01', N'04', N'16', N'21', N'23', N'28', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-02-07', N'2010016', N'02', N'08', N'10', N'12', N'30', N'33', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-02-09', N'2010017', N'01', N'03', N'06', N'11', N'12', N'23', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-02-11', N'2010018', N'11', N'28', N'29', N'30', N'32', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-02-21', N'2010019', N'02', N'10', N'22', N'24', N'26', N'27', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-02-23', N'2010020', N'05', N'06', N'14', N'22', N'24', N'26', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-02-25', N'2010021', N'02', N'09', N'16', N'17', N'19', N'25', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-02-28', N'2010022', N'01', N'02', N'18', N'29', N'31', N'32', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-03-02', N'2010023', N'02', N'09', N'11', N'22', N'24', N'27', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-03-04', N'2010024', N'07', N'16', N'26', N'27', N'29', N'31', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-03-07', N'2010025', N'04', N'05', N'07', N'10', N'13', N'25', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-03-09', N'2010026', N'02', N'04', N'05', N'08', N'19', N'22', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-03-11', N'2010027', N'03', N'04', N'15', N'25', N'26', N'30', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-03-14', N'2010028', N'01', N'03', N'06', N'12', N'16', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-03-16', N'2010029', N'01', N'05', N'14', N'16', N'17', N'22', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-03-18', N'2010030', N'03', N'06', N'10', N'16', N'25', N'31', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-03-21', N'2010031', N'05', N'07', N'13', N'24', N'25', N'28', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-03-23', N'2010032', N'08', N'18', N'21', N'28', N'29', N'33', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-03-25', N'2010033', N'08', N'10', N'11', N'12', N'25', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-03-28', N'2010034', N'06', N'11', N'13', N'22', N'25', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-03-30', N'2010035', N'09', N'10', N'11', N'18', N'19', N'21', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-04-01', N'2010036', N'06', N'13', N'14', N'28', N'29', N'30', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-04-04', N'2010037', N'03', N'16', N'19', N'21', N'24', N'26', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-04-06', N'2010038', N'01', N'06', N'07', N'11', N'13', N'16', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-04-08', N'2010039', N'08', N'17', N'21', N'23', N'25', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-04-11', N'2010040', N'12', N'19', N'24', N'25', N'30', N'32', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-04-13', N'2010041', N'03', N'05', N'13', N'19', N'25', N'29', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-04-15', N'2010042', N'03', N'06', N'11', N'20', N'31', N'32', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-04-18', N'2010043', N'04', N'10', N'19', N'22', N'28', N'33', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-04-20', N'2010044', N'03', N'09', N'21', N'23', N'27', N'31', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-04-22', N'2010045', N'02', N'03', N'04', N'13', N'20', N'29', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-04-25', N'2010046', N'11', N'12', N'21', N'23', N'27', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-04-27', N'2010047', N'03', N'10', N'13', N'20', N'21', N'32', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-04-29', N'2010048', N'01', N'06', N'08', N'10', N'23', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-05-02', N'2010049', N'01', N'06', N'10', N'26', N'27', N'28', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-05-04', N'2010050', N'07', N'21', N'22', N'26', N'28', N'30', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-05-06', N'2010051', N'04', N'17', N'23', N'27', N'28', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-05-09', N'2010052', N'01', N'02', N'19', N'23', N'27', N'29', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-05-11', N'2010053', N'03', N'22', N'24', N'27', N'28', N'30', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-05-13', N'2010054', N'01', N'06', N'08', N'12', N'14', N'25', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-05-16', N'2010055', N'02', N'03', N'13', N'19', N'20', N'23', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-05-18', N'2010056', N'01', N'02', N'03', N'08', N'13', N'32', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-05-20', N'2010057', N'05', N'11', N'12', N'19', N'25', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-05-23', N'2010058', N'01', N'04', N'11', N'17', N'19', N'29', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-05-25', N'2010059', N'01', N'09', N'11', N'12', N'18', N'30', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-05-27', N'2010060', N'01', N'08', N'15', N'18', N'22', N'27', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-05-30', N'2010061', N'02', N'04', N'16', N'19', N'22', N'26', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-06-01', N'2010062', N'11', N'13', N'15', N'20', N'31', N'33', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-06-03', N'2010063', N'02', N'06', N'10', N'17', N'23', N'24', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-06-06', N'2010064', N'08', N'14', N'25', N'26', N'30', N'31', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-06-08', N'2010065', N'02', N'07', N'08', N'17', N'30', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-06-10', N'2010066', N'01', N'03', N'21', N'22', N'31', N'32', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-06-13', N'2010067', N'01', N'07', N'10', N'14', N'21', N'25', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-06-15', N'2010068', N'03', N'13', N'18', N'20', N'23', N'28', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-06-17', N'2010069', N'12', N'14', N'20', N'22', N'24', N'32', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-06-20', N'2010070', N'08', N'13', N'23', N'27', N'31', N'33', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-06-22', N'2010071', N'05', N'13', N'14', N'17', N'20', N'26', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-06-24', N'2010072', N'06', N'08', N'22', N'23', N'30', N'31', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-06-27', N'2010073', N'01', N'16', N'20', N'23', N'27', N'31', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-06-29', N'2010074', N'02', N'10', N'17', N'18', N'19', N'29', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-07-01', N'2010075', N'05', N'09', N'12', N'13', N'15', N'22', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-07-04', N'2010076', N'01', N'12', N'14', N'29', N'31', N'32', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-07-06', N'2010077', N'02', N'08', N'14', N'20', N'21', N'24', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-07-08', N'2010078', N'01', N'03', N'09', N'11', N'17', N'23', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-07-11', N'2010079', N'08', N'11', N'12', N'14', N'18', N'22', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-07-13', N'2010080', N'08', N'10', N'13', N'14', N'16', N'23', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-07-15', N'2010081', N'02', N'03', N'09', N'24', N'26', N'27', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-07-18', N'2010082', N'01', N'08', N'13', N'14', N'27', N'31', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-07-20', N'2010083', N'02', N'20', N'21', N'22', N'23', N'31', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-07-22', N'2010084', N'02', N'10', N'14', N'18', N'20', N'30', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-07-25', N'2010085', N'01', N'08', N'12', N'13', N'24', N'27', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-07-27', N'2010086', N'05', N'21', N'28', N'29', N'30', N'31', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-07-29', N'2010087', N'01', N'08', N'16', N'17', N'25', N'30', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-08-01', N'2010088', N'05', N'06', N'15', N'23', N'27', N'30', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-08-03', N'2010089', N'07', N'08', N'09', N'16', N'23', N'26', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-08-05', N'2010090', N'01', N'06', N'10', N'15', N'25', N'31', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-08-08', N'2010091', N'06', N'13', N'16', N'20', N'22', N'24', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-08-10', N'2010092', N'03', N'13', N'19', N'27', N'28', N'30', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-08-12', N'2010093', N'09', N'10', N'19', N'28', N'32', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-08-15', N'2010094', N'03', N'05', N'07', N'27', N'31', N'32', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-08-17', N'2010095', N'09', N'11', N'16', N'17', N'25', N'27', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-08-19', N'2010096', N'07', N'12', N'21', N'23', N'24', N'28', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-08-22', N'2010097', N'10', N'16', N'18', N'21', N'24', N'26', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-08-24', N'2010098', N'01', N'03', N'08', N'16', N'29', N'33', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-08-26', N'2010099', N'03', N'04', N'17', N'24', N'27', N'30', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-08-29', N'2010100', N'01', N'06', N'12', N'22', N'23', N'26', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-08-31', N'2010101', N'04', N'09', N'18', N'21', N'25', N'26', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-09-02', N'2010102', N'04', N'11', N'16', N'20', N'22', N'29', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-09-05', N'2010103', N'06', N'09', N'14', N'17', N'20', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-09-07', N'2010104', N'07', N'17', N'23', N'24', N'27', N'32', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-09-09', N'2010105', N'01', N'08', N'09', N'19', N'21', N'31', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-09-12', N'2010106', N'02', N'06', N'08', N'15', N'26', N'29', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-09-14', N'2010107', N'08', N'12', N'15', N'17', N'22', N'33', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-09-16', N'2010108', N'02', N'04', N'08', N'20', N'23', N'24', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-09-19', N'2010109', N'04', N'15', N'18', N'25', N'29', N'32', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-09-21', N'2010110', N'01', N'03', N'12', N'24', N'26', N'27', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-09-23', N'2010111', N'04', N'07', N'08', N'13', N'17', N'18', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-09-26', N'2010112', N'01', N'08', N'18', N'24', N'29', N'30', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-09-28', N'2010113', N'05', N'10', N'15', N'18', N'20', N'28', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-09-30', N'2010114', N'01', N'08', N'11', N'15', N'17', N'25', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-10-03', N'2010115', N'01', N'22', N'24', N'25', N'29', N'33', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-10-05', N'2010116', N'05', N'09', N'10', N'20', N'22', N'26', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-10-07', N'2010117', N'01', N'08', N'20', N'22', N'24', N'28', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-10-10', N'2010118', N'05', N'08', N'11', N'13', N'15', N'25', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-10-12', N'2010119', N'07', N'17', N'25', N'27', N'30', N'31', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-10-14', N'2010120', N'01', N'02', N'05', N'06', N'10', N'29', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-10-17', N'2010121', N'08', N'11', N'13', N'18', N'25', N'30', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-10-19', N'2010122', N'02', N'09', N'12', N'16', N'25', N'27', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-10-21', N'2010123', N'06', N'12', N'15', N'18', N'29', N'32', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-10-24', N'2010124', N'02', N'06', N'08', N'11', N'12', N'25', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-10-26', N'2010125', N'06', N'07', N'13', N'23', N'28', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-10-28', N'2010126', N'03', N'13', N'18', N'20', N'27', N'28', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-10-31', N'2010127', N'01', N'04', N'08', N'17', N'25', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-11-02', N'2010128', N'04', N'11', N'19', N'20', N'24', N'28', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-11-04', N'2010129', N'04', N'08', N'14', N'25', N'28', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-11-07', N'2010130', N'01', N'02', N'07', N'15', N'21', N'31', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-11-09', N'2010131', N'05', N'06', N'15', N'16', N'19', N'26', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-11-11', N'2010132', N'02', N'10', N'12', N'18', N'24', N'33', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-11-14', N'2010133', N'03', N'09', N'17', N'21', N'26', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-11-16', N'2010134', N'09', N'15', N'16', N'22', N'27', N'28', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-11-18', N'2010135', N'04', N'10', N'13', N'25', N'26', N'30', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-11-21', N'2010136', N'04', N'10', N'23', N'24', N'26', N'33', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-11-23', N'2010137', N'07', N'09', N'10', N'13', N'19', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-11-25', N'2010138', N'01', N'21', N'23', N'24', N'26', N'30', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-11-28', N'2010139', N'11', N'13', N'18', N'20', N'26', N'31', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-11-30', N'2010140', N'01', N'12', N'13', N'18', N'26', N'29', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-12-02', N'2010141', N'02', N'03', N'07', N'18', N'23', N'27', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-12-05', N'2010142', N'02', N'16', N'18', N'23', N'26', N'27', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-12-07', N'2010143', N'09', N'16', N'18', N'26', N'30', N'31', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-12-09', N'2010144', N'02', N'03', N'08', N'15', N'19', N'21', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-12-12', N'2010145', N'03', N'21', N'24', N'27', N'28', N'31', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-12-14', N'2010146', N'01', N'17', N'18', N'22', N'25', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-12-16', N'2010147', N'02', N'08', N'15', N'18', N'24', N'30', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-12-19', N'2010148', N'01', N'03', N'07', N'18', N'23', N'27', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-12-21', N'2010149', N'02', N'07', N'08', N'16', N'25', N'30', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-12-23', N'2010150', N'02', N'17', N'18', N'23', N'29', N'30', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-12-26', N'2010151', N'02', N'13', N'14', N'17', N'19', N'26', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-12-28', N'2010152', N'04', N'09', N'17', N'21', N'25', N'31', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2010-12-30', N'2010153', N'03', N'06', N'12', N'19', N'30', N'31', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-01-02', N'2011001', N'03', N'09', N'20', N'24', N'26', N'32', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-01-04', N'2011002', N'06', N'08', N'12', N'17', N'28', N'33', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-01-06', N'2011003', N'13', N'14', N'21', N'22', N'23', N'27', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-01-09', N'2011004', N'04', N'06', N'08', N'10', N'13', N'26', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-01-11', N'2011005', N'06', N'09', N'12', N'14', N'20', N'22', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-01-13', N'2011006', N'01', N'03', N'05', N'13', N'16', N'18', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-01-16', N'2011007', N'01', N'09', N'17', N'24', N'26', N'31', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-01-18', N'2011008', N'10', N'12', N'13', N'17', N'24', N'31', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-01-20', N'2011009', N'17', N'18', N'23', N'24', N'25', N'26', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-01-23', N'2011010', N'01', N'04', N'05', N'09', N'15', N'19', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-01-25', N'2011011', N'01', N'12', N'18', N'19', N'21', N'24', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-01-27', N'2011012', N'07', N'08', N'11', N'13', N'15', N'26', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-01-30', N'2011013', N'01', N'03', N'13', N'16', N'21', N'22', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-02-01', N'2011014', N'05', N'07', N'10', N'11', N'23', N'26', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-02-10', N'2011015', N'03', N'06', N'13', N'26', N'27', N'29', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-02-13', N'2011016', N'03', N'04', N'16', N'17', N'22', N'29', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-02-15', N'2011017', N'02', N'06', N'15', N'23', N'26', N'33', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-02-17', N'2011018', N'13', N'15', N'18', N'28', N'30', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-02-20', N'2011019', N'02', N'04', N'12', N'19', N'32', N'33', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-02-22', N'2011020', N'12', N'16', N'17', N'19', N'24', N'30', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-02-24', N'2011021', N'01', N'02', N'14', N'18', N'25', N'31', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-02-27', N'2011022', N'02', N'07', N'14', N'16', N'17', N'21', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-03-01', N'2011023', N'02', N'03', N'06', N'21', N'22', N'25', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-03-03', N'2011024', N'05', N'07', N'10', N'19', N'26', N'31', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-03-06', N'2011025', N'08', N'25', N'26', N'31', N'32', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-03-08', N'2011026', N'07', N'08', N'17', N'19', N'21', N'26', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-03-10', N'2011027', N'13', N'18', N'21', N'22', N'25', N'26', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-03-13', N'2011028', N'01', N'04', N'05', N'14', N'16', N'17', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-03-15', N'2011029', N'01', N'04', N'09', N'10', N'20', N'31', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-03-17', N'2011030', N'02', N'09', N'19', N'24', N'25', N'33', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-03-20', N'2011031', N'16', N'17', N'24', N'28', N'29', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-03-22', N'2011032', N'03', N'05', N'07', N'13', N'14', N'15', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-03-24', N'2011033', N'02', N'08', N'12', N'13', N'19', N'29', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-03-27', N'2011034', N'13', N'14', N'17', N'19', N'24', N'31', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-03-29', N'2011035', N'13', N'14', N'18', N'20', N'27', N'31', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-03-31', N'2011036', N'02', N'11', N'20', N'22', N'24', N'31', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-04-03', N'2011037', N'01', N'03', N'04', N'06', N'17', N'25', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-04-05', N'2011038', N'02', N'14', N'15', N'19', N'23', N'24', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-04-07', N'2011039', N'03', N'07', N'10', N'16', N'24', N'29', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-04-10', N'2011040', N'05', N'11', N'14', N'24', N'26', N'28', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-04-12', N'2011041', N'04', N'10', N'12', N'13', N'30', N'32', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-04-14', N'2011042', N'05', N'13', N'15', N'17', N'19', N'21', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-04-17', N'2011043', N'04', N'13', N'14', N'17', N'25', N'31', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-04-19', N'2011044', N'03', N'14', N'16', N'26', N'27', N'31', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-04-21', N'2011045', N'02', N'16', N'17', N'20', N'26', N'32', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-04-24', N'2011046', N'09', N'17', N'18', N'26', N'29', N'30', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-04-26', N'2011047', N'04', N'13', N'23', N'25', N'27', N'33', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-04-28', N'2011048', N'10', N'14', N'18', N'25', N'26', N'27', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-05-01', N'2011049', N'01', N'11', N'17', N'18', N'27', N'31', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-05-03', N'2011050', N'04', N'05', N'19', N'22', N'28', N'29', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-05-05', N'2011051', N'01', N'07', N'11', N'14', N'15', N'16', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-05-08', N'2011052', N'04', N'05', N'08', N'19', N'27', N'28', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-05-10', N'2011053', N'03', N'06', N'10', N'12', N'22', N'30', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-05-12', N'2011054', N'08', N'11', N'16', N'17', N'22', N'33', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-05-15', N'2011055', N'08', N'13', N'16', N'17', N'29', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-05-17', N'2011056', N'13', N'16', N'19', N'20', N'23', N'25', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-05-19', N'2011057', N'04', N'06', N'20', N'21', N'26', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-05-22', N'2011058', N'07', N'18', N'22', N'30', N'32', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-05-24', N'2011059', N'24', N'26', N'27', N'29', N'31', N'33', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-05-26', N'2011060', N'10', N'11', N'13', N'21', N'27', N'31', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-05-29', N'2011061', N'02', N'03', N'08', N'13', N'19', N'21', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-05-31', N'2011062', N'04', N'08', N'09', N'10', N'29', N'30', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-06-02', N'2011063', N'04', N'06', N'13', N'15', N'18', N'19', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-06-05', N'2011064', N'03', N'06', N'07', N'29', N'30', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-06-07', N'2011065', N'04', N'16', N'23', N'25', N'27', N'29', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-06-09', N'2011066', N'04', N'06', N'14', N'17', N'30', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-06-12', N'2011067', N'17', N'19', N'20', N'24', N'25', N'27', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-06-14', N'2011068', N'03', N'07', N'10', N'15', N'19', N'24', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-06-16', N'2011069', N'02', N'13', N'16', N'18', N'24', N'30', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-06-19', N'2011070', N'01', N'03', N'05', N'12', N'21', N'28', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-06-21', N'2011071', N'01', N'02', N'15', N'22', N'28', N'30', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-06-23', N'2011072', N'01', N'06', N'10', N'11', N'18', N'27', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-06-26', N'2011073', N'03', N'04', N'05', N'12', N'17', N'21', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-06-28', N'2011074', N'02', N'21', N'26', N'28', N'29', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-06-30', N'2011075', N'07', N'09', N'10', N'12', N'31', N'32', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-07-03', N'2011076', N'06', N'19', N'21', N'26', N'32', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-07-05', N'2011077', N'01', N'07', N'08', N'15', N'26', N'29', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-07-07', N'2011078', N'03', N'05', N'13', N'20', N'22', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-07-10', N'2011079', N'03', N'14', N'15', N'16', N'24', N'29', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-07-12', N'2011080', N'02', N'07', N'09', N'25', N'31', N'32', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-07-14', N'2011081', N'06', N'14', N'19', N'23', N'25', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-07-17', N'2011082', N'07', N'16', N'17', N'20', N'25', N'26', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-07-19', N'2011083', N'07', N'16', N'18', N'24', N'28', N'29', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-07-21', N'2011084', N'09', N'10', N'12', N'16', N'18', N'32', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-07-24', N'2011085', N'03', N'06', N'11', N'21', N'24', N'31', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-07-26', N'2011086', N'06', N'07', N'09', N'12', N'17', N'24', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-07-28', N'2011087', N'02', N'03', N'04', N'05', N'18', N'28', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-07-31', N'2011088', N'03', N'09', N'17', N'20', N'21', N'29', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-08-02', N'2011089', N'01', N'02', N'11', N'24', N'29', N'30', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-08-04', N'2011090', N'02', N'05', N'14', N'18', N'21', N'25', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-08-07', N'2011091', N'09', N'15', N'21', N'23', N'28', N'30', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-08-09', N'2011092', N'05', N'10', N'17', N'26', N'31', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-08-11', N'2011093', N'04', N'07', N'11', N'13', N'23', N'30', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-08-14', N'2011094', N'09', N'11', N'12', N'17', N'18', N'19', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-08-16', N'2011095', N'03', N'07', N'08', N'10', N'23', N'24', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-08-18', N'2011096', N'01', N'04', N'07', N'13', N'14', N'19', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-08-21', N'2011097', N'09', N'17', N'19', N'20', N'21', N'26', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-08-23', N'2011098', N'03', N'07', N'20', N'21', N'22', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-08-25', N'2011099', N'10', N'12', N'13', N'21', N'26', N'27', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-08-28', N'2011100', N'07', N'11', N'21', N'23', N'31', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-08-30', N'2011101', N'06', N'10', N'19', N'23', N'29', N'31', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-09-01', N'2011102', N'01', N'05', N'13', N'21', N'27', N'31', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-09-04', N'2011103', N'04', N'05', N'10', N'13', N'15', N'16', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-09-06', N'2011104', N'09', N'10', N'16', N'20', N'25', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-09-08', N'2011105', N'04', N'06', N'23', N'25', N'27', N'28', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-09-11', N'2011106', N'02', N'11', N'12', N'14', N'24', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-09-13', N'2011107', N'04', N'09', N'16', N'17', N'22', N'29', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-09-15', N'2011108', N'02', N'17', N'22', N'26', N'29', N'33', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-09-18', N'2011109', N'01', N'03', N'09', N'15', N'16', N'33', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-09-20', N'2011110', N'12', N'14', N'21', N'26', N'28', N'33', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-09-22', N'2011111', N'01', N'03', N'05', N'20', N'25', N'27', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-09-25', N'2011112', N'03', N'05', N'16', N'18', N'23', N'24', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-09-27', N'2011113', N'06', N'10', N'11', N'25', N'32', N'33', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-09-29', N'2011114', N'01', N'14', N'15', N'16', N'30', N'32', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-10-02', N'2011115', N'07', N'08', N'09', N'12', N'17', N'33', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-10-04', N'2011116', N'01', N'07', N'11', N'12', N'17', N'27', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-10-06', N'2011117', N'08', N'10', N'19', N'26', N'28', N'30', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-10-09', N'2011118', N'05', N'06', N'11', N'14', N'20', N'21', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-10-11', N'2011119', N'09', N'12', N'14', N'19', N'28', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-10-13', N'2011120', N'04', N'14', N'17', N'28', N'30', N'33', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-10-16', N'2011121', N'04', N'14', N'22', N'25', N'32', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-10-18', N'2011122', N'10', N'12', N'18', N'26', N'27', N'31', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-10-20', N'2011123', N'01', N'04', N'05', N'14', N'19', N'28', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-10-23', N'2011124', N'09', N'18', N'19', N'26', N'31', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-10-25', N'2011125', N'03', N'10', N'15', N'24', N'27', N'32', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-10-27', N'2011126', N'03', N'07', N'13', N'18', N'23', N'26', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-10-30', N'2011127', N'16', N'19', N'22', N'23', N'27', N'29', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-11-01', N'2011128', N'09', N'11', N'14', N'17', N'19', N'23', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-11-03', N'2011129', N'07', N'10', N'11', N'21', N'23', N'26', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-11-06', N'2011130', N'07', N'14', N'18', N'23', N'25', N'32', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-11-08', N'2011131', N'02', N'07', N'09', N'17', N'21', N'25', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-11-10', N'2011132', N'02', N'05', N'12', N'13', N'25', N'33', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-11-13', N'2011133', N'12', N'14', N'20', N'21', N'25', N'31', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-11-15', N'2011134', N'01', N'02', N'06', N'07', N'30', N'31', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-11-17', N'2011135', N'12', N'13', N'17', N'20', N'25', N'26', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-11-20', N'2011136', N'02', N'04', N'06', N'20', N'22', N'31', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-11-22', N'2011137', N'02', N'11', N'18', N'23', N'30', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-11-24', N'2011138', N'01', N'05', N'15', N'24', N'28', N'32', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-11-27', N'2011139', N'08', N'20', N'24', N'27', N'30', N'31', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-11-29', N'2011140', N'04', N'18', N'20', N'22', N'27', N'29', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-12-01', N'2011141', N'02', N'04', N'06', N'19', N'24', N'29', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-12-04', N'2011142', N'12', N'15', N'16', N'26', N'29', N'31', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-12-06', N'2011143', N'07', N'08', N'12', N'14', N'15', N'30', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-12-08', N'2011144', N'01', N'02', N'09', N'10', N'16', N'24', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-12-11', N'2011145', N'02', N'04', N'14', N'15', N'26', N'30', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-12-13', N'2011146', N'11', N'23', N'26', N'28', N'32', N'33', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-12-15', N'2011147', N'04', N'08', N'12', N'17', N'18', N'30', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-12-18', N'2011148', N'05', N'14', N'22', N'23', N'25', N'26', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-12-20', N'2011149', N'04', N'05', N'06', N'07', N'23', N'31', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-12-22', N'2011150', N'08', N'10', N'12', N'15', N'22', N'27', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-12-25', N'2011151', N'07', N'11', N'16', N'19', N'31', N'33', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-12-27', N'2011152', N'04', N'10', N'11', N'12', N'21', N'26', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2011-12-29', N'2011153', N'05', N'08', N'09', N'10', N'20', N'25', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-01-01', N'2012001', N'01', N'04', N'05', N'09', N'15', N'17', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-01-03', N'2012002', N'02', N'03', N'07', N'09', N'10', N'32', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-01-05', N'2012003', N'03', N'06', N'08', N'24', N'29', N'31', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-01-08', N'2012004', N'01', N'05', N'10', N'11', N'21', N'23', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-01-10', N'2012005', N'07', N'09', N'18', N'27', N'31', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-01-12', N'2012006', N'02', N'22', N'25', N'29', N'32', N'33', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-01-15', N'2012007', N'10', N'17', N'19', N'27', N'28', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-01-17', N'2012008', N'01', N'12', N'20', N'23', N'24', N'29', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-01-19', N'2012009', N'04', N'16', N'24', N'26', N'27', N'33', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-01-29', N'2012010', N'01', N'03', N'13', N'19', N'25', N'26', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-01-31', N'2012011', N'04', N'14', N'15', N'16', N'20', N'26', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-02-02', N'2012012', N'15', N'17', N'18', N'20', N'23', N'27', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-02-05', N'2012013', N'06', N'08', N'24', N'29', N'30', N'32', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-02-07', N'2012014', N'01', N'02', N'05', N'16', N'28', N'30', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-02-09', N'2012015', N'01', N'03', N'06', N'10', N'21', N'23', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-02-12', N'2012016', N'02', N'05', N'12', N'17', N'22', N'25', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-02-14', N'2012017', N'06', N'09', N'14', N'19', N'25', N'28', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-02-16', N'2012018', N'03', N'05', N'06', N'22', N'26', N'32', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-02-19', N'2012019', N'07', N'14', N'18', N'20', N'22', N'30', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-02-21', N'2012020', N'03', N'08', N'12', N'18', N'23', N'29', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-02-23', N'2012021', N'01', N'15', N'16', N'18', N'22', N'30', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-02-26', N'2012022', N'04', N'08', N'12', N'24', N'26', N'27', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-02-28', N'2012023', N'05', N'09', N'15', N'23', N'24', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-03-01', N'2012024', N'04', N'12', N'19', N'21', N'25', N'28', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-03-04', N'2012025', N'03', N'08', N'09', N'17', N'25', N'27', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-03-06', N'2012026', N'03', N'07', N'09', N'15', N'24', N'25', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-03-08', N'2012027', N'04', N'16', N'22', N'25', N'30', N'31', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-03-11', N'2012028', N'10', N'15', N'20', N'21', N'28', N'30', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-03-13', N'2012029', N'04', N'07', N'15', N'25', N'26', N'28', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-03-15', N'2012030', N'09', N'10', N'17', N'18', N'21', N'31', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-03-18', N'2012031', N'04', N'16', N'22', N'24', N'27', N'31', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-03-20', N'2012032', N'01', N'02', N'10', N'17', N'22', N'24', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-03-22', N'2012033', N'02', N'03', N'15', N'16', N'17', N'27', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-03-25', N'2012034', N'02', N'03', N'08', N'23', N'32', N'33', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-03-27', N'2012035', N'09', N'11', N'12', N'21', N'24', N'26', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-03-29', N'2012036', N'02', N'11', N'13', N'18', N'19', N'26', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-04-01', N'2012037', N'05', N'14', N'19', N'24', N'28', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-04-03', N'2012038', N'09', N'10', N'11', N'15', N'19', N'33', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-04-05', N'2012039', N'01', N'02', N'05', N'13', N'22', N'29', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-04-08', N'2012040', N'03', N'08', N'09', N'22', N'25', N'31', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-04-10', N'2012041', N'08', N'11', N'15', N'20', N'24', N'32', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-04-12', N'2012042', N'05', N'06', N'11', N'19', N'24', N'28', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-04-15', N'2012043', N'02', N'09', N'11', N'21', N'26', N'33', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-04-17', N'2012044', N'06', N'09', N'10', N'14', N'22', N'25', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-04-19', N'2012045', N'08', N'11', N'20', N'21', N'27', N'30', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-04-22', N'2012046', N'04', N'12', N'19', N'20', N'23', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-04-24', N'2012047', N'06', N'07', N'11', N'16', N'32', N'33', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-04-26', N'2012048', N'01', N'05', N'14', N'22', N'24', N'30', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-04-29', N'2012049', N'04', N'12', N'13', N'19', N'20', N'32', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-05-01', N'2012050', N'07', N'13', N'15', N'17', N'19', N'24', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-05-03', N'2012051', N'02', N'12', N'14', N'17', N'30', N'31', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-05-06', N'2012052', N'02', N'03', N'05', N'06', N'20', N'24', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-05-08', N'2012053', N'04', N'15', N'22', N'25', N'27', N'33', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-05-10', N'2012054', N'06', N'14', N'18', N'20', N'30', N'33', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-05-13', N'2012055', N'04', N'06', N'13', N'20', N'24', N'28', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-05-15', N'2012056', N'04', N'07', N'14', N'17', N'26', N'31', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-05-17', N'2012057', N'03', N'05', N'19', N'21', N'27', N'31', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-05-20', N'2012058', N'03', N'06', N'15', N'20', N'25', N'26', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-05-22', N'2012059', N'04', N'13', N'21', N'22', N'26', N'31', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-05-24', N'2012060', N'07', N'10', N'13', N'16', N'17', N'29', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-05-27', N'2012061', N'03', N'08', N'11', N'12', N'14', N'18', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-05-29', N'2012062', N'02', N'13', N'16', N'17', N'20', N'31', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-05-31', N'2012063', N'02', N'10', N'17', N'19', N'24', N'27', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-06-03', N'2012064', N'05', N'10', N'11', N'16', N'23', N'24', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-06-05', N'2012065', N'08', N'10', N'18', N'19', N'27', N'31', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-06-07', N'2012066', N'01', N'02', N'09', N'26', N'29', N'33', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-06-10', N'2012067', N'04', N'05', N'10', N'21', N'26', N'30', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-06-12', N'2012068', N'05', N'17', N'22', N'26', N'32', N'33', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-06-14', N'2012069', N'08', N'10', N'11', N'18', N'20', N'29', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-06-17', N'2012070', N'02', N'03', N'04', N'24', N'31', N'32', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-06-19', N'2012071', N'03', N'04', N'19', N'21', N'22', N'23', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-06-21', N'2012072', N'02', N'03', N'07', N'09', N'13', N'30', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-06-24', N'2012073', N'04', N'07', N'09', N'10', N'17', N'27', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-06-26', N'2012074', N'15', N'16', N'18', N'19', N'28', N'32', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-06-28', N'2012075', N'04', N'06', N'22', N'23', N'29', N'32', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-07-01', N'2012076', N'11', N'18', N'22', N'27', N'29', N'30', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-07-03', N'2012077', N'02', N'04', N'13', N'18', N'26', N'28', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-07-05', N'2012078', N'08', N'15', N'22', N'24', N'28', N'33', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-07-08', N'2012079', N'06', N'07', N'12', N'24', N'30', N'33', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-07-10', N'2012080', N'04', N'09', N'14', N'15', N'16', N'27', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-07-12', N'2012081', N'02', N'05', N'10', N'24', N'25', N'29', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-07-15', N'2012082', N'02', N'04', N'11', N'18', N'22', N'29', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-07-17', N'2012083', N'04', N'09', N'14', N'15', N'26', N'33', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-07-19', N'2012084', N'02', N'10', N'20', N'26', N'28', N'29', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-07-22', N'2012085', N'05', N'17', N'24', N'30', N'31', N'33', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-07-24', N'2012086', N'08', N'09', N'13', N'15', N'22', N'23', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-07-26', N'2012087', N'03', N'10', N'11', N'13', N'14', N'22', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-07-29', N'2012088', N'03', N'05', N'23', N'24', N'27', N'31', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-07-31', N'2012089', N'03', N'07', N'10', N'13', N'14', N'25', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-08-02', N'2012090', N'02', N'13', N'20', N'25', N'29', N'30', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-08-05', N'2012091', N'01', N'05', N'07', N'08', N'19', N'21', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-08-07', N'2012092', N'06', N'13', N'17', N'18', N'28', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-08-09', N'2012093', N'03', N'05', N'19', N'21', N'24', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-08-12', N'2012094', N'06', N'09', N'14', N'16', N'23', N'33', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-08-14', N'2012095', N'17', N'24', N'27', N'28', N'29', N'30', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-08-16', N'2012096', N'04', N'07', N'11', N'16', N'29', N'33', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-08-19', N'2012097', N'05', N'08', N'13', N'14', N'19', N'22', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-08-21', N'2012098', N'02', N'12', N'19', N'26', N'29', N'31', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-08-23', N'2012099', N'08', N'12', N'15', N'16', N'21', N'27', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-08-26', N'2012100', N'05', N'07', N'15', N'18', N'25', N'33', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-08-28', N'2012101', N'09', N'12', N'17', N'18', N'20', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-08-30', N'2012102', N'13', N'25', N'27', N'28', N'29', N'30', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-09-02', N'2012103', N'04', N'09', N'11', N'14', N'32', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-09-04', N'2012104', N'04', N'05', N'09', N'10', N'19', N'28', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-09-06', N'2012105', N'06', N'13', N'14', N'15', N'17', N'30', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-09-09', N'2012106', N'13', N'14', N'20', N'22', N'23', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-09-11', N'2012107', N'11', N'12', N'15', N'24', N'25', N'31', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-09-13', N'2012108', N'01', N'09', N'12', N'13', N'19', N'28', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-09-16', N'2012109', N'02', N'12', N'24', N'26', N'29', N'31', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-09-18', N'2012110', N'03', N'07', N'10', N'13', N'22', N'32', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-09-20', N'2012111', N'02', N'09', N'10', N'20', N'22', N'31', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-09-23', N'2012112', N'08', N'15', N'20', N'21', N'27', N'31', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-09-25', N'2012113', N'03', N'06', N'09', N'13', N'18', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-09-27', N'2012114', N'01', N'06', N'11', N'26', N'27', N'29', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-09-30', N'2012115', N'03', N'08', N'20', N'24', N'26', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-10-02', N'2012116', N'03', N'21', N'26', N'29', N'31', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-10-04', N'2012117', N'13', N'15', N'18', N'20', N'24', N'28', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-10-07', N'2012118', N'05', N'06', N'07', N'12', N'15', N'28', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-10-09', N'2012119', N'12', N'20', N'25', N'26', N'27', N'28', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-10-11', N'2012120', N'01', N'04', N'20', N'24', N'28', N'29', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-10-14', N'2012121', N'01', N'07', N'08', N'20', N'23', N'24', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-10-16', N'2012122', N'12', N'13', N'19', N'22', N'28', N'29', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-10-18', N'2012123', N'08', N'10', N'16', N'25', N'28', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-10-21', N'2012124', N'06', N'07', N'21', N'25', N'27', N'33', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-10-23', N'2012125', N'08', N'12', N'13', N'26', N'29', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-10-25', N'2012126', N'03', N'05', N'12', N'15', N'23', N'24', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-10-28', N'2012127', N'01', N'09', N'11', N'21', N'26', N'32', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-10-30', N'2012128', N'05', N'09', N'12', N'29', N'30', N'31', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-11-01', N'2012129', N'01', N'07', N'09', N'17', N'21', N'29', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-11-04', N'2012130', N'01', N'03', N'15', N'20', N'22', N'31', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-11-06', N'2012131', N'06', N'18', N'19', N'26', N'28', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-11-08', N'2012132', N'07', N'12', N'16', N'17', N'21', N'25', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-11-11', N'2012133', N'01', N'08', N'11', N'20', N'21', N'29', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-11-13', N'2012134', N'02', N'05', N'06', N'07', N'13', N'23', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-11-15', N'2012135', N'02', N'05', N'07', N'08', N'11', N'17', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-11-18', N'2012136', N'02', N'07', N'08', N'17', N'21', N'28', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-11-20', N'2012137', N'01', N'02', N'04', N'06', N'13', N'17', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-11-22', N'2012138', N'01', N'07', N'16', N'17', N'19', N'21', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-11-25', N'2012139', N'08', N'19', N'21', N'24', N'28', N'31', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-11-27', N'2012140', N'14', N'18', N'27', N'30', N'31', N'33', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-11-29', N'2012141', N'03', N'05', N'08', N'19', N'20', N'27', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-12-02', N'2012142', N'05', N'18', N'22', N'28', N'29', N'31', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-12-04', N'2012143', N'07', N'08', N'18', N'25', N'30', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-12-06', N'2012144', N'03', N'10', N'12', N'13', N'27', N'30', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-12-09', N'2012145', N'05', N'20', N'26', N'27', N'28', N'33', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-12-11', N'2012146', N'01', N'05', N'07', N'13', N'29', N'32', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-12-13', N'2012147', N'02', N'12', N'15', N'23', N'24', N'32', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-12-16', N'2012148', N'03', N'06', N'11', N'17', N'21', N'31', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-12-18', N'2012149', N'01', N'05', N'13', N'25', N'26', N'32', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-12-20', N'2012150', N'09', N'11', N'17', N'23', N'24', N'26', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-12-23', N'2012151', N'05', N'14', N'24', N'25', N'26', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-12-25', N'2012152', N'10', N'12', N'18', N'22', N'28', N'29', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-12-27', N'2012153', N'04', N'05', N'11', N'21', N'27', N'28', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2012-12-30', N'2012154', N'05', N'07', N'12', N'16', N'28', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-01-01', N'2013001', N'06', N'08', N'14', N'15', N'24', N'25', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-01-03', N'2013002', N'01', N'16', N'18', N'22', N'28', N'30', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-01-06', N'2013003', N'22', N'23', N'26', N'27', N'28', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-01-08', N'2013004', N'06', N'10', N'16', N'20', N'27', N'32', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-01-10', N'2013005', N'01', N'13', N'14', N'25', N'31', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-01-13', N'2013006', N'09', N'10', N'13', N'17', N'22', N'30', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-01-15', N'2013007', N'02', N'09', N'15', N'22', N'26', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-01-17', N'2013008', N'03', N'08', N'17', N'21', N'25', N'32', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-01-20', N'2013009', N'01', N'04', N'09', N'13', N'16', N'23', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-01-22', N'2013010', N'01', N'09', N'11', N'17', N'32', N'33', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-01-24', N'2013011', N'03', N'12', N'17', N'24', N'27', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-01-27', N'2013012', N'06', N'14', N'17', N'22', N'28', N'29', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-01-29', N'2013013', N'05', N'06', N'13', N'19', N'22', N'28', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-01-31', N'2013014', N'02', N'04', N'05', N'17', N'19', N'20', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-02-03', N'2013015', N'05', N'06', N'07', N'11', N'13', N'18', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-02-05', N'2013016', N'02', N'05', N'06', N'12', N'14', N'28', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-02-07', N'2013017', N'04', N'06', N'12', N'30', N'31', N'32', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-02-17', N'2013018', N'02', N'08', N'13', N'28', N'29', N'30', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-02-19', N'2013019', N'01', N'02', N'05', N'16', N'20', N'26', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-02-21', N'2013020', N'01', N'07', N'08', N'12', N'16', N'21', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-02-24', N'2013021', N'01', N'06', N'17', N'19', N'26', N'31', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-02-26', N'2013022', N'02', N'04', N'07', N'09', N'15', N'20', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-02-28', N'2013023', N'03', N'06', N'15', N'18', N'30', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-03-03', N'2013024', N'04', N'05', N'13', N'23', N'27', N'30', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-03-05', N'2013025', N'16', N'17', N'18', N'24', N'25', N'30', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-03-07', N'2013026', N'04', N'11', N'14', N'15', N'22', N'31', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-03-10', N'2013027', N'01', N'02', N'04', N'12', N'21', N'24', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-03-12', N'2013028', N'07', N'08', N'14', N'25', N'26', N'28', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-03-14', N'2013029', N'06', N'07', N'10', N'19', N'23', N'29', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-03-17', N'2013030', N'07', N'14', N'18', N'25', N'26', N'29', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-03-19', N'2013031', N'03', N'13', N'14', N'15', N'21', N'33', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-03-21', N'2013032', N'04', N'21', N'25', N'29', N'30', N'33', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-03-24', N'2013033', N'05', N'06', N'13', N'17', N'19', N'28', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-03-26', N'2013034', N'06', N'15', N'20', N'22', N'26', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-03-28', N'2013035', N'01', N'14', N'15', N'17', N'26', N'30', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-03-31', N'2013036', N'04', N'05', N'09', N'27', N'29', N'31', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-04-02', N'2013037', N'02', N'15', N'18', N'27', N'28', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-04-04', N'2013038', N'09', N'10', N'12', N'14', N'15', N'19', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-04-07', N'2013039', N'01', N'02', N'14', N'15', N'24', N'29', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-04-09', N'2013040', N'02', N'04', N'10', N'12', N'17', N'30', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-04-11', N'2013041', N'02', N'10', N'12', N'17', N'23', N'24', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-04-14', N'2013042', N'01', N'08', N'12', N'13', N'15', N'33', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-04-16', N'2013043', N'03', N'06', N'14', N'15', N'17', N'25', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-04-18', N'2013044', N'03', N'05', N'11', N'18', N'26', N'28', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-04-21', N'2013045', N'06', N'07', N'08', N'14', N'23', N'31', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-04-23', N'2013046', N'03', N'16', N'19', N'20', N'24', N'26', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-04-25', N'2013047', N'01', N'08', N'11', N'17', N'27', N'30', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-04-28', N'2013048', N'10', N'13', N'17', N'28', N'30', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-04-30', N'2013049', N'10', N'13', N'14', N'16', N'21', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-05-02', N'2013050', N'03', N'07', N'13', N'18', N'22', N'25', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-05-05', N'2013051', N'08', N'12', N'15', N'19', N'28', N'29', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-05-07', N'2013052', N'06', N'07', N'14', N'21', N'22', N'24', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-05-09', N'2013053', N'03', N'12', N'13', N'22', N'30', N'33', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-05-12', N'2013054', N'03', N'04', N'08', N'14', N'21', N'28', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-05-14', N'2013055', N'08', N'18', N'19', N'22', N'27', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-05-16', N'2013056', N'03', N'12', N'25', N'26', N'28', N'29', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-05-19', N'2013057', N'13', N'16', N'19', N'23', N'26', N'28', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-05-21', N'2013058', N'08', N'11', N'17', N'21', N'23', N'24', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-05-23', N'2013059', N'03', N'10', N'18', N'24', N'27', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-05-26', N'2013060', N'05', N'07', N'10', N'13', N'19', N'20', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-05-28', N'2013061', N'05', N'06', N'07', N'12', N'13', N'18', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-05-30', N'2013062', N'01', N'06', N'07', N'19', N'22', N'27', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-06-02', N'2013063', N'10', N'15', N'18', N'20', N'23', N'31', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-06-04', N'2013064', N'01', N'09', N'13', N'22', N'25', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-06-06', N'2013065', N'07', N'18', N'19', N'23', N'29', N'30', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-06-09', N'2013066', N'01', N'03', N'16', N'17', N'20', N'32', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-06-11', N'2013067', N'01', N'04', N'09', N'15', N'22', N'30', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-06-13', N'2013068', N'02', N'07', N'13', N'20', N'25', N'27', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-06-16', N'2013069', N'07', N'16', N'17', N'18', N'30', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-06-18', N'2013070', N'02', N'03', N'09', N'10', N'28', N'30', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-06-20', N'2013071', N'05', N'12', N'21', N'23', N'26', N'28', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-06-23', N'2013072', N'02', N'08', N'11', N'14', N'19', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-06-25', N'2013073', N'02', N'09', N'13', N'17', N'20', N'28', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-06-27', N'2013074', N'03', N'06', N'08', N'14', N'19', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-06-30', N'2013075', N'04', N'06', N'09', N'25', N'30', N'33', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-07-02', N'2013076', N'14', N'23', N'24', N'26', N'29', N'30', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-07-04', N'2013077', N'09', N'14', N'23', N'24', N'26', N'29', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-07-07', N'2013078', N'03', N'05', N'17', N'18', N'26', N'27', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-07-09', N'2013079', N'07', N'13', N'17', N'19', N'22', N'26', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-07-11', N'2013080', N'10', N'11', N'12', N'23', N'28', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-07-14', N'2013081', N'01', N'04', N'10', N'13', N'21', N'31', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-07-16', N'2013082', N'04', N'13', N'14', N'20', N'22', N'30', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-07-18', N'2013083', N'05', N'06', N'12', N'14', N'19', N'23', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-07-21', N'2013084', N'05', N'07', N'09', N'11', N'20', N'21', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-07-23', N'2013085', N'02', N'08', N'12', N'14', N'16', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-07-25', N'2013086', N'02', N'04', N'11', N'13', N'16', N'26', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-07-28', N'2013087', N'02', N'13', N'19', N'23', N'24', N'28', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-07-30', N'2013088', N'09', N'15', N'20', N'21', N'22', N'24', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-08-01', N'2013089', N'04', N'08', N'12', N'19', N'21', N'25', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-08-04', N'2013090', N'02', N'05', N'11', N'23', N'24', N'29', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-08-06', N'2013091', N'04', N'14', N'24', N'25', N'28', N'31', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-08-08', N'2013092', N'07', N'11', N'15', N'21', N'26', N'31', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-08-11', N'2013093', N'01', N'02', N'08', N'26', N'29', N'31', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-08-13', N'2013094', N'02', N'04', N'14', N'18', N'20', N'22', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-08-15', N'2013095', N'01', N'06', N'15', N'19', N'28', N'29', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-08-18', N'2013096', N'01', N'02', N'22', N'28', N'29', N'30', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-08-20', N'2013097', N'05', N'14', N'17', N'22', N'23', N'25', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-08-22', N'2013098', N'07', N'15', N'18', N'19', N'20', N'26', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-08-25', N'2013099', N'05', N'11', N'20', N'21', N'26', N'31', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-08-27', N'2013100', N'04', N'08', N'11', N'14', N'16', N'20', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-08-29', N'2013101', N'05', N'07', N'09', N'23', N'27', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-09-01', N'2013102', N'02', N'04', N'05', N'06', N'08', N'16', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-09-03', N'2013103', N'02', N'04', N'09', N'13', N'18', N'20', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-09-05', N'2013104', N'01', N'02', N'04', N'15', N'17', N'28', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-09-08', N'2013105', N'01', N'11', N'23', N'27', N'31', N'32', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-09-10', N'2013106', N'09', N'11', N'23', N'30', N'31', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-09-12', N'2013107', N'07', N'09', N'11', N'17', N'28', N'31', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-09-15', N'2013108', N'16', N'21', N'22', N'28', N'31', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-09-17', N'2013109', N'09', N'23', N'24', N'27', N'29', N'32', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-09-19', N'2013110', N'15', N'17', N'18', N'21', N'29', N'32', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-09-22', N'2013111', N'01', N'02', N'03', N'06', N'08', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-09-24', N'2013112', N'01', N'06', N'12', N'13', N'22', N'31', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-09-26', N'2013113', N'04', N'07', N'11', N'17', N'24', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-09-29', N'2013114', N'04', N'06', N'17', N'21', N'23', N'33', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-10-01', N'2013115', N'03', N'12', N'16', N'17', N'18', N'27', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-10-03', N'2013116', N'12', N'15', N'21', N'26', N'32', N'33', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-10-06', N'2013117', N'09', N'12', N'13', N'24', N'27', N'33', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-10-08', N'2013118', N'02', N'03', N'17', N'22', N'32', N'33', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-10-10', N'2013119', N'05', N'15', N'20', N'22', N'26', N'32', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-10-13', N'2013120', N'05', N'06', N'13', N'18', N'23', N'31', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-10-15', N'2013121', N'04', N'05', N'06', N'07', N'25', N'27', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-10-17', N'2013122', N'07', N'10', N'13', N'15', N'26', N'27', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-10-20', N'2013123', N'01', N'02', N'06', N'11', N'17', N'25', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-10-22', N'2013124', N'03', N'09', N'15', N'23', N'25', N'30', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-10-24', N'2013125', N'04', N'06', N'08', N'18', N'25', N'28', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-10-27', N'2013126', N'04', N'10', N'19', N'27', N'31', N'33', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-10-29', N'2013127', N'02', N'03', N'13', N'20', N'22', N'33', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-10-31', N'2013128', N'07', N'13', N'17', N'19', N'25', N'31', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-11-03', N'2013129', N'05', N'06', N'10', N'14', N'27', N'31', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-11-05', N'2013130', N'01', N'03', N'15', N'16', N'31', N'33', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-11-07', N'2013131', N'04', N'06', N'12', N'17', N'19', N'26', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-11-10', N'2013132', N'20', N'21', N'22', N'23', N'25', N'27', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-11-12', N'2013133', N'04', N'07', N'12', N'19', N'22', N'25', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-11-14', N'2013134', N'01', N'17', N'18', N'19', N'25', N'29', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-11-17', N'2013135', N'09', N'23', N'24', N'25', N'29', N'31', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-11-19', N'2013136', N'04', N'06', N'14', N'16', N'18', N'26', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-11-21', N'2013137', N'04', N'17', N'19', N'23', N'24', N'27', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-11-24', N'2013138', N'04', N'15', N'16', N'24', N'27', N'28', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-11-26', N'2013139', N'07', N'08', N'11', N'13', N'21', N'27', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-11-28', N'2013140', N'01', N'05', N'12', N'13', N'21', N'22', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-12-01', N'2013141', N'03', N'04', N'05', N'25', N'30', N'31', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-12-03', N'2013142', N'11', N'12', N'14', N'20', N'22', N'29', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-12-05', N'2013143', N'12', N'18', N'21', N'22', N'27', N'32', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-12-08', N'2013144', N'05', N'07', N'12', N'19', N'27', N'31', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-12-10', N'2013145', N'06', N'10', N'13', N'16', N'23', N'24', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-12-12', N'2013146', N'08', N'20', N'25', N'30', N'32', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-12-15', N'2013147', N'02', N'15', N'16', N'17', N'19', N'30', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-12-17', N'2013148', N'06', N'11', N'12', N'14', N'17', N'22', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-12-19', N'2013149', N'09', N'18', N'25', N'26', N'30', N'32', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-12-22', N'2013150', N'01', N'15', N'16', N'25', N'26', N'29', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-12-24', N'2013151', N'03', N'09', N'10', N'19', N'28', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-12-26', N'2013152', N'04', N'06', N'14', N'16', N'18', N'29', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-12-29', N'2013153', N'08', N'11', N'13', N'18', N'28', N'33', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2013-12-31', N'2013154', N'07', N'11', N'14', N'19', N'24', N'29', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-01-02', N'2014001', N'03', N'09', N'15', N'20', N'27', N'29', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-01-05', N'2014002', N'04', N'21', N'23', N'31', N'32', N'33', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-01-07', N'2014003', N'06', N'10', N'11', N'28', N'30', N'33', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-01-09', N'2014004', N'01', N'04', N'19', N'22', N'24', N'25', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-01-12', N'2014005', N'15', N'18', N'23', N'27', N'32', N'33', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-01-14', N'2014006', N'03', N'04', N'07', N'17', N'21', N'27', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-01-16', N'2014007', N'08', N'10', N'12', N'14', N'18', N'28', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-01-19', N'2014008', N'05', N'14', N'16', N'21', N'29', N'30', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-01-21', N'2014009', N'08', N'09', N'19', N'20', N'25', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-01-23', N'2014010', N'05', N'07', N'08', N'20', N'31', N'33', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-01-26', N'2014011', N'09', N'10', N'13', N'14', N'21', N'32', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-01-28', N'2014012', N'01', N'08', N'11', N'19', N'21', N'24', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-02-09', N'2014013', N'05', N'09', N'13', N'15', N'17', N'21', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-02-11', N'2014014', N'04', N'09', N'19', N'22', N'25', N'29', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-02-13', N'2014015', N'02', N'11', N'19', N'30', N'32', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-02-16', N'2014016', N'02', N'03', N'07', N'13', N'21', N'24', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-02-18', N'2014017', N'04', N'06', N'07', N'14', N'25', N'26', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-02-20', N'2014018', N'13', N'17', N'18', N'21', N'30', N'33', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-02-23', N'2014019', N'02', N'10', N'15', N'19', N'20', N'21', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-02-25', N'2014020', N'09', N'14', N'17', N'23', N'24', N'25', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-02-27', N'2014021', N'08', N'10', N'15', N'17', N'22', N'29', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-03-02', N'2014022', N'04', N'06', N'07', N'10', N'21', N'26', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-03-04', N'2014023', N'07', N'09', N'13', N'17', N'21', N'22', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-03-06', N'2014024', N'08', N'10', N'16', N'20', N'23', N'30', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-03-09', N'2014025', N'01', N'05', N'10', N'14', N'16', N'30', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-03-11', N'2014026', N'01', N'02', N'05', N'06', N'11', N'23', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-03-13', N'2014027', N'08', N'10', N'14', N'16', N'30', N'31', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-03-16', N'2014028', N'06', N'16', N'21', N'27', N'30', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-03-18', N'2014029', N'02', N'07', N'14', N'16', N'21', N'29', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-03-20', N'2014030', N'12', N'18', N'19', N'23', N'24', N'30', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-03-23', N'2014031', N'04', N'10', N'16', N'17', N'21', N'27', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-03-25', N'2014032', N'01', N'02', N'14', N'22', N'29', N'33', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-03-27', N'2014033', N'05', N'13', N'23', N'28', N'32', N'33', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-03-30', N'2014034', N'01', N'03', N'04', N'08', N'25', N'31', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-04-01', N'2014035', N'07', N'08', N'09', N'17', N'32', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-04-03', N'2014036', N'01', N'07', N'08', N'09', N'11', N'22', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-04-06', N'2014037', N'06', N'13', N'14', N'24', N'25', N'30', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-04-08', N'2014038', N'04', N'07', N'22', N'23', N'24', N'33', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-04-10', N'2014039', N'03', N'11', N'15', N'19', N'20', N'31', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-04-13', N'2014040', N'03', N'04', N'06', N'11', N'12', N'15', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-04-15', N'2014041', N'07', N'11', N'16', N'18', N'21', N'22', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-04-17', N'2014042', N'12', N'15', N'20', N'25', N'28', N'33', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-04-20', N'2014043', N'02', N'05', N'09', N'14', N'24', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-04-22', N'2014044', N'04', N'09', N'21', N'27', N'28', N'33', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-04-24', N'2014045', N'02', N'04', N'09', N'11', N'19', N'22', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-04-27', N'2014046', N'02', N'10', N'11', N'17', N'18', N'22', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-04-29', N'2014047', N'08', N'10', N'11', N'12', N'19', N'29', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-05-01', N'2014048', N'06', N'09', N'16', N'17', N'24', N'25', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-05-04', N'2014049', N'06', N'07', N'16', N'17', N'23', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-05-06', N'2014050', N'03', N'17', N'23', N'25', N'26', N'32', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-05-08', N'2014051', N'10', N'16', N'19', N'21', N'23', N'24', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-05-11', N'2014052', N'09', N'13', N'15', N'28', N'30', N'33', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-05-13', N'2014053', N'14', N'17', N'19', N'22', N'26', N'31', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-05-15', N'2014054', N'01', N'04', N'05', N'11', N'29', N'30', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-05-18', N'2014055', N'02', N'09', N'14', N'19', N'21', N'30', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-05-20', N'2014056', N'01', N'11', N'18', N'20', N'28', N'29', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-05-22', N'2014057', N'02', N'04', N'12', N'18', N'23', N'31', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-05-25', N'2014058', N'02', N'03', N'12', N'13', N'14', N'25', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-05-27', N'2014059', N'05', N'08', N'12', N'13', N'23', N'25', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-05-29', N'2014060', N'03', N'05', N'14', N'18', N'25', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-06-01', N'2014061', N'02', N'14', N'17', N'27', N'28', N'31', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-06-03', N'2014062', N'06', N'09', N'15', N'24', N'25', N'26', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-06-05', N'2014063', N'03', N'08', N'17', N'21', N'22', N'31', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-06-08', N'2014064', N'02', N'09', N'15', N'16', N'29', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-06-10', N'2014065', N'03', N'04', N'05', N'08', N'10', N'22', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-06-12', N'2014066', N'02', N'05', N'15', N'17', N'18', N'21', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-06-15', N'2014067', N'01', N'06', N'07', N'17', N'18', N'23', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-06-17', N'2014068', N'04', N'12', N'13', N'22', N'27', N'29', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-06-19', N'2014069', N'05', N'12', N'17', N'19', N'25', N'30', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-06-22', N'2014070', N'01', N'07', N'09', N'19', N'28', N'29', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-06-24', N'2014071', N'02', N'04', N'12', N'17', N'22', N'25', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-06-26', N'2014072', N'01', N'03', N'07', N'13', N'19', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-06-29', N'2014073', N'01', N'12', N'16', N'20', N'30', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-07-01', N'2014074', N'01', N'03', N'06', N'13', N'30', N'31', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-07-03', N'2014075', N'03', N'09', N'11', N'22', N'27', N'29', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-07-06', N'2014076', N'06', N'10', N'12', N'17', N'18', N'33', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-07-08', N'2014077', N'08', N'09', N'12', N'15', N'19', N'22', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-07-10', N'2014078', N'02', N'03', N'05', N'06', N'09', N'17', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-07-13', N'2014079', N'02', N'07', N'16', N'22', N'27', N'28', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-07-15', N'2014080', N'05', N'14', N'16', N'17', N'25', N'30', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-07-17', N'2014081', N'08', N'14', N'22', N'24', N'27', N'29', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-07-20', N'2014082', N'02', N'04', N'20', N'25', N'26', N'29', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-07-22', N'2014083', N'05', N'06', N'19', N'21', N'23', N'33', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-07-24', N'2014084', N'01', N'06', N'09', N'10', N'13', N'25', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-07-27', N'2014085', N'01', N'02', N'11', N'19', N'23', N'29', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-07-29', N'2014086', N'02', N'04', N'10', N'12', N'14', N'30', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-07-31', N'2014087', N'06', N'18', N'22', N'23', N'32', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-08-03', N'2014088', N'03', N'06', N'11', N'14', N'16', N'29', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-08-05', N'2014089', N'04', N'06', N'14', N'17', N'27', N'30', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-08-07', N'2014090', N'05', N'09', N'11', N'19', N'24', N'32', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-08-10', N'2014091', N'01', N'05', N'12', N'19', N'27', N'29', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-08-12', N'2014092', N'03', N'13', N'18', N'19', N'22', N'26', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-08-14', N'2014093', N'02', N'08', N'09', N'10', N'20', N'29', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-08-17', N'2014094', N'01', N'10', N'18', N'20', N'23', N'29', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-08-19', N'2014095', N'05', N'06', N'08', N'14', N'22', N'31', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-08-21', N'2014096', N'12', N'14', N'17', N'19', N'22', N'24', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-08-24', N'2014097', N'07', N'13', N'24', N'25', N'27', N'32', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-08-26', N'2014098', N'02', N'13', N'17', N'20', N'29', N'31', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-08-28', N'2014099', N'01', N'05', N'10', N'11', N'13', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-08-31', N'2014100', N'01', N'06', N'09', N'10', N'14', N'16', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-09-02', N'2014101', N'16', N'18', N'20', N'23', N'24', N'32', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-09-04', N'2014102', N'14', N'16', N'21', N'24', N'28', N'31', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-09-07', N'2014103', N'03', N'08', N'09', N'10', N'18', N'33', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-09-09', N'2014104', N'02', N'06', N'12', N'19', N'27', N'28', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-09-11', N'2014105', N'14', N'16', N'17', N'19', N'27', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-09-14', N'2014106', N'09', N'14', N'17', N'18', N'21', N'25', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-09-16', N'2014107', N'11', N'14', N'17', N'22', N'25', N'27', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-09-18', N'2014108', N'03', N'08', N'09', N'20', N'23', N'28', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-09-21', N'2014109', N'02', N'05', N'11', N'15', N'19', N'28', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-09-23', N'2014110', N'01', N'08', N'11', N'13', N'19', N'30', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-09-25', N'2014111', N'02', N'08', N'17', N'20', N'22', N'28', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-09-28', N'2014112', N'01', N'15', N'16', N'21', N'24', N'30', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-09-30', N'2014113', N'12', N'14', N'28', N'31', N'32', N'33', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-10-02', N'2014114', N'02', N'07', N'23', N'30', N'32', N'33', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-10-05', N'2014115', N'01', N'09', N'10', N'11', N'13', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-10-07', N'2014116', N'09', N'10', N'14', N'15', N'19', N'29', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-10-09', N'2014117', N'05', N'10', N'17', N'25', N'28', N'29', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-10-12', N'2014118', N'05', N'07', N'15', N'18', N'26', N'30', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-10-14', N'2014119', N'06', N'13', N'17', N'20', N'26', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-10-16', N'2014120', N'01', N'07', N'12', N'16', N'23', N'28', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-10-19', N'2014121', N'01', N'02', N'13', N'22', N'28', N'30', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-10-21', N'2014122', N'06', N'09', N'11', N'16', N'20', N'29', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-10-23', N'2014123', N'01', N'06', N'11', N'17', N'28', N'33', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-10-26', N'2014124', N'02', N'17', N'20', N'24', N'31', N'33', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-10-28', N'2014125', N'10', N'11', N'15', N'26', N'31', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-10-30', N'2014126', N'06', N'11', N'16', N'17', N'22', N'27', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-11-02', N'2014127', N'02', N'10', N'12', N'21', N'23', N'27', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-11-04', N'2014128', N'05', N'07', N'08', N'17', N'18', N'24', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-11-06', N'2014129', N'05', N'08', N'09', N'20', N'28', N'32', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-11-09', N'2014130', N'01', N'02', N'10', N'24', N'30', N'33', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-11-11', N'2014131', N'05', N'17', N'21', N'22', N'28', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-11-13', N'2014132', N'05', N'06', N'14', N'15', N'18', N'33', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-11-16', N'2014133', N'13', N'14', N'16', N'23', N'30', N'31', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-11-18', N'2014134', N'05', N'16', N'22', N'23', N'26', N'28', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-11-20', N'2014135', N'02', N'04', N'11', N'13', N'25', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-11-23', N'2014136', N'03', N'16', N'19', N'27', N'31', N'32', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-11-25', N'2014137', N'03', N'06', N'09', N'11', N'25', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-11-27', N'2014138', N'04', N'06', N'13', N'29', N'31', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-11-30', N'2014139', N'01', N'14', N'15', N'20', N'25', N'29', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-12-02', N'2014140', N'06', N'10', N'11', N'14', N'17', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-12-04', N'2014141', N'08', N'09', N'11', N'16', N'21', N'24', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-12-07', N'2014142', N'06', N'21', N'22', N'23', N'25', N'28', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-12-09', N'2014143', N'03', N'12', N'18', N'20', N'25', N'26', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-12-11', N'2014144', N'03', N'05', N'06', N'09', N'10', N'27', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-12-14', N'2014145', N'10', N'12', N'13', N'23', N'26', N'29', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-12-16', N'2014146', N'01', N'06', N'13', N'20', N'29', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-12-18', N'2014147', N'06', N'07', N'22', N'26', N'31', N'32', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-12-21', N'2014148', N'01', N'02', N'05', N'12', N'15', N'16', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-12-23', N'2014149', N'07', N'09', N'10', N'15', N'19', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-12-25', N'2014150', N'03', N'08', N'14', N'22', N'24', N'32', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-12-28', N'2014151', N'04', N'05', N'08', N'11', N'21', N'27', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2014-12-30', N'2014152', N'08', N'13', N'15', N'20', N'21', N'25', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-01-01', N'2015001', N'01', N'07', N'09', N'16', N'20', N'23', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-01-04', N'2015002', N'07', N'15', N'16', N'25', N'28', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-01-06', N'2015003', N'10', N'15', N'20', N'23', N'24', N'31', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-01-08', N'2015004', N'02', N'14', N'15', N'16', N'23', N'24', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-01-11', N'2015005', N'07', N'10', N'16', N'17', N'18', N'32', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-01-13', N'2015006', N'01', N'10', N'11', N'29', N'31', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-01-15', N'2015007', N'01', N'07', N'09', N'17', N'20', N'33', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-01-18', N'2015008', N'04', N'07', N'10', N'16', N'20', N'22', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-01-20', N'2015009', N'04', N'07', N'14', N'17', N'21', N'25', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-01-22', N'2015010', N'01', N'02', N'03', N'08', N'21', N'31', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-01-25', N'2015011', N'04', N'14', N'15', N'17', N'18', N'20', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-01-27', N'2015012', N'03', N'05', N'22', N'23', N'29', N'31', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-01-29', N'2015013', N'08', N'09', N'24', N'25', N'26', N'29', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-02-01', N'2015014', N'02', N'12', N'16', N'19', N'27', N'30', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-02-03', N'2015015', N'01', N'07', N'20', N'24', N'25', N'33', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-02-05', N'2015016', N'02', N'06', N'10', N'15', N'17', N'31', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-02-08', N'2015017', N'13', N'18', N'20', N'25', N'27', N'33', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-02-10', N'2015018', N'06', N'09', N'12', N'14', N'28', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-02-12', N'2015019', N'02', N'06', N'11', N'19', N'25', N'26', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-02-15', N'2015020', N'01', N'04', N'07', N'19', N'22', N'23', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-02-17', N'2015021', N'14', N'15', N'16', N'17', N'27', N'28', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-02-26', N'2015022', N'04', N'07', N'10', N'16', N'23', N'25', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-03-01', N'2015023', N'08', N'09', N'10', N'13', N'29', N'30', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-03-03', N'2015024', N'09', N'11', N'16', N'18', N'23', N'24', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-03-05', N'2015025', N'10', N'11', N'12', N'15', N'27', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-03-08', N'2015026', N'02', N'13', N'17', N'21', N'22', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-03-10', N'2015027', N'05', N'07', N'09', N'16', N'26', N'29', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-03-12', N'2015028', N'04', N'07', N'10', N'26', N'27', N'28', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-03-15', N'2015029', N'07', N'14', N'15', N'19', N'21', N'28', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-03-17', N'2015030', N'08', N'11', N'14', N'15', N'16', N'26', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-03-19', N'2015031', N'01', N'05', N'07', N'22', N'26', N'32', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-03-22', N'2015032', N'11', N'14', N'16', N'18', N'29', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-03-24', N'2015033', N'03', N'06', N'21', N'29', N'31', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-03-26', N'2015034', N'12', N'13', N'17', N'18', N'20', N'27', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-03-29', N'2015035', N'01', N'08', N'09', N'22', N'24', N'33', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-03-31', N'2015036', N'04', N'06', N'16', N'17', N'26', N'33', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-04-02', N'2015037', N'05', N'07', N'12', N'18', N'28', N'31', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-04-05', N'2015038', N'05', N'06', N'11', N'12', N'14', N'33', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-04-07', N'2015039', N'01', N'13', N'15', N'26', N'29', N'30', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-04-09', N'2015040', N'13', N'16', N'18', N'27', N'30', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-04-12', N'2015041', N'04', N'09', N'11', N'17', N'21', N'25', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-04-14', N'2015042', N'09', N'10', N'19', N'21', N'23', N'32', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-04-16', N'2015043', N'11', N'12', N'15', N'24', N'26', N'27', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-04-19', N'2015044', N'02', N'03', N'04', N'13', N'14', N'16', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-04-21', N'2015045', N'01', N'05', N'13', N'22', N'30', N'31', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-04-23', N'2015046', N'05', N'07', N'10', N'14', N'23', N'31', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-04-26', N'2015047', N'02', N'03', N'20', N'24', N'26', N'27', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-04-28', N'2015048', N'13', N'16', N'17', N'22', N'25', N'27', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-04-30', N'2015049', N'07', N'12', N'14', N'17', N'20', N'23', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-05-03', N'2015050', N'03', N'09', N'12', N'16', N'17', N'31', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-05-05', N'2015051', N'04', N'10', N'24', N'26', N'28', N'32', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-05-07', N'2015052', N'02', N'04', N'11', N'16', N'25', N'26', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-05-10', N'2015053', N'03', N'07', N'17', N'22', N'32', N'33', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-05-12', N'2015054', N'01', N'02', N'07', N'10', N'22', N'26', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-05-14', N'2015055', N'01', N'10', N'15', N'18', N'19', N'28', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-05-17', N'2015056', N'01', N'07', N'08', N'16', N'18', N'20', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-05-19', N'2015057', N'09', N'20', N'24', N'25', N'26', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-05-21', N'2015058', N'02', N'09', N'10', N'18', N'19', N'20', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-05-24', N'2015059', N'02', N'06', N'09', N'16', N'25', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-05-26', N'2015060', N'01', N'03', N'18', N'27', N'31', N'32', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-05-28', N'2015061', N'06', N'18', N'22', N'26', N'32', N'33', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-05-31', N'2015062', N'09', N'14', N'15', N'18', N'21', N'26', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-06-02', N'2015063', N'01', N'07', N'09', N'16', N'22', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-06-04', N'2015064', N'11', N'12', N'14', N'17', N'23', N'27', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-06-07', N'2015065', N'08', N'10', N'14', N'19', N'26', N'29', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-06-09', N'2015066', N'05', N'08', N'11', N'17', N'24', N'28', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-06-11', N'2015067', N'02', N'05', N'08', N'24', N'25', N'31', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-06-14', N'2015068', N'06', N'15', N'18', N'21', N'26', N'27', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-06-16', N'2015069', N'01', N'13', N'17', N'18', N'23', N'30', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-06-18', N'2015070', N'01', N'07', N'13', N'19', N'21', N'29', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-06-21', N'2015071', N'08', N'18', N'20', N'28', N'29', N'31', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-06-23', N'2015072', N'01', N'03', N'05', N'20', N'21', N'31', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-06-25', N'2015073', N'01', N'02', N'17', N'22', N'26', N'27', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-06-28', N'2015074', N'04', N'07', N'21', N'25', N'26', N'29', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-06-30', N'2015075', N'06', N'11', N'13', N'19', N'21', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-07-02', N'2015076', N'01', N'09', N'10', N'19', N'23', N'27', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-07-05', N'2015077', N'01', N'06', N'08', N'10', N'13', N'27', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-07-07', N'2015078', N'03', N'07', N'20', N'22', N'26', N'29', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-07-09', N'2015079', N'09', N'14', N'15', N'20', N'26', N'32', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-07-12', N'2015080', N'14', N'17', N'25', N'27', N'28', N'30', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-07-14', N'2015081', N'13', N'20', N'22', N'26', N'28', N'31', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-07-16', N'2015082', N'02', N'08', N'09', N'14', N'28', N'30', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-07-19', N'2015083', N'06', N'07', N'16', N'18', N'29', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-07-21', N'2015084', N'15', N'18', N'20', N'22', N'28', N'29', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-07-23', N'2015085', N'02', N'08', N'25', N'27', N'28', N'29', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-07-26', N'2015086', N'05', N'06', N'08', N'16', N'18', N'22', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-07-28', N'2015087', N'09', N'15', N'16', N'19', N'20', N'28', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-07-30', N'2015088', N'02', N'12', N'20', N'24', N'29', N'31', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-08-02', N'2015089', N'12', N'14', N'19', N'27', N'28', N'29', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-08-04', N'2015090', N'10', N'12', N'14', N'22', N'25', N'33', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-08-06', N'2015091', N'05', N'07', N'17', N'19', N'22', N'31', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-08-09', N'2015092', N'09', N'15', N'19', N'21', N'26', N'27', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-08-11', N'2015093', N'01', N'03', N'13', N'21', N'25', N'31', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-08-13', N'2015094', N'01', N'04', N'06', N'13', N'16', N'17', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-08-16', N'2015095', N'04', N'15', N'21', N'28', N'30', N'31', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-08-18', N'2015096', N'06', N'16', N'17', N'23', N'24', N'31', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-08-20', N'2015097', N'09', N'12', N'14', N'20', N'26', N'27', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-08-23', N'2015098', N'06', N'09', N'13', N'26', N'27', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-08-25', N'2015099', N'06', N'07', N'10', N'11', N'14', N'22', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-08-27', N'2015100', N'02', N'03', N'11', N'17', N'19', N'21', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-08-30', N'2015101', N'08', N'16', N'22', N'24', N'28', N'29', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-09-01', N'2015102', N'07', N'09', N'12', N'14', N'21', N'23', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-09-03', N'2015103', N'06', N'08', N'13', N'26', N'30', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-09-06', N'2015104', N'09', N'18', N'21', N'23', N'25', N'26', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-09-08', N'2015105', N'09', N'10', N'16', N'19', N'20', N'26', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-09-10', N'2015106', N'01', N'03', N'04', N'23', N'31', N'32', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-09-13', N'2015107', N'07', N'14', N'16', N'18', N'21', N'25', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-09-15', N'2015108', N'02', N'12', N'19', N'22', N'24', N'27', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-09-17', N'2015109', N'01', N'08', N'09', N'16', N'32', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-09-20', N'2015110', N'05', N'07', N'16', N'17', N'22', N'23', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-09-22', N'2015111', N'08', N'14', N'16', N'18', N'20', N'30', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-09-24', N'2015112', N'01', N'03', N'10', N'19', N'20', N'27', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-09-27', N'2015113', N'01', N'05', N'07', N'08', N'19', N'27', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-09-29', N'2015114', N'04', N'07', N'09', N'13', N'21', N'26', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-10-01', N'2015115', N'01', N'07', N'08', N'14', N'24', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-10-04', N'2015116', N'04', N'06', N'15', N'23', N'26', N'28', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-10-06', N'2015117', N'04', N'11', N'12', N'18', N'26', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-10-08', N'2015118', N'01', N'04', N'11', N'21', N'23', N'31', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-10-11', N'2015119', N'02', N'08', N'10', N'18', N'23', N'31', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-10-13', N'2015120', N'16', N'21', N'24', N'26', N'27', N'29', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-10-15', N'2015121', N'01', N'03', N'20', N'21', N'28', N'29', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-10-18', N'2015122', N'05', N'07', N'11', N'16', N'22', N'25', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-10-20', N'2015123', N'05', N'08', N'09', N'12', N'22', N'28', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-10-22', N'2015124', N'02', N'03', N'05', N'12', N'18', N'27', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-10-25', N'2015125', N'05', N'13', N'22', N'27', N'30', N'33', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-10-27', N'2015126', N'10', N'11', N'15', N'20', N'23', N'29', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-10-29', N'2015127', N'07', N'10', N'19', N'22', N'27', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-11-01', N'2015128', N'01', N'03', N'08', N'11', N'22', N'28', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-11-03', N'2015129', N'05', N'08', N'11', N'16', N'18', N'27', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-11-05', N'2015130', N'06', N'14', N'15', N'16', N'17', N'22', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-11-08', N'2015131', N'10', N'12', N'13', N'19', N'22', N'26', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-11-10', N'2015132', N'03', N'05', N'11', N'28', N'30', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-11-12', N'2015133', N'02', N'03', N'13', N'20', N'22', N'24', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-11-15', N'2015134', N'02', N'05', N'14', N'19', N'27', N'31', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-11-17', N'2015135', N'01', N'12', N'14', N'18', N'26', N'32', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-11-19', N'2015136', N'02', N'05', N'12', N'23', N'28', N'29', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-11-22', N'2015137', N'14', N'22', N'23', N'27', N'28', N'31', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-11-24', N'2015138', N'01', N'02', N'08', N'16', N'19', N'24', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-11-26', N'2015139', N'01', N'10', N'13', N'18', N'25', N'27', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-11-29', N'2015140', N'06', N'20', N'28', N'29', N'30', N'31', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-12-01', N'2015141', N'03', N'08', N'19', N'25', N'27', N'28', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-12-03', N'2015142', N'13', N'17', N'19', N'20', N'22', N'25', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-12-06', N'2015143', N'13', N'15', N'19', N'20', N'21', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-12-08', N'2015144', N'01', N'04', N'07', N'15', N'28', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-12-10', N'2015145', N'07', N'08', N'15', N'19', N'20', N'24', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-12-13', N'2015146', N'16', N'17', N'21', N'28', N'30', N'32', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-12-15', N'2015147', N'08', N'09', N'16', N'23', N'24', N'30', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-12-17', N'2015148', N'09', N'13', N'14', N'22', N'26', N'27', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-12-20', N'2015149', N'09', N'10', N'20', N'21', N'22', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-12-22', N'2015150', N'01', N'03', N'08', N'11', N'29', N'31', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-12-24', N'2015151', N'05', N'06', N'08', N'23', N'31', N'32', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-12-27', N'2015152', N'11', N'18', N'19', N'21', N'29', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-12-29', N'2015153', N'08', N'11', N'15', N'22', N'27', N'29', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2015-12-31', N'2015154', N'07', N'09', N'11', N'15', N'18', N'25', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-01-03', N'2016001', N'06', N'13', N'16', N'18', N'20', N'22', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-01-05', N'2016002', N'09', N'14', N'17', N'20', N'24', N'30', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-01-07', N'2016003', N'01', N'10', N'14', N'23', N'26', N'28', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-01-10', N'2016004', N'08', N'10', N'17', N'22', N'25', N'33', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-01-12', N'2016005', N'11', N'14', N'18', N'20', N'31', N'33', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-01-14', N'2016006', N'13', N'16', N'18', N'20', N'28', N'31', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-01-17', N'2016007', N'05', N'12', N'14', N'20', N'27', N'29', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-01-19', N'2016008', N'02', N'15', N'24', N'29', N'32', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-01-21', N'2016009', N'10', N'14', N'24', N'25', N'27', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-01-24', N'2016010', N'02', N'04', N'12', N'14', N'19', N'25', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-01-26', N'2016011', N'03', N'08', N'10', N'15', N'22', N'29', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-01-28', N'2016012', N'07', N'12', N'14', N'16', N'27', N'32', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-01-31', N'2016013', N'07', N'12', N'21', N'22', N'26', N'31', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-02-02', N'2016014', N'02', N'08', N'10', N'18', N'20', N'27', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-02-04', N'2016015', N'01', N'02', N'14', N'22', N'25', N'26', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-02-14', N'2016016', N'01', N'20', N'22', N'24', N'25', N'26', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-02-16', N'2016017', N'05', N'06', N'08', N'20', N'22', N'30', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-02-18', N'2016018', N'12', N'13', N'14', N'17', N'21', N'25', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-02-21', N'2016019', N'06', N'13', N'16', N'17', N'23', N'30', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-02-23', N'2016020', N'01', N'02', N'10', N'12', N'22', N'24', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-02-25', N'2016021', N'09', N'11', N'13', N'22', N'24', N'26', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-02-28', N'2016022', N'04', N'09', N'19', N'22', N'23', N'30', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-03-01', N'2016023', N'03', N'06', N'10', N'19', N'25', N'29', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-03-03', N'2016024', N'02', N'05', N'07', N'14', N'18', N'31', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-03-06', N'2016025', N'04', N'11', N'12', N'17', N'24', N'30', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-03-08', N'2016026', N'04', N'09', N'12', N'28', N'30', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-03-10', N'2016027', N'11', N'13', N'15', N'17', N'19', N'31', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-03-13', N'2016028', N'06', N'08', N'12', N'21', N'25', N'29', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-03-15', N'2016029', N'12', N'15', N'18', N'20', N'21', N'27', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-03-17', N'2016030', N'10', N'14', N'19', N'22', N'25', N'29', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-03-20', N'2016031', N'03', N'08', N'10', N'19', N'26', N'33', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-03-22', N'2016032', N'08', N'12', N'14', N'15', N'21', N'27', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-03-24', N'2016033', N'06', N'17', N'18', N'20', N'27', N'29', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-03-27', N'2016034', N'03', N'15', N'21', N'22', N'23', N'28', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-03-29', N'2016035', N'04', N'13', N'19', N'20', N'26', N'29', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-03-31', N'2016036', N'03', N'04', N'07', N'09', N'20', N'22', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-04-03', N'2016037', N'06', N'15', N'26', N'31', N'32', N'33', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-04-05', N'2016038', N'03', N'12', N'13', N'22', N'28', N'29', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-04-07', N'2016039', N'01', N'03', N'07', N'18', N'19', N'27', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-04-10', N'2016040', N'03', N'13', N'19', N'20', N'23', N'26', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-04-12', N'2016041', N'12', N'17', N'18', N'21', N'22', N'24', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-04-14', N'2016042', N'07', N'14', N'17', N'23', N'26', N'31', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-04-17', N'2016043', N'05', N'14', N'20', N'26', N'30', N'33', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-04-19', N'2016044', N'01', N'03', N'10', N'12', N'18', N'30', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-04-21', N'2016045', N'04', N'09', N'12', N'17', N'30', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-04-24', N'2016046', N'07', N'20', N'25', N'26', N'27', N'30', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-04-26', N'2016047', N'02', N'05', N'08', N'15', N'17', N'22', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-04-28', N'2016048', N'03', N'08', N'13', N'14', N'15', N'30', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-05-01', N'2016049', N'06', N'08', N'13', N'14', N'22', N'27', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-05-03', N'2016050', N'09', N'12', N'24', N'28', N'29', N'30', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-05-05', N'2016051', N'01', N'02', N'04', N'09', N'15', N'33', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-05-08', N'2016052', N'01', N'06', N'13', N'19', N'24', N'28', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-05-10', N'2016053', N'02', N'08', N'10', N'12', N'29', N'31', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-05-12', N'2016054', N'06', N'11', N'16', N'19', N'28', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-05-15', N'2016055', N'05', N'06', N'10', N'16', N'22', N'26', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-05-17', N'2016056', N'03', N'04', N'08', N'11', N'16', N'18', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-05-19', N'2016057', N'07', N'12', N'19', N'22', N'23', N'26', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-05-22', N'2016058', N'03', N'05', N'18', N'20', N'24', N'32', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-05-24', N'2016059', N'04', N'11', N'12', N'20', N'25', N'28', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-05-26', N'2016060', N'04', N'05', N'22', N'26', N'29', N'32', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-05-29', N'2016061', N'05', N'06', N'08', N'18', N'20', N'32', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-05-31', N'2016062', N'12', N'13', N'15', N'18', N'19', N'21', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-06-02', N'2016063', N'16', N'17', N'18', N'23', N'28', N'32', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-06-05', N'2016064', N'03', N'12', N'14', N'17', N'19', N'26', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-06-07', N'2016065', N'13', N'16', N'22', N'25', N'26', N'27', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-06-09', N'2016066', N'03', N'07', N'13', N'18', N'19', N'20', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-06-12', N'2016067', N'09', N'13', N'18', N'20', N'27', N'31', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-06-14', N'2016068', N'08', N'19', N'23', N'28', N'31', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-06-16', N'2016069', N'08', N'10', N'11', N'20', N'21', N'27', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-06-19', N'2016070', N'03', N'06', N'11', N'18', N'23', N'29', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-06-21', N'2016071', N'19', N'21', N'26', N'28', N'29', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-06-23', N'2016072', N'05', N'16', N'19', N'22', N'24', N'25', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-06-26', N'2016073', N'09', N'11', N'12', N'15', N'16', N'20', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-06-28', N'2016074', N'06', N'10', N'11', N'12', N'20', N'25', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-06-30', N'2016075', N'01', N'03', N'06', N'16', N'29', N'32', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-07-03', N'2016076', N'07', N'08', N'13', N'22', N'30', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-07-05', N'2016077', N'01', N'09', N'17', N'19', N'20', N'29', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-07-07', N'2016078', N'02', N'04', N'08', N'23', N'26', N'29', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-07-10', N'2016079', N'01', N'03', N'10', N'12', N'24', N'28', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-07-12', N'2016080', N'01', N'16', N'17', N'24', N'25', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-07-14', N'2016081', N'02', N'06', N'15', N'25', N'30', N'32', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-07-17', N'2016082', N'06', N'12', N'14', N'15', N'17', N'20', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-07-19', N'2016083', N'09', N'16', N'17', N'24', N'30', N'31', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-07-21', N'2016084', N'02', N'04', N'12', N'18', N'24', N'26', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-07-24', N'2016085', N'01', N'12', N'19', N'20', N'21', N'25', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-07-26', N'2016086', N'09', N'10', N'11', N'12', N'15', N'32', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-07-28', N'2016087', N'02', N'03', N'10', N'11', N'14', N'21', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-07-31', N'2016088', N'03', N'14', N'16', N'18', N'25', N'33', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-08-02', N'2016089', N'01', N'03', N'14', N'30', N'31', N'32', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-08-04', N'2016090', N'02', N'13', N'17', N'20', N'21', N'26', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-08-07', N'2016091', N'04', N'08', N'14', N'22', N'23', N'28', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-08-09', N'2016092', N'02', N'13', N'15', N'23', N'24', N'29', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-08-11', N'2016093', N'06', N'09', N'15', N'17', N'25', N'27', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-08-14', N'2016094', N'06', N'07', N'10', N'12', N'18', N'31', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-08-16', N'2016095', N'01', N'05', N'09', N'12', N'18', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-08-18', N'2016096', N'06', N'13', N'14', N'21', N'22', N'24', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-08-21', N'2016097', N'06', N'13', N'25', N'26', N'28', N'31', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-08-23', N'2016098', N'02', N'08', N'25', N'29', N'31', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-08-25', N'2016099', N'01', N'11', N'21', N'23', N'27', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-08-28', N'2016100', N'03', N'10', N'22', N'23', N'27', N'29', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-08-30', N'2016101', N'01', N'03', N'19', N'24', N'32', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-09-01', N'2016102', N'05', N'08', N'10', N'14', N'17', N'30', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-09-04', N'2016103', N'01', N'05', N'13', N'19', N'24', N'27', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-09-06', N'2016104', N'05', N'09', N'11', N'18', N'30', N'31', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-09-08', N'2016105', N'08', N'10', N'19', N'27', N'28', N'31', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-09-11', N'2016106', N'04', N'05', N'13', N'22', N'25', N'30', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-09-13', N'2016107', N'06', N'11', N'18', N'26', N'27', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-09-15', N'2016108', N'02', N'03', N'07', N'08', N'19', N'26', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-09-18', N'2016109', N'09', N'11', N'15', N'16', N'27', N'33', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-09-20', N'2016110', N'05', N'07', N'28', N'31', N'32', N'33', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-09-22', N'2016111', N'02', N'04', N'07', N'14', N'15', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-09-25', N'2016112', N'06', N'12', N'14', N'15', N'18', N'25', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-09-27', N'2016113', N'01', N'11', N'16', N'17', N'20', N'26', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-09-29', N'2016114', N'05', N'16', N'20', N'22', N'27', N'29', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-10-02', N'2016115', N'06', N'08', N'20', N'22', N'26', N'27', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-10-04', N'2016116', N'07', N'18', N'20', N'23', N'27', N'31', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-10-06', N'2016117', N'03', N'10', N'14', N'17', N'28', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-10-09', N'2016118', N'09', N'14', N'22', N'23', N'31', N'33', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-10-11', N'2016119', N'09', N'19', N'21', N'30', N'31', N'32', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-10-13', N'2016120', N'02', N'05', N'06', N'21', N'25', N'28', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-10-16', N'2016121', N'02', N'03', N'10', N'23', N'25', N'28', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-10-18', N'2016122', N'15', N'22', N'23', N'24', N'28', N'29', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-10-20', N'2016123', N'07', N'09', N'12', N'14', N'20', N'27', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-10-23', N'2016124', N'09', N'15', N'21', N'24', N'27', N'32', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-10-25', N'2016125', N'01', N'06', N'08', N'20', N'27', N'30', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-10-27', N'2016126', N'02', N'06', N'12', N'17', N'18', N'19', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-10-30', N'2016127', N'07', N'12', N'17', N'26', N'29', N'31', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-11-01', N'2016128', N'04', N'09', N'11', N'17', N'26', N'27', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-11-03', N'2016129', N'05', N'06', N'08', N'21', N'31', N'33', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-11-06', N'2016130', N'03', N'17', N'21', N'23', N'27', N'28', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-11-08', N'2016131', N'04', N'10', N'18', N'19', N'25', N'27', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-11-10', N'2016132', N'05', N'08', N'13', N'19', N'27', N'28', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-11-13', N'2016133', N'15', N'16', N'21', N'22', N'27', N'33', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-11-15', N'2016134', N'11', N'12', N'13', N'14', N'18', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-11-17', N'2016135', N'02', N'08', N'10', N'18', N'20', N'33', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-11-20', N'2016136', N'02', N'07', N'10', N'20', N'27', N'29', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-11-22', N'2016137', N'01', N'06', N'09', N'10', N'15', N'32', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-11-24', N'2016138', N'07', N'16', N'20', N'24', N'25', N'30', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-11-27', N'2016139', N'01', N'06', N'19', N'26', N'28', N'30', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-11-29', N'2016140', N'01', N'02', N'05', N'17', N'26', N'32', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-12-01', N'2016141', N'04', N'13', N'15', N'17', N'21', N'24', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-12-04', N'2016142', N'01', N'10', N'17', N'21', N'23', N'30', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-12-06', N'2016143', N'06', N'09', N'23', N'24', N'25', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-12-08', N'2016144', N'04', N'10', N'12', N'27', N'32', N'33', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-12-11', N'2016145', N'01', N'03', N'07', N'12', N'19', N'20', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-12-13', N'2016146', N'03', N'07', N'15', N'16', N'17', N'23', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-12-15', N'2016147', N'04', N'14', N'18', N'28', N'31', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-12-18', N'2016148', N'01', N'02', N'11', N'20', N'26', N'30', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-12-20', N'2016149', N'03', N'20', N'23', N'26', N'32', N'33', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-12-22', N'2016150', N'02', N'04', N'05', N'09', N'13', N'21', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-12-25', N'2016151', N'06', N'11', N'16', N'20', N'22', N'33', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-12-27', N'2016152', N'02', N'08', N'09', N'16', N'20', N'22', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2016-12-29', N'2016153', N'07', N'09', N'16', N'24', N'25', N'29', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-01-01', N'2017001', N'09', N'11', N'14', N'20', N'25', N'26', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-01-03', N'2017002', N'15', N'19', N'23', N'24', N'25', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-01-05', N'2017003', N'01', N'04', N'08', N'15', N'27', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-01-08', N'2017004', N'05', N'13', N'17', N'26', N'27', N'30', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-01-10', N'2017005', N'06', N'11', N'12', N'22', N'23', N'30', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-01-12', N'2017006', N'02', N'04', N'08', N'26', N'29', N'33', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-01-15', N'2017007', N'02', N'04', N'05', N'24', N'26', N'33', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-01-17', N'2017008', N'07', N'13', N'15', N'27', N'28', N'29', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-01-19', N'2017009', N'02', N'06', N'08', N'09', N'15', N'29', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-01-22', N'2017010', N'05', N'08', N'19', N'25', N'28', N'30', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-01-24', N'2017011', N'10', N'11', N'12', N'23', N'26', N'29', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-01-26', N'2017012', N'10', N'11', N'14', N'15', N'16', N'24', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-02-05', N'2017013', N'08', N'11', N'28', N'29', N'31', N'33', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-02-07', N'2017014', N'06', N'08', N'18', N'20', N'23', N'31', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-02-09', N'2017015', N'01', N'08', N'09', N'14', N'17', N'32', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-02-12', N'2017016', N'05', N'08', N'16', N'22', N'27', N'29', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-02-14', N'2017017', N'03', N'07', N'08', N'10', N'22', N'23', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-02-16', N'2017018', N'01', N'02', N'03', N'17', N'25', N'31', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-02-19', N'2017019', N'04', N'06', N'08', N'12', N'23', N'25', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-02-21', N'2017020', N'04', N'08', N'10', N'12', N'31', N'33', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-02-23', N'2017021', N'02', N'05', N'10', N'22', N'32', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-02-26', N'2017022', N'02', N'06', N'15', N'16', N'18', N'32', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-02-28', N'2017023', N'01', N'03', N'04', N'11', N'18', N'22', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-03-02', N'2017024', N'09', N'21', N'25', N'26', N'29', N'31', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-03-05', N'2017025', N'02', N'15', N'16', N'17', N'22', N'32', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-03-07', N'2017026', N'03', N'10', N'12', N'19', N'27', N'30', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-03-09', N'2017027', N'02', N'04', N'11', N'14', N'27', N'30', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-03-12', N'2017028', N'07', N'08', N'12', N'13', N'22', N'30', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-03-14', N'2017029', N'02', N'15', N'21', N'23', N'25', N'30', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-03-16', N'2017030', N'01', N'07', N'09', N'20', N'23', N'30', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-03-19', N'2017031', N'06', N'10', N'16', N'26', N'27', N'29', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-03-21', N'2017032', N'05', N'08', N'15', N'24', N'27', N'31', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-03-23', N'2017033', N'05', N'07', N'15', N'20', N'23', N'30', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-03-26', N'2017034', N'04', N'07', N'08', N'19', N'32', N'33', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-03-28', N'2017035', N'01', N'06', N'14', N'24', N'28', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-03-30', N'2017036', N'01', N'02', N'05', N'10', N'24', N'27', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-04-02', N'2017037', N'11', N'15', N'20', N'22', N'25', N'30', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-04-04', N'2017038', N'01', N'04', N'08', N'13', N'24', N'27', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-04-06', N'2017039', N'02', N'04', N'12', N'14', N'17', N'24', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-04-09', N'2017040', N'15', N'19', N'23', N'28', N'29', N'33', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-04-11', N'2017041', N'04', N'10', N'13', N'15', N'22', N'27', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-04-13', N'2017042', N'01', N'02', N'04', N'07', N'10', N'23', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-04-16', N'2017043', N'08', N'13', N'16', N'23', N'27', N'31', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-04-18', N'2017044', N'08', N'16', N'19', N'21', N'31', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-04-20', N'2017045', N'05', N'07', N'16', N'20', N'21', N'25', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-04-23', N'2017046', N'04', N'13', N'14', N'23', N'26', N'32', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-04-25', N'2017047', N'02', N'05', N'08', N'10', N'32', N'33', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-04-27', N'2017048', N'05', N'08', N'09', N'14', N'15', N'19', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-04-30', N'2017049', N'01', N'08', N'14', N'15', N'20', N'29', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-05-02', N'2017050', N'10', N'12', N'20', N'24', N'27', N'29', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-05-04', N'2017051', N'02', N'05', N'09', N'15', N'24', N'25', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-05-07', N'2017052', N'07', N'08', N'18', N'24', N'29', N'31', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-05-09', N'2017053', N'04', N'09', N'11', N'15', N'29', N'31', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-05-11', N'2017054', N'02', N'03', N'09', N'23', N'28', N'33', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-05-14', N'2017055', N'07', N'12', N'13', N'20', N'24', N'31', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-05-16', N'2017056', N'13', N'14', N'18', N'19', N'21', N'28', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-05-18', N'2017057', N'18', N'20', N'22', N'23', N'30', N'31', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-05-21', N'2017058', N'01', N'09', N'13', N'22', N'28', N'32', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-05-23', N'2017059', N'04', N'08', N'09', N'15', N'19', N'25', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-05-25', N'2017060', N'05', N'10', N'13', N'24', N'26', N'31', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-05-28', N'2017061', N'06', N'07', N'12', N'20', N'26', N'27', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-05-30', N'2017062', N'01', N'07', N'22', N'24', N'26', N'31', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-06-01', N'2017063', N'12', N'16', N'20', N'22', N'25', N'31', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-06-04', N'2017064', N'02', N'10', N'16', N'22', N'24', N'28', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-06-06', N'2017065', N'02', N'05', N'08', N'10', N'12', N'21', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-06-08', N'2017066', N'01', N'04', N'06', N'17', N'19', N'26', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-06-11', N'2017067', N'01', N'03', N'04', N'10', N'18', N'29', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-06-13', N'2017068', N'02', N'06', N'10', N'22', N'30', N'31', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-06-15', N'2017069', N'02', N'11', N'12', N'23', N'29', N'31', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-06-18', N'2017070', N'01', N'06', N'14', N'22', N'25', N'26', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-06-20', N'2017071', N'02', N'03', N'06', N'14', N'31', N'32', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-06-22', N'2017072', N'06', N'11', N'14', N'23', N'26', N'30', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-06-25', N'2017073', N'03', N'06', N'16', N'23', N'26', N'30', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-06-27', N'2017074', N'02', N'06', N'16', N'23', N'30', N'31', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-06-29', N'2017075', N'01', N'03', N'06', N'19', N'21', N'29', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-07-02', N'2017076', N'01', N'04', N'08', N'09', N'14', N'15', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-07-04', N'2017077', N'01', N'02', N'04', N'15', N'17', N'22', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-07-06', N'2017078', N'05', N'07', N'18', N'19', N'22', N'24', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-07-09', N'2017079', N'03', N'07', N'14', N'23', N'25', N'27', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-07-11', N'2017080', N'01', N'12', N'16', N'20', N'22', N'24', N'08')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-07-13', N'2017081', N'03', N'05', N'14', N'25', N'26', N'30', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-07-16', N'2017082', N'14', N'18', N'21', N'25', N'28', N'29', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-07-18', N'2017083', N'03', N'08', N'14', N'20', N'24', N'26', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-07-20', N'2017084', N'01', N'05', N'11', N'20', N'22', N'24', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-07-23', N'2017085', N'01', N'05', N'06', N'16', N'25', N'30', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-07-25', N'2017086', N'03', N'05', N'06', N'13', N'20', N'22', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-07-27', N'2017087', N'03', N'06', N'13', N'14', N'19', N'28', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-07-30', N'2017088', N'07', N'09', N'18', N'22', N'23', N'29', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-08-01', N'2017089', N'11', N'12', N'13', N'16', N'23', N'25', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-08-03', N'2017090', N'01', N'07', N'10', N'16', N'22', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-08-06', N'2017091', N'05', N'07', N'10', N'23', N'28', N'29', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-08-08', N'2017092', N'10', N'18', N'19', N'29', N'32', N'33', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-08-10', N'2017093', N'07', N'08', N'09', N'15', N'22', N'27', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-08-13', N'2017094', N'08', N'11', N'13', N'19', N'28', N'31', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-08-15', N'2017095', N'09', N'10', N'12', N'19', N'22', N'29', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-08-17', N'2017096', N'02', N'06', N'11', N'12', N'19', N'29', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-08-20', N'2017097', N'05', N'10', N'18', N'19', N'30', N'31', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-08-22', N'2017098', N'04', N'19', N'22', N'27', N'30', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-08-24', N'2017099', N'02', N'05', N'06', N'16', N'28', N'29', N'04')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-08-27', N'2017100', N'04', N'07', N'08', N'18', N'23', N'24', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-08-29', N'2017101', N'01', N'04', N'11', N'28', N'31', N'32', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-08-31', N'2017102', N'04', N'08', N'10', N'14', N'18', N'20', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-09-03', N'2017103', N'01', N'21', N'23', N'25', N'31', N'33', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-09-05', N'2017104', N'01', N'14', N'15', N'20', N'23', N'30', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-09-07', N'2017105', N'03', N'06', N'07', N'12', N'25', N'26', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-09-10', N'2017106', N'12', N'15', N'20', N'25', N'27', N'31', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-09-12', N'2017107', N'08', N'09', N'15', N'17', N'30', N'32', N'06')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-09-14', N'2017108', N'07', N'12', N'14', N'15', N'17', N'20', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-09-17', N'2017109', N'08', N'14', N'16', N'18', N'21', N'23', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-09-19', N'2017110', N'01', N'03', N'12', N'15', N'19', N'23', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-09-21', N'2017111', N'05', N'10', N'17', N'19', N'29', N'32', N'12')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-09-24', N'2017112', N'03', N'10', N'14', N'16', N'22', N'23', N'11')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-09-26', N'2017113', N'04', N'06', N'16', N'27', N'29', N'33', N'05')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-09-28', N'2017114', N'06', N'12', N'13', N'15', N'18', N'26', N'13')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-10-01', N'2017115', N'04', N'10', N'11', N'25', N'30', N'31', N'01')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-10-03', N'2017116', N'02', N'14', N'20', N'22', N'30', N'32', N'02')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-10-05', N'2017117', N'01', N'02', N'08', N'11', N'14', N'21', N'09')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-10-08', N'2017118', N'08', N'09', N'15', N'22', N'30', N'33', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-10-10', N'2017119', N'09', N'16', N'21', N'25', N'26', N'31', N'14')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-10-12', N'2017120', N'08', N'10', N'15', N'19', N'23', N'28', N'16')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-10-15', N'2017121', N'11', N'18', N'19', N'22', N'24', N'32', N'07')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-10-17', N'2017122', N'11', N'20', N'21', N'22', N'24', N'27', N'15')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-10-19', N'2017123', N'04', N'05', N'06', N'11', N'21', N'31', N'10')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-10-22', N'2017124', N'02', N'06', N'11', N'26', N'28', N'29', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-10-24', N'2017125', N'01', N'14', N'23', N'25', N'29', N'30', N'03')
GO
INSERT [dbo].[dstbl_lotteryds] ([dslotterytimeds], [dslotteryidds], [dsred1ds], [dsred2ds], [dsred3ds], [dsred4ds], [dsred5ds], [dsred6ds], [dsblueds]) VALUES (N'2017-10-26', N'2017126', N'01', N'16', N'17', N'21', N'27', N'30', N'16')
GO
ALTER TABLE [dbo].[dstbl_lotteryds] ADD  DEFAULT (NULL) FOR [dslotteryidds]
GO
ALTER TABLE [dbo].[dstbl_lotteryds] ADD  DEFAULT (NULL) FOR [dsred1ds]
GO
ALTER TABLE [dbo].[dstbl_lotteryds] ADD  DEFAULT (NULL) FOR [dsred2ds]
GO
ALTER TABLE [dbo].[dstbl_lotteryds] ADD  DEFAULT (NULL) FOR [dsred3ds]
GO
ALTER TABLE [dbo].[dstbl_lotteryds] ADD  DEFAULT (NULL) FOR [dsred4ds]
GO
ALTER TABLE [dbo].[dstbl_lotteryds] ADD  DEFAULT (NULL) FOR [dsred5ds]
GO
ALTER TABLE [dbo].[dstbl_lotteryds] ADD  DEFAULT (NULL) FOR [dsred6ds]
GO
ALTER TABLE [dbo].[dstbl_lotteryds] ADD  DEFAULT (NULL) FOR [dsblueds]
GO

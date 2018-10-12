select * from dstbl_lotteryds;

/*蓝球*/
select dsblueds as 蓝球号码,count(dsblueds) as 出现次数 from dstbl_lotteryds
group by dsblueds
order by dsblueds;

/*红球1*/
select dsred1ds as 红球号码,count(*) as 出现次数
from (
	select dsred1ds from dstbl_lotteryds
	union all
	select dsred2ds from dstbl_lotteryds
	union all
	select dsred3ds from dstbl_lotteryds
	union all
	select dsred4ds from dstbl_lotteryds
	union all
	select dsred5ds from dstbl_lotteryds
	union all
	select dsred6ds from dstbl_lotteryds
)as red
group by dsred1ds
order by dsred1ds;

/*红球2*/
create view redView(redNum)
as (
	select dsred1ds from dstbl_lotteryds
	union all
	select dsred2ds from dstbl_lotteryds
	union all
	select dsred3ds from dstbl_lotteryds
	union all
	select dsred4ds from dstbl_lotteryds
	union all
	select dsred5ds from dstbl_lotteryds
	union all
	select dsred6ds from dstbl_lotteryds
);
select redNum as 红球号码,count(*) as 出现次数
from redView
group by redNum
order by redNum;
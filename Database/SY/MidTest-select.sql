select * from dstbl_lotteryds;

/*����*/
select dsblueds as �������,count(dsblueds) as ���ִ��� from dstbl_lotteryds
group by dsblueds
order by dsblueds;

/*����1*/
select dsred1ds as �������,count(*) as ���ִ���
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

/*����2*/
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
select redNum as �������,count(*) as ���ִ���
from redView
group by redNum
order by redNum;
int jie(int x)
{
	int s = 1;
	for(;x>=1;x--)
		s*=x;
	return s;
}
int combinNum(int m,int n)
{
	return (jie(m) / (jie(n) * jie(m-n)));
}
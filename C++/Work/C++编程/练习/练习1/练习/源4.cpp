#include <stdio.h>
#define N 10
int MaxValue(int arr[])
{
    int max = 0;
    for (int n = 0;n < N;n++)
    {
        if (max < arr[n]) max = arr[n];
    }
    return max;
}
int MinValue(int arr[])
{
    int min = 100;
    for (int n = 0;n < N;n++)
    {
        if (min > arr[n]) min = arr[n];
    }
    return min;
}
int Sum(int arr[])
{
    int sum = 0;
    for(int n = 0;n < N;n++)
    {
        sum += arr[n];
    }
    return sum;
}
double Average(int arr[])
{
    return (float)Sum(arr) / N;
}
void Rank(int arr[])
{
    for(int i=9; i>=0; i--)
    {
        for(int j=0;j<=i;j++)
        {
            if(arr[j] < arr[j+1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }                 
        }                
    }
	for(int i = 0;i <= 9;i++)
	{
		printf(" %d ",arr[i]);
	}
	printf("\n");
}
int main()
{
    int score[N]={67,98,75,63,82,79,81,91,66,84};
	int max = MaxValue(score),min = MinValue(score),sum = Sum(score);
	double aver = Average(score);
	printf("总分：%d，最高分：%d，最低分：%d，平均分：%f。\n",sum,max,min,aver);
	printf("降序排列\n");
	Rank(score);
	return 0;
}
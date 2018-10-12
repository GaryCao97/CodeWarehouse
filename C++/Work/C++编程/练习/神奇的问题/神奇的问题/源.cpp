#include <iostream>
using namespace std;
int main()
{
	float a[4][6];
	float a1 = 0,a2 = 0,a3 = 0,s1 = 0,s2 = 0,s3 = 0,s4 = 0,s5 = 0; 
	int i,j;
	cout<<"请输入原始的成绩数据:"<<endl;
	for(i = 0;i < 3;i++)                                         //循环输入数据 
	{
		for(j = 0;j < 5;j++)
		{
			scanf("%f",&a[i][j]);
		}
	}
	cout<<"输入成绩："<<endl;                                    //打印输入的数据 
    for(i = 0;i < 3;i++)
    {
    	for(j = 0;j < 5;j++)
        {
        	printf("%-3.0f",a[i][j]);
		}
		cout<<endl;
	}
    for(j = 0;j < 5;j++)                                         //计算每个学生的平均成绩 
    {
        a1 += a[0][j];
        a2 += a[1][j];
        a3 += a[2][j];
	}
	for(j = 0;j < 5;j++)
		a[3][j] = 0;
	a[3][5] = 0;
	for(i = 0;i < 3;i++)                                         //计算单科成绩的总和 
	{
		a[3][0] += a[i][0];
		a[3][1] += a[i][1];
		a[3][2] += a[i][2];
        a[3][3] += a[i][3];
		a[3][4] += a[i][4];
    }
	a[0][5] = a1 / 5.0;                                          //将学生的平均成绩放入数组 
	a[1][5] = a2 / 5.0;
	a[2][5] = a3 / 5.0;
	s1 = a[3][0] / 3;                                            //计算单科平均成绩 
	s2 = a[3][1] / 3;
    s3 = a[3][2] / 3;
	s4 = a[3][3] / 3; 
	s5 = a[3][4] / 3;
	cout<<"输出结果："<<endl;
	for(i = 0;i < 4;i++)                                         //输出得到结果后的数组 
	{
		for(j = 0;j < 6;j++)
		{
			if(j == 5 && i < 3)
			{
				printf("%.1f ",a[i][j]);
			} 
			else if(i == 3 && j < 5) 
			{
				printf("%.1f ",a[i][j]);
			} 
			else
			cout<<a[i][j]<<"    ";
		}
		cout<<endl;
	}
	cout<<"平均分："<<endl;
	printf("%.1f  %.1f  %.1f  %.1f  %.1f",s1,s2,s3,s4,s5);
}

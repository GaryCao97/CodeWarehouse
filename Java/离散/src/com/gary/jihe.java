package com.gary;
import java.util.Scanner;
public class jihe {
	static int LEN = 150;
	static int[][] arr = new int[LEN][12];
	static int[][] relation = new int[LEN][LEN];
	static int nnn;
	static int num;
	static Scanner input = new Scanner(System.in);
	public static void main(String[] args) {
			System.out.println( "请输入集合中的元素个数 : ");
			nnn = input.nextInt();
			System.out.println("请输入集合中的关系个数 : ");
			num = input.nextInt();
			System.out.println("请输入集合中的关系元素，一共有"+num+"对关系,"+num * 2+"个元素(请以整数形式输入) : ");
			int num1, num2;
			for (int i = 1; i <= num; i++)
			{
				num1 = input.nextInt();
				num2 = input.nextInt();
				arr[i][1] = num1;
				arr[i][2] = num2;
				relation[num1][num2] = 1;
			}
			System.out.println("输出关系矩阵 : ");
			for (int i = 1; i <= nnn; i++)
			{
				for (int j = 1; j <= nnn; j++)
				{
					System.out.print(relation[i][j]+"     ");
				}
				System.out.println();
			}
			System.out.println();


			System.out.println("判断结论 : ");
			//判断是否满足自反性  
			Func1();
			//判断是否满足对称性  
			Func2();
			//判断是否满足传递性  
			Func3();
			//判断是否满足反自反性  
			Func4();
			//判断是否满足反对称性  
			Func5();


    }
	public static void Func1()
	{
		boolean flag = true;
		for (int i = 1; i <= nnn; i++)
		{
			if (relation[i][i] != 1)
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			System.out.println("满足自反性");
		}
		else
		{
			System.out.println("不满足自反性");
		}
	}
	public static void Func2()
	{
		boolean flag = true;
		for (int i = 1; i <= nnn; i++)
		{
			for (int j = 1; j <= nnn; j++)
			{
				if (relation[i][j] != relation[j][i])
				{
					flag = false;
				}
			}
		}
		if (flag == true)
		{
			System.out.println("满足对称性");
		}
		else
		{
			System.out.println("不满足对称性");
		}
	}
	public static void Func3()
	{
		boolean flag = true;
		for (int i = 1; i <= num - 1; i++)
		{
			for (int j = 2; j <= num; j++)
			{
				if (arr[i][2] == arr[j][1])
				{
					int num1 = arr[i][1], num2 = arr[j][2];
					if (relation[num1][num2] != 1)
					{
						flag = false;
						break;
					}
				}
			}
			if (flag == false)
				break;
		}
		if (flag == true)
		{
			System.out.println("满足传递性");
		}
		else
		{
			System.out.println("不满足传递性");
		}
	}
	public static void Func4()
	{
		boolean flag = true;
		for (int i = 1; i <= nnn; i++)
		{
			if (relation[i][i] != 0)
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			System.out.println("满足反自反性");
		}
		else
		{
			System.out.println("不满足反自反性");
		}

	}

	public static void Func5()
	{
		boolean flag = true;
		for (int i = 1; i <= nnn - 1; i++)
		{
			for (int j = i + 1; j <= nnn; j++)
			{
				if (relation[i][j] == 1 && relation[j][i] == 1 && i != j)
				{
					flag = false;
					break;
				}
			}
		}
		if (flag == true)
		{
			System.out.println("满足反对称性");
		}
		else
		{
			System.out.println("不满足反对称性");
		}
	}
}

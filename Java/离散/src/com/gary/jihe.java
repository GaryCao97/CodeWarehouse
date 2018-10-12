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
			System.out.println( "�����뼯���е�Ԫ�ظ��� : ");
			nnn = input.nextInt();
			System.out.println("�����뼯���еĹ�ϵ���� : ");
			num = input.nextInt();
			System.out.println("�����뼯���еĹ�ϵԪ�أ�һ����"+num+"�Թ�ϵ,"+num * 2+"��Ԫ��(����������ʽ����) : ");
			int num1, num2;
			for (int i = 1; i <= num; i++)
			{
				num1 = input.nextInt();
				num2 = input.nextInt();
				arr[i][1] = num1;
				arr[i][2] = num2;
				relation[num1][num2] = 1;
			}
			System.out.println("�����ϵ���� : ");
			for (int i = 1; i <= nnn; i++)
			{
				for (int j = 1; j <= nnn; j++)
				{
					System.out.print(relation[i][j]+"     ");
				}
				System.out.println();
			}
			System.out.println();


			System.out.println("�жϽ��� : ");
			//�ж��Ƿ������Է���  
			Func1();
			//�ж��Ƿ�����Գ���  
			Func2();
			//�ж��Ƿ����㴫����  
			Func3();
			//�ж��Ƿ����㷴�Է���  
			Func4();
			//�ж��Ƿ����㷴�Գ���  
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
			System.out.println("�����Է���");
		}
		else
		{
			System.out.println("�������Է���");
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
			System.out.println("����Գ���");
		}
		else
		{
			System.out.println("������Գ���");
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
			System.out.println("���㴫����");
		}
		else
		{
			System.out.println("�����㴫����");
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
			System.out.println("���㷴�Է���");
		}
		else
		{
			System.out.println("�����㷴�Է���");
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
			System.out.println("���㷴�Գ���");
		}
		else
		{
			System.out.println("�����㷴�Գ���");
		}
	}
}

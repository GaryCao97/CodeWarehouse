package com.niu;
import java.util.Scanner;
public class jihe {
	static Scanner input = new Scanner(System.in);
	static int n, i, j;
	public static void main(String[] args) {
		int[][] s = new int[100][100];
		int z;
		System.out.print("����Ԫ�ظ���\n "); /*����Ԫ�ظ���*/
		n = input.nextInt();
		System.out.print("�����ϵ����\n");/*�����ϵ����*/
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<n; j++)
				s[i][j] = input.nextInt();
		}
		System.out.println("Choice");
		System.out.println("1:zifan");
		System.out.println("2:chuandi1");
		System.out.println("3:chuandi2");
		System.out.println("4:duichen");/*���ѡ�߲˵�*/
		z = input.nextInt();
		switch (z)
		{
		case 1:zifan(s); break;                        /*�����Է�����*/
		case 2:chuandi1(s); break;                      /*���ô��ݺ���1*/
		case 3:chuandi2(s); break;                      /*���ô��ݺ���2*/
		case 4:duichen(s); break;                      /*���öԳƺ���*/
		}
	}
	static void output(int[][] s)                      /*�������*/
	{
		System.out.println("input the matrix");
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<n; j++)
				System.out.print(s[i][j]);
			System.out.println();
		}
	}
	static void zifan(int[][] s2)                     /*�Է�����*/
	{
		for (i = 0; i<n; i++)
			s2[i][i] = 1;
		output(s2);
	}
	static void duichen(int[][] s2)                  /*�Գƺ���*/
	{
		int[][] s1 = new int[100][100];
		for (i = 0; i<n; i++)
			for (j = 0; j<n; j++)
				s1[j][i] = s2[i][j];
		for (i = 0; i<n; i++)
			for (j = 0; j<n; j++)
			{
				s2[i][j] = s2[i][j] + s1[i][j];
				if (s2[i][j]>1)
					s2[i][j] = 1;
			}
		output(s2);

	}
	static void chuandi1(int[][] s2)              /*�㷨1�󴫵ݺ���*/
	{
		int[][] m = new int[100][100];
		int[][] a = new int[100][100];
		int k;
		int h;
		int[][] t = new int[100][100];
		for (i = 0; i<n; i++)
			for (j = 0; j<n; j++)
			{
				a[i][j] = 0;
				t[i][j] = s2[i][j];
				m[i][j] = s2[i][j];
			}
		for (h = 0; h<n; h++)
		{
			for (i = 0; i<n; i++)
				for (j = 0; j<n; j++)
					if (m[i][j] == 1)
					{
						for (k = 0; k<n; k++)
							if (s2[j][k] == 1)
								a[i][k] = 1;
					}
			for (i = 0; i<n; i++)
				for (j = 0; j<n; j++)
				{
					m[i][j] = a[i][j];
					t[i][j] += a[i][j];
					a[i][j] = 0;
					if (t[i][j]>1)
						t[i][j] = 1;
				}
		}
		output(t);
	}
	static void chuandi2(int[][] s2)       /*�㷨2�󴫵ݺ���*/
	{
		int k;
		for (i = 0; i<n; i++)
			for (j = 0; j<n; j++)
				if (s2[j][i] == 1)
					for (k = 0; k<n; k++)
						s2[j][k] += s2[i][k];
		for (i = 0; i<n; i++)
			for (j = 0; j<n; j++)
				if (s2[i][j]>1)
					s2[i][j] = 1;
		output(s2);
	}

}

package com.yang;
import java.util.Scanner;

public class allPai {
	static Scanner input = new Scanner(System.in);
	static void print(int[] a,int n,int cur) 
	{ 
	    int i,j; 
	    if(cur == n) 
		{ 
	    	for(i=0;i<n;i++) 
	    		System.out.print(a[i] + " ");
	    	System.out.println();     
		}
		else
		{
	       for(j=1;j<=n;j++) 
		   { 
	           boolean ok = true;  
			   for(i=0;i<cur;i++)            
			   { 
	              if(a[i]==j)                 
	            	  ok = false;           
			   }             
			   if(ok)            
			   { 
	              a[cur]=j;  
	              print(a,n,cur+1);          
			   }         
		  }       
	   }  
	}
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		int[] a = new int[100];     
		int n; 
		System.out.println("请输入n:");
		n = input.nextInt();
		while(n != ' ')     
		{
			System.out.println("n的全排列为：");  
			print(a,n,0);
			System.out.println("请输入n:");
			n = input.nextInt();
		}
	}

}

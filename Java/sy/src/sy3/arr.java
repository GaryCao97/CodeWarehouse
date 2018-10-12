package sy3;
import java.util.Scanner;

public class arr {
	static Scanner input = new Scanner(System.in);
	public static void main(String[] args) {
		int i,j,k,x,y,z;
		System.out.println("输入矩阵A:");
		System.out.print("定义行数=");
		x = input.nextInt();
		System.out.print("列数=");
		y = input.nextInt();
		System.out.println("输入矩阵:行数=" + x + " 列数=" + y);
		int[][] A = new int[x][y];
		for(i = 0;i < x;i++) {
			for(j = 0;j < y;j++) {
				A[i][j] = input.nextInt();
			}
		}
		System.out.println("输入矩阵B:行数=" + y);
		System.out.print("定义列数=");
		z = input.nextInt();
		System.out.println("输入矩阵:行数=" + y + " 列数=" + z);
		int[][] B = new int[y][z];
		for(j = 0;j < y;j++) {
			for(k = 0;k < z;k++) {
				B[j][k] = input.nextInt();
			}
		}
		System.out.println("两矩阵相乘，结果为:");
		int[][] C = new int[x][z];
		for(i = 0;i < x;i++) {
			for(k = 0;k < z;k++) {
				C[i][k] = 0;
				for(j = 0;j < y;j++) {
					C[i][k] += A[i][j] * B[j][k];
				}
			}
		}
		for(i = 0;i < x;i++) {
			for(k = 0;k < z;k++) {
				System.out.print(C[i][k] + " ");
			}
			System.out.print("\n");
		}
	}
}

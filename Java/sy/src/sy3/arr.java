package sy3;
import java.util.Scanner;

public class arr {
	static Scanner input = new Scanner(System.in);
	public static void main(String[] args) {
		int i,j,k,x,y,z;
		System.out.println("�������A:");
		System.out.print("��������=");
		x = input.nextInt();
		System.out.print("����=");
		y = input.nextInt();
		System.out.println("�������:����=" + x + " ����=" + y);
		int[][] A = new int[x][y];
		for(i = 0;i < x;i++) {
			for(j = 0;j < y;j++) {
				A[i][j] = input.nextInt();
			}
		}
		System.out.println("�������B:����=" + y);
		System.out.print("��������=");
		z = input.nextInt();
		System.out.println("�������:����=" + y + " ����=" + z);
		int[][] B = new int[y][z];
		for(j = 0;j < y;j++) {
			for(k = 0;k < z;k++) {
				B[j][k] = input.nextInt();
			}
		}
		System.out.println("��������ˣ����Ϊ:");
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

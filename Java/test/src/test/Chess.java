package test;
import java.util.Scanner;

public class Chess {
	static Scanner input = new Scanner(System.in);
	static char[] chess = {'O',' ','X'};
	static int[][] chessNum = {{0,0,0},{0,0,0},{0,0,0}};// -1 O 1 X
	static int[] check = {0,0,0,0,0,0,0,0};
	static int nowNum = 1;// -1 O 1 X
	static int index = 0;
	public static void main(String[] args) {
		printChessBox();
		int win;
		do {
			playChess();
			printChessBox();
			win = isEnd();
		}while(win == 0);
		if(win == 2)System.out.println("Nobody won");
		else System.out.println(chess[win + 1] + " player won");
	}
	public static void printChessBox() {
		for(int j = 0;j < 3;j++) {
			System.out.println("-------------");
			for(int i = 0;i < 3;i++) {
				System.out.print("| " + chess[chessNum[j][i] + 1] + " ");
			}
			System.out.println("|");
		}
		System.out.println("-------------");
	}
	public static int isEnd() {
		for(int i = 0;i < check.length;i++) {
			if(check[i] != 0 && check[i] % 3 == 0)return check[i]/3;
		}
		if(index == 9)return 2;
		return 0;
	}
	public static void playChess() {
		int i,j;
		do {
			System.out.print("Enter a row (0, 1, or 2) for player " + chess[nowNum + 1] + ":");
			j = input.nextInt();
			System.out.print("Enter a column (0, 1, or 2) for player " + chess[nowNum + 1] + ":");
			i = input.nextInt();
		}while(chessNum[j][i] != 0);
		chessNum[j][i] = nowNum;
		check[j] += nowNum;
		check[i + 3] += nowNum;
		check[6] = chessNum[0][0] + chessNum[1][1] + chessNum[2][2];
		check[7] = chessNum[0][2] + chessNum[1][1] + chessNum[2][0];
		index ++;
		if(nowNum == 1)nowNum = -1;
		else nowNum = 1;
	}
}

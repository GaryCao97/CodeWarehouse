package test;
import java.util.Random;

public class Craps {
	static Random rand = new Random();
	public static void main(String[] args) {
		int craps1 = rand.nextInt(6) + 1,
				craps2 = rand.nextInt(6) + 1;
		int num1 = craps1 + craps2,num2;
		printCraps(craps1,craps2);
		switch(num1){
		case 2:
		case 3:
		case 12:
			printLose();
			break;
		case 7:
		case 11:
			printWin();
			break;
			default:{
				System.out.println("point is " + num1);
				do{
					craps1 = rand.nextInt(6) + 1;
					craps2 = rand.nextInt(6) + 1;
					num2 = craps1 + craps2;
				}while(num2 != num1 && num2 != 7);
				printCraps(craps1,craps2);
				if(num2 == num1)
					printWin();
				else 
					printLose();
			}
			break;
		}
	}
	public static void printCraps(int craps1,int craps2){
		System.out.println("You rolled " + craps1 + " + " + craps2 + " = " + (craps1+craps2));
	}
	public static void printWin(){
		System.out.println("You win");
	}
	public static void printLose(){
		System.out.println("You lose");
	}
}

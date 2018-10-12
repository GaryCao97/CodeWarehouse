package sy2;
import java.util.Scanner;

public class yuan {
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		System.out.println("请输入圆1的坐标和半径，格式为(x,y) r");
		double x1 = input.nextDouble(),
				y1 = input.nextDouble(),
				r1 = input.nextDouble();
		System.out.println("请输入圆2的坐标和半径，格式为(x,y) r");
		double x2 = input.nextDouble(),
				y2 = input.nextDouble(),
				r2 = input.nextDouble();
		double l = Math.sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
		if(l <= Math.abs(r1-r2)) {
			System.out.println("圆2在圆1内");
		}
		else if(l <= r1+r2) {
			System.out.println("圆1和圆2重叠");
		}

	}

}

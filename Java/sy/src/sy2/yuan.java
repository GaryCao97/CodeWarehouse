package sy2;
import java.util.Scanner;

public class yuan {
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		System.out.println("������Բ1������Ͱ뾶����ʽΪ(x,y) r");
		double x1 = input.nextDouble(),
				y1 = input.nextDouble(),
				r1 = input.nextDouble();
		System.out.println("������Բ2������Ͱ뾶����ʽΪ(x,y) r");
		double x2 = input.nextDouble(),
				y2 = input.nextDouble(),
				r2 = input.nextDouble();
		double l = Math.sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
		if(l <= Math.abs(r1-r2)) {
			System.out.println("Բ2��Բ1��");
		}
		else if(l <= r1+r2) {
			System.out.println("Բ1��Բ2�ص�");
		}

	}

}

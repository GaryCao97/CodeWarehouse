package sy1;
import java.util.Scanner;
import javax.swing.JOptionPane;

public class huobi {
	static Scanner input = new Scanner(System.in);
	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		System.out.println("��������Ԫ��");
		double Dollar = input.nextDouble();
		double RMB = Dollar * 6.3699;
		JOptionPane.showMessageDialog(null, String.format("��%.1f=��%.1f", Dollar, RMB), "ת�����", JOptionPane.INFORMATION_MESSAGE);
	}
}

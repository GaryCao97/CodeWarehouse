package sy1;
import java.util.Scanner;
import javax.swing.JOptionPane;

public class huobi {
	static Scanner input = new Scanner(System.in);
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		System.out.println("请输入美元：");
		double Dollar = input.nextDouble();
		double RMB = Dollar * 6.3699;
		JOptionPane.showMessageDialog(null, String.format("＄%.1f=￥%.1f", Dollar, RMB), "转换结果", JOptionPane.INFORMATION_MESSAGE);
	}
}

package sy1;
import javax.swing.JOptionPane;

public class bijiao {
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		String str1 = JOptionPane.showInputDialog("请输入数字1："),
				str2 = JOptionPane.showInputDialog("请输入数字2：");
		JOptionPane.showMessageDialog(
				null,
				(Double.parseDouble(str1) > Double.parseDouble(str2) ? str1 : str2), 
				"大数为：",
				JOptionPane.INFORMATION_MESSAGE
		);
	}
}

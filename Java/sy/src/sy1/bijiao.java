package sy1;
import javax.swing.JOptionPane;

public class bijiao {
	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		String str1 = JOptionPane.showInputDialog("����������1��"),
				str2 = JOptionPane.showInputDialog("����������2��");
		JOptionPane.showMessageDialog(
				null,
				(Double.parseDouble(str1) > Double.parseDouble(str2) ? str1 : str2), 
				"����Ϊ��",
				JOptionPane.INFORMATION_MESSAGE
		);
	}
}

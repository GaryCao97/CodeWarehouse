package MidTest;
//����һ�����ⳤ�ȵ��ַ������ҳ���������ͬ�ַ����Ӷ��ɵ���ַ��������ԡ���ĸ�����ȡ�����ʽ���ء�
//���硰aaxxxbbbbxxxxxdd������������ͬ�ַ����Ӷ��ɵ����Ϊxxxxx���򷵻ء�x��5����
//��������ɲ�ͬ�ַ����ɵĳ�����ͬ���ַ������򷵻��ȳ��ֵ��ַ�����

import java.util.Scanner;

public class MidTest {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		do {
			String str = input.next();
			char ch = str.charAt(0),chMax = ' ';
			int num = 1,max = 0;
			for(int i = 1;i < str.length();i++) {
				char tmp = str.charAt(i);
				if(tmp == ch)num++;
				else {
					if(num > max) {
						max = num;
						chMax = ch;
					}
					num = 1;
					ch = tmp;
				}
			}
			System.out.println(chMax + "," + max);			
		}while(input.hasNext());
		input.close();
	}
}

package MidTest;
//给定一个任意长度的字符串，找出其中由相同字符连接而成的最长字符串，并以“字母，长度”的形式返回。
//比如“aaxxxbbbbxxxxxdd”，其中由相同字符连接而成的最长串为xxxxx，则返回“x，5”。
//如果出现由不同字符构成的长度相同的字符串，则返回先出现的字符串。

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

package ����;

import java.util.Arrays;

public class �������� {
	public static void main(String[] args)
	{
		String[] arry = { "49", "38", "65", "97", "76", "13", "27" };
		// ����������.���統����Ϊ49,38, 65, 97, 76, 13, 27
		// ��ʱ��,��һ�ξͰ���Сһλ�ŵ���һλ,,����������
		method2(arry);
		//Arrays.sort(array, 0, arry.length);
		//for (int i = 0; i < arry.length; i++) {
			//System.out.println("Result:" + array[i]);
		//}
	}
	public static boolean compareString(String str1,String str2){
		for(int q = 0;q < str1.length();q++){
			if(str1.charAt(q) > str2.charAt(q)){
				return false;
			}
			if(str1.charAt(q) < str2.charAt(q)){
				return true;
			}
		}
		return false;
	}
	public static void method2(String[] array) {
		// 1��������������I��J������ʼ��ʱ��I=0��J=N-1��
		int i = 0;
		int j = array.length - 1;// ��ȡ�������һλ
		// 2���Ե�һ������Ԫ����Ϊ�ؼ����ݣ���ֵ��key���� key=A[0]��
		String k = array[0];// ��ȡ�����һλ
		int f = 0;
		boolean check = false;
		int x = 0;
		while (i != j) {
			// 3����J��ʼ��ǰ���������ɺ�ʼ��ǰ������J=J-1�����ҵ���һ��С��key��ֵA[J]��A[j]��A������
			while (!compareString(array[j],k)) {
				j--;
			}
			String temp = k;
			k = array[j];
			array[j] = temp;
			// [49, 38, 65, 97, 76, 13, 27] 
			// [27, 38, 65, 97, 76, 13, 49]
			// [27, 38, 49, 97, 76, 13, 65]
			// [27, 38, 49, 97, 76, 49, 65] 
			// [27, 38, 13, 97, 76, 49, 65]
			// [27, 38, 13, 49, 76, 97, 65]
			// [27, 38, 13, 49, 76, 97, 65]
			// 4����I��ʼ�������������ǰ��ʼ���������I=I+1�����ҵ���һ������key��A��A[j]��A������
			while (compareString(array[i],k)) {
				i++;
			}
			String temp1 = k;
			k = array[i];
			array[i] = temp1;
			// [27, 38, 65, 97, 76, 13, 49]
			// [27, 38, 49, 97, 76, 13, 49]
			// [27, 38, 49, 97, 76, 13, 65]
			// [27, 38, 13, 97, 76, 49, 65]
			// [27, 38, 13, 49, 76, 49, 65]
			// [27, 38, 13, 49, 76, 97, 65]
			System.out.println(array[i] + " " + array[j]);
			if (array[i] == array[j]) {
				x++;
				if (x > (array.length / 2 + 1)) {
					check = true;
				}
			}
			if (i == j || check) {
				k = array[0];// ��ȡ�����һλ
				if (i == j && i == 0) {
					k = array[1];
				}
				i = 0;
				j = array.length - 1;// ��ȡ�������һλ
				check = false;
				x = 0;
				if (f > (array.length / 2 + 1)) {
					k = array[j];
				}
				if (f == array.length) {
					break;
				}
				f++;
			} // [27, 38, 13, 49, 76, 97, 65] //[13, 27, 38, 49, 76, 97, 65]
		}
		for (int t = 0; t < array.length; t++) {
			System.out.println("resualt:" + array[t]);
		}
	}
}

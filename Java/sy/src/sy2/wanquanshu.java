package sy2;

public class wanquanshu {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		int index = 0,num = 1;
		while(num <= 10000) {
			int sum = 0;
			int i = 1;
			while(i < num) {
				sum += (num % i == 0) ? i : 0;
				i++;
			}
			if(sum == num) {
				System.out.print(num + " ");
				index++;
				if(index % 5 == 0)
					System.out.print("\n");
			}
			num++;
		}

	}

}

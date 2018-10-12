package sy2;

public class huiwenzhengshu {
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		long index = 0L,num = 1L;
		while(num <= 99999) {
			if(isPalindrome(num) && isPalindrome(num * num) && isPalindrome(num * num * num)) {
				System.out.print(num + " ");
				index++;
				if(index % 5 == 0)
					System.out.print("\n");
			}
			num++;
		}
	}
	public static long reverse(long number) {
		long num = 0;
		while(number != 0) {
			num *= 10;
			num += number % 10;
			number /= 10;
		}
		return num;
	}
	public static boolean isPalindrome(long number) {
		if(number == reverse(number))
			return true;
		else return false;
	}
}

package sy4;
import java.util.Date;

public class bank {
	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		Account newAccount = new Account(123456,10000,0.033);
		newAccount.withdraw(2000);
		newAccount.deposit(3000);
		System.out.println("��" + newAccount.getBalance() + "Ԫ");
		System.out.println("����Ϣ��" + newAccount.getMonthlyInterest() + "Ԫ");
		System.out.println("�������ڣ�" + newAccount.getDateCreated());
	}
}

class Account {
	int id;
	double balance;
	double annualInterestRate;
	Date dateCreated;
	public Account() {
		dateCreated = new Date();
	}
	public Account(int id,double balance,double annualInterestRate) {
		this.id = id;
		this.balance = balance;
		this.annualInterestRate = annualInterestRate;
		dateCreated = new Date();
	}
	public int getId() {
		return id;
	}
	public double getBalance() {
		return balance;
	}
	public double getAnnualInterestRate() {
		return annualInterestRate;
	}
	public void setId(int id) {
		this.id = id;
	}
	public void setBalance(double balance) {
		this.balance = balance;
	}
	public void setAnnualInterestRate(double annualInterestRate) {
		this.annualInterestRate = annualInterestRate;
	}
	public String getDateCreated() {
		return dateCreated.toString();
		//String.format("%04d��%02d��%02d�� ����%d %02d:%02d:%02d", dateCreated.getYear(), dateCreated.getMonth(), dateCreated.getDate(), dateCreated.getDay(), dateCreated.getHours(), dateCreated.getMinutes(), dateCreated.getSeconds());
	}
	public double getMonthlyInterest() {
		return balance * annualInterestRate / 12;
	}
	public void withdraw(double amount) {
		balance -= amount;
	}
	public void deposit(double amount) {
		balance += amount;
	}
}
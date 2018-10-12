package AfterClass;

import java.util.ArrayList;
import java.util.Date;

public class bank {
	public static void main(String[] args) {
		Account a1 = new Account();
		SavingAccount a2 = new SavingAccount();
		CheckingAccount a3 = new CheckingAccount();
		System.out.println(a1.toString());
		System.out.println(a2.toString());
		System.out.println(a3.toString());
		
		Account test = new Account("George",1122,1000,1.2);
		test.deposit(30);
		test.deposit(40);
		test.deposit(50);
		test.withdraw(5);
		test.withdraw(4);
		test.withdraw(2);
		System.out.println(test.printAccount());
	}
}

class Transaction {
	private Date date;
	private char type;
	private double amount;
	private double balance;
	private String description;
	public Transaction(char type,double amount,double balance,String description) {
		date = new Date();
		this.type = type;
		this.amount = amount;
		this.balance = balance;
		this.description = description + "交易类型：" + type + "\n交易数额：" + amount + "\n账户余额：" + balance + "\n交易日期：" + date.toString() + "\n";
	}
	public String getDate() {
		return date.toString();
	}
	public char getType() {
		return type;
	}
	public double getAmount() {
		return amount;
	}
	public double getBalance() {
		return balance;
	}
	public String getDescription() {
		return description;
	}
	public void setDescription(String description) {
		this.description = description;
	}
}

class Account {
	private int id = 0;
	private double balance = 0;
	static private  double annualInterestRate = 0;
	private Date dateCreated;
	private String name;
	private ArrayList<Transaction> transactions = new ArrayList<Transaction>();
	public Account() {
		dateCreated = new Date();
	}
	public Account(int id,double balance,double annualInterestRate) {
		this.id = id;
		this.balance = balance;
		Account.annualInterestRate = annualInterestRate;
		dateCreated = new Date();
	}
	public Account(String name,int id,double balance,double annualInterestRate) {
		this.name = name;
		this.id = id;
		this.balance = balance;
		Account.annualInterestRate = annualInterestRate;
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
	public String getName() {
		return name;
	}
	public void setId(int id) {
		this.id = id;
	}
	public void setBalance(double balance) {
		this.balance = balance;
	}
	public void setAnnualInterestRate(double annualInterestRate) {
		Account.annualInterestRate = annualInterestRate;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getDateCreated() {
		return dateCreated.toString();
		//String.format("%04d年%02d月%02d日 星期%d %02d:%02d:%02d", dateCreated.getYear(), dateCreated.getMonth(), dateCreated.getDate(), dateCreated.getDay(), dateCreated.getHours(), dateCreated.getMinutes(), dateCreated.getSeconds());
	}
	public double getMonthlyInterest() {
		return balance * annualInterestRate / 100 / 12;
	}
	public void withdraw(double amount) {
		balance -= amount;
		transactions.add(new Transaction('W',amount,balance,""));
	}
	public void deposit(double amount) {
		balance += amount;
		transactions.add(new Transaction('D',amount,balance,""));
	}
	public String printAccount() {
		String str = "";
		str += "账户持有者名字：" + name + "\n";
		str += "利率：" + Account.annualInterestRate + "\n";
		str += "余额：" + balance + "\n";
		for(int i = 0;i<transactions.size();i++) {
			str +=transactions.get(i).getDescription();
		}
		
		return str;
	}
}

class SavingAccount extends Account{
	static double touzhixiane = 0;
}

class CheckingAccount extends Account{
	double touzhixiane;
}

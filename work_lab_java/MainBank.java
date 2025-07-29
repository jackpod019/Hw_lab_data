package p4_2;

import p4_1.Date;

public class Main {

	public static void main(String[] args) {
		BankAccount q1 =new BankAccount("i");
		BankAccount q2 =new BankAccount("B",500,new Date(24,7,2025));
		q1.deposit(1000);
		 q2.transfer(q1,300);
		 q2.withdraw(300);
		 System.out.println(q1.property()+" "+ q1.getInfo());
		 System.out.println(q2.property()+" "+ q2.getInfo());
	}

}

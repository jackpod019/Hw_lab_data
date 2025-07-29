package p4_2;
import p4_1.Date;

	public class BankAccount {
	    private String name;
	    private double amount;
	    private Date date;

	    
	    public BankAccount(String name) {
	        this.name = name;
	        this.amount = 0.0;
	        this.date = new Date(); 
	    }

	    
	    public BankAccount(String name, double amount, Date date) {
	        this.name = name;
	        this.amount = amount;
	        this.date = date;
	    }

	    
	    public void deposit(double amount) {
	        if (amount > 0) {
	            this.amount += amount;
	        }
	    }

	   
	    public boolean withdraw(double amount) {
	        if (amount > 0 && amount <= this.amount) {
	            this.amount -= amount;
	            return true;
	        } else {
	            return false;
	        }
	    }

	    
	    public void transfer(BankAccount other, double amount) {
	        if (this.withdraw(amount)) {
	            other.deposit(amount);
	        }
	    }

	    
	    public double getamount() {
	        return this.amount;
	    }

	    
	    public String getInfo() {
	        return "ชื่อบัญชี: " + this.name + ", วันที่เปิดบัญชี: " ;
	    }


		public double property() {
			
			return amount;
		}
	}

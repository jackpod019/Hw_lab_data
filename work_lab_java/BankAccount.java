public class BankAccount {
    private String name;
    private double amount;
    private Date date;


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
            System.out.println("ไม่สามารถถอนเงินได้ เนื่องจากยอดเงินไม่เพียงพอ.");
            return false;
        }
    }

    public void transfer(BankAccount other, double amount) {
        if (this.withdraw(amount)) {
            other.deposit(amount);
        }
    }

    public double getAmount() {
        return this.amount;
    }

    public String getInfo() {
        return "ชื่อบัญชี: " + this.name + ", วันที่เปิดบัญชี: "
            + this.date.getday() + "/" + this.date.getmonth() + "/" + this.date.getyear();
    }

    public double property() {
        return amount;
    }
}


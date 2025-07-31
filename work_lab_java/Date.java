public class Date {
    private int day;
    private int month;
    private int year;

    public Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    public Date() {}

    public int getday() {
        return day;
    }

    public void setday(int day) {
        if (day >= 1 && day <= 31) {
            this.day = day;
        }
    }

    public int getmonth() {
        return month;
    }

    public void setmonth(int month) {
        if (month >= 1 && month <= 12) {
            this.month = month;
        }
    }

    public int getyear() {
        return year + 543;
    }

    public void setyear(int year) {
        this.year = year;
    }
}


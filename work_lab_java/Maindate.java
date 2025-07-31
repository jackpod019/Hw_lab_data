
public class Maindate {
    public static void main(String[] args) {
        
        Date date1 = new Date(15, 7, 2025);
        System.out.println("วันที่ที่สร้างไว้: " + date1.getday() + "/" + date1.getmonth() + "/" + date1.getyear());

        
        Date date2 = new Date();
        date2.setday(31);
        date2.setmonth(12);
        date2.setyear(2020);
        System.out.println("วันที่ตั้งค่าด้วย setter: " + date2.getday() + "/" + date2.getmonth() + "/" + date2.getyear());

    }
}

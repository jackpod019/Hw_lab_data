package p4_1;

import java.security.PublicKey;

public class Date {
	private int day;
	private int mount;
	private int year;
	public Date(int d,int m,int y) {
		day=d;
		mount=m;
		year=y;
	}
	public Date() {
		
	}
	public int getday() {
		return day;
	}
	
	public void setday(int day) {
		if(day>=1&&day<=31) {
		this.day =day;
		}
	}
	
	public int getmount() {
		return mount;
	}
	
	public void setmount(int mount) {
		if(mount>=1&&mount<=12)
		this.mount =mount;
	}
	
	public int getyear() {
		return year+543;
	}
	
	public void setyear(int year) {
		this.year =year;
	}
}

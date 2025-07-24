package p4_1;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Date t = new Date();
		Scanner sc = new Scanner(System.in);
		System.out.printf("Enter Day: ");
		int d =sc.nextInt();
		t.setday(d);
		System.out.printf("Enter Mount: ");
		int m =sc.nextInt();
		t.setday(m);
		System.out.printf("Enter year: ");
		int y =sc.nextInt();
		t.setyear(y);
	}

}

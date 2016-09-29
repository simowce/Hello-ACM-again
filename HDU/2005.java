import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		String date;
		Scanner in = new Scanner(System.in);
		int year;
		int month;
		int day;

		while (in.hasNext()) {
			date = in.nextLine();
			String[] d = date.split("/");
			year = Integer.parseInt(d[0]);
			month = Integer.parseInt(d[1]);
			day = Integer.parseInt(d[2]);

			boolean leap = isLeap(year);
			System.out.println(inThDay(leap, month, day));
		}
	}

	public static boolean isLeap(int year) {
		if (year%100==0)
			return year%400==0 ? true: false;
		else
			return year%4==0 ? true : false;
	}

	public static int inThDay(boolean isLeap, int month, int day) {
		int amount = 0;

		switch (month-1) {
			case 11: amount += 30;
			case 10: amount += 31;
			case  9: amount += 30;
			case  8: amount += 31;
			case  7: amount += 31;
			case  6: amount += 30;
			case  5: amount += 31;
			case  4: amount += 30;
			case  3: amount += 31;
			case  2: amount += isLeap ? 29 : 28;
			case  1: amount += 31;
		}
		amount += day;

		return amount;
	}
}

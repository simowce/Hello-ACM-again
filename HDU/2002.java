import java.util.Scanner;
import java.text.DecimalFormat;

public class Main {
	public static void main(String[] args) {
		final double PI = 3.1415927;
		double r;
		Scanner in = new Scanner(System.in);
		DecimalFormat df = new DecimalFormat("0.000");

		while (in.hasNext()) {
			r = in.nextDouble();
			System.out.println(df.format(PI*r*r*r*4/3));
		}
	}
}

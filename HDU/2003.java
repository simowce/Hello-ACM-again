import java.util.Scanner;
import java.text.DecimalFormat;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		DecimalFormat df = new DecimalFormat("0.00");
		double n;

		while (in.hasNext()) {
			n = in.nextDouble();
			System.out.println(df.format(n > 0 ? n : -n));
		}
	}
}

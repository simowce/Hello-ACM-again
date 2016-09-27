import java.util.*;
import java.text.DecimalFormat;
import java.math.RoundingMode;

public class Main {
	public static void main(String[] args) {
		double x1, x2, y1, y2;
		double instance;
		Scanner in = new Scanner(System.in);

		while (in.hasNext()) {
			x1 = in.nextDouble();
			y1 = in.nextDouble();
			x2 = in.nextDouble();
			y2 = in.nextDouble();

			DecimalFormat df = new DecimalFormat("0.00");
			//df.setRoundingMode(RoundingMode.DOWN);
			instance = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
			instance = Math.sqrt(instance);
			System.out.println(df.format(instance));
		}
	}
}

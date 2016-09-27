import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int nums;
		int sum;

		while (in.hasNextInt()) {
			nums = in.nextInt();
			sum = 0;
			for (int i = 0; i < nums; i++)
				sum += in.nextInt();
			System.out.println(sum);
		}
	}
}

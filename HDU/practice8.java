import java.util.*;

public class Main {
	public static void main(String[] args) {
		int counts;
		Scanner in = new Scanner(System.in);
		int nums;
		int sum;

		counts = in.nextInt();
		for (int i = 0; i < counts; i++) {
			nums = in.nextInt();
			sum = 0;
			for (int j = 0; j < nums; j++)
				sum += in.nextInt();
			System.out.println(sum);
			if (i != counts-1)
				System.out.println();
		}
	}
}

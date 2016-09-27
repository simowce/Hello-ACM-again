import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int counts;
		int sum;
		int nums;

		counts = in.nextInt();
		for (int i = 0; i < counts; i++) {
			nums = in.nextInt();
			sum = 0;
			for (int j = 0; j < nums; j++)
				sum += in.nextInt();
			System.out.println(sum);
		}
	}
}

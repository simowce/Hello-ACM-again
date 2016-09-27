import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int nums;
		Scanner in = new Scanner(System.in);
		int sum;

		while (in.hasNextInt()) {
			nums = in.nextInt();	
			if (nums == 0)
				break;

			sum = 0;
			for (int i = 0; i < nums; i++) {
				sum += in.nextInt();
			}
			System.out.println(sum);
		}
	}
}

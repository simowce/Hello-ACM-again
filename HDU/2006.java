import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int ret;
		int t;

		while (in.hasNext()) {
			int all = in.nextInt();
			ret = 1;
			for (int i = 0; i < all; i++) {
				t = in.nextInt();
				if (t%2 != 0)
					ret *= t;
			}

			System.out.println(ret);
		}
	}
}

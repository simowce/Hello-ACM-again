import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int timers;
		int n1, n2;

		timers = in.nextInt();
		for (int i = 0; i < timers; i++) {
			n1 = in.nextInt();
			n2 = in.nextInt();

			System.out.println(n1+n2);
		}
	}
}

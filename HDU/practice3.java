import java.util.*;

public class Main {
	public static void main(String[] args) {
		int n1, n2;
		Scanner in = new Scanner(System.in);

		while (in.hasNextInt()) {
			n1 = in.nextInt();
			n2 = in.nextInt();
			if (n1 != 0 || n2 != 0)
				System.out.println(n1+n2);
			else
				break;
		}
	}
}

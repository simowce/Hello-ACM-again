import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int score;

		// BUG#1: if in is a negative value between -1 and -9, its result of dividing 10 is 0!!!
		while (in.hasNext()) {
			score = in.nextInt();
			if (score > 100 || score < 0) {
				System.out.println("Score is error!");
				continue;
			}
			switch (score/10) {
			case 10:
			case 9:
				System.out.println("A");
				break;
			case 8:
				System.out.println("B");
				break;
			case 7:
				System.out.println("C");
				break;
			case 6:
				System.out.println("D");
				break;
			case 5: case 4: case 3: case 2: case 1: case 0:
				System.out.println("E");
				break;
			}
		}
	}
}

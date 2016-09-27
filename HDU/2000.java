import java.util.*;

public class Main {
	public static void main(String[] args) {
		int count;
		Scanner in = new Scanner(System.in);
		String str;

		//count = in.nextInt();
		count = Integer.parseInt(in.nextLine());
		for (int i = 0; i < count; i++) {
			// TODO: 1. 怎样读取带空格的字符串
			//       2. 怎样知道一个数组的大小
			//       3. count 在读入之后剩下的回车会被当成是下一个输入
			str = in.nextLine();
			String[] split = str.split(" ");
			StringBuilder sb = new StringBuilder();
			
			for (int j = 0; j < split.length; j++) {
				StringBuilder tmp = new StringBuilder(split[j]);
				tmp.reverse();
				sb.append(tmp.toString());
				if (j != split.length-1)
					sb.append(" ");
			}
			System.out.print(sb.toString());
			if (i != count-1)
				System.out.println();
		}
	}
}

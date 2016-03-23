import java.util.Scanner;

public class TrapCoins {

	public static int N;
	public static long[] a = new long[1000100];
	public static long[] best = new long[1000100];

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		for(int i = 1;i<=N;++i) {
			a[i] = scanner.nextInt();
		}
		best[0] = 0;
		best[1] = Math.max(0,a[1]);
		for(int i=2;i<=N;++i) {
			best[i] = Math.max(best[i-1], a[i] + best[i - 2]);
		}
		System.out.println(best[N]);
	}
}
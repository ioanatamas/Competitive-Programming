import java.util.Scanner;

public class PerfectFactorial {

	public static long countP(int N, int p) {
		long powP = p, ret = 0;
		while(powP <= N) {
			ret += N / powP;
			powP *= p;
		}
		return ret;
	}
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int P = scanner.nextInt();
		int K = scanner.nextInt();

		int ret = 0, left = 1, right = 2000000000;
		while(left <= right) {
			int mid = left + (right - left)/2;
			if(countP(mid, P) >= K) {
				ret = mid;
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
		System.out.println(ret);
	}
}
import java.util.Scanner;

public class GameOfAlgorithms {

	public static int N;
	public static int[] a = new int[100100];

	public static boolean check(int rounds) {
		long R = 0;
		for(int i=1;i<=N;++i) {
			//We sum up how many times each student can prepare
			R = R + Math.max(0, rounds - a[i]);
		}
		return (rounds <= R);
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		int left = 0;
		for(int i=1;i<=N;++i) {
			a[i] = scanner.nextInt();
			left = Math.max(left, a[i]);
		}
		int right = 2000000000, ret = 2000000000;
		while(left <= right) {
			int mij = left + (right-left)/2;
			if(check(mij)) {
				ret = mij;
				right = mij-1;
			} else {
				left = mij+1;
			}
		}
		System.out.println(ret);
	}
}
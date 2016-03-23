import java.util.Scanner;

public class CountingBinaryNumbers {

	public static int N,k;
	public static int[][] best = new int[100100][15];
	public static int[] bestSum = new int[100100];
	public static final int MOD = 666013;

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		k = scanner.nextInt();
		best[0][0]= 1;
		bestSum[0] = 1;
		for(int i=1;i<=N;++i) {
			for(int j=0;j<=k;++j) {
				if(j==0) {
					best[i][j] = bestSum[i-1];
				} else {
					best[i][j] = best[i-1][j-1];
				}
				bestSum[i] = (bestSum[i] + best[i][j]) % MOD;
			}
		}
		System.out.println(bestSum[N]);
	}
}
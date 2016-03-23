import java.util.Scanner;

public class ChocolateSquares {

	public static int N,M;
	public static int[][] best = new int[510][510];

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		M = scanner.nextInt();
		for(int i=1;i<=N;++i) {
			for(int j=1;j<=M;++j) {
				if(i==j) {
					best[i][j] = 0;
					continue;
				}
				best[i][j] = M*N;
				for(int k=1;k<j;++k) {
					best[i][j] = Math.min(best[i][j], 1 + best[i][k] + best[i][j-k]);
				}
				for(int k=1;k<i;++k) {
					best[i][j] = Math.min(best[i][j], 1 + best[k][j] + best[i-k][j]);
				}
			}
		}
		System.out.println(best[N][M]);
	}
}
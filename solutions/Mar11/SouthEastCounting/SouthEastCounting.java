import java.util.Scanner;

public class SouthEastCounting {

	public static int N,M;
	public static int[][] a = new int[2010][2010];
	public static int[][] num = new int[2010][2010];
	public static final int MOD = 666013;

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		M = scanner.nextInt();
		for(int i=1;i<=N;++i) {
			for(int j=1;j<=M;++j) {
				a[i][j] = scanner.nextInt();
			}
		}
		if(a[1][1] == 1 || a[N][M] == 1) {
			System.out.println(0);
			return;
		}
		num[1][1]= 1;
		for(int i=1;i<=N;++i) {
			for(int j=1;j<=M;++j) {
				if(i > 1 || j > 1) {
					num[i][j] = 0;
				}
				if(a[i][j] == 1) continue;
				if(i>1 && a[i-1][j]==0) {
					num[i][j] = num[i-1][j];
				}
				if(j>1 && a[i][j-1]==0) {
					num[i][j] = (num[i][j] + num[i][j-1]) % MOD;
				}
			}
		}
		System.out.println(num[N][M]);
	}
}
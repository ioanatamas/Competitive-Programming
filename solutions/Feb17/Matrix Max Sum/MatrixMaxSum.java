import java.util.Scanner;

public class MatrixMaxSum {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		int[][] a = new int[210][210];
		long[][] s = new long[210][210];
		long sumMax = 0;
		for(int i=1;i<=N;++i) {
			for(int j=1;j<=M;++j) {
				s[0][j] = 0;
				a[i][j] = scanner.nextInt();
				if(i==1 && j==1) {
					sumMax = a[i][j];
				} else {
					sumMax = Math.max(sumMax, a[i][j]);
				}
				s[i][j] = s[i-1][j] + a[i][j];
			}
		}

		for(int i=1;i<=N;++i) {
			for(int j=i;j<=N;++j) {
				//Do maximum subsequence sum for the partial sums between lines i and j
				long sumCurrent = 0;
				for(int k=1;k<=M;++k) {
					if(sumCurrent + s[j][k] - s[i-1][k] < 0) {
						sumCurrent = 0;
					} else {
						sumCurrent += s[j][k] - s[i - 1][k];
						sumMax = Math.max(sumMax, sumCurrent);
					}
				}
			}
		}

		System.out.println(sumMax);
	}
}
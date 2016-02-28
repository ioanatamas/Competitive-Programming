import java.util.Scanner;

public class EatingIceCream {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		long a[] = new long[100100];
		long s[] = new long[100100];
		s[0] = 0;
		for(int i=1;i<=N;++i) {
			a[i] = scanner.nextInt();
			s[i] = s[i-1] + a[i];
		}
		for(int i=0;i<M;++i) {
			int ind = scanner.nextInt();
			long val = scanner.nextInt();
			int left = 0, right = N-1, nr = -1;
			while(left <= right) {
				int mid = (left + right)/2;
				long sum = 0;
				if(ind + mid <= N) {
					sum = s[ind+mid] - s[ind-1];
				} else {
					sum = s[ind+mid-N] + s[N] - s[ind-1];
				}
				if(sum <= val) {
					nr = mid;
					left = mid+1;
				} else {
					right = mid-1;
				}
			}
			System.out.println(nr+1);
		}
	}
}
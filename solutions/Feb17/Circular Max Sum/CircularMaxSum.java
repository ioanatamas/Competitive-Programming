import java.util.Scanner;

public class CircularMaxSum {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		long a[] = new long[1000100];
		long sumTotal = 0, sumMax = 0, sumMin = 0;
		for(int i=1;i<=N;++i) {
			a[i] = scanner.nextInt();
			sumTotal += a[i];
			if(i==1) {
				sumMax = a[i];
				sumMin = a[i];
			}
			sumMax = Math.max(a[i], sumMax);
			sumMin = Math.min(a[i], sumMin);
		}
		if(sumMax < 0) {
			System.out.println(sumMax);
			return;
		}
		long sumCurrent = 0;
		for(int i=1;i<=N;++i) {
			if(sumCurrent + a[i] < 0) {
				sumCurrent = 0;
			} else {
				sumCurrent += a[i];
				sumMax = Math.max(sumMax, sumCurrent);
			}
		}
		sumCurrent = 0;
		for(int i=1;i<=N;++i) {
			if(sumCurrent + a[i] > 0) {
				sumCurrent = 0;
			} else {
				sumCurrent += a[i];
				sumMin = Math.min(sumMin, sumCurrent);
			}
		}
		System.out.println(Math.max(sumMax, sumTotal - sumMin));
	}
}
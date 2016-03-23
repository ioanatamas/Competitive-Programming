import java.util.ArrayList;
import java.util.Scanner;

public class TreeCoins {

	public static int N;
	public static int[] a = new int[100100];
	public static int[] vis = new int[100100];
	public static long[] take = new long[100100];
	public static long[] noTake = new long[100100];
	public static ArrayList<Integer>[] edges = new ArrayList[100100];

	public static void dfs(int x) {
		vis[x] = 1;
		take[x] = a[x];
		noTake[x] = 0;
		for(Integer y: edges[x]) {
			if(vis[y]==1) continue;
			dfs(y);
			take[x] += noTake[y];
			noTake[x] += Math.max(take[y], noTake[y]);
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		N = scanner.nextInt();
		for(int i=1;i<=N;++i) {
			edges[i] = new ArrayList<Integer>();
			a[i] = scanner.nextInt();
			vis[i] = 0;
		}
		for(int i = 1;i<N;++i) {
			int x = scanner.nextInt();
			int y = scanner.nextInt();
			edges[x].add(y);
			edges[y].add(x);
		}
		dfs(1);
		System.out.println(Math.max(take[1], noTake[1]));
	}
}
import java.util.Scanner;

/**
 * ADS_quang_cao
 */
public class ADS_quang_cao {
    int n, m;
    int[][] arr = new int[101][101];
    boolean[] visited = new boolean[101];
    boolean[] inStack = new boolean[101];

    int dfs(int u, int cha) {
        visited[u] = true;
        inStack[u] = true;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (i != cha && arr[u][i] > 0) {
                if (inStack[i])
                    res++;
                if (!visited[i])
                    res += dfs(i, u);
            }
        }
        inStack[u] = false;
        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ADS_quang_cao a = new ADS_quang_cao();

        a.n = scanner.nextInt();
        a.m = scanner.nextInt();
        int u, v;

        for (int i = 0; i < a.m; i++) {
            u = scanner.nextInt();
            v = scanner.nextInt();
            a.arr[u][v] = v;
            a.arr[v][u] = u;
        }
        scanner.close();

        int res = 0;
        for (u = 1; u <= a.n; u++) {
            if (!a.visited[u]) {
                res += a.dfs(u, 0);
            }
        }
        System.out.println(res);
    }
}
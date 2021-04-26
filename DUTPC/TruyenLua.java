import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class TruyenLua {

    class Pair<X, Y> {
        X x;
        Y y;
    }

    static int[][] a = new int[1011][1011];
    static int[][] visited = new int[1011][1011];
    static int n, m;
    Pair<Integer, Integer> pa = new Pair<>();

    void bfs() {
        Queue<Pair> q = new LinkedList<>();

        boolean[] visit = new boolean[n * m];

        Arrays.fill(visit, false);

        q.enqueue(pa);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = scanner.nextInt();
            }
        }

    }
}

package bfs;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Dhoom4 {
    static final int MAX = 100000 + 5;
    static final int MOD = 100000;
    static int N;
    static int[] dist = new int[MAX];
    static int[] a= new int[MAX];

    public static int bfs(int s, int f) {
        Arrays.fill(dist, -1);
        Queue<Integer> queue = new LinkedList<>();
        queue.add(s);
        dist[s] = 0;

        while(!queue.isEmpty()) {
            int u = queue.poll();
            for(int i = 0; i < N; i++) {
                Long tmp = (1L * a[i] * u) % MOD;
                int v = tmp.intValue();

                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    queue.add(v);

                    if(v == f) {
                        return dist[v];
                    }
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int s = scanner.nextInt();
        int f = scanner.nextInt();
        N = scanner.nextInt();
        for (int i = 0; i < N; i++) {
            a[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(bfs(s, f));
    }
}   
package bfs;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class ShortestReach {
    static final int MAX = 1000 + 5;
    static int V, E;
    static boolean[] visited = new boolean[MAX];
    static int[] dist = new int[MAX];
    static ArrayList<Integer>[] graph = new ArrayList[MAX];

    public static void BFS(int s) {
        Queue<Integer> q = new LinkedList<>();
        visited[s] = true;
        q.add(s);

        while (!q.isEmpty()) {
            int u = q.poll();

            for (int v: graph[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    dist[v] = dist[u] + 1;
                    q.add(v);
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int Q = scanner.nextInt();
        for (int i = 0; i < MAX; i++) {
            graph[i] = new ArrayList<>();
        }
        while (Q-- > 0) {
            int V = scanner.nextInt();
            int E = scanner.nextInt();

            for (int i = 0; i < MAX; i++) {
                graph[i].clear();
                visited[i] = false;
                dist[i] = 0;
            }

            for (int i = 0; i < E; i++) {
                int u = scanner.nextInt();
                int v = scanner.nextInt();
                graph[u].add(v);
                graph[v].add(u);
            }

            int s = scanner.nextInt();
            BFS(s);
            for (int i = 1; i <= V; i++) {
                if (i == s) continue;
                System.out.print((visited[i] ? dist[i] * 6 : -1) + " ");
            }
            System.out.println();
        }
        scanner.close();
    }
}

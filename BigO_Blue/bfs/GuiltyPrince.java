package bfs;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class GuiltyPrince {
    static final int MAX = 21;
    static final int[] dr = {0, 0, -1, 1};
    static final int[] dc = {1, -1, 0, 0};
    static int W, H;
    static boolean[][] visited = new boolean[MAX][MAX];
    static String[] maze = new String[MAX];

    static class Cell {
        int r, c;

        public Cell(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    public static boolean isValid(int r, int c) {
        return r >= 0 && r < H && c >= 0 && c < W;
    }

    public static int bfs(Cell s) {
        Queue<Cell> q = new LinkedList<>();
        q.add(s);
        visited[s.r][s.c] = true;
        int count = 1;

        while (!q.isEmpty()) {
            Cell u = q.poll();

            for (int i = 0; i < 4; i++) {
                int r = u.r + dr[i];
                int c = u.c + dc[i];

                if (isValid(r, c) && maze[r].charAt(c) == '.' && !visited[r][c]) {
                    visited[r][c] = true;
                    q.add(new Cell(r, c));
                    count++;
                }
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int ntests = scanner.nextInt();
        int k = 1;
        Cell s = new Cell(0, 0);
        while (ntests-- > 0) {
            W = scanner.nextInt();
            H = scanner.nextInt();

            for(int i = 0; i < H; i++) {
                maze[i] = scanner.next();

                for(int j = 0; j < W; j++) {
                    if (maze[i].charAt(j) == '@') {
                        s = new Cell(i, j);
                    }
                    visited[i][j] = false;
                }
            }
            System.out.println("Case "+ k++ + ": " + bfs(s));
        }
        scanner.close();
    }
}

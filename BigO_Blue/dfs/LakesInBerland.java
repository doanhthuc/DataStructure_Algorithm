package dfs;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;
import java.util.stream.Collectors;

public class LakesInBerland {
    static final int MAX = 51;
    static int[] offset = {0, 1, 0, -1, 0};
    static int n, m, k;
    static boolean[][] visited = new boolean[MAX][MAX];
    static char[][] table;

    
    static class Cell {
        int r, c;

        public Cell(int r, int c) {
            this.r = r;
            this.c = c;
        }
    };

    static ArrayList<ArrayList<Cell>> lakes = new ArrayList<ArrayList<Cell>>();

    public static boolean isValid(int r, int c) {
        return r >= 0 && c >= 0 && r < n && c < m;
    }

    public static boolean onBorder(int r, int c) {
        return r == 0 || c == 0 || r == n - 1 || c == m - 1;
    }

    public static void dfs(Cell src) {
        Stack<Cell> s = new Stack<>();
        visited[src.r][src.c] = true;
        s.add(src);

        boolean isOcean = false;
        ArrayList<Cell> tmp = new ArrayList<>();

        while(!s.isEmpty()) {
            Cell u = s.pop();
            tmp.add(u);

            if (onBorder(u.r, u.c)) {
                isOcean = true;
            }

            for(int i = 0; i < 4; i++) {
                int r = u.r + offset[i];
                int c = u.c + offset[i + 1];

                if (isValid(r, c) && table[r][c] == '.' && !visited[r][c]) {
                    visited[r][c] = true;
                    s.add(new Cell(r, c));
                }
            }
        }

        if (!isOcean) {
            lakes.add(tmp);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        k = scanner.nextInt();
        
        table = new char[n][m];

        for (int i = 0; i < n; i++) {
            table[i] = scanner.next().toCharArray();
        }
        scanner.close();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && table[i][j] == '.') {
                    dfs(new Cell(i, j));
                }
            }
        }

        List<ArrayList<Cell>> sortedLakes = lakes
                                                .stream()
                                                .sorted(
                                                    Comparator
                                                        .comparing(list -> list.size()))
                                                .collect(Collectors.toList());

        int sumCells = 0;

        for (int i = 0; i < sortedLakes.size() - k; i++) {
            sumCells += sortedLakes.get(i).size();
            sortedLakes.get(i).forEach(cell -> table[cell.r][cell.c] = '*');
        }

        System.out.println(sumCells);
        
        Arrays.asList(table).stream().forEach(System.out::println);
    }
}
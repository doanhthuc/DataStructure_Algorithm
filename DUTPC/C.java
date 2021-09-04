import java.util.LinkedList;
import java.util.Scanner;

// den so vung

class C {
    public static int numIslands(char[][] grid) {
        int count = 0;
        for (int i = 0; i < grid.length; i++)
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 'W') {
                    bfsFill(grid, i, j);
                    count++;
                }
            }
        return count;
    }

    private static void bfsFill(char[][] grid, int x, int y) {
        grid[x][y] = '.';
        int n = grid.length;
        int m = grid[0].length;
        LinkedList<Integer> queue = new LinkedList<Integer>();
        int code = x * m + y;
        queue.offer(code);
        while (!queue.isEmpty()) {
            code = queue.poll();
            int i = code / m;
            int j = code % m;
            if (i > 0 && grid[i - 1][j] == 'W') // search upward and mark adjacent '1's as '0'.
            {
                queue.offer((i - 1) * m + j);
                grid[i - 1][j] = '.';
            }
            if (i < n - 1 && grid[i + 1][j] == 'W') // down
            {
                queue.offer((i + 1) * m + j);
                grid[i + 1][j] = '.';
            }
            if (j > 0 && grid[i][j - 1] == 'W') // left
            {
                queue.offer(i * m + j - 1);
                grid[i][j - 1] = '.';
            }
            if (j < m - 1 && grid[i][j + 1] == 'W') // right
            {
                queue.offer(i * m + j + 1);
                grid[i][j + 1] = '.';
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, m;
        n = Integer.parseInt(scanner.nextLine());
        m = Integer.parseInt(scanner.nextLine());
        char[][] a = new char[n][m];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLine().toCharArray();
        }
        int res = numIslands(a);
        System.out.println(res);
    }
}
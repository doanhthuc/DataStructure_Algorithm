package QuyHoachDong;

import java.util.Scanner;

public class SubSetSum {
    static boolean isSubSetSum(int[] set, int n, int sum) {
        boolean[][] table = new boolean[100][100];
        // Neu sum = 0 thi la true
        for (int i = 0; i <= n; i++) {
            table[i][0] = true;
        }
        // Neu sum != 0 ma set empty thi false
        for (int i = 1; i <= sum; i++) {
            table[0][i] = false;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (j < set[i - 1]) {
                    table[i][j] = table[i - 1][j];
                }
                if (j >= set[i - 1]) {
                    table[i][j] = table[i - 1][j] || table[i - 1][j - set[i - 1]];
                }
            }
        }
        return table[n][sum];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[] set = new int[100];
        int sum, n;
        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            set[i] = scanner.nextInt();
        }
        sum = scanner.nextInt();
        if (isSubSetSum(set, n, sum) == true)
            System.out.println("Yes");
        else
            System.out.println("No");
        scanner.close();
    }
}

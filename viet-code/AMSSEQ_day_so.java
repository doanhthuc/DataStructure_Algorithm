import java.util.Scanner;

/* https://vnoi.info/problems/AMSSEQ/ */
public class AMSSEQ_day_so {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, k;
        int[] arr = new int[10011];
        n = scanner.nextInt();
        k = scanner.nextInt();
        arr[0] = 0;
        for (int i = 1; i <= n; i++) {
            arr[i] = scanner.nextInt();
        }

        int[] table = new int[10011];
        for (int i = 0; i < n + 1; i++) {
            table[i] = Integer.MIN_VALUE;
        }
        table[0] = 0;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0 && j >= i - k; j--) {
                table[i] = Math.max(table[i], table[j] + arr[i]);
            }
            res = Math.max(res, table[i]);
        }

        System.out.println(res);
        scanner.close();
    }
}

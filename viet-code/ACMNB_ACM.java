import java.util.Arrays;
import java.util.Scanner;

public class ACMNB_ACM {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int a, b;
        int[] c = new int[2 * n];
        int res = 0;
        for (int i = 0; i < 2 * n; i++) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            res += b;
            c[i] = a - b;
        }
        Arrays.sort(c);
        for (int i = 0; i < n; i++) {
            res += c[i];
        }
        System.out.println(res);
        scanner.close();
    }
}

import java.util.Scanner;

public class BLGEN_Chuoi_gen {
    boolean isPrime(long x) {
        if (x == 0)
            return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }

    long cbrt(long x) {
        return Math.round(Math.pow(x, 1.0 / 3.0));
    }

    boolean isSpecial(long x) {
        long r = Math.round(Math.sqrt(x));
        long r3 = cbrt(x);
        return r * r == x || (r3 * r3 * r3 == x && isPrime(r3));
    }

    int[] read(String s) {
        String[] str = s.split(" ");
        int[] res = new int[str.length + 2];
        res[0] = 0; // Chưa thêm điều kiện phải là số đặc biệt như đề
        for (int i = 1; i <= str.length; i++) {
            res[i] = Integer.parseInt(str[i - 1]);
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BLGEN_Chuoi_gen b = new BLGEN_Chuoi_gen();
        String s1 = scanner.nextLine();
        int[] a1 = b.read(s1);
        String s2 = scanner.nextLine();
        int[] a2 = b.read(s2);
        scanner.close();
        int[][] table = new int[100][100];

        for (int i = 1; i <= a1.length; i++) {
            for (int j = 1; j <= a2.length; j++) {
                if (a1[i] == a2[j]) {
                    table[i][j] = table[i - 1][j - 1];
                } else {
                    table[i][j] = Math.max(table[i - 1][j], table[i][j - 1]);
                }
            }
        }
        System.out.println(table[a1.length - 1][a2.length - 1]);

    }
}

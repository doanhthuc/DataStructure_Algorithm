package QuyHoachDong;

import java.util.Arrays;

public class BaiToanCaiTui {
    int[] w = new int[100];
    int[] v = new int[100];
    int[][] f = new int[100][100];
    int n, m;

    void optimize() {
        Arrays.fill(f[0], 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                f[i][j] = f[i - 1][j];
                if (w[i] <= j && f[i][j] < f[i - 1][j - w[i]] + v[i]) {
                    f[i][j] = f[i - 1][j - w[i]] + v[i];
                }
            }
        }
    }

    void trace() {
        System.out.println("Gia tri lon nhat co the lay duoc: " + f[n][m]);
        // Truy vet tren bang phuong an tu hang n len hang 0
        int i = n;
        int j = m;
        while (i != 0) {
            if (f[i][j] != f[i - 1][j]) {
                System.out.print(i + "  ");
                j = j - w[i]; // đã chọn gói thứ i rồi thì chỉ có thể mang thêm được trọng lượng m - w[i] nữa
                              // thôi
            }
            i--;
        }
    }

    public static void main(String[] args) {
        BaiToanCaiTui b = new BaiToanCaiTui();
        b.w[0] = 0;
        b.w[1] = 3;
        b.w[2] = 4;
        b.w[3] = 5;
        b.w[4] = 9;
        b.w[5] = 4;

        b.v[0] = 0;
        b.v[1] = 3;
        b.v[2] = 4;
        b.v[3] = 4;
        b.v[4] = 10;
        b.v[5] = 4;

        b.n = 5;
        b.m = 11;

        b.optimize();
        b.trace();
    }
}

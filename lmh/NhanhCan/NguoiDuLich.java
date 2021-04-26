package NhanhCan;

import java.util.Arrays;

public class NguoiDuLich {
    int[][] cost = { { 0, 3, 2, 1 }, { 3, 0, 1, 2 }, { 2, 1, 0, 4 }, { 1, 0, 4, 0 } };

    int[] X = new int[4];
    int[] bestWay = new int[4];
    int[] tong = new int[4]; // De luu chi phi di tu Xo --> Xi
    boolean[] free = new boolean[4]; //
    int minSpend;

    void khoiTao() {
        Arrays.fill(free, true);
        X[0] = 0;
        tong[0] = 0;
        free[0] = false;
        minSpend = Integer.MAX_VALUE;
    }

    void deQuy(int i) {
        for (int j = 1; j < X.length; j++) {
            if (free[j] && cost[X[i - 1]][j] > 0) {
                X[i] = j; // Thử đi
                tong[i] = tong[i - 1] + cost[X[i - 1]][j];
                if (tong[i] < minSpend) {
                    if (i < bestWay.length - 1) { // chưa đi đến được tp cuối
                        free[j] = false;
                        deQuy(i + 1);
                        free[j] = true;
                    } else {
                        if (tong[i] + cost[X[i]][0] < minSpend) {
                            bestWay = X;
                            minSpend = tong[i] + cost[X[i]][0];
                        }
                    }
                }
            }
        }
    }

    void in() {
        for (int i = 0; i < bestWay.length; i++) {
            System.out.print(bestWay[i] + " --> ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        NguoiDuLich n = new NguoiDuLich();
        n.khoiTao();
        n.deQuy(1);
        n.in();
        System.out.println(n.tong[3]);
    }
}

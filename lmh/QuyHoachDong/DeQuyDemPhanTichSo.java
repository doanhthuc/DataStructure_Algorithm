package QuyHoachDong;

import java.util.Arrays;

public class DeQuyDemPhanTichSo {
    int[][] arr = new int[100][100];

    DeQuyDemPhanTichSo() {
        for (int i = 0; i < arr.length; i++) {
            Arrays.fill(arr[i], -1);
        }
    }

    int deQuy(int m, int v) {
        if (arr[m][v] == -1) {
            if (m == 0) {
                if (v == 0) {
                    arr[m][v] = 1;
                } else
                    arr[m][v] = 0;
            } else {
                if (m > v) {
                    arr[m][v] = deQuy(m - 1, v);
                } else
                    arr[m][v] = deQuy(m - 1, v) + deQuy(m, v - m);
            }
        }
        return arr[m][v];
    }

    public static void main(String[] args) {
        DeQuyDemPhanTichSo d = new DeQuyDemPhanTichSo();
        int res = d.deQuy(5, 5);
        System.out.println(res);
    }
}

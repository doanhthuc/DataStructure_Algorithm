package SinhHoanVi;

import java.util.Arrays;

/**
 * SinhNhiPhan
 */
public class SinhNhiPhan {
    int[] arr = new int[100];

    void sinhNhiPhan(int n) {
        int i;
        Arrays.fill(arr, 0, n, 0);
        do {
            i = n - 1;
            in(n);
            while (i >= 0 && arr[i] == 1) {
                arr[i] = 0;
                i -= 1;
            }

            if (i >= 0) {
                arr[i] = 1;
                // for (int j = i + 1; j < n; j++) {
                // arr[j] = 0;
                // }
            }
        } while (i >= 0);
    }

    void in(int n) {
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i]);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        SinhNhiPhan s = new SinhNhiPhan();
        s.sinhNhiPhan(3);
    }
}
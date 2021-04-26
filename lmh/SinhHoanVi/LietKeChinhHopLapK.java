package SinhHoanVi;

import java.util.Arrays;

public class LietKeChinhHopLapK {
    int[] arr = new int[100];

    void lietKeChinhHopLapK(int n) {
        Arrays.fill(arr, 0, n, 1);
        int i;
        do {
            in(n);
            i = n - 1;
            while (i >= 0 && arr[i] == n)
                i -= 1;
            if (i >= 0) {
                arr[i]++;
                for (int j = i + 1; j < n; j++) {
                    arr[j] = 1;
                }
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
        LietKeChinhHopLapK l = new LietKeChinhHopLapK();
        l.lietKeChinhHopLapK(3);
    }
}

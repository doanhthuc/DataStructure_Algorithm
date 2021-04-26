package QuayLui;

import java.util.Arrays;

public class LietKeChinhHopKhongLapK {

    int[] arr = new int[100];
    boolean[] b = new boolean[100];

    void khoiTao() {
        Arrays.fill(b, true);
    }

    void lietKeChinhHopKhongLapK(int n, int k, int i) {
        for (int j = 1; j <= n; j++) {
            if (b[j]) {
                arr[i] = j;
                if (i == k)
                    in(k);
                else {
                    b[j] = false;
                    lietKeChinhHopKhongLapK(n, k, i + 1);
                    b[j] = true;
                }
            }
        }
    }

    void in(int n) {
        arr[0] = 0;
        for (int i = 1; i <= n; i++) {
            System.out.print(arr[i]);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        LietKeChinhHopKhongLapK l = new LietKeChinhHopKhongLapK();
        l.khoiTao();
        l.lietKeChinhHopKhongLapK(5, 3, 1);
    }
}

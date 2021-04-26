package QuyHoachDong;

import java.util.Arrays;

public class DemPhanTichSo {
    int[] arr = new int[100];

    DemPhanTichSo() {
        Arrays.fill(arr, 0);
        arr[0] = 1;
    }

    int demCachPhanTichSo(int n) {
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                arr[j] = arr[j] + arr[j - i];
            }
        }
        return arr[n];
    }

    public static void main(String[] args) {
        DemPhanTichSo d = new DemPhanTichSo();

        int res = d.demCachPhanTichSo(5);
        System.out.println(res);
    }

}

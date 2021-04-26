package QuayLui;

/* 
    CHUA XONG, KQ SAI
*/
public class PhanTichSo {
    int[] arr = new int[100];
    int[] t = new int[100];

    void khoiTao() {
        arr[0] = 1;
        t[0] = 0;
    }

    void inKq(int n) {
        for (int i = 1; i <= n; i++) {
            System.out.print(arr[i] + " + ");
        }
        System.out.println();
    }

    void phanTichSo(int n, int i) {
        for (int j = arr[i - 1]; j <= (n - t[i - 1]) / 2; j++) {
            arr[i] = j;
            t[i] = t[i - 1] + j;
            // System.out.println("tai vi tri " + i + ": " + arr[i] + " - " + j + " - " +
            // arr[i - 1]);

            phanTichSo(n, i + 1);
        }
        arr[i] = n - t[i - 1];
        inKq(i);

    }

    public static void main(String[] args) {
        PhanTichSo p = new PhanTichSo();
        p.khoiTao();
        p.phanTichSo(6, 1);
    }
}

package QuayLui;

/**
 * LietKeNhiPhanN
 */
public class LietKeNhiPhanN {
    int[] arr = new int[100];

    void lietKeNhiPhanN(int i, int n) {
        for (int j = 0; j <= 1; j++) {
            arr[i] = j;
            if (i == n) {
                in(n);
            } else
                lietKeNhiPhanN(i + 1, n);
        }
    }

    void in(int n) {
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i]);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        LietKeNhiPhanN l = new LietKeNhiPhanN();
        l.lietKeNhiPhanN(0, 3);
    }
}
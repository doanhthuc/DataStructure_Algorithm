package SinhHoanVi;

public class LietKeTapConKpt {
    int[] arr = new int[100];

    // Liet ke ra cac tap con co k phan tu cua tap s co n phan tu
    void lietKeTapConKpt(int n, int k) {
        // Khoi tao cau hinh ban dau
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }
        int i;
        do {
            i = k - 1;
            in(k);
            while (i >= 0 && arr[i] == n - k + i + 1) {
                i -= 1;
            }
            if (i >= 0) {
                arr[i]++;
                for (int j = i + 1; j <= k; j++) {
                    arr[j] = arr[j - 1] + 1;
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
        LietKeTapConKpt l = new LietKeTapConKpt();
        l.lietKeTapConKpt(5, 3);
    }
}

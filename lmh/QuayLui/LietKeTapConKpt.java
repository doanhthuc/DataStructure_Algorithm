package QuayLui;

public class LietKeTapConKpt {

    int[] arr = new int[100];

    void lietKeTapConKpt(int i, int n, int k) {
        for (int j = arr[i - 1] + 1; j < n - k + i + 1; j++) {
            arr[i] = j;
            if (i == k)
                in(k);
            else
                lietKeTapConKpt(i + 1, n, k);
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
        LietKeTapConKpt l = new LietKeTapConKpt();
        l.lietKeTapConKpt(1, 5, 3);
    }
}

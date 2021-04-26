package QuyHoachDong;

public class DayConTangDaiNhat {
    int[] arr = new int[100];
    int[] L = new int[100];
    int[] T = new int[100];
    int n = 10;

    void optimize() {
        arr[0] = Integer.MIN_VALUE; // Gan phan tu bat dau la am vo cung
        arr[n + 1] = Integer.MAX_VALUE; // Gan phan tu ket thuc duong vo cung
        L[n + 1] = 1; // Dien co so cua quy hoach dong vao bang solution
        for (int i = n; i >= 0; i--) {
            int jMax = n + 1;
            for (int j = i + 1; j <= n + 1; j++) {
                if (arr[j] > arr[i] && L[j] > L[jMax]) {
                    jMax = j;
                }
                L[i] = L[jMax] + 1;
                T[i] = jMax;
            }
        }
    }

    void printResult() {
        int res = L[0] - 2;
        System.out.println("Chieu dai day con tang dai nhat: " + res);
        // Truy vet dai con tang dai nhat
        int i = T[0];
        while (i != n + 1) {
            System.out.print("arr[" + i + "] = " + arr[i] + "  ");
            i = T[i];
        }
    }

    public static void main(String[] args) {
        DayConTangDaiNhat d = new DayConTangDaiNhat();
        int[] a = { 5, 2, 3, 4, 9, 10, 5, 6, 7, 8 };
        d.arr[0] = Integer.MIN_VALUE;
        d.arr[d.n + 1] = Integer.MAX_VALUE;
        for (int i = 1; i <= 10; i++) {
            d.arr[i] = a[i - 1];
        }
        d.optimize();
        d.printResult();
    }

}

package SinhHoanVi;

public class LietKeHoanVi {
    int[] arr = new int[100];

    void lietKeHoanVi(int n) {
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }
        int i, k, temp, a, b;
        do {
            i = n - 1;
            in(n);
            while (i >= 0 && arr[i] > arr[i + 1])
                i -= 1;
            if (i >= 0) {
                k = n - 1;
                while (arr[k] < arr[i])
                    k--;
                temp = arr[i];
                arr[i] = arr[k];
                arr[k] = temp;

                // Lat nguoc doan cuoi giam dan a: dau doan, b: cuoi doan
                a = i + 1;
                b = n - 1;
                while (a < b) {
                    temp = arr[a];
                    arr[a] = arr[b];
                    arr[b] = temp;
                    a++;
                    b--;
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
        LietKeHoanVi l = new LietKeHoanVi();
        l.lietKeHoanVi(3);
    }
}

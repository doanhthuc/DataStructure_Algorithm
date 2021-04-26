package QuyHoachDong;

/**
 * CaiTienDayConTang
 */
public class CaiTienDayConTang {

    int[] arr = new int[100];
    int[] L = new int[100];
    int[] T = new int[100];
    int[] startOf = new int[100];
    int n = 10, max;

    CaiTienDayConTang() {
        arr[0] = Integer.MIN_VALUE;
        arr[n + 1] = Integer.MAX_VALUE;
        max = 1;
        L[n + 1] = 1;
        startOf[1] = n + 1;
    }

    int find(int i) {
        int inf = 1, sup = max + 1, median, j;
        while (inf + 1 < sup) {
            median = (inf + sup) / 2;
            j = startOf[median];
            if (arr[j] > arr[i])
                inf = median;
            else
                sup = median;
        }
        return startOf[inf];
    }

    void optimize() {
        int j, k;
        for (int i = n; i >= 0; i--) {
            j = find(i);
            k = L[j] + 1;
            if (k > max) {
                max = k;
                startOf[k] = i;
            } else {
                if (arr[startOf[k]] < arr[i]) {
                    startOf[k] = i;
                }
                L[i] = k;
                T[i] = j;
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

    // From leetcode
    public int lengthOfLIS(int[] nums) {
        int[] tails = new int[nums.length];
        int size = 0;
        for (int x : nums) {
            int i = 0, j = size;
            while (i != j) {
                int m = (i + j) / 2;
                if (tails[m] < x)
                    i = m + 1;
                else
                    j = m;
            }
            tails[i] = x;
            if (i == size)
                ++size;
        }
        return size;
    }

    public static void main(String[] args) {
        CaiTienDayConTang d = new CaiTienDayConTang();
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
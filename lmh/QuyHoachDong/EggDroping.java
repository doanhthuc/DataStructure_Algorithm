package QuyHoachDong;

public class EggDroping {
    static int eggDrop(int n, int k) {
        int[][] table = new int[n + 1][k + 1];

        /*
         * Khoi tao truong hop - co i qua trung nhung dang o tang 1 thi chi can drop 1
         * lan - co i qua trung nhung dan o tang 0 nen khong can tha
         */
        for (int i = 0; i <= n; i++) {
            table[i][1] = 1;
            table[i][0] = 0;
        }
        // - co 1 qua trung thi can tha i lan tu duoi len tren
        for (int i = 0; i <= k; i++) {
            table[1][i] = i;
        }

        /*
         * Quy hoach dong Khi tha qua trung tu 1 tang thi co 2 truong hop - Qua trung
         * roi tu tang x xuong thi bi vo thi se con n-1 trung va se tha tu tang x-1 -
         * Qua trung roi tu tang x xuong k vo thi se van con n trung va se tha tu tang x
         * tro len tuc la con lai k-x tang Sau do tim cai nao max lan tha cua 2 truong
         * hop tren, lay cai lon hon vi de cho chac dam bao dau ra chinh xac nhat
         */
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= k; j++) {
                table[i][j] = Integer.MAX_VALUE;
                for (int x = 1; x <= j; x++) {
                    table[i][j] = Math.min(table[i][j], 1 + Math.max(table[i - 1][x - 1], table[i][j - x]));
                }
            }
        }
        return table[n][k];
    }

    public static void main(String[] args) {

        int n = 2, k = 10;
        System.out.println("Minimum number of trials in worst" + " case with " + n + "  eggs and " + k + " floors is "
                + eggDrop(n, k));

    }
}

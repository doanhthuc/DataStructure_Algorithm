package QuyHoachDong;

public class CoinChangeWay {
    public static int countWays(int[] coins, int m, int n) {
        int[] table = new int[n + 1];
        table[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = coins[i]; j <= n; j++) {
                table[j] += table[j - coins[i]];
            }
        }
        return table[n];
    }

    public static void main(String args[]) {
        int arr[] = { 1, 2, 3 };
        int m = arr.length;
        int n = 4;
        System.out.println(countWays(arr, m, n));
    }
}

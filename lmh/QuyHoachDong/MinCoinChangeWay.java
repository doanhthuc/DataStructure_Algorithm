package QuyHoachDong;

public class MinCoinChangeWay {
    static int minCoins(int[] coins, int v) {
        // Tạo bảng lưu trữ kêt quả
        int[] table = new int[v + 1];
        // Tạo trường hợp cơ sở
        table[0] = 0;
        // Khởi tạo các giá trị cho bảng kêt quả
        for (int i = 1; i <= v; i++) {
            table[i] = Integer.MAX_VALUE;
        }

        for (int i = 1; i <= v; i++) {
            for (int j = 0; j < coins.length; j++) {
                if (coins[j] <= i) {
                    table[i] = Math.min(table[i], table[i - coins[j]] + 1);
                }
            }
        }
        return table[v] == Integer.MAX_VALUE ? -1 : table[v];
    }

    public static void main(String[] args) {
        int coins[] = { 9, 6, 5, 1 };
        int V = 11;
        System.out.println("Minimum coins required is " + minCoins(coins, V));
    }
}

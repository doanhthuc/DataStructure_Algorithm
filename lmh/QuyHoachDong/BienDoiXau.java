package QuyHoachDong;

/**
 * BienDoiXau
 */
public class BienDoiXau {
    char[] arr1 = new char[200];
    char[] arr2 = new char[200];
    int[][] f = new int[100][100];
    int n, m; // n là độ dài của xâu 2 (xâu mẫu), m là length của string 2 (xâu bị biến đổi)

    void optimize() {
        // Lưu cơ cở quy hoạch động
        for (int i = 0; i <= n; i++) {
            f[0][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            f[i][0] = i;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (arr1[i] == arr2[j])
                    f[i][j] = f[i - 1][j - 1];
                else
                    f[i][j] = Math.min(Math.min(f[i][j - 1] + 1, f[i - 1][j - 1] + 1), f[i - 1][j] + 1);
            }
        }
    }

    void tracer() {
        int i = m;
        int j = n;
        while (i > 0 || j > 0) {
            if (arr1[i] == arr2[j]) {
                i--;
                j--; // Chỉ việc truy chéo lên trên bảng phương án
            } else {

            }

        }
    }
}

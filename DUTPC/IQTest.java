import java.util.Scanner;

/**
 * IQTest
 */
public class IQTest {

    static boolean solved(int[][] arr) {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1];
                if (sum >= 3) {
                    return true;
                }
                if (sum < 2) {
                    return true;
                }
            }
        }
        return false;
    }

    // static void in(int[][] arr) {
    // for (int i = 0; i < 4; i++) {
    // for (int j = 0; j < 4; j++) {
    // System.out.print(arr[i][j]);
    // }
    // System.out.println();
    // }
    // }

    // static void inchuoi(String[] arr) {
    // for (int i = 0; i < arr.length; i++) {
    // System.out.println(arr[i]);
    // }
    // }

    public static void main(String[] args) {
        int[][] arr = new int[4][4];
        Scanner scanner = new Scanner(System.in);
        String[] str = new String[4];
        for (int i = 0; i < 4; i++) {
            str = scanner.nextLine().split("");
            // inchuoi(str);
            for (int j = 0; j < 4; j++) {
                if (str[j].equals("#"))
                    arr[i][j] = 1;
                else
                    arr[i][j] = 0;
            }
        }
        scanner.close();
        // in(arr);
        System.out.println();
        if (solved(arr))
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}
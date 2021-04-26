import java.util.Scanner;

public class BinarySearchApplication {

    public static int binarySearch(int[] arr, int n, int x){
        int left = 0, right = n - 1;

        while (left < right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] < x) left = mid + 1;
            else right = mid;
        }
        if (arr[left] == x) return left;
        return -1;
    }

    public static void printResultArr(int[] arr, int start, int end){
        for (int i = start; i <= end; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static boolean solve(int[] arr, int[] b, int n, int s){
        b[0] = arr[0];
        for (int i = 1; i < n; i++) {
            b[i] = b[i-1] + arr[i];
        }
        for (int i = 0; i < n; i++) {
            if (b[i] == s){
                printResultArr(arr, 0, i);
                return true;
            }
            if (b[i] > s){
                int pos = binarySearch(b, n, b[i] - s);
                if (pos != -1){
                    printResultArr(arr, pos+1, i);
                    return true;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        int s = scanner.nextInt();
        boolean k = solve(arr, b, n, s);
        if (k == false){
            System.out.println(-1);
        }
    }
}

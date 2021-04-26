package kadane_Algorithm;

public class Kadane_Algorithm {
    public int arrayMaxConsecutiveSum(int[] arr) {
        int max_sum = arr[0];
        int current_sum = max_sum;
        for (int i = 0; i < arr.length; i++) {
            current_sum = Math.max(current_sum + arr[i], arr[i]);
            max_sum = Math.max(current_sum, max_sum);
        }
        return max_sum;
    }

    public static void main(String[] args) {
        Kadane_Algorithm k = new Kadane_Algorithm();
        int[] arr = {-2, 2, 5, -11, 6};
        System.out.println(k.arrayMaxConsecutiveSum(arr));
    }
}
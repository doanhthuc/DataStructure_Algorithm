import java.util.Arrays;

public class Inversions {
    private static int mergeAndCount(int[]arr, int l, int m, int r) {
        int[] left = Arrays.copyOfRange(arr, l, m + 1);
        int[] right = Arrays.copyOfRange(arr, m+1, r + 1);

        int i = 0, j = 0, k = l, swaps = 0;

        while (i < left.length && j < right.length) {
            if (left[i] <= right[j])
                arr[k++] = left[i++];
            else {
                arr[k++] = right[j++];
                swaps += (m + 1) - (l + i);
            }
        }
        while(i < left.length) arr[k++] = left[i++];
        while(j < right.length) arr[k++] = right[j++];
        return swaps;
    }

    private static int mergeSortAndCount(int[] arr, int l, int r) {
        int count = 0;
        if (l < r) {
            int m = (l + r) / 2;
            //System.out.println(Arrays.toString(arr) + " De quy " + count);
            // left sub array count
            count += mergeSortAndCount(arr, l, m);
            //System.out.println(Arrays.toString(arr) + " De quy 1 " + count);
            // right sub array cont
            count += mergeSortAndCount(arr, m + 1, r);

            // Merge count
            count += mergeAndCount(arr, l, m, r);
        }
        return count;
    }

    public static void main(String[] args) {
        int[] arr = {1, 20, 6, 4, 5};
        int res = mergeSortAndCount(arr, 0, arr.length - 1);
        System.out.println("Number of inversions are: " + res);
        System.out.println("mang sau khi kt: " + Arrays.toString(arr));
    }
}

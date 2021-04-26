package sum_of_two;

import java.util.HashSet;

public class SumOfTwo {
    public boolean sumOfTwo(int[] a, int[] b, int v) {
        HashSet<Integer> needValues = new HashSet<>();
        for (int i = 0; i < a.length; i++) {
            int need = v - a[i];
            needValues.add(need);
        }

        for (int i = 0; i < b.length; i++) {
            if (needValues.contains(b[i])) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int[] a = {0 , 0, -5, 302};
        int[] b = {-10, 40, -3, 9};
        int v = -8;
        SumOfTwo s = new SumOfTwo();
        System.out.println(s.sumOfTwo(a, b, v));
    }
}

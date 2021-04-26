import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class QueueMobileScreen {
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>();
        boolean[] b = new boolean[100];
        int[] a = new int[100];
        int n, k;
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < 100; i++) {
            b[i] = false;
        }
        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        k = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            if (!b[a[i]]){
                if (queue.size() < k){
                    b[a[i]] = true;
                    queue.add(a[i]);
                }else {
                    b[queue.peek()] = false;
                    b[a[i]] = true;
                    queue.add(a[i]);
                    queue.poll();
                }
            }
        }
        while (!queue.isEmpty()){
            System.out.print(queue.peek() + " ");
            queue.poll();
        }
    }
}

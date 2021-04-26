import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class QueuExample {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            queue.add(scan.nextInt());
        }
        int k = scan.nextInt();
        while(k-- > 0){
            queue.add(queue.remove());
        }
        for (Integer i: queue) {
            System.out.print(i + " ");
        }
    }
}

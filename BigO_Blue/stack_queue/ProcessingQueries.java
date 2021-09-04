package stack_queue;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class ProcessingQueries {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int b = scanner.nextInt();
        int t, d;
        long processTime = 0;
        Queue<Long> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            t = scanner.nextInt();
            d = scanner.nextInt();

            while (!queue.isEmpty() &&  queue.peek() <= t) {
                queue.remove();
            }

            if (queue.size() <= b) {
                processTime = Math.max(processTime, t) + d;
                System.out.print(processTime + " ");
                queue.add(processTime);
            } else {
                System.out.print("-1 ");
            }
        }
        scanner.close();
    }
}

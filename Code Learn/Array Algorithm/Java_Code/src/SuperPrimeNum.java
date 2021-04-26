import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class SuperPrimeNum {
    public static boolean isPrime(int n){
        if (n < 2) return false;
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if(n % i == 0) return false;
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Queue<Integer> queue = new LinkedList<>();
        int n = scanner.nextInt();
        for (int i = 2; i <= n && i < 10; i++) {
            if (isPrime(i)) queue.add(i);
        }
        while (!queue.isEmpty()){
            for (int i = 1; i <= 9; i++) {
                int k = queue.peek()*10 + i;
                if(isPrime(k) && k <= n) queue.add(k);
            }
            System.out.print(queue.poll() + " ");
        }
    }
}

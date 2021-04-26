import java.util.Scanner;

public class copys {
    public static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        long m = sc.nextLong();
        long a = sc.nextLong();
        long b = sc.nextLong();

        if (a % m == 1 && b % m == 0) {
            System.out.println(1);
            return;
        } else if ((a - 1) / m == (b - 1) / m) {
            System.out.println(1);
            return;
        } else if (a % m == 1 || b % m == 0) {
            System.out.println(2);
            return;
        } else {
            System.out.println(3);
            return;
        }
    }
}

import java.util.Scanner;

/**
 * QuangCao
 */
public class QuangCao {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int ntests = Integer.parseInt(scanner.nextLine());
        while (ntests > 0) {
            int k = Integer.parseInt(scanner.nextLine());
            String s = scanner.nextLine();
            String a = scanner.nextLine();
            String b = scanner.nextLine();
            if (s.length() > a.length() + b.length() + k) {
                System.out.println("NO");
            } else if (s.startsWith(a) && s.endsWith(b)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
            ntests--;
        }
        scanner.close();
    }
}

/**
 * SoNgTo
 */
import java.math.BigInteger;
import java.util.Scanner;

public class SoNgTo {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        BigInteger n = new BigInteger(scanner.nextLine());
        scanner.close();
        System.out.println(n.isProbablePrime(1) ? "YES" : "NO");
    }

}
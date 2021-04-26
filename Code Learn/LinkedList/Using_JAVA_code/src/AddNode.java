import java.util.LinkedList;
import java.util.Scanner;

public class AddNode {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        LinkedList<Integer> linkedList = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            linkedList.add(scanner.nextInt());
        }
        int k = scanner.nextInt();
        int x = scanner.nextInt();
        linkedList.add(k, x);
        for (Integer i: linkedList) {
            System.out.print(i + " ");
        }
    }
}

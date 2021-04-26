import java.util.LinkedList;
import java.util.Scanner;

public class DeleteSpecificElement {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        LinkedList<Integer> linkedList = new LinkedList<>();
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            linkedList.add(scanner.nextInt());
        }
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            if (linkedList.get(i) == a) linkedList.set(i, b);
        }
        for (Integer i: linkedList) {
            System.out.print(i + " ");
        }
    }
}

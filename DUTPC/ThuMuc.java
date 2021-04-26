import java.util.Scanner;

public class ThuMuc {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String path = scanner.nextLine();
        int i = 0, j = i + 1;
        scanner.close();
        while (i != path.length()) {
            while (path.charAt(i) != '/' && path.charAt(j) != '/') {
                i++;
                j++;
            }

            while (path.charAt(j) == '/') {
                j++;
            }
            path = path.substring(0, 1);
        }
    }
}

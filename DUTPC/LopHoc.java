import java.util.Scanner;

public class LopHoc {
    public static void main(String[] args) {
        Set<String> setMonHoc = new Set<String, String>();
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String s = "";
        String mon = "";
        for (int i = 0; i < n; i++) {
            s = scanner.nextLine();
            mon = s.substring(lastIndexOf(" "));
            setMonHoc.put(mon);

        }
    }
}

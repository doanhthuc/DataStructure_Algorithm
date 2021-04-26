import java.util.Scanner;

public class Folders {

    public static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        String s = sc.nextLine().trim();
        s = s.replaceAll("[^a-z/]", "");
        s = s.replaceAll("//", "/");
        while (s.indexOf("//") >= 0) {
            s = s.replaceAll("//", "/");
        }

        if (s.charAt(0) != '/')
            s = '/' + s;
        if (s.charAt(s.length() - 1) == '/')
            s = s.substring(0, s.length() - 1);

        System.out.println(s);
    }
}
// //usr///local//////////nginx/sbin//

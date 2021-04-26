import java.util.Scanner;

class Chuoi {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int i = 0;

        while (s.charAt(i) == '_') {
            i++;
        }
        s = s.substring(i);

        i = s.length() - 1;
        while (s.charAt(i) == '_') {
            i--;
        }
        s = s.substring(0, i + 1);
        s = s.toLowerCase();
        i = 0;
        int j = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i-1) == '_' && s.charAt(i) == '_') {
                s = s.substring()
            }
        }
        System.out.println(s);
    }
}
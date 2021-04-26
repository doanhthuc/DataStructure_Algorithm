import java.util.Scanner;

public class doiSo {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        // System.out.print("Enter a decimal number : ");
        int num = input.nextInt();

        // calling method toHexString()
        String str = Integer.toHexString(num);
        str = str.toUpperCase();

        int extraZeros = 4 - (str.length() % 4);
        if (extraZeros < 4) {
            for (int j = 0; j < extraZeros; j++) {
                str = "0" + str;
            }
        }

        for (int i = 4; i <= str.length(); i += 4) {
            str = str.substring(0, i) + " " + str.substring(i);
            i++;
        }
        System.out.println(str);
    }
}

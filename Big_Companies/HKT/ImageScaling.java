import java.util.Scanner;

/**
 * ImageScaling
 */

public class ImageScaling {

    public static int[] sol(int[] pic, int w1, int h1, int w2, int h2) {

        int[] res = new int[h2 * w2];
        // EDIT: added +1 to account for an early rounding problem
        int x_ratio = (int) ((w1 << 16) / w2) + 1;
        int y_ratio = (int) ((h1 << 16) / h2) + 1;
        int x2, y2;
        for (int i = 0; i < h2; i++) {
            for (int j = 0; j < w2; j++) {
                x2 = ((j * x_ratio) >> 16);
                y2 = ((i * y_ratio) >> 16);
                res[(i * w2) + j] = pic[(y2 * w1) + x2];
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int h1, w1, h2, w2;
        Scanner scanner = new Scanner(System.in);
        h1 = scanner.nextInt();
        w1 = scanner.nextInt();
        h2 = scanner.nextInt();
        w2 = scanner.nextInt();
        int[] pic = new int[h1 * w1];
        for (int i = 0; i < h1 * w1; i++) {
            pic[i] = scanner.nextInt();
        }

        int[] res = new int[h2 * w2];
        res = sol(pic, w1, h1, w2, h2);
        int a = 0;
        for (int i = 0; i < h2; i++) {
            for (int j = 0; j < w2; j++) {
                System.out.printf("%d", res[a++]);
            }
            System.out.println();
        }
    }

}
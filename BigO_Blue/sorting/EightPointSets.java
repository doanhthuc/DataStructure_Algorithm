package sorting;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class EightPointSets {
    static final int MAX = (int) (1e6 + 5);
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Point> points = new ArrayList<>();
        ArrayList<Integer> unique_x = new ArrayList<>(), unique_y = new ArrayList<>();
        boolean[] freq_x = new boolean[MAX], freq_y = new boolean[MAX];

        for (int i = 0; i < 8; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            points.add(new Point(x, y));

            if (!freq_x[x]) {
                freq_x[x] = true;
                unique_x.add(x);
            }

            if (!freq_y[y]) {
                freq_y[y] = true;
                unique_y.add(y);
            }
        }
        scanner.close();
        if (unique_x.size() != 3 || unique_y.size() != 3) {
            System.out.print("ugly");
            return;
        }

        Collections.sort(unique_x);
        Collections.sort(unique_y);
        Collections.sort(points);
        int index = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j && i == 1) {
                    continue;
                }
                int x = points.get(index).x;
                int y = points.get(index).y;
                if (unique_x.get(i) == x && unique_y.get(j) == y) {
                    index++;
                } else {
                    System.out.println("ugly");
                    return;
                }
            }
        }
        System.out.print("respectable");
    }
}

class Point implements Comparable<Point> {
    Integer x, y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(Point point) {
        if (x.equals(point.x)) {
            return y.compareTo(point.y);
        }
        return x.compareTo(point.x);
    }
}

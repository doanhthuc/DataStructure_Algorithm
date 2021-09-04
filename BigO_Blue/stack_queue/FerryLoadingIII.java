package stack_queue;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Car {
    final int id;
    final int arriveTime;

    public Car(int id, int arriveTime) {
        this.id = id;
        this.arriveTime = arriveTime;
    }
}

public class FerryLoadingIII {
    static final int MAX = 10000 + 5;

    public static void main(String[] args) {
        int res[] = new int[MAX];
        Scanner scanner = new Scanner(System.in);
        int nTest = scanner.nextInt();

        while (nTest-- > 0) {
            Queue<Car>[] qSide = new Queue[2];
            qSide[0] = new LinkedList<>();
            qSide[1] = new LinkedList<>();
            
            int n = scanner.nextInt();
            int t = scanner.nextInt();
            int m = scanner.nextInt();

            for (int i = 1; i <= m; i++) {
                int arriveTime = scanner.nextInt();
                String bank = scanner.next();
                if (bank.equals("left")) {
                    qSide[0].add(new Car(i, arriveTime));
                } else {
                    qSide[1].add(new Car(i, arriveTime));
                }
            }

            int curSide = 0, curTime = 0, nextTime;
            int waiting = (!qSide[0].isEmpty() ? 1 : 0) + (!qSide[1].isEmpty() ? 1 : 0);

            while (waiting > 0) {
                if (waiting == 1) {
                    nextTime = (qSide[0].isEmpty() ? qSide[1].peek().arriveTime : qSide[0].peek().arriveTime);
                } else {
                    nextTime = Math.min(qSide[0].peek().arriveTime, qSide[1].peek().arriveTime);
                }
                curTime = Math.max(curTime, nextTime);
                int carried = 0;

                while (!qSide[curSide].isEmpty() 
                    && qSide[curSide].peek().arriveTime <= curTime 
                    && carried < n) {
                        res[qSide[curSide].poll().id] = curTime + t; 
                        carried++;
                    }
                
                curTime += t;
                curSide = 1 - curSide;
                waiting = (!qSide[0].isEmpty() ? 1 : 0) + (!qSide[1].isEmpty() ? 1 : 0);
            }
            
            for (int i = 1; i <= m; i++) {
                System.out.println(res[i]);
            }

            if (nTest > 0) {
                System.out.println();
            }
        }
        scanner.close();
    }
}

package heap;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class RoyAndTrendingTopics {
    static class Topic {
        Long id;
        Long oldScore;
        Long newScore;
        Long change;

        Topic(Long id, Long oldScore, Long newScore) {
            this.id = id;
            this.oldScore = oldScore;
            this.newScore = newScore;
            this.change = newScore - oldScore;
        }

        public Long getId() {return id;}
        public Long getChange() {return change;}
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = 0;
        n = scanner.nextInt();
        PriorityQueue<Topic> pq = 
                                new PriorityQueue<>(Comparator
                                                        .comparingLong(Topic::getChange)
                                                        .thenComparing(Topic::getId).reversed());
        long id, score, post, like, cmt, share, newScore;
        for (int i = 0; i < n; i++) {
            id = scanner.nextLong();
            score = scanner.nextLong();
            post = scanner.nextLong();
            like = scanner.nextLong();
            cmt = scanner.nextLong();
            share = scanner.nextLong();
            newScore = post * 50 + like * 5 + cmt * 10 + share * 20; 
            pq.add(new Topic(id, score, newScore));
        }

        scanner.close();
        Topic t;
        for (int i = 0; i < 5; i++) {
            t = pq.poll();
            System.out.println(t.getId() + " " + t.newScore);
        }
    }
}

import java.util.ArrayList;
import java.util.LinkedList;

public class ShortestPath {
    static void addEdge(ArrayList<ArrayList<Integer>> adj, int i, int j) {
        adj.get(i).add(j);
        adj.get(j).add(i);
    }

    static void printShortestDistance(ArrayList<ArrayList<Integer>> adj, int s, int dest, int v) {
        int[] pred = new int[v];
        int[] dist = new int[v];

        if (!BFS(adj, s, dest, v, pred, dist)) {
            System.out.println("Given source and destination are not connected");
            return;
        }

        // LinkedList to store path
        LinkedList<Integer> path = new LinkedList<>();
        int crawl = dest;
        path.add(crawl);
        while (pred[crawl] != -1) {
            path.add(pred[crawl]);
            crawl = pred[crawl];
        }

        // print distance
        System.out.println("Shortest path length is: " + dist[dest]);

        // print path
        System.out.println("Path is:");
        for (int i = path.size() - 1; i >= 0; i--) {
            System.out.print(path.get(i) + " ");
        }
    }

    // A modified version of BFS that stores predecessor
    // of each vertex in array pred and its distance from source in array dist
    static boolean BFS(ArrayList<ArrayList<Integer>> adj, int src, int dest, int v, int[] pred, int[] dist) {

        LinkedList<Integer> queue = new LinkedList<>();

        boolean[] visited = new boolean[v];

        for (int i = 0; i < v; i++) {
            visited[i] = false;
            dist[i] = Integer.MAX_VALUE;
            pred[i] = -1;
        }

        // now source is first to be visited and
        //distance from source to itself should be 0
        visited[src] = true;
        dist[src] = 0;
        queue.add(src);

        //bfs algorithm
        while (!queue.isEmpty()) {
            int u = queue.poll();
            for (int i = 0; i < adj.get(u).size(); i++) {
                if (!visited[adj.get(u).get(i)]) {
                    visited[adj.get(u).get(i)] = true;
                    dist[adj.get(u).get(i)] = dist[u] + 1;
                    pred[adj.get(u).get(i)] = u;
                    queue.add(adj.get(u).get(i));

                    // Stopping condition (When we find our destination)
                    if (adj.get(u).get(i) == dest) return true;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        // Number of vertices
        int v = 8;

        // Adjacency list for storing which vertices are connected
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>(v);
        for (int i = 0; i < v; i++) {
            adj.add(new ArrayList<>());
        }
        addEdge(adj, 0, 1);
        addEdge(adj, 0, 3);
        addEdge(adj, 1, 2);
        addEdge(adj, 3, 4);
        addEdge(adj, 3, 7);
        addEdge(adj, 4, 5);
        addEdge(adj, 4, 6);
        addEdge(adj, 4, 7);
        addEdge(adj, 5, 6);
        addEdge(adj, 6, 7);
        int source = 0, dest = 7;
        printShortestDistance(adj, source, dest, v);
    }
}

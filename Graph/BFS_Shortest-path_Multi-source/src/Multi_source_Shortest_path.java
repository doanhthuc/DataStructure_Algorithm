import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;

class Pair
{
    int first, second;

    public Pair(int first, int second)
    {
        this.first = first;
        this.second = second;
    }
}

public class Multi_source_Shortest_path {
    static final int N = 100000 + 1;
    static final int inf = Integer.MAX_VALUE;
    // This array stores the distance of the
    // vertices from the nearest source
    static int[] dist = new int[N];

    // a hash array where source[i] = i
    // means vertex is a source
    static int[] source = new int[N];

    // The BFS Queue of
    // The pairs are of the form (vertex, distance from current source)
    static Deque<Pair> BFSQueue = new LinkedList<>();
    // dequeue<Pair<int, int>> BFSQueue;

    // Visited array for remember visited vertices
    static int[] visited = new int[N];

    // The BFS function
    static void BFS(ArrayList<Integer>[] graph, int start) {

        // clearing the queue
        while (!BFSQueue.isEmpty()) BFSQueue.removeLast();

        // Push_back starting vertices
        BFSQueue.add(new Pair(start, 0));

        while (!BFSQueue.isEmpty()){
            int s = BFSQueue.peekFirst().first;
            int d = BFSQueue.peekFirst().second;
            visited[s] = 1;
            BFSQueue.removeFirst();

            // Stop at the first source
            // we reach during BFS
            if (source[s] == 1) {
                dist[start] = d;
                return;
            }

            // Pushing the adjacent unvisited vertices
            // with distance from current source = this vertex's distance + 1
            for (int i = 0; i < graph[s].size(); i++) {
                if (visited[graph[s].get(i)] == 0) {
                    BFSQueue.add(new Pair(graph[s].get(i), d + 1));
                }
            }
        }
    }

    // This function calculates the distance of each vertex
    // from nearest source
    static void nearestTown(ArrayList<Integer>[] graph, int n, int[] sources, int s) {

        // Resetting the source hash array
        for (int i = 1; i <= n; i++) {
            source[i] = 0;
        }
        for (int i = 0; i <= s - 1; i++) {
            source[sources[i]] = 1;
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                visited[j] = 0;
            }
            BFS(graph, i);
        }

        // Printing the distances
        for (int i = 1; i <= n; i++) {
            System.out.println(i + " " + dist[i]);
        }
    }

    static void addEdge(ArrayList<Integer>[] graph, int u, int v) {
        graph[u].add(v);
        graph[v].add(u);
    }

    public static void main(String[] args) {
        // Number of vertices
        int n = 6;
        ArrayList<Integer>[] graph = new ArrayList[n+1];
        Arrays.fill(graph, new ArrayList<>());

        // Edges
        addEdge(graph, 1, 2);
        addEdge(graph, 1, 6);
        addEdge(graph, 2, 6);
        addEdge(graph, 2, 3);
        addEdge(graph, 3, 6);
        addEdge(graph, 5, 4);
        addEdge(graph, 6, 5);
        addEdge(graph, 3, 4);
        addEdge(graph, 5, 3);

        // Sources
        int[] sources = { 1, 5 };

        int S = sources.length;

        nearestTown(graph, n, sources, S);
    }

}



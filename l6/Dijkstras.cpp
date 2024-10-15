#include <iostream>
#include <vector>
#include <queue>
#include <climits> // For INT_MAX

using namespace std;

class Edge {
public:
    int v;
    int wt;

    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};

void dijkstra(int src, vector<vector<Edge> > &graph, int V) {
    // Min-heap priority queue (distance, vertex)
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    vector<int> dist(V, INT_MAX); // Distance from source to each vertex
    dist[src] = 0;
    pq.push(make_pair(0, src)); // Push starting vertex with distance 0

    while (!pq.empty()) {
        int u = pq.top().second; // Get the vertex with the smallest distance
        pq.pop();

        // Explore neighbors of u
        for (Edge e : graph[u]) {
            int v = e.v;
            int weight = e.wt;

            // Relaxation step
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // Print shortest distances from the source vertex
    cout << "Vertex   Distance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << dist[i] << endl;
    }
}

int main() {
    int V = 6; // Number of vertices
    vector<vector<Edge> > graph(V);

    // Add edges to the graph (directed graph)
    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, 1));
    graph[1].push_back(Edge(3, 7));

    graph[2].push_back(Edge(4, 3));

    graph[3].push_back(Edge(5, 1));

    graph[4].push_back(Edge(3, 2));
    graph[4].push_back(Edge(2, 5));

    // Run Dijkstra's algorithm from vertex 0
    dijkstra(0, graph, V);

    return 0;
}

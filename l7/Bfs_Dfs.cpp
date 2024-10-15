#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V; 
    list<int> *l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v){ // u -> v (directed graph)
        l[u].push_back(v);
    }

    void bfs(int start){
        vector<bool> vis(V, false);
        queue<int> q;
        
        q.push(start);
        vis[start] = true;

        while(!q.empty()){
            int u = q.front(); // current vertex
            q.pop();
            cout << u << " ";

            for(int v : l[u]){ // visiting all neighbours of the current vertex
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    void dfsHelper(int u, vector<bool>& vis){
        vis[u] = true;
        cout << u << " ";
        for(int v : l[u]){
            if(!vis[v]){
                dfsHelper(v, vis);
            }
        }
    }

    void dfs(int start){
        vector<bool> vis(V, false);
        dfsHelper(start, vis);
        cout << endl;
    }
};

int main(){
    Graph graph(10);

    graph.addEdge(1, 6);
    graph.addEdge(6, 4);
    graph.addEdge(4, 3);
    graph.addEdge(4, 9);
    graph.addEdge(3, 8);
    graph.addEdge(3, 7);
    graph.addEdge(0, 2);
    graph.addEdge(2, 5);

    int startNode;
    cout << "Enter the starting node for BFS and DFS: ";
    cin >> startNode;

    cout << "BFS from node " << startNode << ": ";
    graph.bfs(startNode);

    cout << "DFS from node " << startNode << ": ";
    graph.dfs(startNode);

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long int ll;

int primMST(int V,vector<vector<int> > adj[]){
    // Implementation of Prim's algorithm goes here
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<int> vis(V,0);
    //{weight,node}

    pq.push({0,0});
    int sum=0;
    //E
    while(!pq.empty()){
        //logE
        auto it = pq.top();
        pq.pop();
        int node=it.second;
        int wt=it.first;
        if(vis[node] == 1) continue;

        vis[node] =1;

        sum+=wt;
        //E logE
        for(auto it : adj[node]){
            int adjNode=it[0];
            int edW=it[1];
            if(!vis[adjNode]){
                pq.push({edW,adjNode});
            }
        } 
    }
    return sum;
    
}

int main()
{
    int V = 5;
	vector<vector<int> > edges;
    for(int i =0;i<V;i++){
        vector<int> temp(3);
        for(int i=0;i<3;i++){
            cin>>temp[0]>>temp[1]>>temp[2];
        }
        edges.push_back(temp);
    }
	vector<vector<int> > adj[V];
	for (auto it : edges) {
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}

	
	int sum = primMST(V, adj);
	cout << "The sum of all the edge weights: " << sum << endl;

    // Call the primMST function
    return 0;
}

// TC-->O(ELOG(E)+ELOG(E))
// SC-->O(E) for the priority queue

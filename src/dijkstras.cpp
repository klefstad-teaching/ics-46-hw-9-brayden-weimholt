#include "dijkstras.h"


vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    int n = G.numVertices;
    vector<int> distances(n, INF);
    previous.assign(n, -1);
    vector<bool> visited(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    if(source < n) distances[source] = 0;
    else source = 0;

    while(!pq.empty()){
        int u = pq.top().second;

        if(visited[u]) continue;
        else visited[u] = true;

        int dist_u = pq.top().first;
        pq.pop();

        for(const Edge& e : G[u]){
            int v = e.dst;
            int wgt = e.weight;
            if(!visited[v] && distances[u] + wgt < distances[v]){
                distances[v] = distances[u] + wgt;
                previous[v] = u;
                pq.push({distances[v], v});
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination);

void print_path(const vector<int>& path, int total) {
    for (size_t i = 0; i < path.size(); ++i) {
        if (i > 0)
            cout << " ";
        cout << path[i];
    }
    cout << endl;
    cout << "Total cost is " << total << endl;
}


 //.assign() needed, not resize()




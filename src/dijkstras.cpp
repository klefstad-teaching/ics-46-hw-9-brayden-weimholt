#include "dijkstras.h"


vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous);

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




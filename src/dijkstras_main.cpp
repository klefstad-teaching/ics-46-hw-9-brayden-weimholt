#include "dijkstras.h"

int main(int argc, char* argv[]){
    Graph G;
    string file;
    if(argc >= 1) file = argv[0];
    else file = "small.txt";
    file_to_graph(file, G);

    int source = 0;
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, source, previous);
    for(int i = 0; i < G.numVertices; ++i){
        vector<int> path = extract_shortest_path(distances, previous, i);
        print_path(path, distances[i]);
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Edge {
    public:
        int source, sink, capacity;
        Edge *redge;
        Edge(int x, int y, int z) : source(x), sink(y), capacity(z) {}
        bool operator==(const Edge& edge) const {
            return this->source == edge.source && this->sink == edge.sink;
        }
        bool operator<(const Edge& edge) const {
            return this->source < edge.source;
        }
};

class FlowNetwork {
    private:
        map<int, vector<Edge>> edges;
        map<Edge, int> flow;
        bool has_edge(vector<Edge> path, Edge edge) {
            for (Edge cur_edge : path) {
                if (cur_edge == edge) return true;
            }
            return false;
        }
    public:
        void add_vertex(int vertex) {
            edges.insert(make_pair(vertex, vector<Edge>()));
        }

        vector<Edge> get_edges(int vertex) {
            return edges.find(vertex)->second;
        }

        void add_edges(int source, int sink, int capacity) throw (string){
            if (source == sink) throw "source equals sink";
            Edge edge = {source, sink, capacity};
            Edge redge = {sink, source, 0};
            edge.redge = &redge;
            redge.redge = &edge;
            if (edges.find(source) != edges.end()) {
                edges.find(source)->second.push_back(edge);
            } else {
                edges.insert(make_pair(source, vector<Edge> {edge}));
            }
            if (edges.find(sink) != edges.end()) {
                edges.find(sink)->second.push_back(redge);
            } else {
                edges.insert(make_pair(sink, vector<Edge> {redge}));
            }
            flow.find(edge)->second = 0;
            flow.find(redge)->second = 0;
        }

        vector<Edge> find_path(int source, int sink, vector<Edge> path) {
            if (source == sink) return path;
            for (Edge edge : get_edges(source)) {
                int residual = edge.capacity - flow.find(edge)->second;
                if (residual > 0 && !has_edge(path, edge)) {
                    path.push_back(edge);
                    vector<Edge> result = find_path(edge.sink, sink, path); 
                    if (!result.empty()) return result;
                    path.pop_back();
                }
            }
            return vector<Edge>{};
        }

        int max_flow(int source, int sink) {
            int a = 0, min_flow = 0;
            vector<Edge> path = find_path(source, sink, vector<Edge> {});

            while (!path.empty()) {
                for (Edge edge : path) {
                    if (min_flow > edge.capacity - flow.find(edge)->second) min_flow = flow.find(edge)->second;
                }
                for (Edge edge : path) {
                    flow.find(edge)->second += min_flow;
                    flow.find(*edge.redge)->second -= min_flow;
                }
                path = find_path(source, sink, vector<Edge> {});
            }

            for (Edge edge: get_edges(source)) {
                a += flow.find(edge)->second;
            }

            return a;
        }
};

int main() {
    FlowNetwork fn;
    for (int n = 0; n < 6; ++n) {
        fn.add_vertex(n);
    }
    fn.add_edges(0, 1, 3);
    fn.add_edges(0, 2, 3);
    fn.add_edges(1, 2, 2);
    fn.add_edges(1, 3, 3);
    fn.add_edges(3, 4, 4);
    fn.add_edges(3, 5, 2);
    cout<<fn.max_flow(0, 5)<<endl;
    return 0;
}

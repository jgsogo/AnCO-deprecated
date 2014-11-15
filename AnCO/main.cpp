#include <iostream>
#include <fstream>
#include <sstream>

#include "graph.h"
#include "nest.h"

using namespace std;

int main()
{
    cout << "==========" << endl;
    cout << "AnCO::Demo" << endl;
    cout << "==========" << endl << endl;

    // 1) Load graph
    std::string graph_file = "data/Slashdot0902.txt";
    anco::graph graph;
    auto get_or_create_node = [&graph](int id_node) -> anco::node& {
        try {
            return graph.get_node(id_node);
            }
        catch(anco::graph::not_found& e) {
            }
        };

    cout << "Graph: " << graph_file << endl;
    ifstream infile(graph_file);
    std::string line;
    int n1, n2, counter = 0;
    while(std::getline(infile, line)) {
        std::istringstream ss(line);
        if (ss >> n1 >> n2) {
            graph.create(n1);
            graph.create(n2);
            anco::node& node1 = graph.get_node(n1);
            anco::node& node2 = graph.get_node(n2);
            graph.connect(node1.get_id(), node2.get_id());
            if (counter++ % 10000 == 0) {
                cout << counter << " edges so far" << endl;
                }
            }
        }
    cout << "\t - nodes: " << graph.get_nodes().size() << endl;
    cout << "\t - edges: " << graph.get_edges().size() << endl;

    // 2) Create nests
    anco::Nest nest(graph);
    nest.configure();
    while(true) {
        nest.run();
        }

    // 3) Learn
    // 4) Do search
    // 5) Print stats
    return 0;
}

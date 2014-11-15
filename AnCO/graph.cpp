
#include "graph.h"

namespace anco {

    // Nodos
    node::node(const id& id_): _id(id_) {}

    node::~node() {

        }

    // Aristas - arcos
    edge::edge(node& source, node& target) : _source(source), _target(target) {
        _source._outgoing.push_back(this);
        _target._incoming.push_back(this);
        }

    edge::~edge() {

        }

    // El grafo
    graph::graph() {
        _next_id = 0;
        }

    graph::~graph() {
        }

    void graph::create(const node::id& id) {
        if (_nodes.find(id) != _nodes.end()) {return;}
        else {
            node* n = new node(id);
            _nodes.insert(std::make_pair(n->get_id(), n));
            }
        }

    void graph::connect(const node::id& source, const node::id& target) {
        edge* e = new edge(this->get_node(source), this->get_node(target));
        _edges.push_back(e);
        }

    node& graph::get_node(const node::id& id) {
        t_node_map::iterator it = _nodes.find(id);
        if (it != _nodes.end()) {
            return *it->second;
            }
        else {
            throw(graph::not_found());
            }
        }
    }

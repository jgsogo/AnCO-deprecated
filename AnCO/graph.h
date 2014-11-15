
#include <vector>
#include <map>

namespace anco {

    class edge;

    class node {
        friend class edge;
        public:
            typedef int id;
        public:
            node(const id&);
            ~node();
            const id& get_id() const { return _id;}
            const std::vector<edge*>& get_incoming() const { return _incoming;}
            const std::vector<edge*>& get_outgoing() const { return _outgoing;}
        protected:
            std::vector<edge*> _incoming;
            std::vector<edge*> _outgoing;
            id _id;
        };

    class edge {
        public:
            edge(node& source, node& target);
            ~edge();
        protected:
            node& _source;
            node& _target;
        };

    class graph {
        public:
            typedef std::exception not_found;
            typedef std::map<node::id, node*> t_node_map;
        public:
            graph();
            ~graph();

            void create(const node::id& id_created);
            void connect(const node::id& source, const node::id& target);

            node& get_node(const node::id&);
            const t_node_map& get_nodes() const { return _nodes;};
            const std::vector<edge*>& get_edges() const { return _edges;};
        protected:
            t_node_map _nodes;
            std::vector<edge*> _edges;
            node::id _next_id;
        };

    }


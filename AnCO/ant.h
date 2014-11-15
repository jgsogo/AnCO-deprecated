
#pragma once

#include "graph.h"

namespace anco {

    class Nest;

    class Ant {
        public:
            Ant(Nest&);
            ~Ant();

            void place(node& node, const bool& reset=true);
            void run(const int& n_steps=1);
            const std::vector<node*>& get_path() const { return _path;}
        protected:
            Nest& _nest;
            std::vector<node*> _path;
            int _target_node;
        };

    }


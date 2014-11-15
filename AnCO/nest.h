
#pragma once

#include "graph.h"
#include "ant.h"

namespace anco {

    class Nest {
        public:
            Nest(graph& graph);
            ~Nest();

            void configure();
            void run(const int& n_steps=1);

            void on_finished_ant(Ant& ant, const std::string& msg="");
        protected:
            std::vector<Ant*> _ants;
            graph& _graph;
        };

    }


#include <iostream>
#include <algorithm>
#include "nest.h"

namespace anco {

    Nest::Nest(graph& graph): _graph(graph) {
        }

    Nest::~Nest() {
        }

    void Nest::configure() {
        Ant* i0 = new Ant(*this);
        i0->place(_graph.get_node(0));
        _ants.push_back(i0);
        }

    void Nest::run(const int& n_steps) {
        std::for_each(_ants.begin(), _ants.end(), [&n_steps](Ant* item){item->run(n_steps);});
        }

    void Nest::on_finished_ant(Ant& ant, const std::string& msg) {
        const std::vector<node*>& path = ant.get_path();
        std::cout << "["<< path.size() << "] ";
        std::for_each(path.begin(), path.end(), [](node* n){
            std::cout << n->get_id() << " > ";
            });

        std::cout << std::endl;
        if ((*path.begin())->get_id() == (*path.rbegin())->get_id()) {
            std::cout << "Ant finished! =) " << msg << std::endl;
            }
        else {
            std::cout << "Ant failed  :( " << msg << std::endl;
            }

        std::cout << "Press ENTER to continue..." << std::endl;

        getchar();
        static int n_init = 0;
        ant.place(_graph.get_node(n_init++));
        }
    }

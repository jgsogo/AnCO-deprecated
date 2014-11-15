
#include <iostream>
#include <algorithm>
#include "ant.h"
#include "nest.h"

using namespace std;

namespace anco {

    Ant::Ant(Nest& nest) : _nest(nest) {
        }

    Ant::~Ant() {
        }

    void Ant::place(node& node_, const bool& reset) {
        if (reset) {
            _path.clear();
            _target_node = rand() % 3500;
            }
        _path.push_back(&node_);
        }

    void Ant::run(const int& n_steps) {
        for(int i = n_steps; i--; i>0) {
            node* ini = *_path.rbegin();
            const std::vector<edge*>& outgoing = (*_path.rbegin())->get_outgoing();
            if (outgoing.size() > 1) {
                int item = std::rand() % outgoing.size();
                edge* e = outgoing[item];
                node& next = e->get_target();
                _path.push_back(&next);
                if (next.get_id()==_target_node) {
                    _nest.on_finished_ant(*this, "lo encontré!!!!");
                    }
                else if (_path.size() >= 1000) {
                    _nest.on_finished_ant(*this, "me he cansado de buscar");
                    }
                }
            else {
                _nest.on_finished_ant(*this, "no puedo salir del nodo");
                }
            }
        if (_path.size() % 100 == 0) {
            std::cout << _path.size() << " nodes visited" << std::endl;
            }
        }

    }

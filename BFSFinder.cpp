//
// Created by Admin on 2022/8/10.
//

#include "BFSFinder.h"
#include <vector>
#include "iostream"
#include "cmath"
#include "algorithm"


void BFSFinder::tick() {
    if (ways.empty()) {
        return;
    }
    Node n = ways.back();
    map[n.x][n.y] = 1;
    ways.pop_back();
}

bool con(const std::vector<Node*>& c, const Node *element) {
    for(auto begin=c.begin();begin!=c.end();begin++) {
        if((**begin)==*element) {
            return true;
        }
    }
    return false;
}

bool con(const std::deque<Node*>& c, const Node *element) {
    for(auto begin=c.begin();begin!=c.end();begin++) {
        if((**begin)==*element) {
            return true;
        }
    }
    return false;
}




void remove(Node &a1,std::deque<Node*> open) {
    for(auto b=open.begin();b!=open.end();b++) {
        if((**b).g==a1.g&&(**b).x==a1.x&&(**b).y==a1.y) {
            open.erase(b);
        }
    }
}

BFSFinder::BFSFinder(Node node) : Finder(),goal(node) {
    Node* org=new Node(0,0);
    std::vector<Node*> close;
    std::deque<Node*> open;
    open.push_back(org);
    while (true) {
        std::sort(open.begin(),open.end(),[] (const Node *a1,const Node *a2) ->bool {return a1->g>a2->g;});
        if (open.empty()) {
            std::cerr << "can't find!";
            exit(1);
        }
        Node *n = open.back();
        open.pop_back();
        std::cout<<"("<<n->x<<","<<n->y<<") "<<n->g<<std::endl;
        close.push_back(n);
        for (auto &a: Helper::getNext(n,goal,map)) {
            std::cout<<"child ("<<a->x<<","<<a->y<<") "<<a->g<<std::endl;
            if ((!con(close, a)) && !(con(open, a))) {
                if (goal == *a) {
                    Helper::solution(*a,ways);
                    goto end;
                }
                open.push_front(a);
            } else if (con(open,a)) {
                auto node1 = std::find(open.begin(), open.end(),a);
                if(node1!=open.end()) {
                    if (((*node1)->g) > a->g) {
                        remove(*a,open);
                    }
                }
            }
        }
    }
    end:
    {
        std::cout.flush();
        for (auto &a: open) {
            delete a;
        }
        for (auto &a: close) {
            delete a;
        }
    }
}
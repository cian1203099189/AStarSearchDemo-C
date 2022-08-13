//
// Created by Admin on 2022/8/10.
//

#include "Node.h"

bool Node::equals(const Node &n) const {
    return (x==n.x)&&(y==n.y);
}

bool operator==(const Node &n,const Node &n1) {
    return n.equals(n1);
}
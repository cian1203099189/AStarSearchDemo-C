//
// Created by Admin on 2022/8/10.
//

#ifndef TEST_NODE_H
#define TEST_NODE_H


class Node {
public:
    Node *parents= nullptr;
    int x;
    int y;
    int g=0;
    bool equals(const Node &n) const;
    Node() = default;
    Node(int x,int y):x(x),y(y) {}
};

bool operator==(const Node &n,const Node &n1);
#endif //TEST_NODE_H

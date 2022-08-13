//
// Created by Admin on 13/08/2022.
//

#ifndef TEST_HELP_H
#define TEST_HELP_H
#include "Node.h"
#include "deque"
namespace Helper {
    bool isValid(const Node *n, int map[10][10]);
    void solution(Node a, std::deque<Node> &ways);
    std::deque<Node *> getNext(Node *n, const Node &goal, int map[10][10]);
}
#endif //TEST_HELP_H

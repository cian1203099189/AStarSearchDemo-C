//
// Created by Admin on 13/08/2022.
//
#include "Help.h"

bool Helper::isValid(const Node *n, int map[10][10]) {
    return (n->x < 10) && (n->x >= 0) && (n->y < 10) && (n->y >= 0) && (map[n->x][n->y] != 2);
}

void Helper:: solution(Node a, std::deque<Node> &ways) {
    int i = 0;
    while (true) {
        ways.push_back(a);
        i++;
        if (a.parents) {
            if (*a.parents == a) {
                break;
            }
            a = *a.parents;
        } else {
            break;
        }
    }
}

std::deque<Node *> Helper:: getNext(Node *n, const Node &goal, int map[10][10]) {
    std::deque<Node *> d;

    Node *up = new Node();
    up->parents = n;
    up->x = n->x;
    up->y = n->y - 1;
    up->g = (n->g + 1) + (std::abs(goal.x - up->x) + std::abs(goal.y - up->y));
    if (isValid(up, map)) {
        d.push_back(up);
    }
    Node *down = new Node();
    down->parents = n;
    down->x = n->x;
    down->y = n->y + 1;
    down->g = n->g + 1 + (std::abs(goal.x - down->x) + std::abs(goal.y - down->y));
    if (isValid(down, map)) {
        d.push_back(down);
    }

    Node *left = new Node();
    left->x = n->x - 1;
    left->y = n->y;
    left->parents = n;
    left->g = n->g + 1 + (std::abs(goal.x - left->x) + std::abs(goal.y - left->y));
    if (isValid(left, map)) {
        d.push_back(left);
    }
    Node *right = new Node();
    right->parents = n;
    right->x = n->x + 1;
    right->y = n->y;
    right->g = n->g + 1 + (std::abs(goal.x - right->x) + std::abs(goal.y - right->y));
    if (isValid(right, map)) {
        d.push_back(right);
    }

    return d;
}

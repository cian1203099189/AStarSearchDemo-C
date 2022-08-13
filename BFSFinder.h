//
// Created by Admin on 2022/8/10.
//

#ifndef TEST_BFSFINDER_H
#define TEST_BFSFINDER_H

#include "string"
#include "Finder.h"
#include "graphics.h"
class BFSFinder :public Finder{
public:
    Node goal;
    void tick() override;
    explicit BFSFinder(Node goal);
    std::deque<Node> ways;
};


#endif //TEST_BFSFINDER_H

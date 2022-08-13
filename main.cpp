#include <graphics.h>
#include "Finder.h"
#include "BFSFinder.h"
#include "Node.h"
#include "deque"

using namespace std;
void init();
void loop();
void clearUP();
void renderer();
Finder *f;

int main() {
    f=new BFSFinder(Node(8,3));
    init();
    loop();
    clearUP();
    return 0;
};


void init() {
    initgraph(500,500,0);
    renderer();
}

void clearUP() {
    closegraph();
    delete f;
}

void loop() {
    while(true) {
        Sleep(50);
        f->tick();
        renderer();
    }
}

void renderer() {
    for(int x =0;x<10;x++) {
        for(int y = 0;y<10;y++) {
            LPSTR lp("¨¨¨\n¨¨¨\n¨¨¨");
            switch (f->map[x][y]) {
                case 0:
                    setcolor(0x00);
                    break;
                case 1:
                    setcolor(0xff000);
                    break;
                case 2:
                    setcolor(0xFFFFFF);
                    break;
            }
            rectprintf(x*50,y*50,50,50,lp);
        }
    }
}

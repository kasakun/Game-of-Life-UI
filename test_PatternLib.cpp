//
// Created by chenzy on 4/27/18.
//

#include "PatternLib.h"

int main(int /* argc */, char ** /* argv */) {
    PatternLib lib(800, 800);
    lib.initPatternList();
    bool** grid;
    lib.getPattern("ADDER", grid);
    return 0;
}
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "pattern.h"

int main()
{
    Pattern mask;
    std::string filename1 ="ACORN";
    int width=0 ;
    int height=0 ;
    mask.readWrite(filename1, &width, &height);
    std::cout<<width<<std::endl;

    bool** pattern = new bool* [height];
    pattern[0] = new bool[height*width];
    mask.getPattern(filename1, width, height, pattern);
}
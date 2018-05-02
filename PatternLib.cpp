/*
 * Created by Zeyu Chen on 4/27/18.
 *
 * Zeyu Chen, Yijun Zhang
 */

#include <assert.h>
#include <cstdlib>
#include <cstring>
#include <dirent.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>

#include "PatternLib.h"

#define MAX(X, Y) X > Y? X:Y
PatternLib::PatternLib(int _width, int _height) {
    width = _width;
    height = _height;
    num = 0;
}

PatternLib::~PatternLib() {
}

int PatternLib::initPatternList() {
    DIR* dir;
    int counter;
    struct dirent *fptr;

    dir = opendir(ROOT);
    assert (dir!=NULL);

    counter = 0;
    while ((fptr = readdir(dir)) != NULL) {
        if (strcmp(fptr->d_name, ".") == 0 || strcmp(fptr->d_name, "..") == 0)
            continue;
        int i, j;
        for (i = 0; i < fptr->d_reclen; ++i) {
            if (*(fptr->d_name + i) == '.')
                break;
        }
        std::string name = std::string(fptr->d_name, i);
        for (j = i, i = 0; i < fptr->d_reclen; ++i) {
            if (*(fptr->d_name + i) == 0)
                break;
        }
        std::string suffix = std::string(fptr->d_name + j, i-j);
        patternList.insert(std::pair<std::string, std::string>(name, suffix));
        ++counter;
    }
    return counter;
}
std::vector<std::string> PatternLib::getPatternList() {
    std::vector<std::string> list;
    std::unordered_map<std::string, std::string>::iterator it;
    for (it = patternList.begin(); it != patternList.end(); ++it) {
        if (it->first == "WELCOME") continue;
        list.push_back(it->first.data());
    }

    return list;
}
bool PatternLib::printPatternList() {
    std::unordered_map<std::string, std::string>::iterator it;
    for (it = patternList.begin(); it != patternList.end(); ++it)
        std::cout << it->first.data() << " " << it->second.data() <<std::endl;
    return true;
}
bool PatternLib::getPattern(std::string patternName, bool** pattern) {
    std::int8_t shift;
    std::fstream f;
    std::string temp;

    auto x = patternList.find(patternName);
    if (x == patternList.end()) {
        std::cout << "Pattern not found!" << std::endl;
        return false;
    }
    std::string path = ROOT + x->first + x->second;
//    std::cout<< path << std::endl;

    // Clear
    for (int i = 0; i < width; ++i) {
        *(pattern + i) = new bool[width];
    }
    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            pattern[i][j] = false;
        }
    }

    // loading file
    f.open(path);
    assert(f.is_open());

    // check file version
    std::string line;
    std::getline(f, line);
    // Only implement Life 1.05
    if (x->second == ".LIF" && line == "#Life 1.05\r") {
        readLife105(f, pattern);
    }
    //std::cout << blockCord.size() << " blocks" << std::endl;
    f.close();
    return true;
}

bool PatternLib::readLife105(std::fstream& f, bool** pattern) {
    std::string line;
    while (std::getline(f, line)) {
        if (line[0] == '#' && line[1] == 'N')
            break;
    }
    // Start here
    int cord[2], cordShift[2], row, col;
    while (std::getline(f, line)) {
        // #P X Y determine the strat of the block
        if (line[0] == '#' && line[1] == 'P') {
            std::stack<char> constructor; int* tempCord = cord;
            for (int i = 2; i < line.length(); ++i) {
                if ((line[i] == ' ' || line[i] == '\r') && constructor.size() != 0) {
                    *tempCord = 0;
                    for (int j = 0; constructor.size() != 0; ++j) {
                        if (constructor.top() != '-')
                            *tempCord += (j == 0) ? (constructor.top() - '0') : (constructor.top() - '0')*10*j;
                        else
                            *tempCord *= -1;
                        constructor.pop();
                    }
                    ++tempCord;
                }
                if (line[i] == '-' || line[i] >= '0' && line[i] <= '9')
                    constructor.push(line[i]);
            }
//            std::cout << cord[0] << " " << cord[1] << std::endl;
            cordShift[0] = cord[0] + width/2; // modify to the matrix in the program
            cordShift[1] = cord[1] + height/2;

            row = cordShift[1];

        } else { // must be the last #P's block, use cord directly
            for (int col = cordShift[0]; col < line.length() + cordShift[0]; ++col) {
                if(line[col - cordShift[0]] == '*')
                    pattern[row][col] = true;
            }
            ++row;
        }
    }
    return true;
}
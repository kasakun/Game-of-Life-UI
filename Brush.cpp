/*
 * Created by Zeyu Chen on 5/1/18.
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

#include "Brush.h"

#define BRUSH_ROOT "Brush/"
Brush::Brush() {

}

Brush::~Brush() {
}

int Brush::initBrushList() {
    DIR* dir;
    struct dirent *fptr;

    dir = opendir(BRUSH_ROOT);
    assert (dir!=NULL);
    int counter = 0;
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
        brushList.insert(std::pair<std::string, std::string>(name, suffix));
        ++counter;
    }

    return counter;
}

std::vector<std::string> Brush::getBrushList() {
    std::vector<std::string> list;
    for (auto x:brushList) {
        list.push_back(x.first);
    }

    return list;
}


bool Brush::getBrush(std::string brushName) {
    std::string line;
    std::fstream f;

    auto x = brushList.find(brushName);
    if (x == brushList.end()) {
        std::cout << "Pattern not found!" << std::endl;
        return false;
    }
    std::string path = BRUSH_ROOT + x->first + x->second;
    f.open(path);
    assert(f.is_open());


    std::getline(f, line);
    std::stack<char> constructor; int* tempSize = size;
    for (int i = 1; i < line.length(); ++i) {
        if ((line[i] == ' ' || line[i] == '\\') && constructor.size() != 0) {
            *tempSize = 0;
            for (int j = 0; constructor.size() != 0; ++j) {
                if (constructor.top() != '-')
                    *tempSize += (j == 0) ? (constructor.top() - '0') : (constructor.top() - '0')*10*j;
                else
                    *tempSize *= -1;
                constructor.pop();
            }
            ++tempSize;
        }
        if (line[i] == '-' || line[i] >= '0' && line[i] <= '9')
            constructor.push(line[i]);
    }

    this->brush = new bool*[size[0]];
    for (int i = 0; i < size[0]; ++i)
        *(this->brush + i) = new bool[size[1]];
    int row = 0;
    while (std::getline(f, line)) {
        for (int i = 0; i < line.length(); ++i)
            this->brush[row][i] = (line[i] == '*');
        ++row;
    }

    return true;
}

bool Brush::getBrushSize(int& width, int& height) {
    width = size[0];
    height = size[1];
}
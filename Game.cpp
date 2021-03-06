/*
 * Created by Zeyu Chen on 4/12/18.
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Game.h"

Game::Game(const int w, const int h) :width(w), height(h) {
    // grid, nextgrid bool**
    grid = new bool*[width];
    Nextgrid = new bool*[width];

    for (int i = 0; i < width; ++i) {
        *(grid + i) = new bool[height];
        *(Nextgrid + i) = new bool[height];
    }

    // the neighbours position
    x = new int[3];
    y = new int[3];

    // Random Seed
    srand((unsigned)time(NULL));
}

Game::~Game() {
    delete [] grid;
    delete [] Nextgrid;
    delete [] x;
    delete [] y;

}

void Game::init() {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
//            double r = (double)rand() / RAND_MAX;
            grid[i][j] = false;
        }
    }
}

void Game::update() {
    for (int i = 0; i < width; ++i) {
        for(int j = 0; j < height; ++j) {
            int neighbors = numofNeighbour(i, j);

            if (grid[i][j]) {
                Nextgrid[i][j] = neighbors == 2 || neighbors == 3;
            }
            else {
                Nextgrid[i][j] = neighbors == 3;
            }
        }
    }
    bool** t = grid;
    grid = Nextgrid;
    Nextgrid = t;
}

int Game::numofNeighbour(const int pos_x, const int pos_y) {
    // inside each domain
    int n = 0;

    // Adjust the pos x, y if they are on the edge.
    x[0] = pos_x == 0 ? (width - 1): (pos_x - 1);
    x[1] = pos_x;
    x[2] = (pos_x == (width - 1)) ? 0 : (pos_x + 1);

    y[0] = pos_y == 0 ? (height - 1): (pos_y - 1);
    y[1] = pos_y;
    y[2] = (pos_y == (height - 1)) ? 0 : (pos_y + 1);


    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            //
            if ((x[i] != pos_x || y[j] != pos_y) && grid[x[i]][y[j]])
                    ++n;
        }
    }

    return n;
}

bool Game::valueofPos(const int pos_x, const int pos_y) {
    return grid[pos_x][pos_y];
}

void Game::randomPattern() {
    const double prob = 0.3;
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            double r = (double)rand() / RAND_MAX;
            grid[i][j] = (r < prob);
        }
    }
}

bool Game::readLibrary(bool **g) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            grid[i][j] = g[i][j];
        }
    }
    return true;
}

bool Game::paint(int pos_x, int pos_y, int brushw, int brushh, bool** brush) {
    for (int i = 0; i < brushh; ++i)
        for (int j = 0; j < brushw; ++j)
            grid[(pos_y + j - brushw/2)][ (pos_x + i - brushh/2)] = brush[j][i];
}

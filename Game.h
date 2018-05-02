/*
 * Created by Zeyu Chen on 4/12/18.
 */

#ifndef GAME_OF_LIFE_UI_GAME_H
#define GAME_OF_LIFE_UI_GAME_H


class Game {
private:
    bool** grid;
    bool** Nextgrid;
    int* x;
    int* y;
    int width, height;
public:
    Game(const int w, const int h);
    ~Game();
    // Initialize the pattern of the Game
    void init();
    // Updating function
    void update();
    // return the num of neighbours of (x, y)
    int numofNeighbour(const int pos_x, const int pos_y);
    // return the value of the position (x, y)
    bool valueofPos(const int pos_x, const int pos_y);
    //PatternLib
    void randomPattern();
    //read
    bool readLibrary(bool** g);
    //modify
    bool paint(int pos_x, int pos_y, int brushw, int brushh, bool** brush);
};
#endif //GAME_OF_LIFE_UI_GAME_H

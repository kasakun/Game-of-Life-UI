/*
 * Created by Zeyu Chen on 5/1/18.
 */

#ifndef GAME_OF_LIFE_UI_BRUSH_H
#define GAME_OF_LIFE_UI_BRUSH_H
class Brush {
private:
    int size[2];
    std::unordered_map<std::string, std::string> brushList;  // store pattern path
public:
    bool** brush;
    Brush();
    ~Brush();
    int initBrushList();
    std::vector<std::string> getBrushList();
    bool getBrush(std::string brushName);
    bool getBrushSize(int& width, int& height);
};
#endif //GAME_OF_LIFE_UI_BRUSH_H

//
// Created by Yijun Zhang on 4/27/18.
//

#ifndef TEST_PATTERN_H
#define TEST_PATTERN_H



#define ROOT "Lib/"

class PatternLib{
private:
    int num;                        // number of patterns
    int width;
    int height;
    std::unordered_map<std::string, std::string> patternList;  // store pattern path

public:
    PatternLib(int _weight, int _height);
    ~PatternLib();
    int initPatternList();   // search all files in the dir and return the number.
    std::vector<std::string> getPatternList();
    bool printPatternList();
    bool getPattern(std::string patternName, bool** pattern);
    bool readLife105(std::fstream& f, bool** pattern);
};

#endif //TEST_PATTERN_H
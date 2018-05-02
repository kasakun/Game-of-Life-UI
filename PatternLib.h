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
    bool printPatternList();
    bool getPattern(std::string patternName, bool** pattern);
    bool readLife105(std::fstream& f, bool** pattern);
//    int readWrite(std::string filename1, int *width, int *height) {
//        std::string filename = "lifep/" + filename1 + ".LIF";
//        std::int8_t shift;
//        std::fstream f;
//        std::string temp;
//        f.open(filename);
//        if (!f.is_open()) //File has not been created!
//        {
//            std::cout << filename << " not found. Creating..." << std::endl;
//            f.open(filename, std::ios::out | std::ios::in | std::ios::trunc);
//            if (!f.is_open()) {
//                std::cout << "Error creating file " << filename << "!" << std::endl;
//                f.close(); //Is this necessary since the is_open() returns false?
//                return -1;
//            }
//
//            //f << 1; //This program has been run one time since creation of count.dat
//        }
//        else //File already exists, meaning it has a number in it
//        {
//            int value = 0;
//            //std::string *pattern;
//            std::string line;
//            while (std::getline(f, line)) {
//                std::string a;
//                a = line[0];
//                if (a != "#") {
//                    value = 1;
//                    std::cout << line << std::endl;
//                    //std::cout << line[2] <<std::endl;
//                    //pattern[*height] = line;
//
//                    *height = *height + 1;
//                    if (*width <= (int) (size(line)))
//                        *width = (int) (size(line) - 1);
//                }
//                else {
//                    if (value)
//                        break;
//                }
//            }
//
//            f.clear();
//            f.seekg(0);
//        }
//        f.close();
//        return 0;
//    }

};

#endif //TEST_PATTERN_H
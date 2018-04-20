#include <iostream>
#include <fstream>
#include <cstdlib>

/**
 * Keeps track of how many times this program has run,
 * using count.dat as a source of "memory" for it.
 */
int readWrite(std::string filename)
{
    std::int8_t shift;
    std::fstream f;
    std::string temp;
    f.open(filename);
    if (!f.is_open()) //File has not been created!
    {
        std::cout << filename << " not found. Creating..." << std::endl;
        f.open(filename, std::ios::out|std::ios::in|std::ios::trunc);
        if (!f.is_open())
        {
            std::cout << "Error creating file " << filename << "!" << std::endl;
            f.close(); //Is this necessary since the is_open() returns false?
            return -1;
        }

        //f << 1; //This program has been run one time since creation of count.dat
    }
    else //File already exists, meaning it has a number in it
    {
        int n = 0;
        std::string line;
        while(std::getline(f, line))
        {
            /*//n = std::stoi(line);
            n = atoi(line.c_str());*/
            std::cout<<line<<std::endl;
        }
        f.clear();
        f.seekg(0);
    }
    f.close();
    return 0;
}

int main()
{
    std::string filename = "count.dat";
    if (readWrite(filename) == 0)
    {
        std::cout << "count.dat" << " sucessfully incremented!" << std::endl;
    }   else std::cout << "There was some error...";

    return 0;
}
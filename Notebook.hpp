#include <iostream>
#include <string>
#include "Direction.hpp"
using namespace std;
namespace ariel
{
    class Notebook
    {
    public:
        Notebook();
        void write(int page, int row, int col, Direction direction, string text);
        string read(int page, int row, int col, Direction direction, int numOfChars);
        void erase(int page, int row, int col, Direction direction, int numOfChars);
        void show(int page);
    };
};
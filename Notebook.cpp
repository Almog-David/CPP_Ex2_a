#include <iostream>
#include <string>
#include "Direction.hpp"
#include "Notebook.hpp"
using namespace std;
using namespace ariel;
Notebook::Notebook() {}
void Notebook::write(int page, int row, int col, Direction direction, string text) {}
string Notebook::read(int page, int row, int col, Direction direction, int numOfChars) { return ""; }
void Notebook::erase(int page, int row, int col, Direction direction, int numOfChars) {}
void Notebook::show(int page) {}

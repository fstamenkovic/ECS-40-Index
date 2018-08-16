//Authors: Filip Stamenkovic and Ryland Sepic

#ifndef P8_INDEXPAGER_H
#define P8_INDEXPAGER_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include "pager.h"

using namespace std;

class IndexPager : Pager
{
  map<string, int> WordKey;
  multimap<int, int> MultiKey;
public:
  void read(istream &is);
  void insertString(string &s, int lineNum);
  void createVector();
  void readInVector(vector<int> &lines, int i);
}; //class IndexPager

#endif //P8_INDEXPAGER_H

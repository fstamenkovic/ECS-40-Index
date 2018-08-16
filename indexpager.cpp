//Authors: Filip Stamenkovic and Ryland Sepic

#include "indexpager.h"
#include <cctype>

void IndexPager::read(istream &is)
{
  string s;
  string m = "";
  m.erase();
  int lineNumber = 0;
  
  while(getline(is, s, '\n'))
  {
    s += ";";
    
    for (std::string::iterator it = s.begin(); it != s.end(); it++ )
    {
      if(isalpha(*it))
        m.push_back(*it);
      else //quits
        if(!(isalpha(*it)) && !(m.empty()))
        {
          insertString(m, lineNumber);
          m.erase();
        } //quits
      
    } //runs through a whole line
    
    
    lineNumber++;
  } // runs a while loop until file ends also updates string
  
  createVector();
} // reads the file and parses the words


void IndexPager::insertString(string &s, int lineNum)
{
  int number;
  static int wordCount;
  std::map<string, int>::iterator it;
  it = WordKey.find(s);
  
  if(it == WordKey.end())
  {
    WordKey.insert(std::pair<string, int>(s, wordCount));
    wordCount++;
    it = WordKey.find(s);
  }//if the word is not in the map
  
  std::multimap<int, int>::iterator itm = MultiKey.find(it->second);
  
    if (itm->second != lineNum || lineNum == 0)
      MultiKey.insert(std::pair<int, int>(it->second, lineNum));
    
  
}//fills in the two maps


void IndexPager::createVector()
{
  std::map<string, int>::iterator it;
  
  for(it = WordKey.begin(); it != WordKey.end(); it++)
  {
    string s;
    std::multimap<int, int>::iterator itm, c;
    s += it->first + " ";
    vector<int> lines;
    
    readInVector(lines, it->second);
    std::vector<int>::iterator pos, next;
    
    for(next = pos = lines.begin(); pos != lines.end(); pos++)
    {
      next++;
      s += intToString(*pos);
      
      if(next != lines.end() && *next - 1 == *pos)
      {
        while(next != lines.end() && *pos == *(next) - 1)
          next++ = pos++;
        s += "-" + intToString(*pos);
      } //adds the range of lines
      
      if(next == lines.end())
        break;
      s += ", ";
    } //creates the string
    
    s += ".";
    text.push_back(s);
  }//goes through every word
} //makes vecror


void IndexPager::readInVector(vector<int> &lines, int i)
{
  std::multimap<int, int>::iterator itm, c;
  
  for(c = itm = MultiKey.find(i); itm->first == c->first; itm++)
    if(lines.size() == 0)
      lines.push_back(itm->second);
    else //not empty and check if there is a number like that already
    if(lines.size() > 0 && lines.back() != itm->second)
      lines.push_back(itm->second);
} // makes a vector for output



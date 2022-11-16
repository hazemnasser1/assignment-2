#ifndef DOCUMENTSIMILARITY_STRINGSET_H
#define DOCUMENTSIMILARITY_STRINGSET_H
#include <set>
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class StringSet {
private:
    set<string> Documents;
    string token;
public:
    StringSet() = default;
    StringSet(string s);
    StringSet(string filename, int x);
    void parsing(string &s);
    void print()const;
    StringSet operator+(const StringSet &rhs)const;
    StringSet operator*(const StringSet &rhs)const;
    double Computes_Similarity(const StringSet &rhs);

};


#endif //DOCUMENTSIMILARITY_STRINGSET_H

#include "StringSet.h"
StringSet::StringSet(string s) {
    parsing(s);
}
StringSet::StringSet(string filename, int x) {
    fstream f;
    string s;
    f.open(filename, ios::in);
    while (!f.eof()){
        getline(f, s);
        parsing(s);
    }
}
void StringSet::parsing(string &s) {
    while (!s.empty()) {
        while (isalpha(*s.begin())) {
            token += tolower(*s.begin());
            s.erase(s.begin());
        }
        if(isalpha(token[0]))
            Documents.insert(token);
        token.clear();
        if(!s.empty())
          s.erase(s.begin());
    }
}
void StringSet::print()const {

    for(const auto &e: Documents)
        cout << e << " ";
    cout << endl;
}

StringSet StringSet::operator+(const StringSet &rhs)const {
    StringSet temp;
    for(const auto el: Documents){
        temp.Documents.insert(el);
    }
    for(const auto el: rhs.Documents){
        temp.Documents.insert(el);
    }
    return temp;
}

StringSet StringSet::operator*(const StringSet &rhs) const {
    StringSet temp;
    for(const auto &e: Documents){
        if(rhs.Documents.find(e) != rhs.Documents.end()){
            temp.Documents.insert(e);
        }
    }
    return temp;
}
double StringSet::Computes_Similarity(const StringSet &rhs) {
     double similarity;
     similarity = (((*this) * rhs).Documents.size()) / (sqrt(Documents.size()) * sqrt(rhs.Documents.size()));
     return similarity;
}
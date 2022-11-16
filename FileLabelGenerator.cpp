//
// Created by Hazem on 11/11/2022.
//

#include "FileLabelGenerator.h"

FileLabelGenerator::FileLabelGenerator(string t, int n, string name): LabelGenerator(t,n) {
    f.open(name ,ios :: in);

}
string FileLabelGenerator::nextLabel() {
    string text;
    getline(f,text);
    return type+to_string(num++)+" "+text;
}
FileLabelGenerator::~FileLabelGenerator() {
    f.close();
}
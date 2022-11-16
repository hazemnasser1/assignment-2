
#include "LabelGenerator.h"

LabelGenerator::LabelGenerator(string t,int n) {
    type=t;
    num=n;
}
string LabelGenerator::nextLabel() {
    return type+to_string(num++);
}

string LabelGenerator::get_type() {
    return type;
}

int LabelGenerator::get_num() {
    return num;
}

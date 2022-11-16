//
// Created by Hazem on 11/11/2022.
//

#ifndef TASK2_LABEL_LABELGENERATOR_H
#define TASK2_LABEL_LABELGENERATOR_H

#include <iostream>
using namespace std;

class LabelGenerator {
protected:
    string type;
    int num;
public:
    LabelGenerator()=default;
    LabelGenerator(string t,int n);
    string nextLabel();
    string get_type();
    int get_num();



};


#endif //TASK2_LABEL_LABELGENERATOR_H

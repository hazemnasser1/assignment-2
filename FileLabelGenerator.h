//
// Created by Hazem on 11/11/2022.
//

#ifndef TASK2_LABEL_FILELABELGENERATOR_H
#define TASK2_LABEL_FILELABELGENERATOR_H
#include "LabelGenerator.h"
#include <fstream>

class FileLabelGenerator : LabelGenerator {
private:
    fstream f;
public:
    FileLabelGenerator()=default;
    FileLabelGenerator(string t,int n,string name);
    string nextLabel();
    ~FileLabelGenerator();

};


#endif //TASK2_LABEL_FILELABELGENERATOR_H

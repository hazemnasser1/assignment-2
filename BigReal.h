#ifndef BIGREAL_BIGREAL_H
#define BIGREAL_BIGREAL_H

#include "BigDecimalIntClass.h"
class BigReal {

private:
    BigDecimalInt obj;
    int point_pos;
    char sign;
    string num;


public:
    BigReal () = default;      // Default constructor
    BigReal (string realNumber);
    BigReal (BigDecimalInt bigInteger);
    BigReal (const BigReal& other);          // Copy constructor
    BigReal (BigReal&& other);              // Move constructor
    BigReal& operator= (BigReal& other);    // Assignment operator
    BigReal& operator= (BigReal&& other);
    BigReal operator+ ( BigReal other);
    BigReal operator- (BigReal other);
    bool operator< (BigReal &anotherReal);
    bool operator> (BigReal &anotherReal);
    bool operator== ( BigReal &anotherReal);
    int size() ;
    char get_sign()  ;
    friend ostream& operator << (ostream& out, const BigReal& num);
    string get_num();
    friend istream& operator >> (istream& in, BigReal& other);
    friend void same_size(string &n1, string &n2);

};




#endif //BIGREAL_BIGREAL_H

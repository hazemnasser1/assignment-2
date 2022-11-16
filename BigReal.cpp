#include "BigReal.h"
#include "BigDecimalIntClass.h"

regex validInput("[-+]?[0-9]+[.][0-9]+" );

BigReal::BigReal(string realNumber) {
    if(regex_match(realNumber, validInput)){
        num = realNumber;
        if(num[0] == '+' || num[0] == '-'){
            sign = num[0];
        } else{
            sign = '+';
        }
    } else{
        cerr << "Invalid input" << endl;
        exit(-1);
    }

}

void same_size(string &n1, string &n2){
    char sign1, sign2;
    bool flag{false}, in{false};
        if(n1[0] == '+' || n1[0] == '-') {
            sign1 = n1[0];
            n1.erase(n1.begin());
            flag = !flag;
        }
        if(n2[0] == '+' || n2[0] == '-'){
            sign2 = n2[0];
            n2.erase(n2.begin());
            in = !in;
        }

    int sz1 = n1.substr(0 , n1.find('.')).size();
    int sz2 = n2.substr(0, n2.find('.')).size();
    int sz3 = n1.substr(n1.find('.') +1, n1.size()).size();
    int sz4 = n2.substr(n2.find('.') +1, n2.size()).size();

    if(sz1 > sz2){
        n2 = string(sz1 - sz2, '0') + n2;
    } else{
        n1 = string(sz2 - sz1, '0') + n1;
    }
    if(sz3 > sz4){
        n2 += string(sz3-sz4,'0');
    } else{
        n1 += string(sz4-sz3,'0');
    }
    if(flag){
        n1 = sign1 + n1;
    } if(in){
        n2 = sign2 + n2;
    }
}

BigReal::BigReal(BigDecimalInt bigInteger){
    obj.setNumber(bigInteger.getNumber());
    num = obj.getNumber();
    sign = obj.sign();

}

BigReal BigReal::operator+ (BigReal other){

    same_size(num, other.num);
    other.num.erase(other.num.find('.'), 1);
    int sz = num.substr(num.find('.'), num.size()).size();
    point_pos = num.find('.') ;
    num.erase(num.find('.'), 1);
    BigDecimalInt n1{num}, n2{other.num};
    BigDecimalInt temp = n1 + n2;
    BigReal res{temp};
    if(num[0] == '+' || num[0] == '-'){
        point_pos -= 1;
        num.erase(num.begin());
    }

    if(n1.sign() == n2.sign()) {
        if (res.num.size() > num.size()) {
            res.num.insert(res.num.begin() + point_pos + (res.num.size() - num.size()), '.');
        }

        else{
            res.num.insert(res.num.begin() + point_pos , '.');

        }
    } else{
        if (res.num.size() < num.size()) {
            res.num.insert(res.num.begin() + point_pos - (num.size()-res.num.size()), '.');
        } else {
            res.num.insert(res.num.begin() + point_pos, '.');
        }
    }
    res.sign = temp.sign();
    if(res.num.size() < sz){
        res.num.erase(res.num.begin());
        if(res.num[0] != '0') {
            res.num = string(sz - res.num.size() - 1, '0') + res.num;
            res.num = '.' + res.num;
        } else{
            res.num =  '.' + res.num;

        }
    }
    if(res.num[0] == '.'){
        res.num = '0' + res.num;
    }
    while (res.num[res.num.size()-1] == '0' && res.num[res.num.size()-2] != '.'){
        res.num.erase(res.num.size()-1, 1);
    }
    num.insert(num.begin()+point_pos, '.');
    return res;

}

BigReal BigReal::operator-(BigReal other) {

    if(other.num[0] == '+'){
        other.num[0] = '-';
    } else if(other.num[0] == '-'){
        other.num[0] = '+';
    } else{
        other.num = '-' + other.num;
    }
    BigReal res = *this + other;
    return res;

}

ostream & operator <<(ostream & out, const BigReal& other){
    if (other.sign == '+')
        out << other.num;
    else
        out << other.sign << other.num ;

    return out;
}

istream & operator >>(istream &in,  BigReal & other){
 string s;
 in >> s;
 BigReal temp{s};
 other = temp;
    return in;
}
bool BigReal::operator<(BigReal &anotherReal) {
    if(num[0] == '+' || num[0] == '-'){
        num.erase(num.begin());

    }
    if(anotherReal.num[0] == '+' || anotherReal.num[0] == '-'){
        anotherReal.num.erase(anotherReal.num.begin());
    }
    same_size(num, anotherReal.num);
    if(sign == '+' && anotherReal.sign == '+') {
        if (num < anotherReal.num) {
            return true;
        }
        else{
            return false;
        }
    }
    else if(sign == '+' && anotherReal.sign == '-'){
        return false;
    }
    else if(sign == '-' && anotherReal.sign == '+'){
        return true;
    }
    else {
        if(num > anotherReal.num){
            return true;
        }
        else{
            return false;
        }
    }

}
bool BigReal::operator>(BigReal &anotherReal) {
    if(num[0] == '+' || num[0] == '-'){
        num.erase(num.begin());

    }
    if(anotherReal.num[0] == '+' || anotherReal.num[0] == '-'){
        anotherReal.num.erase(anotherReal.num.begin());
    }
    same_size(num, anotherReal.num);
    if(sign == '+' && anotherReal.sign == '+') {
        if (num > anotherReal.num) {
            return true;
        }
        else{
            return false;
        }
    }
    else if(sign == '+' && anotherReal.sign == '-'){
        return true;
    }
    else if(sign == '-' && anotherReal.sign == '+'){
        return false;
    }
    else {
        if(num > anotherReal.num){
            return false;
        }
        else{
            return true;
        }
    }

}
bool BigReal::operator==(BigReal &anotherReal) {
    if(sign == anotherReal.sign && num == anotherReal.num){
        return true;
    }
    else{
        return false;
    }
}
BigReal::BigReal(const BigReal &rhs){
    num = rhs.num;
    point_pos = rhs.point_pos;
    sign = rhs.sign;
    obj = rhs.obj;
}
BigReal &BigReal::operator= (BigReal& other){
    num = other.num;
    sign = other.sign;
    point_pos = other.point_pos;
    obj = other.obj;
    return *this;
}

char BigReal ::get_sign() {
    return sign;
}
int BigReal ::size() {
    return num.size();
}
string BigReal ::get_num() {
    return num;
}
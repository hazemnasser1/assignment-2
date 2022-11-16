#include <bits/stdc++.h>
#include <functional>
using namespace std;

class Function{
public:
    virtual double evaluateAt(double value)=0;
};
class SimpleFunction : public Function{
private:
    function<double(double)> f;
public:
    SimpleFunction(function<double(double)> g):f{g}{}
    double evaluateAt(double value) {
        return f(value);
    }
};
class CompositionFunction : public Function{
private:
    function<double(double)>g;
    function<double(double)>f;
public:
    CompositionFunction(function<double(double)>g,function<double(double)>f): g{g}, f{f}{}
    double evaluateAt(double value){
        return g(f(value));
    }
};
class DerivativeFunction : public Function{
private:
    function<double(double)>f;
    double deltaX;
public:
    DerivativeFunction(function<double(double)>f, double deltaX):f{f}, deltaX{deltaX}{}
    double evaluateAt(double value){
        return (f(value + deltaX) - f(value - deltaX)) /( 2*deltaX);

    }
};
double square(double x){
    return x * x;
}
double cube(double x){
    return x * x * x;
}
double absolute(double x) {
    if (x < 0) {
        return -x;
    }
    else {
        return x;
    }
}
int main() {

    SimpleFunction f{absolute};
    CompositionFunction g{square, cube};
    cout << f.evaluateAt(-2) << endl;
    cout << g.evaluateAt(2) << endl;
    DerivativeFunction v{[](double n) {return n*n; },5 };
    cout << v.evaluateAt(4);



    return 0;
}

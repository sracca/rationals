//
// Rational.h - srracca
//

#include <ostream>

using std::ostream;
using std::istream;

#ifndef PA5_RATIONAL_H
#define PA5_RATIONAL_H


class Rational {

public:
    //varis
    int numerator;
    int denominator;

    //constructors
    Rational(const int num, const int denom);
    Rational(const int wholeNum);
    Rational();
    operator double();



    //fcns
    double toDouble();
    Rational simplifyFrac();

    //operators

    //input and output
    friend ostream& operator<< (ostream& os, Rational a);
    friend istream& operator>>(istream& is, Rational &a);

    //math
    Rational operator-(Rational b);
    Rational operator*(Rational b);
    Rational operator/ (Rational b);
    Rational operator+ (Rational b);
    Rational* operator+=(Rational b);
    Rational* operator-=(Rational b);
    Rational* operator*=(Rational b);
    Rational* operator/=(Rational b);
    Rational* operator=(Rational b);

    //comparison
    bool operator== (Rational b);
    bool operator< (Rational b);
    bool operator!= (Rational b);
    bool operator> (Rational b);
    bool operator<= (Rational b);
    bool operator>= (Rational b);

};//Rational


#endif //PA5_RATIONAL_H

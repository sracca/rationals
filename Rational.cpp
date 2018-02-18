//
// Rational.cpp - srracca
//

#include <iostream>
#include "Rational.h"

using std::ostream;
using std::istream;
using std::cout;
using std::endl;


//fcns

//gives the decimal value of a rational
double Rational::toDouble() {
    return ((double)numerator/(double)denominator);
}//toDouble


//Simplifies fraction given, returns new rational
Rational Rational::simplifyFrac(){

    bool negative = false;
    long long int a = this->numerator;
    long long int b = this->denominator;
    if(a < 0 ){
        negative = !negative;
        a = -a;
    }
    if(b < 0){
        negative = !negative;
        b = -b;
    }
    int gcd;
    long long int remainder;
    Rational simpRat;

    while(remainder != 0){
        remainder = a % b;
        a = b;
        b = remainder;
    }
    gcd = a;

    simpRat.numerator = this->numerator/gcd;
    simpRat.denominator = this->denominator/gcd;

    if(negative)
        simpRat.numerator = -simpRat.numerator;

    return simpRat;
}//Rational::simplifyFrac()



//printing fcns

//takes the current rational and outputs to the user in the desired state
ostream& operator<< (ostream& os, Rational a){
    return os << a.numerator << '/' << a.denominator;
}//operator<<(Rational a)


//takes the input given by the user and creates a rational from it
istream& operator>> (istream& is, Rational &a){
    a.denominator = 1;
    is >> a.numerator;
    if(is.peek() == '/'){
        is.ignore();
        is >> a.denominator;
    }
    return is;
}//operator>>(Rational a)



//comparitive fcns

//compares given and current Rational, returns true if current is smaller or equal
bool Rational::operator<= (Rational b){
    return (this->numerator * b.denominator) <= (this->denominator * b.numerator);
}//Rational::operator<=(Rational b)


//compares given and current Rational, returns true if current is larger or equal
bool Rational::operator>= (Rational b){
    return (this->numerator * b.denominator) >= (this->denominator * b.numerator);
}//Rational::operator>=(Rational b)


//compares given and current Rational, returns true if current is smaller
bool Rational::operator< (Rational b){
    if(this->denominator == 0 || this->denominator <0)
        cout<< "Error" <<endl;
    return  (this->numerator * b.denominator) < (this->denominator * b.numerator);
}//Rational::operator<(Rational b)


//compares given and current Rational, returns true if current is larger
bool Rational::operator> (Rational b){
    return (this->numerator * b.denominator) > (this->denominator * b.numerator);
}//Rational::operator>(Rational b)


//compares given and current Rational, returns true if not equal
bool Rational::operator!= (Rational b){
    return (this->numerator * b.denominator) != (this->denominator * b.numerator);
}//Rational::operator!=(Rational b)


//compares given and current Rational, returns true if equal
bool Rational::operator== (Rational b){
    if(this->denominator == 0 || this->denominator <0)
        cout<< "Error" <<endl;
    return (this->numerator * b.denominator) == (this->denominator * b.numerator);
}//Rational::operator== (Rational b)

//mathematic fcns

//adds the current and a new Rational together, returns the resulting Rational
Rational Rational::operator+ (Rational b){
    Rational newRat;

    newRat.numerator = (this->numerator * b.denominator) + (b.numerator * this->denominator);
    newRat.denominator = this->denominator * b.denominator;

    newRat = newRat.simplifyFrac();

    return newRat;
}//Rational::operator+(Rational b)


//subtracts other Rational from this Rational, returns resultant
Rational Rational::operator-(Rational b){
    Rational newRat;

    newRat.numerator = (this->numerator * b.denominator) - (b.numerator * this->denominator);
    newRat.denominator = this->denominator * b.denominator;

    newRat = newRat.simplifyFrac();

    return newRat;
}//Rational::operator-(Rational b)


//multplies arrays together, returns resultant
Rational Rational::operator*(Rational b){
    Rational newRat;

    newRat.numerator = this->numerator * b.numerator;
    newRat.denominator = this->denominator * b.denominator;

    newRat = newRat.simplifyFrac();

    return newRat;
}//Rational::operator*(Rational b)


//divides current array by one provided, returns resultant
Rational Rational::operator/ (Rational b){
    Rational newRat;

    newRat.numerator = this->numerator * b.denominator;
    newRat.denominator = this->denominator * b.numerator;

    newRat = newRat.simplifyFrac();

    return newRat;
}//Rational::operator/(Rational b)

//adds and assigns a value
Rational* Rational::operator+=(Rational b){
    Rational thisRat;
    thisRat.numerator = (this->numerator * b.denominator) + (b.numerator * this->denominator);
    thisRat.denominator = this->denominator * b.denominator;
    thisRat = thisRat.simplifyFrac();

    this->numerator = thisRat.numerator;
    this->denominator = thisRat.denominator;
    return this;
}//Rational::operator+=(Rational b)

//subtracts and assigns a value
Rational* Rational::operator-=(Rational b){
    Rational thisRat;
    thisRat.numerator = (this->numerator * b.denominator) - (b.numerator * this->denominator);
    thisRat.denominator = this->denominator * b.denominator;

    thisRat = thisRat.simplifyFrac();
    this->numerator = thisRat.numerator;
    this->denominator = thisRat.denominator;

    return this;
}//Rational::operator-=(Rational b)

//multiplies and assigns a value
Rational* Rational::operator*=(Rational b){
    Rational thisRat;
    thisRat.numerator = this->numerator * b.numerator;
    thisRat.denominator = this->denominator * b.denominator;

    thisRat = thisRat.simplifyFrac();
    this->numerator = thisRat.numerator;
    this->denominator = thisRat.denominator;

    return this;
}//Rational::operator*=(Rational b)

//divides and assigns a value
Rational* Rational::operator/=(Rational b){
    Rational thisRat;
    thisRat.numerator = this->numerator * b.denominator;
    thisRat.denominator = this->denominator * b.numerator;

    thisRat = thisRat.simplifyFrac();
    this->numerator = thisRat.numerator;
    this->denominator = thisRat.denominator;

    return this;
}//Rational::operator/=(Rational b)

//assigns rational to each other
Rational* Rational::operator=(Rational b){

    this->numerator = b.numerator;
    this->denominator = b.denominator;

    return this;
}//Rational::operator(Rational b)




//constructors

//constructor to set for any legit value
Rational::Rational(const int num, const int denom){
    numerator = num;
    denominator = denom;
}//Rational(const int num, const int denom)


//constructor if rational is whole number
Rational::Rational(const int wholeNum){
    numerator = wholeNum;
    denominator = 1;
}//Rational(const int wholeNum)


//default constructor for rational
Rational::Rational() {
    numerator = 0;
    denominator = 1;
}//Rational()

//assigns doubles
Rational::operator double(){
    return this->toDouble();
}


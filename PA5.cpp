/*
 * PA5 - srracca
 */

#include <iostream>
#include <fstream>
#include <stack>
#include "Rational.h"
#include <vector>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
using std::ifstream;
using std::getline;
using std::string;
using std::stack;
using std::vector;
using std::stringstream;

int main(int argc, char *argv[]) {

    for (int i = 1; i < argc; i++) {

        //opens the file and prints file name
        ifstream opened(argv[i]);
        cout<< argv[i]<<endl << endl;

        Rational rational;
        stack<Rational> allRats;
        bool lineBool;
        bool isBool = false;

        char temp;
        opened.get(temp);

        while(!opened.eof()) {
            //pushes to EOF, so last line's answer doesn't print twice
            opened.unget();
            //prints the line
            string line;
            getline(opened, line);
            cout<< line <<"\t:";

            stringstream file;
            file.str(line);
            //if its not the end of the file
            bool eof = !file.eof();

            while(eof){
                //peek at what's coming next
                int next = file.peek();
                //helps with error handling if multiple booleans
                int boolCount = 0;
                //sets eof to !eof  again
                eof = !file.eof();

                //creates rational
                if (isdigit(next)) {
                    file >> rational;
                    allRats.push(rational);
                    file.ignore();
                }
                //mathematic functions
                else if (next == '+') {
                    //checks if operations is +=
                    if(file.seekg(1, file.cur).peek() == '='){
                        //takes first rational in a line
                        Rational first = allRats.top();
                        allRats.pop();
                        //takes second
                        Rational second = allRats.top();
                        allRats.pop();
                        //checks for errors within rationals
                        if((first.denominator <= 0) ||
                                (second.denominator <= 0)){
                            cout<< "Error" <<endl;
                            continue;
                        }
                        first += second;
                        //puts answer back on the stack
                        allRats.push(first);
                        //ignores so that the search moves on
                        file.ignore(2, ' ');
                    }
                    else{
                        Rational first = allRats.top();
                        allRats.pop();
                        Rational second = allRats.top();
                        allRats.pop();
                        if((first.denominator <= 0) ||
                           (second.denominator <= 0)){
                            cout<< "Error" <<endl;
                            continue;
                        }
                        Rational answer = first + second;
                        allRats.push(answer);
                        file.ignore(1, ' ');
                    }
                }
                else if (next == '-') {
                    if(file.seekg(1, file.cur).peek() == '='){
                        Rational first = allRats.top();
                        allRats.pop();
                        Rational second = allRats.top();
                        allRats.pop();
                        if((first.denominator <= 0) ||
                           (second.denominator <= 0)){
                            cout<< "Error" <<endl;
                            continue;
                        }
                        first -= second;
                        allRats.push(first);
                        file.ignore(2, ' ');
                    }
                    else{
                        Rational first = allRats.top();
                        allRats.pop();
                        Rational second = allRats.top();
                        allRats.pop();
                        if((first.denominator <= 0) ||
                           (second.denominator <= 0)){
                            cout<< "Error" <<endl;
                            continue;
                        }
                        Rational answer = first - second;
                        allRats.push(answer);
                        file.ignore(1, ' ');
                    }
                }
                else if (next == '/') {
                    if(file.seekg(1, file.cur).peek() == '='){
                        Rational first = allRats.top();
                        allRats.pop();
                        Rational second = allRats.top();
                        allRats.pop();
                        if((first.denominator <= 0) ||
                           (second.denominator <= 0)){
                            cout<< "Error" <<endl;
                            continue;
                        }
                        first /= second;
                        allRats.push(first);
                        file.ignore(2, ' ');
                    }
                    else{
                        Rational first = allRats.top();
                        allRats.pop();
                        Rational second = allRats.top();
                        allRats.pop();
                        if((first.denominator <= 0) ||
                           (second.denominator <= 0)){
                            cout<< "Error" <<endl;
                            continue;
                        }
                        Rational answer = first/second;
                        allRats.push(answer);
                        file.ignore(1, ' ');
                    }
                }
                else if (next == '*') {
                    if(file.seekg(1, file.cur).peek() == '='){
                        Rational first = allRats.top();
                        allRats.pop();
                        Rational second = allRats.top();
                        allRats.pop();
                        if((first.denominator <= 0) ||
                           (second.denominator <= 0)){
                            cout<< "Error" <<endl;
                            continue;
                        }
                        first *= second;
                        allRats.push(first);
                        file.ignore(2, ' ');
                    }
                    else{
                        Rational first = allRats.top();
                        allRats.pop();
                        Rational second = allRats.top();
                        allRats.pop();
                        if((first.denominator <= 0) ||
                           (second.denominator <= 0)){
                            cout<< "Error" <<endl;
                            continue;
                        }
                        Rational answer = first * second;
                        allRats.push(answer);
                        file.ignore(1, ' ');
                    }
                }
                //comparitive or assignment operators
                else if (next == '=') {
                    //checks if ==
                    if(file.seekg(1, file.cur).peek() == '='){
                        //isBool is for printing, switches it over
                        isBool = true;
                        Rational first = allRats.top();
                        allRats.pop();
                        Rational second = allRats.top();
                        allRats.pop();
                        if((first.denominator <= 0) ||
                           (second.denominator <= 0)){
                            cout<< "Error" <<endl;
                            continue;
                        }
                        //creates the answer to be printed
                        lineBool = (first == second );
                        //for error handling
                        boolCount++;
                        file.ignore(2, ' ');
                    }
                    else{
                        Rational first = allRats.top();
                        allRats.pop();
                        Rational second = allRats.top();
                        allRats.pop();
                        if((first.denominator <= 0) ||
                           (second.denominator <= 0)){
                            cout<< "Error" <<endl;
                            continue;
                        }
                        first = second;
                        allRats.push(first);
                        file.ignore(1, ' ');
                    }
                }
                else if (next == '!') {
                    isBool = true;
                    Rational first = allRats.top();
                    allRats.pop();
                    Rational second = allRats.top();
                    allRats.pop();
                    if((first.denominator <= 0) ||
                       (second.denominator <= 0)){
                        cout<< "Error" <<endl;
                        continue;
                    }
                    lineBool = (first != second );
                    boolCount++;
                    file.ignore(2, ' ');
                }
                else if (next == '<') {
                    if(file.seekg(1, file.cur).peek() == '='){
                        isBool = true;
                        Rational first = allRats.top();
                        allRats.pop();
                        Rational second = allRats.top();
                        allRats.pop();
                        if((first.denominator <= 0) ||
                           (second.denominator <= 0)){
                            cout<< "Error" <<endl;
                            continue;
                        }
                        lineBool = (first <= second );
                        boolCount++;
                        file.ignore(2, ' ');
                    }
                    else{
                        isBool = true;
                        Rational first = allRats.top();
                        allRats.pop();
                        Rational second = allRats.top();
                        allRats.pop();
                        if((first.denominator <= 0) ||
                           (second.denominator <= 0)){
                            cout<< "Error" <<endl;
                            continue;
                        }
                        lineBool = (first < second );
                        boolCount++;
                        file.ignore(1, ' ');
                    }
                }
                else if (next == '>') {
                    if(file.seekg(1, file.cur).peek() == '='){
                        isBool = true;
                        Rational first = allRats.top();
                        allRats.pop();
                        Rational second = allRats.top();
                        allRats.pop();
                        if((first.denominator <= 0) ||
                           (second.denominator <= 0)){
                            cout<< "Error" <<endl;
                            continue;
                        }
                        lineBool = (first >= second );
                        boolCount++;
                        file.ignore(2, ' ');
                    }
                    else{
                        isBool = true;
                        Rational first = allRats.top();
                        allRats.pop();
                        Rational second = allRats.top();
                        allRats.pop();
                        if((first.denominator <= 0) ||
                           (second.denominator <= 0)){
                            cout<< "Error" <<endl;
                            continue;
                        }
                        lineBool = (first > second );
                        boolCount++;
                        file.ignore(1, ' ');
                    }
                }
                else{
                    //prints error if the boolCount is larger than supposed to be
                    if(boolCount > 1)
                        cout<< "Error" <<endl;
                    //prints if the answer is supposed to be a bool
                    if (isBool)
                        cout << lineBool;
                    //prints if answer is mathematic
                    else {
                        Rational answer = allRats.top();
                        cout << answer << " (double: " << answer.toDouble() << ")";
                    }
                    cout << endl << endl << endl;
                }
            }
            opened.get(temp);
        }
        opened.close();
    }
    return 0;
}
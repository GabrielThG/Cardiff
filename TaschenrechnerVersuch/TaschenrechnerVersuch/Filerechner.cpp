#include "Filerechner.h"
#include <vector>
#include "InputOutput.h"
#include <fstream>
#include <iostream>
#include <string>



bool is_number(const std::string s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
int vecAdd(std::vector<int> vec) {
    int zahlErg = 1;
    for (auto i = vec.begin(); i != vec.end(); ++i)
        zahlErg += *i;
    return zahlErg;
}
int vecSub(std::vector<int> vec) {
    int zahlErg = 1;
    for (auto i = vec.begin(); i != vec.end(); ++i)
        zahlErg -= *i;
    return zahlErg;
}
int vecMul(std::vector<int> vec) {
    int zahlErg = 1;
    for (auto i = vec.begin(); i != vec.end(); ++i)
        zahlErg *= *i;
    return zahlErg;
}
int vecDiv(std::vector<int> vec) {
    int zahlErg = 1;
    for (auto i = vec.begin(); i != vec.end(); ++i)
        zahlErg /= *i;
    return zahlErg;
}
char fstoc(std::string s)
{
    char c = s[0];
    return c;
}
std::vector<std::string> makeVectorF() {
    std::vector<std::string> vec;
    std::string filename("input.txt");
    std::string number;
    std::ifstream input_file(filename);
    if (!input_file.is_open()) {
        std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
        return vec;
    }
    while (input_file >> number) {
        vec.push_back(number);
    }
    std::cout << std::endl;
    input_file.close();
    return vec;
}
void fileBerechnen() {
    InputOutput io;
    int zahlErg;
    char zahlOperator;
    std::vector<std::string> svec= makeVectorF();
    std::vector<int> ivec;
    if (is_number(svec.front()))
    {
        io.printFileError();
    }
    else {
        zahlOperator = fstoc(svec.front());
    }
    for (int i = 1; i < svec.size(); i++) {
        ivec[i] = stoi(svec[i]);
    }
    switch(zahlOperator) {
    case '+':
        zahlErg = vecAdd(ivec);
        break;
    case '-':
        zahlErg = vecSub(ivec);
        break;
    case '*':
        zahlErg = vecMul(ivec);
        break;
    case '/':
        zahlErg = vecDiv(ivec);
        break;
    }
    std::cout << "Das Ergebnis ist " << zahlErg << std::endl;
}
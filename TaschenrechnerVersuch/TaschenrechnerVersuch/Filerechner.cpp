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
    int zahlErg = 0;
    for (auto i = vec.begin(); i != vec.end(); ++i)
        zahlErg += *i;
    return zahlErg;
}
int vecSub(std::vector<int> vec) {
    int zahlErg = *vec.begin();
    for (auto i = vec.begin() +1 ; i != vec.end(); ++i)
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
    int zahlErg = *vec.begin();
    for (auto i = vec.begin() +1; i != vec.end(); ++i)
        zahlErg /= *i;
    return zahlErg;
}
char fstoc(std::string s)
{
    char c = s[0];
    return c;
}
//void Filerechner::makeFile()
//{
//    std::cout << "Hello World!\n";
//    int winwidth, winheight, wincolor;       // Declare your variables
//    winwidth = winheight = wincolor = 99;   // Set them all to 0
//    std::string path = "TextFile1.txt";          // Storing your filename in a string
//    std::ifstream fin;
//
//    fin.open(path);                        // Open the file
//    if (fin.is_open())                      // If it opened successfully
//    {
//        fin >> winwidth >> winheight >> wincolor;  // Read the values and
//                           // store them in these variables
//        fin.close();                   // Close the file
//    }
//    else
//    {
//        std::cout << " file not opened successfully..." << std::endl;
//        system("cd");
//    }
//    std::cout << winwidth << '\n';
//    std::cout << winheight << '\n';
//    std::cout << wincolor << '\n';
//}
std::vector<std::string> splitToVec(std::string str, std::string token) {
    std::vector<std::string>result;
    while (str.size()) {
        int index = str.find(token);
        if (index != std::string::npos) {
            result.push_back(str.substr(0, index));
            str = str.substr(index + token.size());
            if (str.size() == 0)result.push_back(str);
        }
        else {
            result.push_back(str);
            break;
        }
    }
    return result;
}
void vectorBerechnen(std::vector < std::string > svec) {
    InputOutput io;
    int zahlErg = 0;
    char zahlOperator;
    std::vector<int> ivec;
        if (is_number(svec.front()))
        {
            io.printFileError();
        }
        else {
            zahlOperator = fstoc(svec.front());
        }
    
        for (int i = 1; i < svec.size(); i++) {
            ivec.push_back(stoi(svec[i]));
        }
    switch (zahlOperator) {
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
    std::ofstream myfile("D:\\WMS Cardiff\\Übungsprojekte\\TaschenrechnerVersuch\\TaschenrechnerVersuch\\output.txt");
    if (myfile.is_open())
    {
        myfile << "Das Ergebnis der letzten Rechnung ist: " << zahlErg << std::endl;
        myfile.close();
    }
    else std::cout << "Unable to open file";
}
void printVec(std::vector<std::string> const& input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}
std::vector<std::string> Filerechner::makeVectorF() {
    std::vector<std::string> vec;
    std::string line;
    std::string del = " ";
    std::string filename("D:\\WMS Cardiff\\Übungsprojekte\\TaschenrechnerVersuch\\TaschenrechnerVersuch\\input.txt");
    std::ifstream input_file(filename);
    if (!input_file.is_open()) {
        std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
        return vec;
    }
    if (input_file.is_open())
    {
        while ( getline(input_file, line))
        {
            std::cout << line << std::endl;
            vec = splitToVec(line, del);
            vectorBerechnen(vec);
        }
        input_file.close();
    }
    std::cout << std::endl;
    input_file.close();
    return vec;
}
void bubbleSort(int array[], int size) {
    for (int step = 0; step < size; ++step) {
        for (int i = 0; i < size - step; ++i) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}



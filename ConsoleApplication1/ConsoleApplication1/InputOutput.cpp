#include "InputOutput.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <list>

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

std::list<std::vector<std::string>> InputOutput::makeVectorF() {
    std::list<std::vector<std::string>> list;
    std::vector<std::string> vec;
    std::string line;
    std::string del = " ";
    std::string filename("input.txt");
    std::ifstream input_file(filename);
    if (!input_file.is_open()) {
        std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
    }
    if (input_file.is_open()) {
        while (getline(input_file, line)) { 
            std::cout << line << std::endl;
            vec = splitToVec(line, del);
            list.push_back(vec);
        }
        input_file.close();
    }
    std::cout << std::endl;
    input_file.close();
    return list;
}
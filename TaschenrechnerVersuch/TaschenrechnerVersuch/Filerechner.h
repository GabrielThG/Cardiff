#pragma once
#include <string>
#include <vector>

class Filerechner
{
public:
    std::vector<std::string> makeVectorF();
    void makeFile();
};

bool is_number(const std::string);


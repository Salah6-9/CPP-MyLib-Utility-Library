#pragma once
#include <string>

namespace MyIO
{
    int ReadPositiveNumber(std::string Message);
    double ReadPositiveDoubleNumber(std::string Message);
    short Read_num_in_range(std::string output, int from, int to);
    bool Ask_for_continue(std::string message);
    std::string ReadString(const std::string &prompt);
    void header();
    std::string colum(int i);
    void multp();
}

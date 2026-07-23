#pragma once
#include <string>
#include <vector>

namespace MyVector
{
    void readVector(std::vector<std::string>& vec);
    std::string VectorToString(std::vector<std::string> vStr);
    void PrintVector(std::vector<std::string>& vec);
    void PrintVector(std::vector<int>& vec);
    std::vector<int> ReversVector(const std::vector<int>& numbers);
}

#pragma once
#include <string>
#include <vector>

namespace MyFile
{
    void LoadDataFromFileToVector(std::string FileName, std::vector<std::string>& vFileContent);
    void SaveVectorToFile(std::string FileName, std::vector<std::string>& vFileContent);
    void PrintFile(std::string FileName, std::string prompt = "the content of file is : ");
    void CreatFile(std::string FileName);
    void appendOneLine(std::string FileName, std::string Line);
    void AppendMultLine(std::string FileName);
    void UpdateRecord(std::string FileName, std::string Record, std::string newtext = "");
    void AddDataLineToFile(std::string stDataLine, std::string UsersFileName);

}

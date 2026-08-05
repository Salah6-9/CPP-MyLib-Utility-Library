#pragma once
#include <string>

namespace MyArray
{
    void PrintArray(std::string message, int N, int array[], std::string n = "");
    void PrintArray_string(std::string message, int N, std::string array[]);

    void Readarray(int N, int array[]);
    void Readarray(int N, std::string array[]);
    void Readarray_auto(int from, int to, int array[]);
    void FillArrayRandomNumbers(int& arrLength, int* array);

    void Copy_array(int arrLength, int source[], int dest[]);
    void Copy_array_reverse(int arrLength, int source[], int dest[]);

    void shuffle(int arrLength, int* arr);
    void add_element_in_array(int number, int array[], int& array_length);

    int Sum_of_Array(int arrLength, int array[]);
    float Average_of_Array(int arrLength, int array[]);
    int max_in_array(int arrLength, int array[]);
    int min_in_array(int arrLength, int array[]);

    int Repeat_N_Array(int N, int array[], int ncheck);
    short Search_N_Array(int arrLength, int array[], int ncheck);
    bool bool_Search_N_Array(int arrLength, int array[], int ncheck);

    void Copy_array_using_addElement(int arrSourceLength, int source[], int& destLength, int dest[]);
    void Copy_Numbers_addElement(int arrSourceLength, int source[], int& destLength, int dest[]);
    void Copy_Prime_Numbers_addElement(int arrSourceLength, int source[], int& destLength, int dest[]);
    void Copy_distinct_Numbers_addElement(int arrSourceLength, int source[], int& destLength, int dest[]);
}

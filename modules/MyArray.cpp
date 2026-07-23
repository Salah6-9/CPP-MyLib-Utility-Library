#include "MyArray.h"
#include "MyMath.h"
#include <iostream>

using namespace std;

namespace MyArray
{
    void PrintArray(string message, int N, int array[], string n)
    {
        cout << message << n << " : ";
        for (int i = 0; i < N; i++) cout << array[i] << " ";
        cout << endl;
    }

    void PrintArray_string(string message, int N, string array[])
    {
        for (int i = 0; i < N; i++)
            cout << message << i + 1 << ": " << array[i] << "\n";
        cout << endl;
    }

    void Readarray(int N, int array[])
    {
        for (int i = 0; i < N; i++) {
            cout << "Enter Array Elements:\nElement [" << i + 1 << "]: ";
            cin >> array[i];
        }
    }

    void Readarray(int N, string array[])
    {
        for (int i = 0; i < N; i++) {
            cout << "Enter Array Elements:\nElement [" << i + 1 << "]: ";
            cin >> array[i];
        }
    }

    void Readarray_auto(int from, int to, int array[])
    {
        for (int i = 0; i < to; i++)
            array[i] = i + 1;
    }

    void FillArray_random(int& arrLength, int* array)
    {
        cout << "\nEnter number of elements:\n";
        cin >> arrLength;
        for (int i = 0; i < arrLength; i++)
            array[i] = MyMath::RandomNum(1, 100);
    }

    void Copy_array(int arrLength, int source[], int dest[])
    {
        for (int i = 0; i < arrLength; i++)
            dest[i] = source[i];
    }

    void Copy_array_reverse(int arrLength, int source[], int dest[])
    {
        for (int i = 0; i < arrLength; i++)
            dest[i] = source[arrLength - 1 - i];
    }

    void shuffle(int arrLength, int* arr)
    {
        for (int i = 0; i < arrLength; i++)
            MyMath::Swap(arr[MyMath::RandomNum(0, arrLength - 1)], arr[MyMath::RandomNum(0, arrLength - 1)]);
    }

    void add_element_in_array(int number, int array[], int& array_length)
    {
        array[array_length++] = number;
    }

    int Sum_of_Array(int arrLength, int array[])
    {
        int sum = 0;
        for (int i = 0; i < arrLength; i++)
            sum += array[i];
        return sum;
    }

    float Average_of_Array(int arrLength, int array[])
    {
        return float(Sum_of_Array(arrLength, array)) / arrLength;
    }

    int max_in_array(int arrLength, int array[])
    {
        int max = array[0];
        for (int i = 0; i < arrLength; i++)
            if (array[i] > max) max = array[i];
        return max;
    }

    int min_in_array(int arrLength, int array[])
    {
        int min = array[0];
        for (int i = 0; i < arrLength; i++)
            if (array[i] < min) min = array[i];
        return min;
    }

    int Repeat_N_Array(int N, int array[], int ncheck)
    {
        int count = 0;
        for (int i = 0; i < N; i++)
            if (array[i] == ncheck) count++;
        return count;
    }

    short Search_N_Array(int arrLength, int array[], int ncheck)
    {
        for (int i = 0; i < arrLength; i++)
            if (array[i] == ncheck) return i;
        return -1;
    }

    bool bool_Search_N_Array(int arrLength, int array[], int ncheck)
    {
        for (int i = 0; i < arrLength; i++)
            if (array[i] == ncheck) return true;
        return false;
    }

    void Copy_array_using_addElement(int arrSourceLength, int source[], int& destLength, int dest[])
    {
        for (int i = 0; i < arrSourceLength; i++)
            add_element_in_array(source[i], dest, destLength);
    }

    void Copy_Numbers_addElement(int arrSourceLength, int source[], int& destLength, int dest[])
    {
        for (int i = 0; i < arrSourceLength; i++)
            if (source[i] % 2 != 0) add_element_in_array(source[i], dest, destLength);
    }

    void Copy_Prime_Numbers_addElement(int arrSourceLength, int source[], int& destLength, int dest[])
    {
        for (int i = 0; i < arrSourceLength; i++)
            if (MyMath::checkprime(source[i]) == MyMath::prime)
                add_element_in_array(source[i], dest, destLength);
    }

    void Copy_distinct_Numbers_addElement(int arrSourceLength, int source[], int& destLength, int dest[])
    {
        for (int i = 0; i < arrSourceLength; i++)
            if (!bool_Search_N_Array(destLength, dest, source[i]))
                add_element_in_array(source[i], dest, destLength);
    }
}

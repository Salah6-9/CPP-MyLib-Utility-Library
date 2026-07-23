#pragma once
#include <string>

namespace MyMatrix
{
    void FillMatRandom(int mat[][3], short rows, short cols);
    void printMatrix(std::string title, int mat[][3], short rows, short cols);
    void readMatrix(std::string msg, int mat1[][3], short rows, short cols);
    void PrintEachRowSumVer01(int mat[3][3], short rows, short cols);
    int RowSum(int mat[3][3], short rows, short cols);
    void PrintEachRowSumVer02(int mat[3][3], short rows, short cols);
    void SumMatixRowsInArry(int mat[3][3], short rows, short cols, int arr[]);
    int ColSum(int mat[3][3], short rows, short cols);
    void PrintEachColSum(int mat[3][3], short rows, short cols);
    void SumMatixColsInArry(int mat[3][3], short rows, short cols, int arr[]);
    void FillMatOrder(int mat[][3], short rows, short cols);
    void TransposeMatrix(int mat[][3], short rows, short cols, int transposed[][3]);
    void MultMitrix(int mat1[][3], int mat2[][3], int MultMat[][3], int rows, int cols);
    void FillMiddleRowOfMatrixInArray(int mat[][3], short rows, short cols, int mid[3]);
    void FillMiddleColOfMatrixInArray(int mat[][3], short rows, short cols, int mid[3]);
    int SumOfMatrix(int mat[][3], short rows, short cols);
    int MatrixSize(int mat1[][3], short rows, short cols);
    int CountNumberInMatrix(int mat1[][3], short rows, short cols, int num);
    bool is_ScalarMatrix(int mat1[][3], short rows, short cols);
    bool is_daigonalMatrix(int mat1[][3], short rows, short cols);
    bool is_identityMatrix(int mat1[][3], short rows, short cols);
    bool is_Equality(int mat1[][3], int mat2[][3], short rows, short cols);
    int MaxNumberInMatrix(int mat1[][3], short rows, short cols);
    int MinNumberInMatrix(int mat1[][3], short rows, short cols);
    bool Is_ExistsInMatrix(int mat1[][3], short rows, short cols, int num);
    void PrintIntersectedNumbersInMatrix(int mat1[][3], int mat2[][3], short rows, short cols);
    bool is_plaindrome(int mat1[][3], short rows, short cols);
}

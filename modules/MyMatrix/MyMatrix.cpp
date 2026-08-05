#include "MyMatrix.h"
#include "../../MyLib.h"
#include <iostream>
#include <cstdio>

using namespace std;

namespace MyMatrix
{
    void FillMatRandom(int mat[][3], short rows, short cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                mat[i][j] = MyMath::RandomNum(1, 100);
            }
        }
    }

    void printMatrix(string title, int mat[][3], short rows, short cols)
    {
        cout << title << "\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << mat[i][j] << " \t";
            }
            cout << "\n";
        }
        cout << endl;
    }

    void readMatrix(string msg, int mat1[][3], short rows, short cols)
    {
        cout << msg << " \n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> mat1[i][j];
            }
        }
    }

    void PrintEachRowSumVer01(int mat[3][3], short rows, short cols)
    {
        int sum = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                sum = sum + mat[i][j];
            }
            cout << "the sum of the row number " << i + 1 << ": " << sum << " \n";
            sum = 0;
        }
    }

    int RowSum(int mat[3][3], short rows, short cols)
    {
        int sum = 0;
        for (int i = 0; i < cols; i++)
        {
            sum = sum + mat[rows][i];
        }
        return sum;
    }

    void PrintEachRowSumVer02(int mat[3][3], short rows, short cols)
    {
        for (int i = 0; i < rows; i++)
        {
            cout << "the sum of the row number " << i + 1 << ": " << RowSum(mat, i, cols) << " \n";
        }
    }

    void SumMatixRowsInArry(int mat[3][3], short rows, short cols, int arr[])
    {
        for (int i = 0; i < rows; i++)
        {
            arr[i] = RowSum(mat, i, cols);
        }
    }

    int ColSum(int mat[3][3], short rows, short cols)
    {
        int sum = 0;
        for (int i = 0; i < rows; i++)
        {
            sum = sum + mat[i][cols];
        }
        return sum;
    }

    void PrintEachColSum(int mat[3][3], short rows, short cols)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "the sum of the column number " << j + 1 << ": " << ColSum(mat, rows, j) << " \n";
        }
    }

    void SumMatixColsInArry(int mat[3][3], short rows, short cols, int arr[])
    {
        for (int j = 0; j < cols; j++)
        {
            arr[j] = ColSum(mat, rows, j);
        }
    }

    void FillMatOrder(int mat[][3], short rows, short cols)
    {
        int num = 1;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                mat[i][j] = num;
                num++;
            }
        }
    }

    void TransposeMatrix(int mat[][3], short rows, short cols, int transposed[][3])
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                transposed[i][j] = mat[j][i];
            }
        }
    }

    void MultMitrix(int mat1[][3], int mat2[][3], int MultMat[][3], int rows, int cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                MultMat[i][j] = mat1[i][j] * mat2[i][j];
            }
        }
    }

    void FillMiddleRowOfMatrixInArray(int mat[][3], short rows, short cols, int mid[3])
    {
        for (int j = 0; j < cols; j++)
        {
            mid[j] = mat[rows / 2][j];
        }
    }

    void FillMiddleColOfMatrixInArray(int mat[][3], short rows, short cols, int mid[3])
    {
        for (int i = 0; i < rows; i++)
        {
            mid[i] = mat[i][cols / 2];
        }
    }

    int SumOfMatrix(int mat[][3], short rows, short cols)
    {
        int sum = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                sum += mat[i][j];
            }
        }
        return sum;
    }

    int MatrixSize(int mat1[][3], short rows, short cols)
    {
        return rows * cols;
    }

    int CountNumberInMatrix(int mat1[][3], short rows, short cols, int num)
    {
        int count = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (mat1[i][j] == num)
                {
                    count++;
                }
            }
        }
        return count;
    }

    bool is_ScalarMatrix(int mat1[][3], short rows, short cols)
    {
        int FirstElement = mat1[0][0];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i == j && mat1[i][j] != FirstElement)
                {
                    return false;
                }
                else if (i != j && mat1[i][j] != 0)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool is_daigonalMatrix(int mat1[][3], short rows, short cols)
    {
        for (int i = 0; i < rows; i++)
        {
            if (mat1[i][i] != 1)
            {
                return false;
            }
        }
        return true;
    }

    bool is_identityMatrix(int mat1[][3], short rows, short cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i == j && mat1[i][j] != 1)
                {
                    return false;
                }
                else if (i != j && mat1[i][j] != 0)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool is_Equality(int mat1[][3], int mat2[][3], short rows, short cols)
    {
        return (SumOfMatrix(mat1, rows, cols) == SumOfMatrix(mat2, rows, cols));
    }

    int MaxNumberInMatrix(int mat1[][3], short rows, short cols)
    {
        int max = mat1[0][0];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (max <= mat1[i][j])
                {
                    max = mat1[i][j];
                }
            }
        }
        return max;
    }

    int MinNumberInMatrix(int mat1[][3], short rows, short cols)
    {
        int min = mat1[0][0];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (min >= mat1[i][j])
                {
                    min = mat1[i][j];
                }
            }
        }
        return min;
    }

    bool Is_ExistsInMatrix(int mat1[][3], short rows, short cols, int num)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (mat1[i][j] == num)
                {
                    return true;
                }
            }
        }
        return false;
    }

    void PrintIntersectedNumbersInMatrix(int mat1[][3], int mat2[][3], short rows, short cols)
    {
        cout << "the intersected numbers in the two matrices are: ";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (Is_ExistsInMatrix(mat2, rows, cols, mat1[i][j]))
                {
                    printf("%d ", mat1[i][j]);
                }
            }
        }
    }

    bool is_plaindrome(int mat1[][3], short rows, short cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols / 2; j++)
            {
                if (mat1[i][j] != mat1[i][cols - 1 - j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    void PrintEqualityMatrixStatus(int mat1[][3], int mat2[][3], short rows, short cols)
    {
        if (is_Equality(mat1, mat2, 3, 3))
        {
            cout << "the matrices are equal." << endl;
        }
        else
        {
            cout << "the matrices are not equal." << endl;
        }
    }

    bool is_MatrixTypical(int mat1[][3], int mat2[][3], short rows, short cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (mat1[i][j] != mat2[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    void PrintTypicalStaus(int mat1[][3], int mat2[][3], short rows, short cols)
    {
        if (is_MatrixTypical(mat1, mat2, 3, 3))
        {
            cout << "the matrices are Typical." << endl;
        }
        else
        {
            cout << "the matrices are not Typical." << endl;
        }
    }

    bool is_sparseMatrix(int mat1[][3], short rows, short cols)
    {
        return (CountNumberInMatrix(mat1, rows, cols, 0) > MyLib::MatrixSize(mat1, rows, cols) / 2);
    }

    void PrintFibonacciSeries(int num)
    {
        int prev1 = 0, prev2 = 1, temp = 0;
        for (int i = 0; i < num; i++)
        {
            temp = prev2;
            cout << prev2 << " ";
            prev2 = prev2 + prev1;
            prev1 = temp;
        }
    }

    void RecPrintFibonacciSeries(int num, int prev1 = 0, int prev2 = 1)
    {
        if (num > 0)
        {
            int temp = prev2;
            cout << prev2 << " ";
            prev2 = prev2 + prev1;
            prev1 = temp;
            RecPrintFibonacciSeries(num - 1, prev1, prev2);
        }
    }

}

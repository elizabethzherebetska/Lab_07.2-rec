#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, int colNo) {
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < colCount - 1)
        CreateRow(a, rowNo, colCount, Low, High, colNo + 1);
}

void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo) {
    CreateRow(a, rowNo, colCount, Low, High, 0);
    if (rowNo < rowCount - 1)
        CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int colCount, int colNo) {
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < colCount - 1)
        PrintRow(a, rowNo, colCount, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int rowCount, const int colCount, int rowNo) {
    PrintRow(a, rowNo, colCount, 0);
    if (rowNo < rowCount - 1)
        PrintRows(a, rowCount, colCount, rowNo + 1);
    else
        cout << endl;
}

int FindMinInRow(int** a, const int rowNo, const int colCount, int colNo, int minVal) {
    if (a[rowNo][colNo] < minVal)
        minVal = a[rowNo][colNo];
    if (colNo < colCount - 1)
        return FindMinInRow(a, rowNo, colCount, colNo + 1, minVal);
    else
        return minVal;
}

int FindMinSumInOddRows(int** a, const int rowCount, const int colCount, int rowNo, int sum) {
    if (rowNo % 2 != 0) {
        int minInRow = FindMinInRow(a, rowNo, colCount, 0, a[rowNo][0]);
        sum += minInRow;
    }
    if (rowNo < rowCount - 1)
        return FindMinSumInOddRows(a, rowCount, colCount, rowNo + 1, sum);
    else
        return sum;
}

int main() {
    srand((unsigned)time(NULL));
    int Low = 1, High = 100;

    int rowCount, colCount;
    cout << "Enter count of rows (k): ";
    cin >> rowCount;
    cout << "Enter count of cols (n): ";
    cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];


    CreateRows(a, rowCount, colCount, Low, High, 0);


    PrintRows(a, rowCount, colCount, 0);

    int minSum = FindMinSumInOddRows(a, rowCount, colCount, 0, 0);
    cout << "Sum of minimum elements in odd rows: " << minSum << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

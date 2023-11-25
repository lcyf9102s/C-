#include <iostream>

// 函数接受二维指针和行列大小作为参数
void processArray(double** arr, int rows, int cols) {
    // const int rows = 2;
    // const int cols = 3;

    // 分配内存给二维数组
    double** mArray = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        mArray[i] = new double[cols];
    }

    // 初始化二维数组
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            mArray[i][j] = i * cols + j + 1;
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            mArray[i][j]=arr[i][j];
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << mArray[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < rows; ++i) {
        delete[] mArray[i];
    }
    delete[] mArray;
}

int main() {
    // const int rows = 2;
    // const int cols = 3;
    int rows;
    int cols;
    std::cin >> rows;
    std::cin >> cols;
    // 分配内存给二维数组
    double** myArray = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        myArray[i] = new double[cols];
    }

    // 初始化二维数组
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            myArray[i][j] = i * cols + j + 1;
        }
    }

    // 将二维指针传递给函数
    processArray(myArray, rows, cols);

    // 释放内存
    for (int i = 0; i < rows; ++i) {
        delete[] myArray[i];
    }
    delete[] myArray;

    return 0;
}

#include <expsample.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

// 线性内插值法：三组数据每组数据相邻两个之间等间距插入两个值
double** expsample::sample_Interpolation(double** sample_x, int row, int col)
{
    using namespace std;
//    const int row=rowv;
//    const int col=colv;
    int rows=row+(row-1)*2;
    int cols=col;


    double** dataI = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        dataI[i] = new double[cols];
    }

    // 初始化二维数组
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            dataI[i][j] = 0;
        }
    }

    int j=0;
    while (j<cols)
    {
        int i=0;
        while (i<rows-1)
        {
            dataI[i][j]=sample_x[(i+3)/3-1][j];
            dataI[i+3][j]=sample_x[(i+3)/3][j];
            if (dataI[i][j] > dataI[i+3][j])
            {
                dataI[i+1][j]=dataI[i+3][j]+2*(dataI[i][j]-dataI[i+3][j])/3;
                dataI[i+2][j]=dataI[i+3][j]+(dataI[i][j]-dataI[i+3][j])/3;
            }
            else
            {
                dataI[i+1][j]=dataI[i][j]+(dataI[i+3][j]-dataI[i][j])/3;
                dataI[i+2][j]=dataI[i][j]+2*(dataI[i+3][j]-dataI[i][j])/3;
            }
            i=i+3;
        }
        j=j+1;
    }

    for(int i=0;i<rows;i++)
    {
      for(int j=0;j<cols;j++)
      {
        cout << dataI[i][j] << "        ";
      }
      cout << endl;
    }

//    ofstream Output;
//    Output.open("output.dat");
//    for(int i=0;i<rows;i++)
//    {
//      for(int j=0;j<cols;j++)
//      {
//        Output << dataI[i][j] << ",";
//      }
//      Output << endl;
//    }


//    for (int i = 0; i < rows; ++i) {
//        delete[] dataI[i];
//    }
//    delete[] dataI;
    return dataI;
}



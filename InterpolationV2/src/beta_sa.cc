#include <expsample.h>
#include <iostream>
#include <fstream>
#include <cstdlib>

double** expsample::beta_sa(double** sam, int row, int col)
{
    using namespace std;
//    const int row=rowv;
//    const int col=colv;
    int rows=row+(row-1)*2-2;
    int cols=col;


    double** dataI = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        dataI[i] = new double[cols+1];
    }

    // 初始化二维数组
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols+1; ++j) {
            dataI[i][j] = 0;
        }
    }

    for(int j=0;j<cols;j++)
    {
        for(int i=0;i<rows;i++)
        {
            dataI[i][j]=sam[i+2-j][j];
        }
    }


    for(int i=0;i<rows;i++)
    {
        dataI[i][3]=(2*dataI[i][0])/(2*dataI[i][0]+dataI[i][1]-dataI[i][2]);
    }

    return dataI;
}
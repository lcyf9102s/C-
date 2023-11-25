#include <expsample.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

double** expsample::RSD_betaTH(double** sam, int row, int col)
{
    using namespace std;
//    const int row=rowv;
//    const int col=colv;
    int rows=row+(row-1)*2-2;
    int cols=col;


    double** dataI = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        dataI[i] = new double[cols+2];
    }

    // 初始化二维数组
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols+2; ++j) {
            dataI[i][j] = 0;
        }
    }

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols+1;j++)
        {
            dataI[i][j]=sam[i][j];
        }
    }

    for(int i=0;i<rows;i++)
    {
        dataI[i][4]=((dataI[i][3]/(2*dataI[i][0])))*sqrt(dataI[i][1]+dataI[i][2]+(pow((dataI[i][2]-dataI[i][1]),2))/dataI[i][0]);
    }

    ofstream Output;
    Output.open("output.dat");
    for(int i=0;i<rows;i++)
    {
      for(int j=0;j<cols+2;j++)
      {
        Output << dataI[i][j] << ",";
      }
      Output << endl;
    }
    return dataI;
}
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <expsample.h>
using namespace std;

int main(){
    using namespace std;
    int row;
    int col;
    cout << "please enter data rows : ";
    cin >> row;
    cout << "please enter data columns : ";
    cin >> col;
    cout << "-----------------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "output data :" << endl;
    cout << endl;
//    const int row_I=row+(row-1)*2;
    ifstream myInput;
    myInput.open("data1.dat");
    double** sample = new double*[row];
    for (int i = 0;i < row;++i)
    {
        sample[i] = new double[col];
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            sample[i][j] = 0;
        }
    }

    for (int i = 0; i<row ;++i)
    {
        for (int j = 0; j<col; ++j)
        {
            myInput >> sample[i][j];
            // std::cout<<a[i][j]<<" ";
        }
        // std::cout<<std::endl;
    }


    expsample exp1;
    double** Interpolation=exp1.sample_Interpolation(sample, row, col);
    double** beta = exp1.beta_sa(Interpolation, row, col);
    double** output = exp1.RSD_betaTH(beta, row, col);

    cout << "-------------------------------------------------------------------" << endl;
    cout << "-----------------同一时刻滤膜正面、反面、盖面的计数----------------------" << endl;
    for(int i=0;i<26;++i)
    {
      for(int j=0;j<5;++j)
      {
        cout << output[i][j] << "        ";
      }
      cout << endl;
    }
    return 0;
}
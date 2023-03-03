#include <iostream>
#include "Matrix.hpp"


//!тестовый код

int main()
{

    Matrix<int, 2, 0> mat;

    for(int i{0};i!=10;i++)
    {
        mat[i][i]=i;
        mat[i][9-i]=9-i;
    }

    std::cout<<"Matrix:"<<std::endl;

    for(int i{1};i!=9;i++)
    {
        for(int k{1};k!=9;k++)
        {
            std::cout<<mat[i][k]<<' ';
        }
        std::cout<<std::endl;
    }

    std::cout<<std::endl;

    std::cout<<"Size:"<<mat.size()<<std::endl<<std::endl;

    for(const auto& [ar,v]:mat)
    {
        std::cout<<"(["<<ar[0]<<','<<ar[1]<<"] -> "<<v<<") "<<std::endl;
    }


    //Optional
    Matrix<int, 5, 0> mat5;

    mat5[1][2][3][4][5]=12345;
    mat5[1][2][3][4][6]=12346;
    mat5[1][2][3][4][7]=12347;


//  test Dimension

//    mat5[1][2][3][4]=12347;
//    mat5[1][2][3][4][5][6]=12347;
//    int v;
//    v=mat5[1][2][3][4];
//    v=mat5[1][2][3][4][5][6];


    std::cout<<std::endl<<"---------------------------------------"<<std::endl;

    std::cout<<mat5[1][2][3][4][5]<<std::endl;
    std::cout<<mat5[1][2][3][4][6]<<std::endl;
    std::cout<<mat5[1][2][3][4][7]<<std::endl;
    std::cout<<mat5[1][2][3][4][8]<<std::endl<<std::endl;


    ((mat5[1][2][3][4][8] = 314) = 0) = 217;
    std::cout<<mat5[1][2][3][4][8]<<std::endl;

    return 0;
}

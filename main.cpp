#include <iostream>
#include <map>
#include "Matrix.hpp"



int main()
{
    Matrix<int, 3, -1> mat;

    mat[1][1][3]=222;
    auto var=mat[1][1][3];
    std::cout<<var;


//    std::array<int,2> k{1,1};

//    std::map<std::array<int,2>, int> tmap;

//    tmap[k]=123;
//    auto var2=tmap[k];

//    std::cout<<var2;
    return 0;
}

//avigael abitbol

#include<iostream>
#include<string>
#include "mat.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace ariel;

using namespace std;
namespace ariel{

    // Function to create the carpet
    string mat(int ec,int er,char char1,char char2)
    {
        /*  sr - starting row = 0
            er - ending row = er
            sc - starting column = 0
            ec - ending column = ec
            char1 - one of the char we want in our carpet
            char2 - the second char we want in our carpet
        */

       //check odd number
        if(ec%2==0){
                throw runtime_error("wrong input - colunm number needs to be odd");
            }
        if (er%2==0){
                throw runtime_error("wrong input - row number needs to be odd");
            }
        //check if the number is smaller then 0
        if(ec<0){
                throw runtime_error("worng input - column number needs to be grather than 0");
            }
        if(er<0){
                throw runtime_error("worng input - row number needs to be positive");
            }
        int i, sr = 0, sc = 0;
        // here - we save the number of row and collum given to transform the matrix to string
        int row = er, col = ec;
        // mat is where we built our matrix (-carpet) 
        char mat[er][ec];
        char c = char1; // c is the first char we will enter in our matrix\carpet and then we will change

        // Fill the matrix
        while (sr < er && sc < ec)
        {
            // Fill the first row 
            for (i = sc; i < ec; ++i){
                mat[sr][i] = c;
            }
            sr++;

            // Fill the last column 
            for (i = sr; i < er; ++i){
                mat[i][ec-1] = c;
            }
            ec--;

            // Fill the last row 
            if (sr < er)
            {
                for (i = ec-1; i >= sc; --i){
                    mat[er-1][i] = c;
                }
                er--;
            }

            // fill the first column 
            if (sc < ec)
            {
                for (i = er-1; i >= sr; --i){
                    mat[i][sc] = c;
                }
                sc++;
            }

            // Flip character for next iteration
            if (c == char2){
                c=char1;
            } 
            else {c = char2;}
        }
        // now we finished to fill the matrix
        // transform the matrix to string.
        string strMat;
        for (i = 0; i < row; i++){
                for (int j = 0; j < col; j++){
                    strMat += mat[i][j];
                }
                strMat += "\n";
            }
    return strMat;
    }
   
}

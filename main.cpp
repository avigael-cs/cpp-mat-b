#include "mat.hpp"
#include "mat.cpp"
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	cout << ariel::mat(13, 3, '$', '*') << endl;
    
    /* 
    $$$$$$$$$$$$$
    $***********$
    $$$$$$$$$$$$$
    */
    cout << ariel::mat(5, 5, '8', '*') << endl;
    //error - even number
    cout << ariel::mat(5, 8, '$', '@') << endl;
    cout << ariel::mat(4, 5, '&', '*') << endl;
    //number=0
    cout << ariel::mat(9, 0, '#', '5') << endl;
}
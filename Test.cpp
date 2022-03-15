/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Avigael Abitbol>
 * 
 * Date: 2021-03-07
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good input")
{
    CHECK(nospaces(mat(3, 3, '&', '-')) == nospaces("&&&\n"
                                                   "&-&\n"
                                                   "&&&"));

    CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));

    CHECK(nospaces(mat(5,7,'@','-')) == nospaces("@@@@@\n"
					        					  "@---@\n"
     					        				  "@-@-@\n"
												  "@-@-@\n"
												  "@-@-@\n"
												  "@---@\n"
												  "@@@@@"));

    CHECK(nospaces(mat(3, 1, '+', '0')) == nospaces("+++"));
    
    CHECK(nospaces(mat(13, 3, '$', '*')) == nospaces("$$$$$$$$$$$$$\n"
                                                     "$***********$\n"
                                                     "$$$$$$$$$$$$$"));
    CHECK(nospaces(mat(9, 3, '$', '@')) == nospaces("888888888\n"
                                                    "8@@@@@@@8\n"
                                                    "888888888"));
    CHECK(nospaces(mat(3,5,'$','+')) == nospaces("$$$\n"
					    	  "$+$\n"
						  "$+$\n"
						  "$+$\n"
						  "$$$"));

    CHECK(nospaces(mat(1,1,'#','#')) == nospaces("#"));
    
}
TEST_CASE("Bad input")
{
    //even number and bad input
    CHECK_THROWS(mat(10,5,'$','%'));
    CHECK_THROWS(mat(10,8,'$','%'));
    //negative number
    CHECK_THROWS(mat(-6,6,'%','$'));
    CHECK_THROWS(mat(-6,-9,'%','$'));
    //number = 0
    CHECK_THROWS(mat(0,0,'#','$'));
    //negative number
    CHECK_THROWS(mat(5,-8,'^','$'));
    //even and negative number
    CHECK_THROWS(mat(-6,-8,'#','$'));
    //even number
    CHECK_THROWS(mat(6,8,'#','$'));
    CHECK_THROWS(mat(4,'3','*','$'));
    //even number and 0
    CHECK_THROWS(mat(4,'0','*','$'));
	CHECK_THROWS(mat(5,2,'*','$'));
	CHECK_THROWS(mat(6,3,'*','$'));
	CHECK_THROWS(mat(4,1,'*','$'));
	CHECK_THROWS(mat(8,3,'*','$'));
	CHECK_THROWS(mat(9,6,'*','$'));
	CHECK_THROWS(mat(7,4,'*','$'));
}

#include "doctest.h"
#include "Direction.hpp"
#include "Board.hpp"
using ariel::Direction;

#include <algorithm>
using namespace std;





// test for post
ariel::Board board;

TEST_CASE("clean boeard") { // 2 test_case
    CHECK(board.read(0,0,Direction::Horizontal,3) == "___"); // no input post yet
    CHECK(board.read(0,0,Direction::Vertical,3) == "___"); // no input post yet
};

TEST_CASE("Horizontal test") {// 5 test_case
	board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "abcd");
        CHECK(board.read(100,200,Direction::Horizontal,4) == "abcd");
        CHECK(board.read(100,199,Direction::Horizontal,6) == "_abcd_");

	board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "xy");
        CHECK(board.read(100,200,Direction::Horizontal,4) == "xycd");
        CHECK(board.read(100,199,Direction::Horizontal,6) == "_xycd_");
	
    board.post(/*row=*/100, /*column=*/205, Direction::Horizontal, "ofir");
        CHECK(board.read(100,199,Direction::Horizontal,11) == "_xycd_ofir_");

};
TEST_CASE("Vertical test") { // 10 test_case
        CHECK(board.read(99,199,Direction::Vertical,6) ==  "______");
        CHECK(board.read(100,200,Direction::Vertical,6) == "x_____");
        CHECK(board.read(100,201,Direction::Vertical,6) == "y_____");
        CHECK(board.read(100,202,Direction::Vertical,6) == "c_____");
        CHECK(board.read(100,203,Direction::Vertical,6) == "d_____");
        CHECK(board.read(99,200,Direction::Vertical,6) == "_x____");
        CHECK(board.read(99,201,Direction::Vertical,6) ==  "_y____");
        CHECK(board.read(99,202,Direction::Vertical,6) ==  "_c____");
        CHECK(board.read(99,203,Direction::Vertical,6) ==  "_d____");
        CHECK(board.read(99,204,Direction::Vertical,6) ==  "______");

};
TEST_CASE("Vertical and Horizontal") {// 3 test_case

	board.post(/*row=*/100, /*column=*/206, Direction::Vertical, "magen");
        CHECK(board.read(99,206,Direction::Vertical,7) ==  "_magen_");
    
    board.post(/*row=*/100, /*column=*/207, Direction::Vertical, "enum");
        CHECK(board.read(99,207,Direction::Vertical,7) ==  "_enum__");
        CHECK(board.read(100,199,Direction::Horizontal,11) == "_xycd_omer_");

};

TEST_CASE("Vertical and Horizontal edges") {

// need to add circulating (board size (2,3) -> read from (0,0) to (0,2*length))
// need to add circulating (board size (2,3) -> read from (0,0) to (2*length,0))
// need to add circulating (board size (2,3) -> read from (0,0) to (max_int + 1,0))
// need to add circulating (board size (2,3) -> read from (0,0) to (0,max_int + 1))


};

TEST_CASE("not good input"){

   // CHECK_THROWS(true);
};



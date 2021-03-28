/**
 * AUTHOR: I M
 * 
 * Date: 03/09/21
 */

#include "doctest.h"
#include "Direction.hpp"
#include "Board.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;



TEST_CASE("GOOD INPUT") { // 

    Board board;
    //INPUT CHECK:

    // 1) POST 
    CHECK_NOTHROW(board.post(100, 200, Direction::Horizontal, "abcd"));
    CHECK_NOTHROW(board.post(100, 200, Direction::Vertical, "abcd"));
    CHECK_NOTHROW(board.post(100, 200, Direction::Horizontal, ""));
    CHECK_NOTHROW(board.post(100, 200, Direction::Vertical, ""));

    CHECK_NOTHROW(board.post(100, 200, Direction::Horizontal, "abcd"));
    CHECK_NOTHROW(board.post(100, 200, Direction::Vertical, "abcd"));
    CHECK_NOTHROW(board.post(100, 200, Direction::Horizontal, ""));
    CHECK_NOTHROW(board.post(100, 200, Direction::Vertical, ""));

    CHECK_NOTHROW(board.post(100, 200, Direction::Horizontal, "abcd"));
    CHECK_NOTHROW(board.post(100, 200, Direction::Vertical, "abcd"));
    CHECK_NOTHROW(board.post(100, 200, Direction::Horizontal, ""));
    CHECK_NOTHROW(board.post(100, 200, Direction::Vertical, ""));

    CHECK_NOTHROW(board.post(100, 200, Direction::Horizontal, "abcd"));
    CHECK_NOTHROW(board.post(100, 200, Direction::Vertical, "abcd"));
    CHECK_NOTHROW(board.post(100, 200, Direction::Horizontal, ""));
    CHECK_NOTHROW(board.post(100, 200, Direction::Vertical, ""));

    // 2) READ
    CHECK_NOTHROW(board.read(10, 10, Direction::Horizontal, 10));
    CHECK_NOTHROW(board.read(10, 10, Direction::Vertical, 10));

    // 3) SHOW
    CHECK_NOTHROW(board.show());

    //OUTPUT CHECK
    Board board1;
    CHECK(board1.read(0, 0, Direction::Horizontal, 0) == "");   
    CHECK(board1.read(0, 0, Direction::Vertical, 0) == "");



}

TEST_CASE("BAD INPUT") {

    Board board;

    //POST check
    CHECK_THROWS(board.post(100, 200, Direction::Horizontal, "abcd"));
    CHECK_THROWS(board.post(100, 200, Direction::Horizontal, "abcd"));

    CHECK_THROWS(board.post(100, 200, Direction::Vertical, "abcd"));
    CHECK_THROWS(board.post(100, 200, Direction::Vertical, "abcd"));

    //READ check
    CHECK_THROWS(board.read(10, 10, Direction::Horizontal, 10));
    CHECK_THROWS(board.read(10, 10, Direction::Horizontal, 10));

    CHECK_THROWS(board.read(10, 10, Direction::Vertical, 10));
    CHECK_THROWS(board.read(10, 10, Direction::Vertical, 10));

    CHECK_THROWS(board.read(10, 10, Direction::Horizontal, 10));
    CHECK_THROWS(board.read(10, 10, Direction::Vertical, 10));

}
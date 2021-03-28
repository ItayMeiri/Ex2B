#include "Board.hpp"
#include <iostream>
#include <vector>
const unsigned int DEFAULT_SIZE = 10L;

namespace ariel {
Board::Board() {
  col_size = DEFAULT_SIZE;
  row_size = DEFAULT_SIZE;
}

// Post on the board
void Board::post(unsigned int row, unsigned int col, Direction direction,
                 std::string msg) {
  if (msg.empty()) {
    return;
  }
  size_t counter = 0;
  if (direction == Direction::Vertical) {
    if (row + msg.length() > row_size) {
      row_size = row + msg.length();
    }
    if (col > col_size) {
      col_size = col;
    }
    for (size_t i = row; i < row + msg.length(); i++) {
      board[i][col] = msg.at(counter);
      counter++;
    }
  } else {
    if (row > row_size) {
      row_size = row;
    }
    if (col + msg.length() > col_size) {
      col_size = col + msg.length();
    }
    for (size_t i = col; i < col + msg.length(); i++) {
      board[row][i] = msg.at(counter);
      counter++;
    }
  }
}

// Show the entire board
void Board::show() {
  for (size_t i = 0; i <= row_size; i++) {
    for (size_t j = 0; j <= col_size; j++) {
      // key not found for entire row, print "_"
      if(board.find(i) != board.end()) {
        if(board.at(i).find(j) != board.at(i).end())
        {
          std::cout << board[i][j];
        }
        else
        {
          std::cout << "_";
        }
      } else {
        std::cout << "_";
      }
    }
    std::cout << "\n"; // end row
  }
}

// Read a part of the board
std::string Board::read(unsigned int row, unsigned int col, Direction direction,
                        unsigned int length) {
  std::string str;
  if (direction == Direction::Vertical) {
    for (unsigned int i = 0; i < length; i++) {
      // the row is within range
      if (board.find(row + i) != board.end()) {
        // the col is within range
        if (board.at(row + i).find(col) != board.at(row + i).end()) {
          str += board.at(row + i).at(col);
        } else {
          str += "_";
        }
      }
      else {      
        str += "_";}
    }

  } else {
    for (unsigned int  i = 0; i < length; i++) {
      // the row is within range
      if (board.find(row) != board.end()) {
        // the col is within range
        if (board.at(row).find(col + i) != board.at(row).end()) {
          str += board.at(row).at(col + i);
        } else {
          str += "_";
        }
      }
      else{
      str += "_";
      }
    }
  }

  return str;
}
Board::~Board() {}
} // namespace ariel
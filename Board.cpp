//
// Created by shahak on 10/06/2021.
//

#include "Board.hpp"
const int num10 = 10;
const int num54 = 54;

/**
 * set the board according to the adds that was added
 * @param board
 * @param row
 * @param column
 * @param msg_size
 */
void set_board_limits_4show(ariel::Board* board, uint row, uint column, uint msg_size){
    board->startColumn = std::min(board->startColumn, column);
    board->startRow = std::min(board->startRow, row);
    board->endColumn = std::max(board->endColumn, column);
    board->endRow = std::max(board->endRow, row);
}

/**
 * Receiving a String with spaces for arrows in the column
 * @param max_col
 * @return
 */
std::string col_spaces_4show(uint max_col){
    std::string result = " ";
    while (max_col > 0){
        max_col /= num10;
        result += " ";
    }
    return result;
}


/**
 * Receiving a String with spaces for arrows in the colomn
 * @param: max_columns - A number that represents the number of columns
 * @return: result - String with spaces
 */
std::string spaces_for_arrows(uint num){
    std::string str = std::to_string(num);
    std::string result = " ";
    for (size_t i = 0; i < str.size()/2; i++){
        result += " ";
    }
    return result;
}



namespace ariel{
    /**
     * Post a message on the board
     * @param row
     * @param column
     * @param direction
     * @param msg
     */
    void Board::post(uint row, uint column, Direction direction, std::string msg){
        if(row-1 != 0){
            this->boardMat[row-1][column].c = '_';
        }
        if(column-1 != 0){
            this->boardMat[row][column-1].c = '_';
        }
        for(char c : msg){
            this->boardMat[row][column].c = c;
            if(direction == ariel::Direction::Horizontal){
                ++column;
            }else{
                row++;
            }

        }
        set_board_limits_4show(this, row, column, msg.length());
    }

    /**
     *
     * @param row
     * @param column
     * @param direction
     * @param length
     * @return result
     */
    std::string Board::read(uint row, uint column, Direction direction, uint length) {
        std::string result;
        for (int i = 0; i < length; ++i) {
            result += this->boardMat[row][column].c;
            if(direction == ariel::Direction::Vertical){
                row++;
            }else
                column++;
        }
        return result;
    }

    /**
     * Shows the full Message Board
     */
    void Board::show(){
        uint row_index = this->startRow, col_index = this->startColumn,
            max_row = this->endRow, max_col = this->endColumn;
        std::string space4num = spaces_for_arrows(max_col);
        std::string max_space4num = col_spaces_4show(max_col);

        if(max_col > num54){
            for (uint row = row_index; row < max_row; ++row) {
                for (uint column = col_index; column < max_col; ++column) {
                    std::cout << this->boardMat[row][column].c << " ";
                }
                std::cout << "← " << "\n";
            }
        }else{
            for (uint col = 0; col < max_col; col++) {
                std::cout << col << max_space4num;
            }
            std::cout << "\n";
            for (uint col = col_index; col < max_col; col++) {
                std::cout << "↓" << max_space4num;
            }
            std::cout << "\n\n";

            for (uint row = row_index; row < max_row; row++) {
                for (uint col = col_index; col < max_col; col++) {
                    std::cout << this->boardMat[row][col].c << max_space4num;
                }
                std::cout << "← " << row << "\n";
            }
        }

    }


}

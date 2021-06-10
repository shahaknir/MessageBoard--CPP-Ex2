//
// Created by shahak on 10/06/2021.
//

#pragma once
#include <iostream>
#include <stdexcept>
#include <map>
#include "Direction.hpp"


#ifndef EX2_PA_BOARD_HPP
#define EX2_PA_BOARD_HPP




/**
 * Represent a single char node
 * @param letter = one char
 */
struct Char{
    char c = '_';
};

namespace ariel{
    class Board {
        const int num10 = 10;
        const int num54 = 54;
    public:
        std::map<uint, std::map<uint, Char>> boardMat;
        /**
         * @param endRow, endColumn = 0
         *          therefore we can adjacent them easily with std::max
         * @param startRow, startColumn = UINT32_MAX
         *          therefore we can adjacent them easily with std::min
         */
        uint endRow = 0, endColumn = 0, startColumn = UINT32_MAX, startRow = UINT32_MAX;

        /**
         * Post a message on the board
         * @param row
         * @param column
         * @param direction
         * @param msg
         */
        void post(uint row, uint column, Direction direction, std::string msg);

        /**
         *
         * @param row
         * @param column
         * @param direction
         * @param length
         * @return
         */
        std::string read(uint row, uint column, Direction direction, uint length);

        /**
         * Shows the full Message Board
         */
        void show();


    };
}



#endif //EX2_PA_BOARD_HPP

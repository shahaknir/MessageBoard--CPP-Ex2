//
// Created by shahak on 10/06/2021.
//

#include "Direction.hpp"
#include "Board.hpp"
#include "doctest.h"
#include <random>

const int maxMsg = 150;
const int maxRows = UINT8_MAX*10;
const int maxColums = UINT8_MAX*10;
const int maxChar = 122;
std::uniform_int_distribution<int> dist_char(65, maxChar);

std::random_device random_engine;
std::uniform_int_distribution<int> dist_msg_size(0, maxMsg);

std::uniform_int_distribution<int> dist_msg_row(0, maxRows);

std::uniform_int_distribution<int> dist_msg_col(0, maxColums);


/**
 * The next functions are for randomize Messages:
 */

/**
 * Generate a random msg size and a random message
 * @return
 */
std::string get_random_msg(){
    std::string msg;
    uint msg_size = (uint)dist_msg_size(random_engine);

    for (int i = 0; i < msg_size; ++i) {
        msg += static_cast<char>(dist_char(random_engine));
    }
    return msg;
}

/**
 * Genrate a random message in the size of msg_size
 * @param msg_size
 * @return msg
 */

std::string msg_size_given(uint msg_size){
    std::string msg;
    for (int i = 0; i < msg_size; ++i) {
        msg += static_cast<char>(dist_char(random_engine));
    }
    return msg;
}

/**
 * Get a message with size and symbol known
 * @param msg_size <=maxMsg
 * @param c
 * @return msg
 */
std::string msg_size_val_given(uint msg_size, char c){
    std::string msg;
    for (int i = 0; i < msg_size; ++i) {
        msg += c;
    }
    return msg;
}


/**
 * First test - try to read a message that WASN'T inserted to the Board
 */
TEST_CASE("Test No.1: check an empty board"){
    ariel::Board b;
    ariel::Direction direction;
    for (uint i = 0; i < 20; ++i) {
        uint row = (uint)dist_msg_row(random_engine);
        uint col = (uint)dist_msg_col(random_engine);
        direction = (rand()%2 == 1)? ariel::Direction::Vertical : ariel::Direction::Horizontal;
        std::string msg = get_random_msg();

        CHECK(b.read(row, col, direction, msg.length()) != msg);
    }

}

TEST_CASE("Test No.2: check insertion to the Board"){
    ariel::Board b;
    ariel::Direction direction;
    for (uint i = 0; i < 20; ++i) {
        uint row = (uint) dist_msg_row(random_engine);
        uint col = (uint) dist_msg_col(random_engine);
        uint msg_size = (uint) dist_msg_size(random_engine);
        direction = (rand() % 2 == 1) ? ariel::Direction::Vertical : ariel::Direction::Horizontal;
        std::string msg = get_random_msg();
        b.post(row, col, direction, msg);

        CHECK_EQ(b.read(row, col, direction, msg.length()), msg);
    }

}

TEST_CASE("Test No.3: Over writing a message on top another"){
    ariel::Board b;
    ariel::Direction direction;
    std::string msg1, msg2;

    for (uint i = 0; i < 20; ++i) {
        uint row = (uint) dist_msg_row(random_engine);
        uint col = (uint) dist_msg_col(random_engine);
        uint msg_size = (uint) dist_msg_size(random_engine);
        direction = (rand() % 2 == 1) ? ariel::Direction::Vertical : ariel::Direction::Horizontal;
        msg1 = msg_size_given(msg_size);
        b.post(row, col, direction, msg1);

        msg2 = msg_size_given(msg_size);
        b.post(row, col, direction, msg2);
        CHECK(b.read(row, col, direction, msg_size) != msg1);
        CHECK_EQ(b.read(row, col, direction, msg_size) , msg2);

    }

    std::string str1 = "abba", str2 = "hgkjlfdbfnk";
    ariel::Board b1;
    b1.post(1,12, ariel::Direction::Horizontal, str1);
    b1.post(2, 0, ariel::Direction::Vertical, str2);
    b1.show();
}


#include <iostream>
#include "Direction.hpp"
#include "Board.hpp"




int main() {
    std::cout << "Hello, World!" << std::endl;
//    std::string str1 = "abba",
//                    str2 = "hgkjlfdbfnk";
//    ariel::Board b;
//    b.post(1,12, ariel::Direction::Horizontal, str1);
//    b.post(2, 0, ariel::Direction::Vertical, str2);
//    b.show();

    ariel::Board board;
    board.post(/*row=*/100, /*column=*/200, ariel::Direction::Horizontal, "abcd");
    std::cout << board.read(/*row=*/99, /*column=*/201, ariel::Direction::Vertical, /*length=*/3) << std::endl;
    // prints "_b_" (starts at row 99 which is empty; then at row 100 there is "b"; then row 101 is empty again).
    board.post(/*row=*/99, /*column=*/202, ariel::Direction::Vertical, "xyz");
    std::cout << board.read(/*row=*/100, /*column=*/200, ariel::Direction::Horizontal, /*length=*/6) << std::endl;
    // prints "abyd__" (First letters are ab; then y from the "xyz"; then d; then two empty cells).

    board.show(); // shows the board in a reasonable way. For example:
    //    98:  _________
    //    99:  ____x____
    //    100: __abyd___
    //    101: ____z____
    //    102: _________

    return 0;
}

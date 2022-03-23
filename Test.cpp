#include "doctest.h"
#include "Direction.hpp"
#include "Notebook.hpp"
#include <string>
using namespace ariel;
using namespace std;

TEST_CASE("good inputs")
{
    Notebook notebook;
    /* writing into the notebook */
    CHECK_NOTHROW(notebook.write(0, 0, 0, Direction::Horizontal, "hello_everybody"));
    CHECK_NOTHROW(notebook.write(0, 1, 0, Direction::Horizontal, "goodbye"));
    CHECK_NOTHROW(notebook.write(1, 3, 3, Direction::Horizontal, "*****"));
    CHECK_NOTHROW(notebook.write(1, 4, 3, Direction::Vertical, "***"));
    CHECK_NOTHROW(notebook.write(1, 7, 3, Direction::Horizontal, "*****"));
    CHECK_NOTHROW(notebook.write(1, 4, 7, Direction::Vertical, "***"));

    /* reading from the notebook */
    CHECK(notebook.read(0, 0, 6, Direction::Horizontal, 5) == "every");
    CHECK(notebook.read(0, 1, 0, Direction::Horizontal, 4) == "good");
    CHECK(notebook.read(1, 3, 5, Direction::Vertical, 5) == "*___*");
}

TEST_CASE("bad input")

{
    Notebook notebook;

    /* invalid numbers - negetiv page/row/col numbers */
    CHECK_THROWS(notebook.write(-1, 0, 0, Direction::Horizontal, "hello_everybody"));
    CHECK_THROWS(notebook.write(3, -2, 0, Direction::Horizontal, "hello_everybody"));
    CHECK_THROWS(notebook.write(4, 1, -7, Direction::Vertical, "goodbye"));
    CHECK_THROWS(notebook.write(-3, -5, -7, Direction::Horizontal, "welcome"));
    CHECK_THROWS(notebook.write(6, 1, 4, Direction::Horizontal, "Ex2_part1"));
    CHECK_THROWS(notebook.read(-1, 0, 0, Direction::Vertical, 44));
    CHECK_THROWS(notebook.read(3, -6, 0, Direction::Horizontal, 12));
    CHECK_THROWS(notebook.read(9, 1, -14, Direction::Vertical, 3));
    CHECK_THROWS(notebook.read(-3, -5, -7, Direction::Horizontal, 1));
    CHECK_THROWS(notebook.erase(6, 1, 4, Direction::Vertical, 9));
    CHECK_THROWS(notebook.erase(-10, 3, 0, Direction::Horizontal, 2));
    CHECK_THROWS(notebook.erase(3, -2, 0, Direction::Horizontal, 7));
    CHECK_THROWS(notebook.erase(99, 40, -12, Direction::Vertical, 4));
    CHECK_THROWS(notebook.show(-8));
    CHECK_THROWS(notebook.show(-4));

    /* invalid numbers - larger then the actuall size of the row */
    CHECK_THROWS(notebook.write(0, 0, 110, Direction::Horizontal, "******"));
    CHECK_THROWS(notebook.write(3, 4, 96, Direction::Horizontal, "1+1=2!"));
    CHECK_THROWS(notebook.read(1, 0, 200, Direction::Vertical, 1));
    CHECK_THROWS(notebook.read(3, 6, 80, Direction::Horizontal, 21));
    CHECK_THROWS(notebook.erase(3, 2, 90, Direction::Horizontal, 13));
    CHECK_THROWS(notebook.erase(99, 40, 110, Direction::Vertical, 100));

    /* invalid chars - can't add the delete char to the notebook */
    CHECK_THROWS(notebook.write(1, 6, 17, Direction::Horizontal, "~~"));
    CHECK_THROWS(notebook.write(2, 4, 33, Direction::Horizontal, "~~~~~~"));
}

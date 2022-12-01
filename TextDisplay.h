#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_

#include "Board.h"

class TextDisplay {
private:
    Board *board; // holds game board

public:
    TextDisplay(Board *board); // constructor

    void printBoard(); // prints board as text
};

#endif


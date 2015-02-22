/*!
 *  @file       Matrix8x8.cpp
 *  Project     Arduino Matrix Library
 *  @version    1.0
 *  @author     Alejandro Simon
 *  @date       22/02/15
 *  @license    MIT - http://opensource.org/licenses/MIT
 */

#include "Matrix8x8.h"

// -----------------------------------------------------------------------------

/*! \brief Contructor.
 Main constructor of the Matrix class
 */
Matrix8x8::Matrix8x8() {
    // Setup pins
    for (int i = 0; i < MAX; i++ ) {
        pinMode(ROWS[i], OUTPUT);
        pinMode(COLS[i], OUTPUT);
    }
    // Reset
    turnOff();
}

/*! \brief Turn Off matrix.
 Turns off all the LEDS in the matrix
 */
void Matrix8x8::turnOff() {
    for (int i = 0; i < MAX; i++ ) {
        digitalWrite(ROWS[i], LOW);
    }
}

/*! \brief Turn On matrix.
 Turns on all the LEDS in the matrix
 */
void Matrix8x8::turnOn() {
    for (int i = 0; i < MAX; i++ ) {
        digitalWrite(ROWS[i], HIGH);
    }
}

/*! \brief Draw a dot
 Draws a morse dot  
 \param waitTime the amount of drawing time
 */
void Matrix8x8::dot(int waitTime) {
    for (int i=0; i<waitTime; i++) {
        displaySymbol(42);
    }
    turnOff();
    delay(waitTime);
}

/*! \brief Draw a dash
 Draws a morse dash
 \param waitTime the amount of drawing time
 */
void Matrix8x8::dash(int waitTime) {
    for (int i=0; i<waitTime; i++) {
        displaySymbol(43);
    }
    turnOff();
    delay(waitTime);
}

/*! \brief Draws a symbol on the matrix board
 Draws a given character during a given time
 \param symbol the character to be drawn
 \param waitTime the amount of drawing time
 */
void Matrix8x8::printSymbol(char symbol, int waitTime) {
    int id = charToSymbol(symbol);
    for (int i=0; i<waitTime; i++) {
        displaySymbol(id);
    }
}

/*! \brief Draws a integer on the matrix board
 Draws a given integer during a given time
 \param number the integer to be drawn
 \param waitTime the amount of drawing time
 */
void Matrix8x8::printNumber(int number, int waitTime) {
    int id = intToSymbol(number);
    for (int i=0; i<waitTime; i++) {
        displaySymbol(id);
    }
}

// -----------------------------------------------------------------------------

/*! \brief Character to symbol
 Returns the id of a given character
 \param c the character which ID will be calculated
 \return integer as the ID of the symbol in the matrix
 */
int Matrix8x8::charToSymbol(char c) {
    switch(c) {
        // Letters
        case 'a': case 'A': return 1; 
        case 'b': case 'B': return 2;
        case 'c': case 'C': return 3;
        case 'd': case 'D': return 4;
        case 'e': case 'E': return 5;
        case 'f': case 'F': return 6;
        case 'g': case 'G': return 7;
        case 'h': case 'H': return 8;
        case 'i': case 'I': return 9;
        case 'j': case 'J': return 10;
        case 'k': case 'K': return 11;
        case 'l': case 'L': return 12;
        case 'm': case 'M': return 13;
        case 'n': case 'N': return 14;
        case 'o': case 'O': return 15;
        case 'p': case 'P': return 16;
        case 'q': case 'Q': return 17;
        case 'r': case 'R': return 18;
        case 's': case 'S': return 19;
        case 't': case 'T': return 20;
        case 'u': case 'U': return 21;
        case 'v': case 'V': return 22;
        case 'w': case 'W': return 23;
        case 'x': case 'X': return 24;
        case 'y': case 'Y': return 25;
        case 'z': case 'Z': return 26;
        // Numbers
        case '0': return 27;
        case '1': return 28;
        case '2': return 29;
        case '3': return 30;
        case '4': return 31;
        case '5': return 32;
        case '6': return 33;
        case '7': return 34;
        case '8': return 35;
        case '9': return 36;
        // Symbols
        case '.': return 37;
        case '!': return 38;
        case '?': return 39;
        case '<': return 40;
        case '>': return 41;
        default: return 0;
    }
}

/*! \brief Integer to symbol
 Returns the id of a given integer
 \param n the integer which ID will be calculated
 \return integer as the ID of the symbol in the matrix
 */
int Matrix8x8::intToSymbol(int n) {
    switch(n) {
        case 0: return 27;
        case 1: return 28;
        case 2: return 29;
        case 3: return 30;
        case 4: return 31;
        case 5: return 32;
        case 6: return 33;
        case 7: return 34;
        case 8: return 35;
        case 9: return 36;
        //
        default: return 0;
    }
}

/*! \brief Draws a symbol on the board
 Draws a symbol given it's ID
 \param symbolID the ID of the symbol to  be drawn
 */
void Matrix8x8::displaySymbol(int symbolID)
{
  for (int colNum=0; colNum<8; colNum++)
  {
    byte rowNum = S_LIST[symbolID][colNum];
    byte tmp = rowNum;
    // Turn off rows
    for (int i = 0; i < MAX; i++ ) {
        digitalWrite(ROWS[i], LOW);
    }
    // Turn off cols
    for (int i = 0; i < MAX; i++ ) {
        digitalWrite(COLS[i], HIGH);
    }
    // Display column
    digitalWrite(COLS[colNum], LOW);
    // Display row
    for(int r=0; r<MAX; r++) {
        tmp = (0x40)&(tmp);
        if (tmp == 0) {
          tmp = rowNum<<r;
          continue;
        }
        digitalWrite(ROWS[r], HIGH);
        tmp = rowNum<<r;
    }
  }
}

// -----------------------------------------------------------------------------

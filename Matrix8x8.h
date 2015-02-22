/*!
 *  @file       Matrix8x8.h
 *  Project     Arduino Matrix Library
 *  @version    1.0
 *  @author     Alejandro Simon
 *  @date       22/02/15
 *  @license    MIT - http://opensource.org/licenses/MIT
 */

#ifndef Matrix8x8_h
#define Matrix8x8_h

#include "Matrix8x8_Defs.h"

// -----------------------------------------------------------------------------

class Matrix8x8 {

public:
    Matrix8x8();
    void turnOff();
    void turnOn();
    void printSymbol(char symbol, int waitTime);
    void printNumber(int number, int waitTime);
    void dot(int waitTime);
    void dash(int waitTime);
private:
    int charToSymbol(char c);
    int intToSymbol(int n);
    void displaySymbol(int symbolID);

    const int ROWS[MAX] = {2, 3, 4, 5, 17, 16, 15, 14};
    const int COLS[MAX] = {6, 7, 8, 9, 10, 11, 12, 13};

    const byte S_LIST[MAX_SYMBOLS][MAX] = {
        {symbol_NULL}, 
        {symbol_A}, {symbol_B}, {symbol_C}, {symbol_D},
        {symbol_E}, {symbol_F}, {symbol_G}, {symbol_H},
        {symbol_I}, {symbol_J}, {symbol_K}, {symbol_L},
        {symbol_M}, {symbol_N}, {symbol_O}, {symbol_P},
        {symbol_Q}, {symbol_R}, {symbol_S}, {symbol_T},
        {symbol_U}, {symbol_V}, {symbol_W}, {symbol_X},
        {symbol_Y}, {symbol_Z},
        {symbol_0}, {symbol_1}, {symbol_2}, {symbol_3},
        {symbol_4}, {symbol_5}, {symbol_6}, {symbol_7},
        {symbol_8}, {symbol_9},
        {symbol_DOT}, {symbol_EXC}, {symbol_QUE},
        {symbol_LAR}, {symbol_RAR}, 
        {symbol_SQA}, {symbol_DASH}
    };
};

// -----------------------------------------------------------------------------

#endif
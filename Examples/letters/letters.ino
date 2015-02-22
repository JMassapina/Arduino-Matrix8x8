/*
 *  @file       letters.ino
 *  Project     Arduino Matrix Library
 *  @version    1.0
 *  @author     Alejandro Simon
 *  @date       22/02/15
 *  @license    MIT - http://opensource.org/licenses/MIT
 */

#include <Matrix8x8.h>

Matrix8x8 matrix;
const int waitTime = 1000;
const int MAX_LETTERS = 31;
const char letters[MAX_LETTERS] = {
  'a', 'b', 'c', 'd', 'e',
  'f', 'g', 'h', 'i', 'j',
  'k', 'l', 'm', 'n', 'o',
  'p', 'q', 'r', 's', 't',
  'u', 'v', 'w', 'x', 'y', 
  'z', '.', '!', '?', '<', '>' };

void setup() {
}

void loop() {
  for (int i=0; i<MAX_LETTERS; i++) {
      matrix.printSymbol(letters[i], waitTime);
  }
}

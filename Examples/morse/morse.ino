/*
 *  @file       morse.ino
 *  Project     Arduino Matrix Library
 *  @version    1.0
 *  @author     Alejandro Simon
 *  @date       22/02/15
 *  @license    MIT - http://opensource.org/licenses/MIT
 */

#include <Matrix8x8.h>

Matrix8x8 matrix;
const int WAIT = 500;

void setup() {
}

void loop() {
  // S
  matrix.dot(WAIT); matrix.dot(WAIT); matrix.dot(WAIT);
  // O
  matrix.dash(WAIT); matrix.dash(WAIT); matrix.dash(WAIT);
  // S
  matrix.dot(WAIT); matrix.dot(WAIT); matrix.dot(WAIT);
  // Reset
  matrix.turnOff();
  delay(1000);
}

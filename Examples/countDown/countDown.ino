/*
 *  @file       countDown.ino
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
  for (int i=0; i<10; i++) {
  	matrix.printNumber(i, WAIT);
  	matrix.turnOff();
  	delay(500);
  }
}

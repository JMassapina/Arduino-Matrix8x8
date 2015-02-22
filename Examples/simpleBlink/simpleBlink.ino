/*
 *  @file       simpleBlink.ino
 *  Project     Arduino Matrix Library
 *  @version    1.0
 *  @author     Alejandro Simon
 *  @date       22/02/15
 *  @license    MIT - http://opensource.org/licenses/MIT
 */

#include <Matrix8x8.h>

Matrix8x8 matrix;

void setup() {
}

void loop() {
  matrix.turnOff();
  delay(500);
  matrix.turnOn();
  delay(500);
}

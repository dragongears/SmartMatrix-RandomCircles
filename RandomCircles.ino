/*
 * SmartMatrix Random Circles
 * A program that displays random expanding circles for the Teensy 3.1 and SmartMatrix Shield.
 *
 * Copyright (c) 2014 Art Dahm (art@dahm.com)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <SmartMatrix_32x32.h>

SmartMatrix matrix;

const int defaultBrightness = 100*(255/100);    // full brightness
//const int defaultBrightness = 15*(255/100);    // dim: 15% brightness
const rgb24 defaultBackgroundColor = {0, 0, 0};

// Teensy 3.1 has the LED on pin 13
const int ledPin = 13;

// the setup() method runs once, when the sketch starts
void setup() {
    // initialize the digital pin as an output.
    pinMode(ledPin, OUTPUT);

    Serial.begin(38400);

    matrix.begin();
    matrix.setBrightness(defaultBrightness);

}
// the loop() method runs over and over again,
// as long as the board has power
void loop() {
	uint16_t Radius;
	int16_t Xpos;
	int16_t Ypos;

    rgb24 myColor;
    myColor.red = random(200) + 55;
    myColor.green = random(200) + 55;
    myColor.blue = random(200) + 55;

	Radius = random(30) + 2;
	Xpos = random(32);
	Ypos = random(32);

	for (int16_t c=1; c<Radius; c++) {
        matrix.fillScreen(defaultBackgroundColor);
	    matrix.drawCircle(Xpos, Xpos, c, myColor);
        matrix.swapBuffers(false);
		delay(50);
	}
}

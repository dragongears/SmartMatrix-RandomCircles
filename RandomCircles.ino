/*
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

	for (int16_t c=1; c<Radius; c++)
	{
        matrix.fillScreen(defaultBackgroundColor);
	    matrix.drawCircle(Xpos, Xpos, c, myColor);
        matrix.swapBuffers(false);
		delay(50);
	}
}

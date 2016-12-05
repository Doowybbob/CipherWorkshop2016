## About

This is a simple Arduino sketch that can be used to learn some of the basics of Arduino, microcontrollers and electronics.

The goal is to have 5 LEDs light up one after another until the user presses enter on their keyboard. when the enter key is pressed, the Arduino should pause on the LED that is lit up. If the user presses enter when the middle LED is lit up, they move onto the next level. If they stop on any of the other LEDs, they have to go back to the first level.

The amount of time that each LED is lit up depends on the level. As the level increases, the time decreases which makes it harder to stop on the right LED

#### Setup

The sketch is set up to have the 5 LEDs connected to pins 8 though 12 on the Arduino.

Remember to add in series resistors connecting the LEDs to ground. I used 1K ohm resistors.

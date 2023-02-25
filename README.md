# rubber-ducko

This is my arduino equivalent to the famous rubber ducky. As the real thing costs about 80 USD and I'm a romanian student, I decided to code my own rubber ducky using an Arduino Leonardo.

## Hardware

In order to edit or replace the Arduino's code, a connection needs to be made between pin 2 and GND. On the other hand, to ensure the delivery of the payload, a connection between pin 2 and 5V needs to be made, but, in my experience, if no connection is made in general, the arduino sees a connection to 5V rather than gibberish or one to GND.

## The code

To "type" the keys, the code uses the <keyboard.h> library. To make my life easier, I implemented the typeKey(), typePhrase() and typeCombination() functions that, well, type a key, a phrase or a combination such as CTRL+T.

## The look

This is more of a gimmik rather than a practical hacking device. Although it does act as you'd expect a rubber ducky to act, the size of the arduino makes it not so hidden. Also, the actual rubber duck it's attached to is likely draw some attention:

<img src="https://github.com/mircea-mihail/rubber-ducko/blob/main/the-arduino.jpg" alt="the board" width="240"/> <img src="https://github.com/mircea-mihail/rubber-ducko/blob/main/the-final-ducko.jpg " alt="the duck" width="240"/>    <img src="https://github.com/mircea-mihail/rubber-ducko/blob/main/the-ducko-in-action.jpg" alt="the final product" width="240"/>

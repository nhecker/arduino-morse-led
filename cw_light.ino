/*
  Adapted from Arduino's Blink et al. <http://www.arduino.cc/en/Tutorial/Blink>
  This code is in the public domain.

  A quick Arduino sketch to blink an LED or toggle a digital pin with Morse
  code ("CW") provided by a variable below. To modify this file for your use,
  at a minimum you're likely to want to modify the `stringToMorseCode` variable
  and possibly the `ledPin` and `ditLen` variables as well.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used. If you want to know
  what pin the on-board LED is connected to on your Arduino model, check the
  Technical Specs of your board at: <https://www.arduino.cc/en/Main/Products>

  Created 2018-10-09 by Nicholas Hecker
  Updated 2022-04-01 by Nicholas Hecker
*/

// Set the string to be repeated here, HELLO WORLD by default.
const char stringToMorseCode[] = "HELLO WORLD";
// The number of the LED pin, LED_BUILTIN by default.
const int ledPin =  LED_BUILTIN;
// The dit length in milliseconds = (60 / (50 * WPM)) * 1000
const long ditLen = 150;

const int dahLen = ditLen * 3;        // length of the morse code 'dah'
const int elemPause = ditLen;         // " pause between elements of a character
const int charPause = ditLen * 3;     // " characters
const int wordPause = ditLen * 7;     // " words
const int messagePause = ditLen * 10; // " repeating the message

// The setup function runs once when you press reset or power the board.
void setup() {
  // Initialize digital pin LED_BUILTIN as an output.
  pinMode(ledPin, OUTPUT);
}

// The loop function runs over and over again forever.
void loop() {
  // Loop through the string and get each character one at a time until the end is reached.
  for (int i = 0; i < sizeof(stringToMorseCode) - 1; i++)
  {
    // Get the character in the current position.
  char tmpChar = stringToMorseCode[i];
  // Set the case to lower case.
  tmpChar = toLowerCase(tmpChar);
  // Call the subroutine to get the morse code equivalent for this character.
  GetChar(tmpChar);
  // Pause 3 dits between characters.
  LightsOff(charPause);
  }
  
  // At the end of the string long pause before looping and starting again.
  LightsOff(messagePause);      
}

// DIT
void MorseDit()
{
  digitalWrite(ledPin, HIGH);
  delay(ditLen);
}

// DAH
void MorseDah()
{
  digitalWrite(ledPin, HIGH);
  delay(dahLen);
}

// Turn Off
void LightsOff(int delayTime)
{
  digitalWrite(ledPin, LOW);
  delay(delayTime);
}

// *** Characters to Morse Code Conversion *** //
void GetChar(char tmpChar)
{
  // Take the passed character and use a switch case to
  // find the morse code for that character.
  switch (tmpChar) {
    case '0': 
    MorseDah();
    LightsOff(elemPause);
        MorseDah();
    LightsOff(elemPause);
        MorseDah();
    LightsOff(elemPause);
        MorseDah();
    LightsOff(elemPause);
        MorseDah();
    LightsOff(elemPause);
    break;

    case '1': 
    MorseDit();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
        MorseDah();
    LightsOff(elemPause);
        MorseDah();
    LightsOff(elemPause);
        MorseDah();
    LightsOff(elemPause);
    break;

    case '2': 
    MorseDit();
    LightsOff(elemPause);
        MorseDit();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
        MorseDah();
    LightsOff(elemPause);
        MorseDah();
    LightsOff(elemPause);
    break;

    case '3': 
    MorseDit();
    LightsOff(elemPause);
        MorseDit();
    LightsOff(elemPause);
        MorseDit();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    break;

    case '4': 
    MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    break;

    case '5': 
    MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    break;

    case '6': 
    MorseDah();
    LightsOff(elemPause);
        MorseDit();
    LightsOff(elemPause);
        MorseDit();
    LightsOff(elemPause);
        MorseDit();
    LightsOff(elemPause);
        MorseDit();
    LightsOff(elemPause);
    break;

    case '7': 
    MorseDah();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
        MorseDit();
    LightsOff(elemPause);
        MorseDit();
    LightsOff(elemPause);
        MorseDit();
    LightsOff(elemPause);
    break;

    case '8': 
    MorseDah();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    break;

    case '9': 
    MorseDah();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
        MorseDit();
    LightsOff(elemPause);
    break;

    
    case 'a': 
    MorseDit();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    break;
    case 'b':
    MorseDah();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    break;
    case 'c':
      MorseDah();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    break;
    case 'd':
    MorseDah();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    break;
    case 'e':
    MorseDit();
    LightsOff(elemPause);
    break;
    case 'f':
      MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    break;
    case 'g':
    MorseDah();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    break;
    case 'h':
      MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    break;
    case 'i':
      MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    break;
    case 'j':
      MorseDit();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    break;
    case 'k':
      MorseDah();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    break;
    case 'l':
      MorseDit();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    break;
    case 'm':
      MorseDah();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    break;
    case 'n':
      MorseDah();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    break;
    case 'o':
      MorseDah();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    break;
    case 'p':
      MorseDit();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    break;
    case 'q':
      MorseDah();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    break;
    case 'r':
      MorseDit();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    break;
    case 's':
      MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    break;
    case 't':
      MorseDah();
    LightsOff(elemPause);
    break;
    case 'u':
      MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    break;
    case 'v':
      MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    break;
    case 'w':
      MorseDit();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    break;
    case 'x':
      MorseDah();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    break;
    case 'y':
      MorseDah();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    break;
    case 'z':
      MorseDah();
    LightsOff(elemPause);
    MorseDah();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    MorseDit();
    LightsOff(elemPause);
    break;
    case ' ':
    LightsOff(wordPause);
    break;
    default: 
    // If a matching character was not found it will default to a blank space
    LightsOff(charPause);      
  }
}

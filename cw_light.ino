/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman
  modified 9 Oct 2018
  by Nicholas Hecker

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// set the string to be repeated
const char stringToMorseCode[] = "HELLO WORLD";
const int ledPin =  LED_BUILTIN; // the number of the LED pin

const long ditLen = 150;               // element duration in milliseconds = (60 / (50 * WPM)) * 1000
const int dahLen = ditLen * 3;         // length of the morse code 'dah'
const int elemPause = ditLen;          // " pause between elements of a character
const int charPause = ditLen * 3;      // " characters
const int wordPause = ditLen * 7;      // " words
const int messagePause = ditLen * 10;  // " repeating the message

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // Loop through the string and get each character one at a time until the end is reached
  for (int i = 0; i < sizeof(stringToMorseCode) - 1; i++)
  {
    // Get the character in the current position
  char tmpChar = stringToMorseCode[i];
  // Set the case to lower case
  tmpChar = toLowerCase(tmpChar);
  // Call the subroutine to get the morse code equivalent for this character
  GetChar(tmpChar);
  // pause 3 dits between characters
  LightsOff(charPause);
  }
  
  // At the end of the string long pause before looping and starting again
  LightsOff(messagePause);      
}

// DIT
void MorseDit()
{
  digitalWrite(ledPin, HIGH);    // turn the LED on 
  delay(ditLen);              // hold in this position
}

// DAH
void MorseDah()
{
  digitalWrite(ledPin, HIGH);    // turn the LED on 
  delay(dahLen);               // hold in this position
}

// Turn Off
void LightsOff(int delayTime)
{
  digitalWrite(ledPin, LOW);     // turn the LED off   
  delay(delayTime);             // hold in this position
}

// *** Characters to Morse Code Conversion *** //
void GetChar(char tmpChar)
{
  // Take the passed character and use a switch case to find the morse code for that character
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

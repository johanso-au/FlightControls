// Elite Dangerous: Basic Flight Control Unit
// 
// This MUST be used with an Arduino compatible with the 
// USB HID library (Leonardo, or any 32u4 chipset.. possibly others)
//
// See: http://i.imgur.com/ilhbTcL.jpg
//
// Left to Right; the Switches 1 to 4 are toggle type, and
// the two buttons are marked red and black.
//
// Wiring:
// Toggle 1 (Lights) - Digital 7
// Toggle 2 (Cargo Scoop) - Digital 6
// Toggle 3 (Landing Gear) - Digital 5
// Toggle 4 (Throttle 100% when up, 75% when down) - Digital 4
// Red Button (Full Stop / 0% Throttle) - Digital 3
// Black Button (Jump / Cruise) - Digital 2
// 
// Wire switches so they are active when switched to GND
// 
// Key Bindings Required:
// Lights - 'B'
// Cargo Scoop - 'HOME' (Default)
// Landing Gear - 'L' (Default)
// Throttle 100% - 'I'
// Throttle 75% - 'K'
// Full Stop - 'X' (Default)
// Jump - 'J' (Default)
//
// The following flags represent the "last known processed status"
// of the Switches. This prevents the key from repeating in one position.
bool Tog1Down = HIGH;
bool Tog2Down = HIGH;
bool Tog3Down = HIGH;
bool Tog4Down = HIGH;

void setup() {
  // Set pins 2 to 7 as Input with Pullup
  for (int i = 2; i < 8; i++){
    pinMode(i, INPUT_PULLUP);
  }
  if (digitalRead(4) == LOW) {Tog1Down = LOW;}
  if (digitalRead(5) == LOW) {Tog2Down = LOW;}
  if (digitalRead(6) == LOW) {Tog3Down = LOW;}
  if (digitalRead(7) == LOW) {Tog4Down = LOW;}
  Keyboard.begin();  
}

void loop() {
  // Black push button
  while (digitalRead(2) == LOW) {
    Keyboard.press('x');
    delay(100);
    Keyboard.releaseAll();
    delay(400);
  }
  // Red push button
  while (digitalRead(3) == LOW) {
    Keyboard.press('j');
    delay(100);
    Keyboard.releaseAll();
    delay(400);
  }
  
  
  // Toggle Switch 4 Down
  while (digitalRead(4) == HIGH && Tog4Down == LOW) {
      Keyboard.press('k');
      delay(100);
      Keyboard.releaseAll();
      Tog4Down = HIGH;
  }
  // Toggle Switch 4 Up
  while (digitalRead(4) == LOW && Tog4Down == HIGH) {
      Keyboard.press('i');
      delay(100);
      Keyboard.releaseAll();
      Tog4Down = LOW;
  }
  
  // Toggle Switch 3 Down
  while (digitalRead(5) == HIGH && Tog3Down == LOW) {
      Keyboard.press('l');
      delay(100);
      Keyboard.releaseAll();
      Tog3Down = HIGH;
  }
  // Toggle Switch 3 Up
  while (digitalRead(5) == LOW && Tog3Down == HIGH) {
      Keyboard.press('l');
      delay(100);
      Keyboard.releaseAll();
      Tog3Down = LOW;
  }   
      
      // Toggle Switch 2 Down
  while (digitalRead(6) == HIGH && Tog2Down == LOW) {
      Keyboard.press(KEY_HOME);
      delay(100);
      Keyboard.releaseAll();
      Tog2Down = HIGH;
  }
  // Toggle Switch 2 Up
  while (digitalRead(6) == LOW && Tog2Down == HIGH) {
      Keyboard.press(KEY_HOME);
      delay(100);
      Keyboard.releaseAll();
      Tog2Down = LOW;
  }   
      
      // Toggle Switch 1 Down
  while (digitalRead(7) == HIGH && Tog1Down == LOW) {
      Keyboard.press('b');
      delay(100);
      Keyboard.releaseAll();
      Tog1Down = HIGH;
  }
  // Toggle Switch 1 Up
  while (digitalRead(7) == LOW && Tog1Down == HIGH) {
      Keyboard.press('b');
      delay(100);
      Keyboard.releaseAll();
      Tog1Down = LOW;
  }  
} 

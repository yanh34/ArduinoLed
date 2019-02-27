// Pins
const int data_pin = 2;
const int clock_pin = 3;
const int latch_pin = 4;
 
// Time to display each LED
int wait = 150;   // milliseconds (ms)
 
void setup() {
  pinMode(data_pin, OUTPUT);
  pinMode(clock_pin, OUTPUT);
  pinMode(latch_pin, OUTPUT);
}
 
void loop() {
 
  // Sweep LEDs in one direction
  byte x = B00000000;
  byte y = B10000000;
  
  byte a = B00000001;
  
  for ( int i = 0; i < 11; i++ ) {
    shiftDisplay(x);
    x = y;
    y = y >> 1;
    y = (y | x);
    
   delay(wait);
  }
   for ( int i = 0; i < 11; i++ ) {
    shiftDisplay(x);
   
    x = x >> 1;
  
    
    delay(wait);
  }
 
  // Sweep LEDs back the other direction
  x = B000000;
  for ( int i = 0; i < 11; i++ ) {
    shiftDisplay(x);
    x = a;
    a = a << 1;
    a = (a | x);
    delay(wait);
  }

   for ( int i = 0; i < 11; i++ ) {
    shiftDisplay(x);
   
    x = x << 1;
  
    
    delay(wait);
  }
}
 
void shiftDisplay(byte data) {
  digitalWrite(latch_pin, LOW);
  shiftOut(data_pin, clock_pin, LSBFIRST, data);
  digitalWrite(latch_pin, HIGH);
}

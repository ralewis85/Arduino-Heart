/*
 Pulse LEDs

 The circuit:
 * LEDs attached from digital pin 09 to ground for center ring
 * LEDs attached from digital pin 10 to ground for outer ring
 * LEDs attached from digital pin 11 to ground for inner ring

 Created 3 May 2018
 By Robert A. Lewis

 */

/* --Pulse array--
   Pulse taken with Pulse Sensor.
   The value read from an analog input is by default 10 bits and 
   needs to be 8 bits for analogWrite.  In order to accomplish that
   goal the smallest value recorded from 500 samples was subtracted 
   from the array in order to 'zero' the LEDs when the pulse was at rest.

   Any value over the maximum 255 was capped at 255.

   --Beat array--
   Beat is a subset of the above pulse array.  Elements pulse[23:65] 
   were extracted and a new 'zero' was found (roughly).
*/
byte pulse[] = {70,73,76,76,73,71,70,68,72,90,130,187,247,255,255,249,201,149,103,65,40,23,16,17,26,40,58,79,96,105,108,103,92,78,65,55,50,48,48,48,49,52,55,56,57,57,58,60,61,64,66,67,66,66,65,69,87,123,180,231,255,250,217,171,121,72,38,16,3,0,7,22,44,67,90,107,113,107,96,82,70,60,52,46,43,42,43,47,50,53,55,58,62,64,66,66,67,66,65,64,64,75,102,156,207,239,246,225,188,144,97,61,34,17,9,10,19,37,57,77,95,108,110,104,92,80,69,62,55,51,50,52,52,53,55,57,59,61,62,63,67,69,69,70,68,66,68,79,108,148,216,251,255,244,207,164,117,81,54,36,28,25,29,40,58,77,97,109,112,108,100,90,80,69,61,56,52,51,52,55,58,61,64,66,67,68,70,72,70,70,69,68,68,77,109,145,217,255,255,255,224,172,124,85,55,37,26,24,27,39,55,79,99,112,116,115,108,96,82,72,64,59,55,55,57,60,63,66,68,69,69,70,72,71,71,71,70,69,71,86,119,156,228,255,255,236,190,142,97,58,35,21,15,18,29,47,70,90,108,117,115,107,96,84,72,64,58,56,56,57,58,61,64,66,68,70,71,72,71,71,71,69,69,79,110,154,208,247,255,238,201,151,108,73,44,27,19,20,29,43,61,82,101,113,115,111,102,89,75,65,60,58,56,57,59,63,64,65,66,67,69,71,75,76,75,73,71,70,77,104,148,207,249,255,253,218,167,120,82,55,37,28,25,31,43,60,79,100,113,119,115,105,93,81,70,62,57,55,54,55,60,63,66,69,72,72,74,74,74,72,70,68,67,70,87,122,166,226,255,255,238,193,147,103,69,44,32,26,25,32,47,66,87,100,109,112,106,96,85,73,65,60,56,55,54,56,58,62,65,66,68,71,73,75,74,71,68,68,78,108,152,209,248,255,246,209,158,111,72,43,23,13,14,27,47,70,90,108,116,117,110,98,87,76,65,58,54,52,53,56,59,63,68,70,74,75,74,72,69,70,76,99,138,195,247,255,255,237,188,140,98,65,42,29,21,25,36,53,72,92,108,114,112,103,92,78,68,59,54,53,53,53,55,59,62,63,67,70,72,73};
byte beat[] = {0,0,0,0,3,24,41,50,53,48,37,23,10,0,0,0,0,0,0,0,0,1,2,2,3,5,6,9,11,12,11,11,10,14,32,68,125,176,200,195,162,116,66};

// Assign LED pins
const int outer_ring_led  = 10;
const int center_ring_led = 9;
const int inner_ring_led  = 11;

int index = 0;

void setup() {
  // nothing happens in setup
}

void loop() {
  // Uncomment the desired LED behavior
  //pulse_subsection_device();
  //pulse_device();
  beat_nodelay_device();
  //beat_delay_device();
}

void pulse_device() {
  if (index >= sizeof(pulse)) index = 0;
  analogWrite(inner_ring_led, pulse[index]);
  analogWrite(center_ring_led, pulse[index]);
  analogWrite(outer_ring_led, pulse[index]);
  index++;
  delay(20);
}

void pulse_subsection_device() {
  if (index >= 66) index = 23;
  analogWrite(inner_ring_led, pulse[index]);
  analogWrite(center_ring_led, pulse[index]);
  analogWrite(outer_ring_led, pulse[index]);
  index++;
  delay(30);
}

void beat_nodelay_device() {
  if (index >= sizeof(beat)) index = 0;
  analogWrite(inner_ring_led, beat[index]);
  analogWrite(center_ring_led, beat[index]);
  analogWrite(outer_ring_led, beat[index]);
  index++;
  delay(30);
}

void beat_delay_device() {
  if (index >= sizeof(beat)) index = 0;
  analogWrite(inner_ring_led, beat[index]);
  analogWrite(center_ring_led, beat[index]);
  analogWrite(outer_ring_led, beat[index]);
  if ( index == 13 ) delay(1000);
  index++;
  delay(30);
}

/* This program allows you to set DMX channels over the serial port.
**
** After uploading to Arduino, switch to Serial Monitor and set the baud rate
** to 9600. You can then set DMX channels using these commands:
**
** <number>c : Select DMX channel
** <number>v : Set DMX channel to new value
**
** These can be combined. For example:
** 100c355w : Set channel 100 to value 255.
**
** For more details, and compatible Processing sketch,
** visit http://code.google.com/p/tinkerit/wiki/SerialToDmx
**
** Help and support: http://groups.google.com/group/dmxsimple       */

#include <DmxSimple.h>

void setup() {
  Serial.begin(9600);
  Serial.println("SerialToDmx ready");
  Serial.println();
  Serial.println("Syntax:");
  Serial.println(" 123c : use DMX channel 123");
  Serial.println(" 45w  : set current channel to value 45");
  DmxSimple.usePin(7);
}

int value = 0;
int channel;
float in, out;
int cast = 0;

int brightness = 0;    // how bright the LED is
int brightness2 = 255;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int fadeAmount2 = 5;    // how many points to fade the LED by

const int CHNL = 2;

void loop() {
  int c;


//  for (in = 0; in < 6.283; in = in + 0.001)
//for (in = 0; in < 6.283; in = in + )
//  {
//    out = sin(in) * 127.5 + 127.5;
//    cast = (int) out;
//    DmxSimple.write(2, out);
//    Serial.println("CHNL");
//    Serial.print(CHNL);
//    Serial.println("cast");
//    Serial.print(cast);
//  }

brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
if (brightness == 0 || brightness == 255) {
  fadeAmount = -fadeAmount ;
}

if (brightness2 == 0 || brightness2 == 255) {
  fadeAmount2 = -fadeAmount2 ;
}

DmxSimple.write(2, brightness);
DmxSimple.write(4, brightness2);


//  while(!Serial.available());
//  c = Serial.read();
//  if ((c>='0') && (c<='9')) {
//    value = 10*value + c - '0';
//  } else {
//    if (c=='c') channel = value;
//    else if (c=='w') {
////      DmxSimple.write(channel, value);
//      Serial.println();
//    }
//    value = 0;
//  }

delay(30);
}


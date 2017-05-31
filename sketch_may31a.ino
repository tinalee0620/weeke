

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_F5, NOTE_F5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_F4,0, NOTE_C5, 
  NOTE_D5,NOTE_F5,NOTE_D5,NOTE_C5
};
int greenPin = 6;
int redPin = 9;
int bluePin = 5;
int counter = 0;


// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4,4,4,4,4, 4, 4,4 ,4,4,4,3
};

void setup() {
  // iterate over the notes of the melody:
  pinMode(greenPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  for (int thisNote = 0; thisNote < 12; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  counter++;
  if(counter == 1){//紅綠同時點亮，產生黃色
    analogWrite(greenPin,255);
    analogWrite(redPin,255);
    analogWrite(bluePin,0);
  }
  else if(counter == 2){//藍紅同時點亮，產生紫色
    analogWrite(greenPin,0);
    analogWrite(redPin,255);
    analogWrite(bluePin,255);
  }
  else if(counter == 3){//藍綠同時點亮，產生青色
    analogWrite(greenPin,255);
    analogWrite(redPin,0);
    analogWrite(bluePin,255);
    counter = 0;
  }
  delay(1000);
  // no need to repeat the melody.
}


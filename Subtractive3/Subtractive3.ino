#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputTDM            tdm2;           //xy=88,195
AudioFilterStateVariable filter1;        //xy=233,118
AudioSynthWaveformSine   sine1;      //xy=233,253
AudioFilterStateVariable filter3;        //xy=385,188
AudioFilterStateVariable filter2;        //xy=387,110
AudioMixer4              mixer1;         //xy=570,161
AudioOutputTDM           tdm1;           //xy=723,182
AudioConnection          patchCord1(tdm2, 0, filter1, 0);
AudioConnection          patchCord2(tdm2, 0, mixer1, 3);
AudioConnection          patchCord3(filter1, 1, mixer1, 0);
AudioConnection          patchCord4(filter1, 1, filter2, 0);
AudioConnection          patchCord5(filter1, 1, filter3, 0);
AudioConnection          patchCord6(sine1, 0, filter2, 1);
AudioConnection          patchCord7(sine1, 0, filter3, 1);
AudioConnection          patchCord8(filter3, 2, mixer1, 2);
AudioConnection          patchCord9(filter2, 0, mixer1, 1);
AudioConnection          patchCord10(mixer1, 0, tdm1, 14);
AudioConnection          patchCord11(mixer1, 0, tdm1, 12);
AudioConnection          patchCord12(mixer1, 0, tdm1, 10);
AudioConnection          patchCord13(mixer1, 0, tdm1, 8);
AudioControlCS42448      cs42448_1;      //xy=598,560
// GUItool: end automatically generated code

float vol = 0.9; 
float amp, lfo;
float cut1, cut2, cut3, q1, q2, q3;

void setup() {
  cs42448_1.enable();
  cs42448_1.volume(.85);
  AudioMemory(48);
  Serial.begin(9600);
  pinMode(2, INPUT_PULLDOWN);
  pinMode(3, INPUT_PULLDOWN); 
}

void loop(){
if(digitalRead(2) == LOW && digitalRead(3) == LOW){
  mixer1.gain(3, vol);
  mixer1.gain(2, 0.0);
  mixer1.gain(1, 0.0);
  mixer1.gain(0, 0.0); 
  }
if(digitalRead(2) == HIGH && digitalRead(3) == LOW){
  mixer1.gain(3, 0.0);
  mixer1.gain(2, vol);
  mixer1.gain(1, 0.0);
  mixer1.gain(0, 0.0); 
  }
if(digitalRead(2) == HIGH && digitalRead(3) == HIGH){
  mixer1.gain(3, 0.0);
  mixer1.gain(2, 0.0);
  mixer1.gain(1, vol);
  mixer1.gain(0, 0.0); 
  }
if(digitalRead(2) == LOW && digitalRead(3) == HIGH){
  mixer1.gain(3, 0.0);
  mixer1.gain(2, 0.0);
  mixer1.gain(1, 0.0);
  mixer1.gain(0, vol); 
  }


  cut1 = analogRead(A14)*2.0;
  q1 = analogRead(A15)/125.0+0.7;
  cut2 = analogRead(A16)*2.0;
  q2 = analogRead(A17)/123.0+0.7;
  cut3 = analogRead(A18)*2.0;
  q3 = analogRead(A19)/123.0+0.7;
  lfo = analogRead(A20)/35.0;
  amp = analogRead(A21)/1023.0;
  filter1.frequency(cut1);
  filter1.resonance(q1);
  filter2.frequency(cut2);
  filter2.resonance(q2);
  filter3.frequency(cut3);
  filter3.resonance(q3);
  sine1.amplitude(amp);
  sine1.frequency(lfo);

}

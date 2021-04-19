#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputTDM            tdm2;           //xy=88,195
AudioFilterStateVariable filter3;        //xy=255,236
AudioFilterStateVariable filter2;        //xy=259,167
AudioFilterStateVariable filter1;        //xy=262,94
AudioMixer4              mixer1;         //xy=430,164
AudioEffectBitcrusher    bitcrusher1;    //xy=565,164
AudioOutputTDM           tdm1;           //xy=742,182
AudioConnection          patchCord1(tdm2, 0, filter1, 0);
AudioConnection          patchCord2(tdm2, 0, filter2, 0);
AudioConnection          patchCord3(tdm2, 0, filter3, 0);
AudioConnection          patchCord4(tdm2, 0, mixer1, 3);
AudioConnection          patchCord5(filter3, 2, mixer1, 2);
AudioConnection          patchCord6(filter2, 1, mixer1, 1);
AudioConnection          patchCord7(filter1, 0, mixer1, 0);
AudioConnection          patchCord8(mixer1, bitcrusher1);
AudioConnection          patchCord9(bitcrusher1, 0, tdm1, 14);
AudioConnection          patchCord10(bitcrusher1, 0, tdm1, 12);
AudioConnection          patchCord11(bitcrusher1, 0, tdm1, 10);
AudioConnection          patchCord12(bitcrusher1, 0, tdm1, 8);
AudioControlCS42448      cs42448_1;      //xy=478,283
// GUItool: end automatically generated code



float vol = 0.9; 
int bitz, crush, crush2;
float cut1, cut2, cut3, q1, q2, q3;

void setup() {
  cs42448_1.enable();
  cs42448_1.volume(.85);
  AudioMemory(48);
  Serial.begin(9600);
  pinMode(2, INPUT_PULLDOWN);
  pinMode(3, INPUT_PULLDOWN); 


}

void loop() {

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
  cut3 = analogRead(A19)*2.0;
  q3 = analogRead(A18)/123.0+0.7;
  bitz = map(analogRead(A20), 0, 1023, 1, 16);
  crush = analogRead(A21);
  if(crush >= 0 && crush <= 256){
    crush2 = 11025;
  }
  if(crush >= 257 && crush <= 512){
    crush2 = 22050;
  }
  if(crush >= 513 && crush <= 1023){
    crush2 = 44100;
  }
  
  filter1.frequency(cut1);
  filter1.resonance(q1);
  filter2.frequency(cut2);
  filter2.resonance(q2);
  filter3.frequency(cut3);
  filter3.resonance(q3);
  bitcrusher1.bits(bitz);
  bitcrusher1.sampleRate(crush2);

}         

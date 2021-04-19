#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthNoiseWhite     noise1;         //xy=135,289
AudioSynthWaveform       waveform3;      //xy=144,219
AudioSynthWaveform       waveform2;      //xy=151,163
AudioSynthWaveform       waveform1;      //xy=153,111
AudioEffectEnvelope      envelope4;      //xy=298,297
AudioEffectEnvelope      envelope3;      //xy=304,238
AudioEffectEnvelope      envelope2;      //xy=312,177
AudioEffectEnvelope      envelope1;      //xy=316,120
AudioMixer4              mixer1;         //xy=482,138
AudioOutputTDM           tdm1;           //xy=633,156
AudioConnection          patchCord1(noise1, envelope4);
AudioConnection          patchCord2(waveform3, envelope3);
AudioConnection          patchCord3(waveform2, envelope2);
AudioConnection          patchCord4(waveform1, envelope1);
AudioConnection          patchCord5(envelope4, 0, mixer1, 3);
AudioConnection          patchCord6(envelope3, 0, mixer1, 2);
AudioConnection          patchCord7(envelope2, 0, mixer1, 1);
AudioConnection          patchCord8(envelope1, 0, mixer1, 0);
AudioConnection          patchCord9(mixer1, 0, tdm1, 14);
AudioConnection          patchCord10(mixer1, 0, tdm1, 12);
AudioConnection          patchCord11(mixer1, 0, tdm1, 10);
AudioConnection          patchCord12(mixer1, 0, tdm1, 8);
AudioControlCS42448      cs42448_1;      //xy=656,355
// GUItool: end automatically generated code



float vol0, vol1, vol2, vol3;
float freq, pulse, period, att;

void setup() {
  cs42448_1.enable();
  cs42448_1.volume(.85);
  AudioMemory(48);
  Serial.begin(9600);
  pinMode(2, INPUT_PULLDOWN);
  pinMode(3, INPUT_PULLDOWN);
  waveform1.begin(.5, 220, WAVEFORM_TRIANGLE);
  waveform2.begin(.5, 440, WAVEFORM_PULSE);
  waveform2.pulseWidth(.25);
  waveform3.begin(.5, 800, WAVEFORM_SQUARE);
  noise1.amplitude(.75);
  envelope1.attack(50);
  envelope1.decay(50);
  envelope1.release(250);  
  envelope2.attack(50);
  envelope2.decay(50);
  envelope2.release(250);
  envelope3.attack(50);
  envelope3.decay(50);
  envelope3.release(250);
  envelope4.attack(50);
  envelope4.decay(50);
  envelope4.release(250);
}

void loop() {
  vol0 = analogRead(A14)/4095.0;
  vol1 = analogRead(A15)/4095.0;
  vol2 = analogRead(A16)/4095.0;
  vol3 = analogRead(A17)/4095.0;
  freq = analogRead(A18)*2.0;
  pulse = analogRead(A19)/1023.0;
  period = analogRead(A20);
  att = analogRead(A21);
  mixer1.gain(0, vol0);
  mixer1.gain(1, vol1);
  mixer1.gain(2, vol2);
  mixer1.gain(3, vol3);
  waveform1.frequency(freq);
  waveform2.frequency(freq*2);
  waveform2.pulseWidth(pulse);
  waveform3.frequency(freq*1.5);


  
  if(digitalRead(2) == HIGH){

  envelope1.noteOn();
  envelope2.noteOn();
  envelope3.noteOn();
  envelope4.noteOn();
  envelope1.attack(att);
  envelope2.attack(att);
  envelope3.attack(att);
  envelope4.attack(att);
  delay(period);
  envelope1.noteOff();
  envelope2.noteOff();
  envelope3.noteOff();
  envelope4.noteOff();
  delay(period);
  }
  if(digitalRead(3) == HIGH){
  envelope1.attack(att);
  envelope2.attack(att);
  envelope3.attack(att);
  envelope4.attack(att);
  envelope1.noteOn();
  envelope2.noteOn();
  envelope3.noteOn();
  envelope4.noteOn();
  }

  /*if(digitalRead(2) == HIGH){
    envelope1.noteOn();    
    }*/

}

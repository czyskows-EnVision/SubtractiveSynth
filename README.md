# Subtractive Synthesizer
The idea behind this project was to create a subtractive synthesizer in three modules. The first module has three oscillators that each output different waveforms - square, triangle, and pulse. This module also contains envelope control, or the attack, sustain, decay, and release of the notes that are played. The second module contains three filters and a ‘bitcrusher’. And the third module contains three more filters and an LFO. Since the idea behind subtractive synthesis is to shape sound by taking things away from it, the audio path starts in module one, then goes to module two to get filtered and bit crushed, then to module three for more filtering and some low-frequency oscillation. 

In order to pass multiple channels of audio to and from the Teensy, I built a custom sound card. The board uses a CS42448 audio codec, which is a beast with 6-in / 8-out audio channels. The driver was written by the same awesome guy who wrote the audio library: Paul Stoffregen (https://github.com/PaulStoffregen/Audio). But I’ll discuss that more in the coming week. For now, I’ll post my Teensy code so people can get an idea of how the audio library works and what the code is doing. Hardware next.   


![SoundCrad](https://user-images.githubusercontent.com/79474454/115282992-acbb6900-a0ff-11eb-9735-deb7b5601ab8.jpg)

# SubtractiveSynth

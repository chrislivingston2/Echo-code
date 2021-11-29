#include <iostream>
#include "WaveFileManager.h"
#include "Echo.h"


int main(){

    WaveFileManager wave;
    wave.read("yes-16-bit-mono.wav");
    //echo class doesnt need to be instantiated, called directly
    auto echoData = Echo::process(wave.getData(),0.6f,10000);
    wave.updateSoundData(echoData);
    wave.save("yes-16-b-t-mono-echo.wav");
    return 0;
}

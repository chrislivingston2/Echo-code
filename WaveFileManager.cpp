#include <fstream>
#include <utility>  
#include "WaveFileManager.h"

void WaveFileManager::read(const std::string &fileName){
    std::ifstream file(fileName, std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char *) &waveHeader, sizeof(wav_header));
        buffer = new short[waveHeader.data_bytes];
        file.read((char*) buffer,waveHeader.data_bytes);
        file.close();

    }
    for (int i=0; i< waveHeader.data_bytes / waveHeader.sample_alignment; i++){
        soundData.push_back((float)buffer[i] / MAX_16BIT);
    }

}


bool abs_compare(float a, float b) {
    return std::abs(a) < std::abs(b);
}

void WaveFileManager::save(const std::string &outFileName){
    std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    //fine the max value in the sound data
    auto maxLocation = std::max_element(soundData.begin(), soundData.end(), abs_compare);
    float maxValue = *maxLocation;
    //normalize the sound data and put it in a buffer
    for(int i = 0; i<soundData.size();i++){
        soundData[i] = soundData[i] / maxValue;
        buffer[i] = (short) (soundData[i] * MAX_16BIT);
    }
    outFile.write((char *) *waveHeader, sizeof(wav_header));
    outFile.write((char *) buffer, waveHeader.data_bytes);
    outFile.close();
}


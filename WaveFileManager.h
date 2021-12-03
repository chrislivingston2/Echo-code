#ifndef FEED_BACK_ECHO_WAVEFILEMANAGER_H
#define FEED_BACK_ECHO_WAVEFILEMANAGER_H


static const float MAX_16BIT = 32768.0f;

#include <iostream>
#include <fstream>
#include <utility>  
#include <vector>
#include <algorithm>
class WaveFileManager{

private:
    //works with 16 bit data only
    short* buffer = nullptr;
    wav_header waveHeader;
    std::vector<float> soundData;

public:
    void read(const std::string &fileName);
    void save(const std::string &outFileName);
    virtual ~WaveFileManager();

    const std::vector<float> &getData();

    void updateSoundData(std::vector<float> newData);
    
};

#endif //FEED_BACK_ECHO_WAVEFILEMANAGER_H
//
// Created by Raymond Khazoum on 27/11/2019.
//

#ifndef SWIPE_PINREADER_H
#define SWIPE_PINREADER_H


#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class pinReader {
public:
    pinReader();

    void read_index(string file_name, vector<uint32_t> header_offset);

private:
};


#endif //SWIPE_PINREADER_H

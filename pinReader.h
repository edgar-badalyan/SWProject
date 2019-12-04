#ifndef SWIPE_PINREADER_H
#define SWIPE_PINREADER_H


#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class pinReader {
public:
    pinReader();

    void read_index(string file_name, vector<uint32_t> *phr_header_offset, vector<uint32_t>* psq_sequence_offset);
private:
};


#endif //SWIPE_PINREADER_H

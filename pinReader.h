#ifndef PINREADER_H
#define PINREADER_H


#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class pinReader {
public:
    pinReader();

    void read_index(string file_name);
    vector<uint32_t > get_header_offset(){ return header_offset;}
    vector<uint32_t> get_sequence_offset(){ return sequence_offset;}
private:
    vector<uint32_t> header_offset;
    vector<uint32_t> sequence_offset;
};


#endif //PINREADER_H

#ifndef SWIPE_PINREADER_H
#define SWIPE_PINREADER_H


#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

class pinReader {
public:
    pinReader();

    void read_index(string file_name, vector<uint32_t> *phr_header_offset, vector<uint32_t> *psq_sequence_offset);

    template <typename type>
    void read_uint( ifstream & file, type & element);
    void read_char(char* element, ifstream & file, int length);

private:
};


#endif //SWIPE_PINREADER_H

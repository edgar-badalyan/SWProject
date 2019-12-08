#ifndef PHRREADER_H
#define PHRREADER_H
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <vector>

using namespace std;

class phrReader {
public:
    phrReader();
    int convert_header(ifstream &file, string character, int i);
    string read_header(string file_name, int index);

    vector<uint32_t >* get_header_offset(){ return &header_offset;}

private:
    vector<uint32_t> header_offset;
    int header_length;
    string header;
};


#endif //PHRREADER_H

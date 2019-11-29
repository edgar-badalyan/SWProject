#ifndef SWIPE_PHRREADER_H
#define SWIPE_PHRREADER_H
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

    vector<uint32_t > get_header_offset(){ return header_offset;}
    void set_header_offset(vector<uint32_t> new_header_offset){ header_offset = new_header_offset;}

private:
    vector<uint32_t> header_offset;
    int header_length;
    string header;
};


#endif //SWIPE_PHRREADER_H

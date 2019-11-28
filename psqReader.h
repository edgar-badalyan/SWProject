//
// Created by Raymond Khazoum on 28/11/2019.
//

#ifndef SWIPE_PSQREADER_H
#define SWIPE_PSQREADER_H

#include <fstream>
#include <iostream>
#include <vector>
#ifndef TEST_READ_H
#define TEST_READ_H


#endif


using namespace std;

class psqReader {
public:
    psqReader();

    string get_sequence_fasta(string file_name);
    int find_sequence(string file_name, string query_sequence);
    char decode_int(int code);
    std::vector<uint32_t> sequence_offset;
};


#endif //SWIPE_PSQREADER_H

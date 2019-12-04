#ifndef SWIPE_PSQREADER_H
#define SWIPE_PSQREADER_H

#include <fstream>
#include <iostream>
#include <vector>
#include <map>


using namespace std;

class psqReader {
public:
    psqReader();
    char decode_int(int code);
    string get_sequence_fasta(string file_name);
    int find_sequence(string file_name, string query_sequence);
    
    vector<uint32_t>* get_sequence_offset(){ return &sequence_offset;}
private:
    vector<uint32_t> sequence_offset;
    string query_file_name;
};


#endif //SWIPE_PSQREADER_H

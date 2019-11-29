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

    string get_sequence_fasta(string file_name);
    int find_sequence(string file_name, string query_sequence);

    vector<uint32_t> get_sequence_offset(){ return sequence_offset;}
    void set_sequence_offset(vector<uint32_t> new_sequence_offset){ sequence_offset = new_sequence_offset;}
private:
    vector<uint32_t> sequence_offset;
};


#endif //SWIPE_PSQREADER_H

#ifndef PSQREADER_H
#define PSQREADER_H

#include <fstream>
#include <iostream>
#include <vector>
#include <map>


using namespace std;

class psqReader {
public:
    psqReader();
//    vector<int> get_sequence_fasta(string file_name);
    vector<vector<int>> find_sequence_score(string file_name, vector<int> query_sequence, int file_size);
    void set_traceback(){ traceback = 1;}
    vector<uint32_t>* get_sequence_offset(){ return &sequence_offset;}

private:
    vector<uint32_t> sequence_offset;
    //string query_file_name;
    char *psq_file;
    uint64_t file_size;
    int traceback = 0;
};


#endif //PSQREADER_H

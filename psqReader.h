// header for psqReader.cpp

#ifndef PSQ_READER_H
#define PSQ_READER_H

#include <vector>

class psqReader {
public:
    psqReader();
    std::vector<std::vector<int>> find_sequence_score(std::string file_name, const std::vector<int> & query_sequence, int file_size, int openPenalty, int extPenalty, double factor, std::string blosum_file);
    std::vector<uint32_t>* get_sequence_offset(){ return &sequence_offset;}

private:
    std::vector<uint32_t> sequence_offset;
    uint64_t file_size;
};

#endif

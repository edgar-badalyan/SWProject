#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <typeinfo>
using namespace std;

class pinReader {
public:
    pinReader();

    void read_file(string file_name, vector<uint32_t> *phr_header_offset, vector<uint32_t> *psq_sequence_offset);

    template <typename type>
    void read_uint( ifstream & file, type & element);
    void read_char(char* element, ifstream & file, int length);

    // new
    const uint32_t get_number_seq() { return number_seq;}
    const uint64_t get_res_count() { return res_count;}
private:
    uint32_t offset;
    uint32_t number_seq;
    uint64_t res_count;
};

#include <vector>




class psqReader {
public:
    psqReader();
//    vector<int> get_sequence_fasta(string file_name);
    std::vector<std::vector<int>> find_sequence_score(std::string file_name, std::vector<int> query_sequence, int file_size, double factor = 12);
//    void set_traceback(){ traceback = 1;}
    std::vector<uint32_t>* get_sequence_offset(){ return &sequence_offset;}

private:
    std::vector<uint32_t> sequence_offset;
    //string query_file_name;
    uint64_t file_size;
//    int traceback = 0;
};

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "test_read.h"
using std::ifstream;
using std::string;
using std::endl;

string get_sequence_fasta(string file_name){
    //reads a single protein sequence from a .fasta file
    ifstream file(file_name, std::ios::in);
    if(file.is_open()){
        string line;
        int i = 0;
        string sequence = "";
        while(getline(file, line)){
            if (i != 0){ //we don't want the first line
                sequence.append(line);
            }
            i++;
        }
        file.close();
        return sequence;
    }
    exit (1);
}

void read_index(string file_name){
    //reads the info on the database from the .pin binary file
    ifstream file(file_name, std::ios::in | std::ios::binary);
    if(file.is_open()){

        uint32_t version;
        file.read((char *)&version, sizeof(uint32_t));
        version = __builtin_bswap32(version);
        std::cout << version<<endl;

        uint32_t type;
        file.read((char *)&type, sizeof(uint32_t));
        type = __builtin_bswap32(type);
        std::cout << type <<endl;

        uint32_t length;
        file.read((char*)&length, sizeof(uint32_t));
        length = __builtin_bswap32(length);
        std::cout << length <<endl;

        char title[length+1];
        file.read(title, length);
        title[length] = '\0';
        std::cout << title << endl;

        uint32_t timestamp_length;
        file.read((char*)&timestamp_length, sizeof(uint32_t));
        timestamp_length = __builtin_bswap32(timestamp_length);
        std::cout << timestamp_length <<endl;

        char timestamp[timestamp_length + 1];
        file.read(timestamp, timestamp_length);
        timestamp[timestamp_length] = '\0';
        std::cout << timestamp <<endl;

        uint32_t num_seq;
        file.read((char*)&num_seq, sizeof(uint32_t));
        num_seq = __builtin_bswap32(num_seq);
        std::cout << num_seq <<endl;

        uint64_t res_count;
        file.read((char*)&res_count, sizeof(uint64_t));
        std::cout << res_count <<endl;

        uint32_t max_seq;
        file.read((char*)&max_seq, sizeof(uint32_t));
        max_seq = __builtin_bswap32(max_seq);
        std::cout << max_seq <<endl;

        std::vector<uint32_t> header_offset;
        for (int i = 0;i<10;i++){
            uint32_t offset;
            file.read((char*)&offset, sizeof(uint32_t));
            offset = __builtin_bswap32(offset);
            header_offset.push_back(offset);
            std::cout << offset <<endl;
        }
    }
}

int find_sequence(string file_name, string query_sequence){
    //scans the .psq file and finds the sequence that is identical to
    //the query sequence and return its index
    ifstream file(file_name, std::ios::in | std::ios::binary);
    if (file.is_open()){
        int i = 0;
        char lettre;
        unsigned int code;
        string sequence = "";
        while (file.good()){
            file.read(&lettre, 1);
            code = (int) lettre;
            sequence.append(conversion[code]);
            if (code == 0){ //sequences end with a NULL byte.
                if (sequence == query_sequence){
                    std::cout << "sequence: " << sequence << " at: " << i <<endl;
                    return i;
                }else{ //reset sequence to read the next one
                    sequence = "";
                }
                i++;
            }
        }
        std::cout << "sequence not found" <<endl;
        file.close();
    }
}

int main(int argc, char* argv[]){
    //string sequence = get_sequence_fasta("P00533.fasta"); //query sequence
    //std::cout << "sequence:" << endl << sequence << endl;
    //find_sequence("uniprot_sprot.fasta.psq", sequence);
    read_index("uniprot_sprot.fasta.pin");
}

#include "psqReader.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

psqReader::psqReader() {
    sequence_offset = {};
}


std::map<char, int> decode_residue =
    {{'A', 1},
     {'B', 2},
     {'C', 3},
     {'D', 4},
     {'E', 5},
     {'F', 6},
     {'G', 7},
     {'H', 8},
     {'I', 9},
     {'K', 10},
     {'L', 11},
     {'M', 12},
     {'N', 13},
     {'P', 14},
     {'Q', 15},
     {'R', 16},
     {'S', 17},
     {'T', 18},
     {'V', 19},
     {'W', 20},
     {'X', 21},
     {'Y', 22},
     {'Z', 23},
     {'U', 24},
     {'*', 25},
     {'O', 26},
     {'J', 27},
 };


std::vector<int> psqReader::get_sequence_fasta(string file_name) {
    //reads a single protein sequence from a .fasta file
    query_file_name = file_name;
    std::vector<int> seq;
    ifstream file(file_name, std::ios::in);
    if(file.is_open()){string line;
        int i = 0;
        while(getline(file, line)){
            if (i != 0){ //we don't want the first line
                for (int i =0;i<line.size();i++){
                    seq.push_back(decode_residue[line[i]]);
                }
            }
            i++;
        }
        return seq;
        file.close();
    }
    exit (1);
}

int psqReader::find_sequence(string file_name, std::vector<int> query_sequence) {
    //scans the .psq file and finds the sequence that is identical to
    //the query sequence and return its index
    ifstream file(file_name, std::ios::in | std::ios::binary);
    if (file.is_open()){
        //load file in memory
        file.seekg(0, file.end);
        file_size = file.tellg();
        file.seekg(0, file.beg);
        psq_file = new char[file_size];
        file.read(psq_file, file_size);
        file.close();


        int index = 0;
        int i=1;
        while(i < file_size){
            int offset = this->sequence_offset[index];
            int len = this->sequence_offset[index+1] - offset;
            std::vector<int> sequence(len-1);
            for (int j=0;j<len-1;j++){
                sequence[j] = psq_file[j + offset];
                i++;
            }
            if (sequence == query_sequence){
                cout << "Query file name:   " << query_file_name << endl;
                cout << "Query length:      " << sequence.size() << " residues" <<endl;
                return index;
            }
            index++;
        }
        std::cout << "sequence not found" <<endl;
        file.close();
    }else{
        return -1;
    }
}


#include "psqReader.h"
#include <fstream>
#include <iostream>
using namespace std;

psqReader::psqReader() {

}

string psqReader::get_sequence_fasta(string file_name) {
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

int psqReader::find_sequence(string file_name, string query_sequence) {
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

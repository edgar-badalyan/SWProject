#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include "psqReader.h"
#include "smithWaterman.h"
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
    seq.push_back(0);
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

int psqReader::find_sequence(string file_name, vector<int> query_sequence) {
    ifstream file(file_name, std::ios::in | std::ios::binary);
    if (file.is_open()){
        smithWaterman *sw = new smithWaterman(); sw->read_blosum();
        std::vector<char> vec(std::istreambuf_iterator<char>(file),(std::istreambuf_iterator<char>()));
        file.close();

        int index = 0;
        for(int i = 0 ; i < 5953912; i++){
            int len = sequence_offset[index+1] - sequence_offset[index];
            vector<int> sequence(vec.begin() + i, vec.begin() + (len + sequence_offset[index] - 1)  );
            sequence.insert(sequence.begin(),0);

            //cout << index << " ; ";
            sw->algo(sequence, query_sequence);
            index++;
            i+=len-1;
        }
    }
}

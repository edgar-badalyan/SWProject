#include <fstream>
#include <iostream>
#include "psqReader.h"
#include "smithWaterman.h"
using namespace std;

psqReader::psqReader() {
    sequence_offset = {};
}


vector<vector<int>> psqReader::find_sequence_score(string file_name, const vector<int> & query_sequence, int file_size, int openPenalty, int extPenalty, double factor, string blosum_file) {
    ifstream file(file_name, std::ios::in | std::ios::binary);
    if (file.is_open()){
        vector<vector <int>> seq_score;

        smithWaterman *sw = new smithWaterman(openPenalty, extPenalty, blosum_file); sw->read_blosum();
        //score of the query sequence with itself, used as a reference point to filter out low scores
        double maxScore = sw->algo(query_sequence, query_sequence);
        // load the whole file in memory for faster reading;
        vector<char> all_file{0};  all_file.insert(all_file.end(),std::istreambuf_iterator<char>(file),(std::istreambuf_iterator<char>()));
        file.close();

        int index = 0, len = 0, score = 0;
        vector<int> other_sequence;

        for(int i = 0 ; i < file_size; i+=len){
            len = sequence_offset[index+1] - sequence_offset[index];
            vector<int>().swap(other_sequence);
            // read sequence of size len
            other_sequence.insert(other_sequence.begin(), all_file.begin() + i, all_file.begin() + (len + sequence_offset[index]));
            score = sw->algo(other_sequence, query_sequence);
            // if score is big enough, add it to the vector that will get printed
            if ( maxScore/factor < score ){
                seq_score.push_back({score, index});
            }
            index++;

        }
        delete sw;
        return seq_score;
    }
    else{
        cout << " Error : psq file " << endl;
    }
    exit(1);
}

#include <fstream>
#include <iostream>
#include "psqReader.h"
#include "smithWaterman.h"
using namespace std;

psqReader::psqReader() {
    sequence_offset = {};
}


vector<vector<int>> psqReader::find_sequence_score(string file_name, vector<int> query_sequence, int file_size, double factor) {
    ifstream file(file_name, std::ios::in | std::ios::binary);
    if (file.is_open()){
        vector<vector <int>> seq_score;
        smithWaterman *sw = new smithWaterman(); sw->read_blosum();
        double maxScore = sw->algo(query_sequence, query_sequence);
        vector<char> all_file{0};  all_file.insert(all_file.end(),std::istreambuf_iterator<char>(file),(std::istreambuf_iterator<char>()));
        file.close();

        int index = 0;
        vector<int> other_sequence;
        int len = 0;
        int score = 0;
        for(int i = 0 ; i < file_size; i++){
            len = sequence_offset[index+1] - sequence_offset[index];
            other_sequence.clear();
            other_sequence.insert(other_sequence.begin(), all_file.begin() + i, all_file.begin() + (len + sequence_offset[index]));
            score = sw->algo(other_sequence, query_sequence);
            if ( maxScore/factor < score ){
                seq_score.push_back({score, index});
            }
            i += len - 1;
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

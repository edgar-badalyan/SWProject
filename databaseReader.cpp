
#include "databaseReader.h"

databaseReader::databaseReader(string database_path, string fasta_seq_path, int openPenalty, int extPenalty, double factor, string blosum_file) {
    pinFile = new pinReader();  phrFile = new phrReader(); psqFile = new psqReader();
    // -------------- query sequence --------------
    vector<int>  fasta_seq = get_fasta_seq(fasta_seq_path);
    // -------------- pinFile init ----------------
    pinFile->read_file(database_path +".pin", phrFile->get_header_offset(), psqFile->get_sequence_offset());
    int psq_file_size = pinFile->get_number_seq() + pinFile->get_res_count();
    cout << "Query file name:   " << fasta_seq_path << endl;

    // -------------- psqFile init ----------------
    vector<vector<int>> vec_score = psqFile->find_sequence_score(database_path + ".psq", fasta_seq, psq_file_size, openPenalty, extPenalty, factor, blosum_file);

    // sort the vector of sequences that have a score higher than the threshold
    // insertion sort is good enough because the vector shouldn't be too big.
    for (int i = 0; i < vec_score.size(); i++){
        vector<int> temp;
        int j=i;
        while (j>0 && vec_score[j-1][0]<vec_score[j][0]){
            temp = vec_score[j];
            vec_score[j] = vec_score[j-1];
            vec_score[j-1] = temp;
            j--;
        }
    }
    // print sequences
    for (int i = 0 ; i < vec_score.size() ; i++){
        cout <<  phrFile->read_header(database_path+".phr",vec_score[i][1]) << "      score : " <<vec_score[i][0] << endl;
    }

}

databaseReader::~databaseReader() {
    delete pinFile;
    delete phrFile;
    delete psqFile;
}
vector<int> databaseReader::get_fasta_seq(string file_name){

    std::vector<int> seq{0};
    ifstream file(file_name, std::ios::in);
    if( file.is_open() ){
        string line;
        int i = 0;
        while(getline(file, line)){
            if (i != 0){ //we don't want the first line
                for (int j =0;j<line.size();j++){
                    //decode_residue is the map that converts a residue to an int according to the NCBI BLAST format
                    seq.push_back(decode_residue[line[j]]);
                }
            }
            i++;
        }
        file.close();
        return seq;
    }
    else{
        cout << "error : fasta sequence file" << endl;
    }
    exit (1);
}

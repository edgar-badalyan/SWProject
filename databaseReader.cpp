
#include "databaseReader.h"

databaseReader::databaseReader(string database_path, string fasta_seq_path) {
    pinFile = new pinReader();  phrFile = new phrReader(); psqFile = new psqReader();
    vector<int>  fasta_seq = get_fasta_seq(fasta_seq_path);
    // -------------- pinFile init ----------------
    pinFile->read_file(database_path +".pin", phrFile->get_header_offset(), psqFile->get_sequence_offset());
    int psq_file_size = pinFile->get_number_seq() + pinFile->get_res_count();

    // -------------- psqFile init ----------------
    vector<vector<int>> vec_score = psqFile->find_sequence_score(database_path + ".psq", fasta_seq, psq_file_size);

    //#!  TO DO : Trier vec_score
    for (int i = 0 ; i < vec_score.size() ; i++){
        cout <<  phrFile->read_header(database_path+".phr",vec_score[i][1]) << "      index :" <<  vec_score[i][1]<< "      score : " <<vec_score[i][0] << endl;
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
                for (int i =0;i<line.size();i++){
                    seq.push_back(decode_residue[line[i]]);
                }
            }
            i++;
        }
        return seq;
        file.close();
    }
    else{
        cout << "error : fasta sequence file" << endl;
    }
    exit (1);
}

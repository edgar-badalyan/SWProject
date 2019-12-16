#include "pinReader.h"
#include "psqReader.h"
#include "phrReader.h"

int main(int argc, char* argv[]){
    if(argc < 3){
        cout << "missing file path, in order: database, sequence"<< endl;
    }
    else{
        pinReader* pinFile = new pinReader();
        phrReader* phrFile = new phrReader();
        psqReader* psqFile = new psqReader();

       /* if(argc > 3){
            for(int i =0; i<argc;i++){
                if(std::string(argv[i]) == "-t"){
                    psqFile->set_traceback();
                }else if(std::string(argv[i] == "-b")){
                    set_blosum(argv[i+1]);
                }else if(std::string(argv[i]) == "-go"){
                    set_gap_open(std::stoi(argv[i+1]));
                }else if(std::string(argv[i]) == "-ge"){
                    set_gap_ext(std::stoi(argv[i+1]));
                }
            }
        }*/

        string database_path(argv[1]);
        pinFile->read_index(database_path + ".pin", phrFile->get_header_offset(), psqFile->get_sequence_offset());

        vector<int> sequence = psqFile->get_sequence_fasta(argv[2]); //query sequence
        psqFile->find_sequence(database_path + ".psq",sequence);
        //string header= phrFile->read_header(database_path + ".phr",psqFile->find_sequence(database_path + ".psq",sequence));
        //cout << "Query description: "<< header << endl;

        delete pinFile;
        delete phrFile;
        delete psqFile;
    }
}

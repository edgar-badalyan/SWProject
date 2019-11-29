#include "pinReader.h"
#include "psqReader.h"
#include "phrReader.h"

int main(int argc, char* argv[]){
    if(argc != 3){
        cout << "missing file path, in order = database, sequence"<< endl;
    }
    else{
        pinReader* pinFile = new pinReader();
        phrReader* phrFile = new phrReader();
        psqReader* psqFile = new psqReader();

        string database_path(argv[1]);
        pinFile->read_index(database_path + ".pin");

        phrFile->set_header_offset(pinFile->get_header_offset());
        psqFile->set_sequence_offset(pinFile->get_sequence_offset());

        string sequence = psqFile->get_sequence_fasta(argv[2]); //query sequence
        //std::cout << "sequence:" << endl << sequence << endl;

        string header= phrFile->read_header(database_path + ".phr",psqFile->find_sequence(database_path + ".psq",sequence));
        cout << "Query description: "<< header << endl;
    }
}

#include "pinReader.h"
#include "psqReader.h"
#include "phrReader.h"
#include "smithWaterman.h"


int main(int argc, char* argv[]){
    if(argc != 5){
        cout << "missing file path, in order = .pin, .fasta, .phr, .psq"<< endl;
    }
    else{
        pinReader* pinFile = new pinReader();
        phrReader* phrFile = new phrReader();
        psqReader* psqFile = new psqReader();
        smithWaterman* smithW = new smithWaterman();

        pinFile->read_index(argv[1], phrFile->get_header_offset(), psqFile->get_sequence_offset());

        string sequence = psqFile->get_sequence_fasta(argv[2]);
        string header= phrFile->read_header(argv[3],psqFile->find_sequence(argv[4],sequence));

        cout << "Query description: "<< header << endl;
        smithW->run(sequence,sequence);

        delete pinFile;
        delete phrFile;
        delete psqFile;
        delete smithW;
    }
}

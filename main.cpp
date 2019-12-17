#include "databaseReader.h"

int main(int argc, char* argv[]){
    if(argc < 3){
        cout << "missing file path, in order: database, sequence"<< endl;
    }
    else{
        /*
        pinReader* pinFile = new pinReader();
        phrReader* phrFile = new phrReader();
        psqReader* psqFile = new psqReader();

        string database_path(argv[1]);
        pinFile->read_file(database_path + ".pin", phrFile->get_header_offset(), psqFile->get_sequence_offset());

        vector<int> sequence = psqFile->get_sequence_fasta(argv[2]); //query sequence
        psqFile->find_sequence(database_path + ".psq",sequence);
        //string header= phrFile->read_header(database_path + ".phr",psqFile->find_sequence(database_path + ".psq",sequence));
        //cout << "Query description: "<< header << endl;

        delete pinFile;
        delete phrFile;
        delete psqFile;
        */
        databaseReader * databaseFiles = new databaseReader(argv[1], argv[2]);
        delete databaseFiles;
    }
}

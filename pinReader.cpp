#include "pinReader.h"

pinReader::pinReader() {
}

void  pinReader::read_file(string file_name, vector<uint32_t> *phr_header_offset, vector<uint32_t> *psq_sequence_offset) {
    //reads the info on the database from the .pin binary file
    ifstream file(file_name, std::ios::in | std::ios::binary);
    if(file.is_open()){
        uint32_t version; read_uint(file, version);
        uint32_t type; read_uint(file, type);
        uint32_t length; read_uint(file, length);
        char title[length + 1]; read_char(title, file, length);
        uint32_t timestamp_length; read_uint(file, timestamp_length);
        char timestamp[timestamp_length + 1]; read_char(timestamp, file, timestamp_length);
        read_uint(file, number_seq);
        read_uint(file, res_count);
        uint32_t max_seq; read_uint(file, max_seq);

        std::cout << "Database file:     " <<  title << endl;
        std::cout << "Database title:    " <<  title << endl;
        std::cout << "Database time:     " << timestamp <<endl;
        std::cout << "Database size:     " << res_count << " residues in "<< number_seq <<" sequences"<<endl;
        std::cout << "Longest db seq:    " << max_seq << " residues" <<endl;

        for (int i = 0;i<number_seq+1;i++){
            uint32_t offset; read_uint(file, offset);
            (*phr_header_offset).push_back(offset);
        }
        for (int i = 0;i<number_seq+1;i++){
            uint32_t offset; read_uint(file, offset);
            (*psq_sequence_offset).push_back(offset);
        }
    }
    else{
        cout << " Error : pin file " << endl;
    }
}

template <typename type>
void pinReader::read_uint( ifstream & file, type & element){
      file.read((char *)&element, sizeof(type));
      if( typeid(element) == typeid(uint32_t)){
        element = __builtin_bswap32(element);
      }
}

void pinReader::read_char(char* element, ifstream & file, int length){
    file.read(element, length);
    element[length] = '\0';
}

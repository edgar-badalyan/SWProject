//
// Created by Raymond Khazoum on 28/11/2019.
//

#ifndef SWIPE_PHRREADER_H
#define SWIPE_PHRREADER_H
#include <vector>
#include <string>

class phrReader {
public:
    phrReader();
    std::string read_header(std::string file_name, int i);
    std::vector<uint32_t> header_offset;

};


#endif //SWIPE_PHRREADER_H

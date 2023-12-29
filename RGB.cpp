//
// Created by poci on 12/27/23.
//

#include "header_files/RGB.h"


void RGB::divide(float d)
{
    red /= d;
    green /= d;
    blue /= d;
}

//OPACITY IS ALREADY INCLUDED

u32 RGB::convert_to_hex() const
{
    std::stringstream res;
    res << "ff" << std::setfill ('0') << std::setw(sizeof(uint8_t)*2) << std::hex << int(blue);
    res << std::setfill ('0') << std::setw(sizeof(uint8_t)*2) << std::hex << int(green);
    res << std::setfill ('0') << std::setw(sizeof(uint8_t)*2) << std::hex << int(red);
    return std::stoul(res.str(), nullptr, 16);
}


#ifndef Hash_H
#define Hash_H
#pragma once
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include "../hash/sha1.hpp"
class Block
{
    public:
        int index,proof_no;
        time_t timer;
        int timestamp = time(&timer);
        std::string hash,prev_hash,data;
        inline std::string calculate_hash()const;
        Block(int indexIn, const std::string &dataIn);
        void mineblock(int Difficulty);
        static bool check_validity(Block prev_block,Block block);
};


#endif
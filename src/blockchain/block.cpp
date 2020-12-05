
#include <vector>
#include <string>
#include <cstdarg>
#include <cstring>
#include <time.h>
#include "block.hpp"
#include <sstream>
Block::Block(int indexIn, const std::string &dataIn) : index(indexIn), data(dataIn)
{

   hash = calculate_hash();
}
inline std::string Block::calculate_hash() const
{
    time_t timer;
    std::stringstream ss;
    SHA1 checksum;
    ss << index << prev_hash << time(&timer) << data << proof_no;
    checksum.update(ss);
    return checksum.final();
}
void Block::mineblock(int Difficulty)
{
    char cstr[Difficulty + 1];
    for (int i = 0; i < Difficulty; ++i)
    {
        cstr[i] = '0';
    }
    cstr[Difficulty] = '\0';

    std::string str(cstr);
    int i = 0;

    do
    {
        i++;
        hash = calculate_hash();
    }

   while (hash.substr(0, Difficulty) != str);

    std::cout <<i/1000<<"kh/s Block mined: " << hash << std::endl;
}
bool Block::check_validity(Block prev_block,Block block)
{
    if (prev_block.index +1 != block.index)
    {
        return false;
    }
    else if (prev_block.calculate_hash() != block.hash)
    {
        return false;
    }
    else if (block.timestamp <= prev_block.timestamp)
    {
        return false;
    }
    return true;
}
#include "blockchain.hpp"
#include <ostream>
#include <iostream>
#include <iterator>
Blockchain::Blockchain()
{
    chain.emplace_back(Block(0,"ABX TO THE MOOOON"));
    difficulty = 1;
}
void Blockchain::add_block(Block new_block)
{
    new_block.prev_hash = get_last_block().hash;
    new_block.mineblock(difficulty);
    chain.push_back(new_block);
}

Block Blockchain::get_last_block()
{
    return chain.back();
}
// Block.cpp

#include "Block.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <openssl/sha.h>
#include <iomanip>

using namespace std;

Block::Block(int index, string data, string previousHash)
    : index(index), data(data), previousHash(previousHash) {
    this->timestamp = getTimestamp();
    this->hash = calculateHash();
}

string Block::calculateHash() {
    stringstream ss;
    ss << index << timestamp << data << previousHash;
    string blockContent = ss.str();

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, blockContent.c_str(), blockContent.length());
    SHA256_Final(hash, &sha256);

    stringstream hashStringStream;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        hashStringStream << std::setfill('0') << std::setw(2) << std::hex << (int)hash[i];
    }

    return hashStringStream.str();
}

string Block::getTimestamp() {
    time_t now = time(0);
    char* dt = ctime(&now);
    return string(dt);
}

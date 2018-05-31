#include <iostream>
#include <string>
#include <ctime>
#include "sha256.h"
#include "block.h"

using namespace std;

string Block::createHash(){
    string headHash = sha256(
        prevHash+
        std::to_string(timestamp)+
        msg+
        to_string(nonce)
    );
    return headHash;
}

void Block::miningBlock(int _difficult){
    srand((unsigned int)time(0));
    int random = rand() % (64-_difficult);
    string target = hash.substr(random, _difficult);

    while(hash.substr(0,_difficult) != target) {
        nonce++;
        hash = createHash();
    }
    cout<<"block head : "<<hash<<endl;
}
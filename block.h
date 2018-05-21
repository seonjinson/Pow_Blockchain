#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "sha256.h"

using namespace std;

class Block {
private:
    int nonce;
    time_t time;

public:
    string hash;
    string prevHash;
    string msg;
    unsigned int height;

    string createHash();
    time_t getTime(){
        return this->time;
    }
    Block(){
    }
    Block(string _prevHash, string _msg, unsigned int _height){
        this->prevHash = _prevHash;
        this->msg = _msg;
        this->height = _height;
        this->time = std::time(nullptr);
        this->hash = createHash();
    }
};

string Block::createHash(){
    string headHash = sha256(
        prevHash+
        std::to_string(time)+
        msg
    );
    cout<<"time : "<<getTime()<<endl;
    return headHash;
}

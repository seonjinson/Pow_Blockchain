#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Block {
private:
    int nonce =0;
    time_t timestamp;

public:
    string hash;
    string prevHash;
    string msg;
    unsigned int height;

    string createHash();
    void miningBlock(int difficult);
    
    time_t getTime(){
        return this->timestamp;
    }
    Block(){
    }
    Block(string _prevHash, string _msg, unsigned int _height){
        this->prevHash = _prevHash;
        this->msg = _msg;
        this->height = _height;
        this->timestamp = std::time(nullptr);
        this->hash = createHash();
    }
};

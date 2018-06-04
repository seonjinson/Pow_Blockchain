#include <iostream>
#include "sha256.h"
#include "block.h"
#include "json/json.h"

using namespace std;

int main() {
    Json::Value root;
    Json::Value chain;

    vector<Block> Blockchain;
    Blockchain.push_back({"","This is first block",Blockchain.size()});
    Blockchain[Blockchain.size()-1].miningBlock(3);

    Blockchain.push_back({Blockchain[Blockchain.size()-1].hash,"This is second block",Blockchain.size()});
    Blockchain[Blockchain.size()-1].miningBlock(4);

    Blockchain.push_back({Blockchain[Blockchain.size()-1].hash,"This is Third block",Blockchain.size()});
    Blockchain[Blockchain.size()-1].miningBlock(5);

    for(std::vector<Block>::iterator it = Blockchain.begin(); it != Blockchain.end(); it++) {

    root["prevHash"] = it->prevHash;
    root["message"] = it->msg;
    root["height"] = it->height;
    root["Hash"] = it->hash;

    chain["blockchain"].append(root);
    }

    Json::StyledWriter writer;
    string output = writer.write(chain);

    cout<<output<<endl;

    return 0;
}
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
    cout<<"Hash for block 1: "<<Blockchain[Blockchain.size()-1].hash <<endl;

    Blockchain.push_back({Blockchain[Blockchain.size()-1].hash,"This is second block",Blockchain.size()});
    cout<<"Hash for block 2: "<<Blockchain[Blockchain.size()-1].hash <<endl;

    for(std::vector<Block>::iterator it = Blockchain.begin(); it != Blockchain.end(); it++) {

    root["prevHash"] = it->prevHash;
    root["message"] = it->msg;
    root["height"] = it->height;

    chain["blockchain"].append(root);
    }

    Json::StyledWriter writer;
    string output = writer.write(chain);

    cout<<output<<endl;

    return 0;
}
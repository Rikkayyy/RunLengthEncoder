#include "RLEInfo.h"

RLEInfo::RLEInfo() {
    RLEString = "";
    RLEFrequencies;
}

void RLEInfo::setString(string inputString) {
    RLEString = inputString;
}

void RLEInfo::setFreq(int inputValue) {
    RLEFrequencies.push_back(inputValue);
}

string RLEInfo::getString() const {
    return RLEString;
}

vector<int> RLEInfo::getFreq() const {
    return RLEFrequencies;
}


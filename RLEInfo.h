#ifndef RLEInfo_H
#define RLEInfo_H
#include <vector>
#include <iostream>

using namespace std;

class RLEInfo {
    private:
    string RLEString; //string to store RLE string
    vector<int> RLEFrequencies; // vector to store the array of frequencies

    public:
    RLEInfo(); // Default constructor
    void setString(string inputString);
    void setFreq(int inputValue); // adds Frequency value to RLEFrequencies vector
    string getString() const;
    vector<int> getFreq() const;
    friend ostream &operator <<(ostream &output, const RLEInfo &obj) {
        output << obj;
        return output;
    }
    friend istream &operator >>(istream &input, const RLEInfo &obj) {
        input >> obj;
        return input;
    }

};

#endif

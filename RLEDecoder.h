#ifndef RLEDecoder_H
#define RLEDecoder_H
#include "RLEInfo.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class RLEDecoder {
    private:
    int size;
    RLEInfo* data;
    string* originalMessages;

    public:
    RLEDecoder(int numMessages); // overloaded constructor
    RLEDecoder(const RLEDecoder& obj); // copy constructor
    RLEDecoder& operator=(const RLEDecoder& objToCopy); // copy-assignment operator
    ~RLEDecoder(); // destructor
    bool readFromFile(const string&); // opens and reads file
    void printInfo();
    void printDecodedMessages();
    void decode();
};

#endif

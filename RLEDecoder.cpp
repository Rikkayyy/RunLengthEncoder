#include "RLEDecoder.h"

//overloading constructor
RLEDecoder::RLEDecoder(int nMessages) { 
    size = nMessages;
    data = new RLEInfo[size];
    originalMessages = new string[size];
}

//copy constructor
RLEDecoder::RLEDecoder(const RLEDecoder& obj) {
    size = obj.size;
    data = new RLEInfo[size];
    data = obj.data;
    originalMessages = new string[size];
    originalMessages = obj.originalMessages;
}

//copy-assignment operator
RLEDecoder& RLEDecoder::operator=(const RLEDecoder& objToCopy) {
    if (this != &objToCopy) {
        delete [] data;
        delete [] originalMessages;
        size = objToCopy.size;
        data = new RLEInfo;
        data = objToCopy.data;
        originalMessages = objToCopy.originalMessages;
    }
    return *this;
}

//destructor
RLEDecoder::~RLEDecoder() {
    delete [] data;
    delete [] originalMessages;
}

bool RLEDecoder::readFromFile(const string& FileName) {
    // getting information from file
    ifstream inFS;
    inFS.open(FileName); //opening file
    if (!inFS.is_open()) {
        return false; // Returns false if FileName can't be opened
    }
    bool isstring = true; // differentiating between string and frequency
    int i = 0;
    while (!inFS.eof()) {
        if (isstring) {
            string MessageInfo;
            getline(inFS, MessageInfo);
            data[i].setString(MessageInfo); // initializing RLEString
            isstring = false; // next line will be frequency
            //cout << data[i].getString() << endl; //testing
            }
        else {
            string lineInfo;
            getline(inFS, lineInfo);
            std::istringstream iss(lineInfo); // Turning string into int vector
            int number;
            int vectorSize;
            iss >> vectorSize; // grabs first number in Frequency line
            while (iss >> number) {
                data[i].setFreq(number);// initializing RLEFrequencies
                }
            i++;
            isstring = true; // next line will be string
            /*for (int j = 0; j < vectorSize; j++) {
                cout << data[i].getFreq().at(j) << " ";
            }
            cout << endl;*/ // tests to see values in RLEFrequencies vector
        }
    }
    inFS.close();
    return true;
}

void RLEDecoder::printInfo() {
    for (int i = 0; i < size; i++){
        cout << "RLEString: " << data[i].getString() << endl;
        cout << "RLEFrequencies: ";
        for (int j = 0; j < data[i].getFreq().size(); j++) {
                cout << data[i].getFreq().at(j) << " ";
        }
        cout << endl << endl;
    }
}

void RLEDecoder::printDecodedMessages() {
    for (int i = 0; i < size; i++) {
        cout << "Decoded Message " << i+1 << ": " << originalMessages[i] << endl;
        if (i < size-1) {
            cout << endl;
        }
    }

}

void RLEDecoder::decode() {
    for (int i = 0; i < size; i++) { // iterating over each data object
        string RLEStr = data[i].getString(); 
        vector<int> Freq = data[i].getFreq();
        string original = "";
        //cout << "HERE: " << RLEStr;
        for (int j = 0; j < RLEStr.length(); j++) { //iterating over string
            // if double add certain amount to original
            if (j <= RLEStr.length()-1) {
                if (RLEStr[j] == RLEStr[j+1]) {
                    int multiply = Freq.at(0);
                    for (int k = 0; k < multiply; k++) {
                        original += RLEStr[j];
                    }
                    Freq.erase(Freq.begin()); // removing frequency used
                    j++; // skips over double letter
                }
                else {
                    original += RLEStr[j];
                }
            }
            else {
                original += RLEStr[j];
            }
        }
        originalMessages[i] = original; // initializing over original message
    }
}
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<uint8_t> getBinaryVector(uint8_t value);

vector<uint8_t> bitMasks = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};

int bitCount = 8;
int byteCount = 4;

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    int maskGetByte = 0x000000FF;

    vector<uint8_t> byteVec(byteCount);
    vector<vector<uint8_t>> bitRepr(byteCount);
    for (size_t i = 0; i < bitRepr.size(); i++) {
        bitRepr[i].resize(bitCount);
    }

    cout << "¬ведите число: ";
    cin >> n;
    
    int byte = 0;
    int bitShift = 0;
    for (int i = 0; i < byteCount; i++) {
        byte = n & maskGetByte;
        byte = byte >> bitShift;
        byteVec[byteCount - i - 1] = byte;
        maskGetByte = maskGetByte << bitCount;
        bitShift += bitCount;
    }
    
    for (size_t i = 0; i < byteVec.size(); i++) {
        cout << (int)byteVec[i] << endl;
    }

    for (size_t i = 0; i < byteVec.size(); i++) {
        bitRepr[i] = getBinaryVector(byteVec[i]);
    }

    for (size_t i = 0; i < bitRepr.size(); i++) {
        for (size_t j = 0; j < bitRepr[i].size(); j++) {
            cout << (int)bitRepr[i][j];
        }
        cout << endl;
    }

    system("pause");
    return 0;
}


vector<uint8_t> getBinaryVector(uint8_t value) {

    vector<uint8_t> binVec(bitCount);
    uint8_t bit = 0;
    for (int i = 0; i < bitCount; i++) {
        bit = value & bitMasks[i];
        if (bit != 0) {
            binVec[i] = 1;
        }
        else {
            binVec[i] = 0;
        }
    }

    return binVec;
}
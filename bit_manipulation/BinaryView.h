#ifndef _BINARY_VIEW_
#define _BINARY_VIEW_

#include <iostream>
#include <vector>

using std::vector;

class BinaryView {
public:
    static BinaryView& getInstance() {
        static BinaryView bw;
        return bw;
    }

    vector<uint8_t> getBinaryNumberForm(int value);
    int getDecimalFromBinaryNumberForm(vector<uint8_t> binForm);

    int bitCount = 8;
    int byteCount = 4;
    int maxBitCount = 32;

    vector<uint8_t> bitMasks = { 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01 };

private:
    BinaryView() {};
    ~BinaryView() {};

    vector<uint8_t> getValueByteToBit(uint8_t value);
    vector<vector<uint8_t>> getBinaryMatrix(vector<uint8_t> binVect);
};

#endif


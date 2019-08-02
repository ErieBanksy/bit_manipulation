#include "BinaryView.h"


vector<uint8_t> BinaryView::getValueByteToBit(uint8_t value) {
    vector<uint8_t> binVec(bitCount);//get value byte to bit
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


vector<uint8_t> BinaryView::getBinaryNumberForm(int value) {
    int maskGetByte = 0x000000FF;

    vector<uint8_t> byteVec(byteCount); 
    vector<uint8_t> bitVector(maxBitCount);

    int byte = 0;
    int bitShift = 0;
    for (int i = 0; i < byteCount; i++) {
        byte = value & maskGetByte;
        byte = byte >> bitShift;
        byteVec[byteCount - i - 1] = byte;
        maskGetByte = maskGetByte << bitCount;
        bitShift += bitCount;
    }

    vector<uint8_t> tmpBitVec;
    for (int i = 0; i < byteCount; i++) {
        tmpBitVec = getValueByteToBit(byteVec[i]);
        for (int j = 0; j < bitCount; j++) {
            bitVector[bitCount * i + j] = tmpBitVec[j];
        }
    }

    return bitVector;
}


vector<vector<uint8_t>> BinaryView::getBinaryMatrix(vector<uint8_t> binVect) {
    vector<vector<uint8_t>> binaryMatrix(byteCount);
    for (size_t i = 0; i < binaryMatrix.size(); i++) {
        binaryMatrix[i].resize(bitCount);
    }

    for (int i = 0; i < byteCount; i++) {
        for (int j = 0; j < bitCount; j++) {
            binaryMatrix[i][j] = binVect[bitCount * i + j];
        }
    }

    return binaryMatrix;
}


int BinaryView::getDecimalFromBinaryNumberForm(vector<uint8_t> binForm) {
    int number = 0;

    for (int i = 0; i < maxBitCount; i++) {
        number += binForm[i] * static_cast<int>(pow(2, maxBitCount - i - 1));
    }

    return number;
}
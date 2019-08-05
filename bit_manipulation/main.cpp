#include "BinaryView.h"
#include <climits>

using std::cout;
using std::cin;
using std::endl;

typedef unsigned int uint;

const int maxBitCount = 32;

void printVector(vector<uint8_t> vect, uint decValue);
void bitManipulation(uint x, uint y, int m , int n);

int main() {
    setlocale(LC_ALL, "Russian");

    uint x, y;
    int m, n;
    cout << "Input numbers x, y, m, n: ";
    cin >> x >> y >> m >> n;

    if (x < 0 || x > UINT_MAX ||
        y < 0 || y > UINT_MAX ||
        m < 0 || m > maxBitCount ||
        n < 0 || n > maxBitCount) {
        cout << "ERROR: Incorrect values ??entered!" << endl;
        system("pause");
        return -1;
    }

    bitManipulation(x, y, m, n);

    system("pause");
    return 0;
}


void bitManipulation(uint x, uint y, int m, int n) {
    cout << endl;
    cout << "\t\t\tbinary" << "\t\t\tdecimal" << endl;
    cout << endl;

    BinaryView &bw = BinaryView::getInstance();

    vector<uint8_t> xVec = bw.getBinaryNumberForm(x);
    vector<uint8_t> yVec = bw.getBinaryNumberForm(y);

    cout << "X = \t";
    printVector(xVec, x);

    cout << "Y = \t";
    printVector(yVec, y);

    size_t xVecSize = xVec.size();
    for (int i = 0; i < m; i++) {
        xVec[xVecSize - i - 1] = yVec[m - i - 1];
    }

    cout << "modX = \t";
    printVector(xVec, bw.getDecimalFromBinaryNumberForm(xVec));

    size_t yVecSize = yVec.size();
    for (int i = 0; i < n; i++) {
        if (yVec[yVecSize - i - 1] == 1) {
            yVec[yVecSize - i - 1] = 0;
        }
        else {
            yVec[yVecSize - i - 1] = 1;
        }
    }

    cout << "modY = \t";
    printVector(yVec, bw.getDecimalFromBinaryNumberForm(yVec));
}


void printVector(vector<uint8_t> vect, uint decValue) {
    int bitCount = 8;

    for (size_t i = 0; i < vect.size(); i++) {
        if (i % bitCount == 0) {
            cout << " ";
        }
        cout << static_cast<int>(vect[i]);
    }
    cout << " | \t" << decValue << endl;
    cout << endl;
}
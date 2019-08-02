#include "BinaryView.h"

#define MAX_INT_SIZE 4294967295
#define MAX_BIT_COUNT 32

using std::cout;
using std::cin;
using std::endl;

typedef unsigned int uint;

void printVector(vector<uint8_t> vect, uint decValue);
void bitManipulation(uint x, uint y, uint m , uint n);

int main() {
    setlocale(LC_ALL, "Russian");

    uint x, y, m , n;
    cout << "¬ведите числа x, y, m, n: ";
    cin >> x >> y >> m >> n;

    if (x < 0 || x > MAX_INT_SIZE || 
        y < 0 || y > MAX_INT_SIZE || 
        m < 0 || m > MAX_BIT_COUNT ||
        n < 0 || n > MAX_BIT_COUNT) {
        cout << "ERROR: ¬ведены некорректные значени€!" << endl;
        system("pause");
        return -1;
    }

    bitManipulation(x, y, m, n);

    system("pause");
    return 0;
}


void bitManipulation(uint x, uint y, uint m, uint n) {
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
    for (size_t i = 0; i < m; i++) {
        xVec[xVecSize - i - 1] = yVec[m - i - 1];
    }

    cout << "modX = \t";
    printVector(xVec, bw.getDecimalFromBinaryNumberForm(xVec));

    size_t yVecSize = yVec.size();
    for (size_t i = 0; i < n; i++) {
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
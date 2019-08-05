# Bit manipulation

The program reads from the keyboard 4 decimal numbers x, y, m, n. Of x, the lower m bits are replaced by the highest m bits of y, then the lower n bits are inverted in y.

As a result, the program displays the binary form of the original numbers x and y, as well as the new x and y values ​​obtained in decimal and binary form.

The program is implemented without the use of special libraries.

The numbers x and y are of type unsigned int.

---

Программа считывает с клавиатуры 4 десятичных числа x, y, m, n. В числе x младшие m бит  заменяются на старшие m бит из числа y, затем младшие n бит инвертируются в числе y.

В результате программа выводит двоичный вид исходных чисел х и у, а также полученные новые значения х и у в десятичном и двоичном виде.

Программа реализована без использования специальных библиотек.

Числа x и y имеют тип  unsigned int.

---

**Examples/Примеры:**

1. Input: 
x = 60627  
y = 3725  
m = 5 
n = 7 

Output:

X =      00000000 00000000 11101100 11010011 |  60627

Y =      00000000 00000000 00001110 10001101 |  3725

modX =   00000000 00000000 11101100 11000000 |  60608

modY =   00000000 00000000 00001110 11110010 |  3826


2. Input: 
x = 456961458  
y = 2326052717 
m = 17 
n = 23 

Output:


X =      00011011 00111100 10101101 10110010 |  456961458

Y =      10001010 10100100 10111111 01101101 |  2326052717

modX =   00011011 00111101 00010101 01001001 |  456987977

modY =   10001010 11011011 01000000 10010010 |  2329624722

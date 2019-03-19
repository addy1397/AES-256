#ifndef AES_H
#define AES_H

#include<bits/stdc++.h>
using namespace std;

typedef uint8_t small;

class AES{
private:
	small (*text)[4]=new small[4][4];
	int size();
	small key[4][56];
public:
	AES(small text[][4]);
	void fillText(small text[][4]);
	void fillKey();
	void keyGeneration();
	void addRoundKey(small round);
	void encryption();
	void decryption();
	void show();
};

void *shiftRowsEncrypt(small stateArray[][4]);
void *shiftRowsDecrypt(small stateArray[][4]);

#endif
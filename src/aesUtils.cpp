//TOODO : remove headers
#include<bits/stdc++.h>
#include"../include/gf256.h"
#include"../include/aes.h"
using namespace std;
typedef uint8_t small;


void *shiftRowsEncrypt(small stateArray[][4])
{
	small temp=stateArray[1][0];
	stateArray[1][0]=stateArray[1][1];
	stateArray[1][1]=stateArray[1][2];
	stateArray[1][2]=stateArray[1][3];
	stateArray[1][3]=temp;

	temp=stateArray[2][0];
	stateArray[2][0]=stateArray[2][1];
	stateArray[2][1]=stateArray[2][2];
	stateArray[2][2]=stateArray[2][3];
	stateArray[2][3]=temp;
	temp=stateArray[2][0];
	stateArray[2][0]=stateArray[2][1];
	stateArray[2][1]=stateArray[2][2];
	stateArray[2][2]=stateArray[2][3];
	stateArray[2][3]=temp;

	temp=stateArray[3][0];
	stateArray[3][0]=stateArray[3][1];
	stateArray[3][1]=stateArray[3][2];
	stateArray[3][2]=stateArray[3][3];
	stateArray[3][3]=temp;
	temp=stateArray[3][0];
	stateArray[3][0]=stateArray[3][1];
	stateArray[3][1]=stateArray[3][2];
	stateArray[3][2]=stateArray[3][3];
	stateArray[3][3]=temp;
	temp=stateArray[3][0];
	stateArray[3][0]=stateArray[3][1];
	stateArray[3][1]=stateArray[3][2];
	stateArray[3][2]=stateArray[3][3];
	stateArray[3][3]=temp;

	return stateArray;
}
void *shiftRowsDecrypt(small stateArray[][4])
{
	small temp=stateArray[1][3];
	stateArray[1][3]=stateArray[1][2];
	stateArray[1][2]=stateArray[1][1];
	stateArray[1][1]=stateArray[1][0];
	stateArray[1][0]=temp;

	temp=stateArray[2][3];
	stateArray[2][3]=stateArray[2][2];
	stateArray[2][2]=stateArray[2][1];
	stateArray[2][1]=stateArray[2][0];
	stateArray[2][0]=temp;
	temp=stateArray[2][3];
	stateArray[2][3]=stateArray[2][2];
	stateArray[2][2]=stateArray[2][1];
	stateArray[2][1]=stateArray[2][0];
	stateArray[2][0]=temp;

	temp=stateArray[3][3];
	stateArray[3][3]=stateArray[3][2];
	stateArray[3][2]=stateArray[3][1];
	stateArray[3][1]=stateArray[3][0];
	stateArray[3][0]=temp;
	temp=stateArray[3][3];
	stateArray[3][3]=stateArray[3][2];
	stateArray[3][2]=stateArray[3][1];
	stateArray[3][1]=stateArray[3][0];
	stateArray[3][0]=temp;
	temp=stateArray[3][3];
	stateArray[3][3]=stateArray[3][2];
	stateArray[3][2]=stateArray[3][1];
	stateArray[3][1]=stateArray[3][0];
	stateArray[3][0]=temp;


	return stateArray;
}

void *mixColumnsEncrypt(small stateArray[][4])
{
	small (*arr)[4]=new small[4][4];
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			arr[i][j]=multiply(2,stateArray[i][j]);
			arr[i][j]^=multiply(3,stateArray[(i+1)%4][j]);
			arr[i][j]^=stateArray[(i+2)%4][j];
			arr[i][j]^=stateArray[(i+3)%4][j];
		}
		return arr;
}

void *mixColumnsDecrypt(small stateArray[][4])
{
	small (*arr)[4]=new small[4][4];
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			arr[i][j]=multiply(14,stateArray[i][j]);
			arr[i][j]^=multiply(11,stateArray[(i+1)%4][j]);
			arr[i][j]^=multiply(13,stateArray[(i+2)%4][j]);
			arr[i][j]^=multiply(9,stateArray[(i+3)%4][j]);
		}
		return arr;
}

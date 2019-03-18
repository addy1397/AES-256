#include<bits/stdc++.h>
#include"aes.h"
#include"aesUtils.cpp"
#include"sbox.cpp"
#include"constants.cpp"
using namespace std;

AES::AES(small text[][4]){
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			this->text[i][j]=text[i][j];
}

void AES::fillKey(){
	cout<<"Fill Key : \n";
	int x;
	for(int i=0;i<8;i++)
		for(int j=0;j<4;j++){
			cout<<"KEY : "<<i<<" "<<j<<"\n";
			cin>>x;
			this->key[j][i]=x;
		}
	for(int i=0;i<8;i++){
		for(int j=0;j<4;j++)
			cout<<int(this->key[i][j])<<" ";
		cout<<"\n";
	}
	this->keyGeneration();
}


void AES::keyGeneration(){
	for(int i=8;i<56;i++)
		if(i%8==0)
		{	
			small temp[4];
			for(int j=0;j<4;j++){
				temp[(j+3)%4]=this->key[i-1][j];
				temp[(j+3)%4]=sboxEncryption[temp[(j+3)%4]];
				if((j+3)%4==0)
					temp[(j+3)%4]^=(1<<((i/8)-1));
				cout<<temp[(j+3)%4]<<"\n";
			}
		}
		else
		{	
			for(int j=0;j<4;j++)
				key[i][j]=key[i-1][j]^key[i-8][j];
		}
}

void AES::addRoundKey(small round){
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			this->text[i][j]^=key[round*4+i][j];
}

void AES::show()
{
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++)
			cout<<text[i][j]<<" ";
		cout<<"\n";
	}

}

void AES::encryption(){
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			this->text[i][j]^=IV[i][j];
			this->text[i][j]^=key[i][j];
		}

	for(int i=1;i<=12;i++)
	{
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				this->text[i][j]=sboxEncryption[this->text[i][j]];
		this->text=(small(*)[4])shiftRowsEncrypt(this->text);
		this->text=(small(*)[4])mixColumnsEncrypt(this->text);
		this->addRoundKey(i);
	}

	for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				this->text[i][j]=sboxEncryption[this->text[i][j]];
	this->text=(small(*)[4])shiftRowsEncrypt(this->text);
	this->addRoundKey(13);
	this->show();

}

int main(){
	cout<<"Change IV in constants file : \n";
	cout<<"Enter 16 bytes of text for encryption : \n";
	small text[4][4];
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			cout<<"BYTE : "<<i*4+j<<" : ";
			cin>>text[j][i];
		}
	AES aes(text);
	cout<<"Enter Key : \n";
	aes.fillKey();
}

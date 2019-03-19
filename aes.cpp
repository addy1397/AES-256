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
			cout<<"KEY : "<<i<<" "<<j<<" : ";
			cin>>x;
			this->key[j][i]=(small)x;
		}
	/*for(int i=0;i<8;i++){
		for(int j=0;j<4;j++)
			cout<<int(this->key[j][i])<<" ";
		cout<<"\n";
	}*/
	this->keyGeneration();
	cout<<"\n\n";
	this->encryption();
	cout<<"\n\n";
	this->show();
}


void AES::keyGeneration(){
	for(int i=8;i<56;i++)
		if(i%8==0)
		{	
			small gfunc[4];
			for(int j=0;j<4;j++)
				gfunc[(j+3)%4]=this->key[j][i-1];
			for(int j=0;j<4;j++)
				gfunc[j]=sboxEncryption[gfunc[j]];
			gfunc[0]^=(1<<((i/8)-1));
			for(int j=0;j<4;j++)
				key[j][i]=gfunc[j];
		}
		else
		{	
			for(int j=0;j<4;j++)
				key[j][i]=key[j][i-1]^key[j][i-8];
		}
	for(int i=0;i<56;i++){
		for(int j=0;j<4;j++)
			cout<<(int)key[j][i]<<" ";
		cout<<"\n";
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
			cout<<(int)this->text[i][j]<<" ";
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

#include<bits/stdc++.h>
#include"../include/aes.h"
#include"aesUtils.cpp"
#include"sbox.cpp"
#include"constants.cpp"
using namespace std;

AES::AES(small text[][4]){
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			this->text[i][j]=text[i][j];
}

void AES::fillText(small text[][4]) {
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
	//cout<<"\n\n";
	//this->encryption();
	//cout<<"\n\n";
	//this->show();
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
	/*for(int i=0;i<56;i++){
		for(int j=0;j<4;j++)
			cout<<(int)key[j][i]<<" ";
		cout<<"\n";
	}*/
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

	this->show();
	cout<<"Starting .. \n";

	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			this->text[i][j]^=IV[i][j];
			this->text[i][j]^=key[i][j];
		}

	//this->show();
	//	cout<<"\n";

	for(int i=1;i<=12;i++)
	{
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				this->text[i][j]=sboxEncryption[this->text[i][j]];
		this->text=(small(*)[4])shiftRowsEncrypt(this->text);
		this->text=(small(*)[4])mixColumnsEncrypt(this->text);
		this->addRoundKey(i);

		//this->show();
		//cout<<"\n";

	}

	for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				this->text[i][j]=sboxEncryption[this->text[i][j]];

	//this->show();
	//cout<<"\n";

	this->text=(small(*)[4])shiftRowsEncrypt(this->text);
	this->addRoundKey(13);
	//this->show();

}

void AES::decryption()
{
	this->show();
	cout<<"Starting .. \n";

	this->addRoundKey(13);
	this->text=(small(*)[4])shiftRowsDecrypt(this->text);

	//this->show();
	//cout<<"\n";

	for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				this->text[i][j]=sboxDecryption[this->text[i][j]];

	for(int i=12;i>=1;--i)
	{
		this->addRoundKey(i);
		this->text=(small(*)[4])mixColumnsDecrypt(this->text);
		this->text=(small(*)[4])shiftRowsDecrypt(this->text);
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				this->text[i][j]=sboxDecryption[this->text[i][j]];

		//this->show();
		//cout<<"\n";
	}

	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			this->text[i][j]^=key[i][j];
			this->text[i][j]^=IV[i][j];
		}

	//this->show();
	//cout<<"\n";


}
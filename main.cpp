#include<bits/stdc++.h>
#include"../src/aes.cpp"
#include"../include/aes.h"
using namespace std;
int main(){
    cout<<"Change IV in constants file : \n";
    cout<<"Enter 16 bytes of text for encryption : \n";
    small text[4][4];
    int x;

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            cout<<"BYTE : "<<i*4+j<<" : ";
            cin>>x;
            text[i][j]=x;
            //cin>>text[j][i];
        }
    AES aes(text);

        cout<<"Text taken : \n";
        aes.show();

    cout<<"Enter Key : \n";

    aes.fillKey();

    cout<<"Starting Encryption : \n";
    aes.encryption();
    cout<<"\n";
    aes.show();
    cout<<"\n";


    /***
        Decryption started
    ***/
    
    cout<<"Enter 16 bytes of text for encryption : \n";
    //small text[4][4];
    //int x;

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            cout<<"BYTE : "<<i*4+j<<" : ";
            cin>>x;
            text[i][j]=x;
            //cin>>text[j][i];
        }

    aes.fillText(text);

    cout<<"Text taken : \n";
    aes.show();

    cout<<"Enter Key : \n";

    aes.fillKey();

    cout<<"Starting Decrytpion : \n";
    aes.decryption();
    cout<<"\n";
    aes.show();
    cout<<"\n";

}

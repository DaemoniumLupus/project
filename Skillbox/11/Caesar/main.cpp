#include <iostream>

using namespace std;

string encrypt_caesar(string original, int x){
    string newText;
    int temporary = 0;
    for (int i = 0; i < original.length(); i++){
        if((original[i] >= 'a' && original[i] <= 'z') || (original[i] >= 'A' && original[i] <= 'Z')){
            temporary = (int) original[i];
            if (original[i] >= 'a' && original[i] <= 'z'){
                temporary -= 'a';
            }else temporary -= 'A';

            temporary += x;
            temporary %= 26;

            if (original[i] >= 'a' && original[i] <= 'z'){
                temporary += 'a';
            }else temporary += 'A';

            newText += (char) temporary;

           /* if (text[i] >= 'a' && text[i] <= 'z'){
                temporary -= 'a'; 
                temporary += x;
                temporary %= 26;
                temporary += 'a';
                newText[i] = (char) temporary; 
            }else {
                temporary -= 'A'; 
                temporary += x;
                temporary %= 26;
                temporary += 'A';
                newText[i] = (char) temporary; 
            } */  
        }else newText += original[i];
    }
    return newText;
}

string decrypt_caesar(string str, int y){
   // y = -y;
    //y += 26;
    return encrypt_caesar(str, y);
}

int main(){
    string text;
    int bias;
    cout << "Enter text: ";
    getline(cin,text);
    cout << "Enter bias: ";
    cin >> bias;
    cout << encrypt_caesar(text, bias);
    cout << endl << decrypt_caesar(encrypt_caesar(text, bias), bias += 16);

}
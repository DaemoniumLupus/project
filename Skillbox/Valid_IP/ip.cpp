#include <iostream>

using namespace std;

string get_address_part(string str, int){

}

bool valid_IP(string str){
    string oktet;
    int oktet_int[4];
    bool match[4];
    for (int i = 0; i < 4; i++){
        oktet = get_address_part(str,i);
        if (oktet.length() <= 3){
            if (oktet.length() == 3){
                oktet_int[i] = (oktet[0] - '0') * 100 + (oktet[1] - '0') * 10 + (oktet[2] - '0');
            }else if (oktet.length() == 2){
                oktet_int[i] = (oktet[0] - '0') * 10 + (oktet[1]-'0');
            }else oktet[i] = oktet[0] - '0';
        }
        

    }
}

int main(){
    string IP;
    cout << "Enter IP-address: ";
    cin >> IP;
    if (valid_IP) cout << "Valid";
    else cout << "Invalid";


}
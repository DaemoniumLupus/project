#include <iostream>

using namespace std;

bool valid_string_IP(string str){
    string condition = "0123456789.";
    bool matchString = true;
    int dotCount = 0;
    int match[str.length()]; 
    if (str.length() < 16){
        for (int i = 0; i < str.length(); i++){
            if (str[i] == '.'){
                dotCount++;
            }
            for (int j = 0; j < condition.length(); j++){
                if (str[i] == condition[j]){
                    match[i] = 1;
                }
            }
        }
    }
    for(int i = 0; i < str.length(); i++){
            if (match[i] != 1) matchString = false; 
    }
    if (dotCount > 3) matchString = false;

    return matchString;
}

string get_address_part(string str, int x){
    string partAddress;
    int count = 0;
    for (int i = 0; i < str.length(); i++){
        if (str[i] == '.'){
            count++;
        }else if (count == x){
            partAddress += str[i];
        }  
        if (count > x) break;
    }
    return partAddress;
}

bool valid_IP(string str){
    string oktet;
    int oktet_int[4];
    bool match = true;
    for (int i = 0; i < 4 && match; i++){
        oktet = get_address_part(str,i);
        if (oktet == "00" || oktet == "000" || (oktet[0] == '0' && oktet.length() != 1)) match = false;
            if (oktet.length() <= 3){
                if (oktet.length() == 3){
                    oktet_int[i] = (oktet[0] - '0') * 100 + (oktet[1] - '0') * 10 + (oktet[2] - '0');
                }else if (oktet.length() == 2){
                    oktet_int[i] = (oktet[0] - '0') * 10 + (oktet[1]-'0');
                }else oktet_int[i] = oktet[0] - '0';
            }else match = false;
            if (oktet_int[i] < 0 || oktet_int[i] > 255){
                match = false;
            } 
          
    }
    return match;
}

int main(){
    string IP;
    while (true){
    cout << "Enter IP-address: ";
    cin >> IP;
    if (valid_string_IP(IP) && valid_IP(IP)) cout << "Valid";
    else cout << "Invalid";
    }
}
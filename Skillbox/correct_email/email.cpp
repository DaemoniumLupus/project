#include <iostream>

using namespace std;

string firstEmail, secondEmail;
bool match3 = false;

bool dot(string email){
    bool dot1 = true;
    for (int i = 0; i < email.length(); i++){
            if(email[i] == '.' && (email[i + 1] == '.' || email[i - 1] == '.')){
                dot1 = false;
                break;
            }
    }
    //cout << dot1;
    return dot1;
}

void separation(string email1){
    bool match = true;
    for (int i = 0; i < email1.length(); i++){
        if(email1[i] == '@'){ 
            match = false;
            match3 = true;
        }
        if (match){
            firstEmail += email1[i];
        }else if (email1[i] != '@'){
            secondEmail += email1[i];
        }
    }
}

bool firstMatch(string firstEmail){

    string /*char*/condition = "!#$%&'*+.-/=?^_`{|}~1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";/* {'!','#','$','%','&', 39,'*','+','-','.','/','=','?','^','_','`','{','|','}','~'};*/
    bool match1 = true;
    int match_1[firstEmail.length()];
    if (firstEmail.length() > 0 && firstEmail.length() < 64){
        for (int i = 0; i < firstEmail.length(); i++){
            if(firstEmail[i] == '.' && (firstEmail[i + 1] == '.' || firstEmail[i - 1] == '.')){
                match1 = false;
                break;
            }
            for (int j = 0; j < condition.length(); j++){
                if (firstEmail[i] == condition[j]){
                    match_1[i] = 1;
                }
            }
        }
        for(int i = 0; i < firstEmail.length(); i++){
            if (match_1[i] != 1) match1 = false;
        }
    }else match1 = false;
    //cout << match1;
    return match1;
}
bool secondMatch(string secondEmail){
    string condition2 = ".-1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    bool match2 = true;
    int match_2[secondEmail.length()];
    //cout << endl << secondEmail << endl;
    if (secondEmail.length() > 0 && secondEmail.length() < 64){
        for (int i = 0; i < secondEmail.length(); i++){
            if(secondEmail[i] == '.' && (secondEmail[i + 1] == '.' || secondEmail[i - 1] == '.')){
                cout << 22;
                match2 = false;
                break;
            }
            for (int j = 0; j < condition2.length(); j++){
                if (secondEmail[i] == condition2[j]){
                    match_2[i] = 1;
                }
            }
        }
        for(int i = 0; i < secondEmail.length(); i++){
            if (match_2[i] != 1) match2 = false;
        }
    }else match2 = false;
    //cout << match2;
    return match2;
}


int main(){
    string email;
    while(true){
        cout << "Enter email: ";
        cin >> email;
  
        separation(email);
    
        if (firstMatch(firstEmail) && secondMatch(secondEmail) && dot(email) && match3) cout << "Yes!";
        else cout << "No!";
    }
}
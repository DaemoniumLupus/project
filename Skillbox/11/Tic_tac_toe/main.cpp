#include <iostream>

using namespace std;

char masive[3][3];

string valid_rules(bool X, bool O){
    int countX = 0;
    int countO = 0;
    for(int x = 0; x < 3; x++){
        for (int y = 0; y < 3; y++){
            if (masive[x][y] == 'X') countX++;
            if (masive[x][y] == 'O') countO++; 
        }
    } 
    if (countX < countO) return "Incorrect.";
    if (X){
        if(countX > countO && countX - 1 == countO){
            return "Petya won";
        }else return "Incorrect.";
    }
    if (O){
        if(countX == countO){
            return "Vanya won";
        }else return "Incorrect.";

    }
    if (O == 0 && X == 0){
            return "Nobody.";
        }
    return "Incorrect.";
}

bool valid_field(string str){
    string condition = "X.O";
    int match[str.length()];
    if (str.length() > 9) return false;
    for (int i = 0; i < str.length(); i++){
        for (int j = 0; j < condition.length(); j++){
            if (str[i] == condition[j]) match[i] = 1;
        }
        if (match[i] != 1) return false;
    }
    return true;

}

string whoWon(string str){
    
    bool X[4] = {0, 0, 0, 0};
    int horizontX[3] = {0, 0, 0};
    int verticalX[3] = {0, 0, 0};
    int diagonalX[2] = {0, 0};

    bool O[4] = {0, 0, 0, 0};
    int horizontO[3] = {0, 0, 0};
    int verticalO[3] = {0, 0, 0};
    int diagonalO[2] = {0, 0};

    if (valid_field(str)){
        for (int x = 0; x < 3; x++){
            for (int y = 0; y < 3; y++){
                if (masive[x][y] == 'X') horizontX[x]++;
                if (masive[x][y] == 'O') horizontO[x]++; 
            }
            if (horizontX[x] == 3) X[1] = 1;  
            if (horizontO[x] == 3) O[1] = 1; 
        }
        if (X[1] == 1 && O[1] == 1) return "Incorrect.";
    
        for (int y = 0; y < 3; y++){
            for (int x = 0; x < 3; x++){
                if (masive[x][y] == 'X') verticalX[y]++;
                if (masive[x][y] == 'O') verticalO[y]++; 
            }
            if (verticalX[y] == 3) X[2] = 1; 
            if (verticalO[y] == 3) O[2] = 1;
        }
        if (X[2] == 1 && O[2] == 1) return "Incorrect.";
        
        for (int x = 0; x < 3; x++){
            if (masive[x][x] == 'X') diagonalX[0]++;
            if (masive[x][x] == 'O') diagonalO[0]++; 
            if (masive[x][2 - x] == 'X') diagonalX[1]++;
            if (masive[x][2 - x] == 'O') diagonalO[1]++; 
        }
        for(int i = 0; i < 2; i++){
            if (diagonalX[i] == 3) X[3] = 1; 
            if (diagonalO[i] == 3) O[3] = 1;
        }
        for (int i = 1;i < 4; i++){
            int count = 0; 
            if (X[i] == 1)count++;
            if (count > 1){ 
                return "Incorrect.";
            }else if (count == 1){
                X[0] = 1;
            }else X[0] = 0;
        }
        for (int i = 1;i < 4; i++){
            int count = 0; 
            if (O[i] == 1)count++;
            if (count > 1) {
                return "Incorrect.";
            }else if (count == 1){
                O[0] = 1;
            }else O[0] = 0;
        }
        
    }else return "Incorrect.";
    
    return valid_rules(X[0], O[0]);

}

void massive_char(string str){
    int i = 0;
    for(int x = 0; x < 3; x++){
        for (int y = 0; y < 3; y++, i++){
            masive[x][y] = str[i];
        }
    }
}



int main(){
    string str;
    string str2;
    while(true){
        str.clear();
        cout << "Enter field: "<< endl;
        for (int i = 0; i < 3; i++){
            cin >> str2;
            str += str2;
        }
        massive_char(str);
        
        cout << whoWon(str);

    }
}
#include <iostream>
#include <windows.h>

#define bg_white (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY)

using namespace std;

ostream& bold_off(ostream& os){
    return os << "\e[0m";
}

ostream& bold_on(ostream& os){
    return os << "\e[1m";
};


void rectangle(ostream& os){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int a,b,c;

    cout <<"Write width a: "; cin >> a;
    cout << "\n" <<"Write height b: "; cin >> b;
    if(a==b || a <= 0 || b <= 0){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        cout << "\n" << bold_on <<"This not a rectangle!!" << bold_off << "\n\n";
        SetConsoleTextAttribute(hConsole, bg_white);
    }else{
        cout << "\n" <<char(201);
        for(int i = 0; i < a; i++){
            cout << char(205);
        }
        cout << char(187) << endl;
        for(int d = 0; d < b; d++){
            cout << char(186);
            for(int e = 0; e < a; e++){
                cout << char(32);
            }
            cout << char(186) << endl;
        }
        cout << char(200);
        for(int g = 0; g < a; g++){
            cout << char(205);
        }
        cout << char(188) << "\n\n";
    }

}

int main(){
    SetConsoleTitleA("Write your rectangle");
    rectangle(cout);
    system("pause");
    return 0;
}
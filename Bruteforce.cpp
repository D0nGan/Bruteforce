#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

vector <string> numbers = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
vector <string> letters = { "a", "b", "c", "d", "e", "f", "g", "e", "h", "i", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
vector <string> Cletters = { "A", "B", "C", "D", "E", "F", "G", "E", "H", "I", "k", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
vector <string> simvols = { ".", "!", "&", "?", "=", "+", "#", ",", "-", "_", ";", ":", " "};

void enumeration(string password, vector <string> simvol){
    system("cls");
    cout << "Загрузка... \n";
    for (int i = 0; i < simvol.size(); i++) {
        for (int j = 0; j < simvol.size(); j++) {
            for (int t = 0; t < simvol.size(); t++) {
                for (int k = 0; k < simvol.size(); k++) {
                    if ((simvol[i] + simvol[j] + simvol[t] + simvol[k]) == password) {
                        system("cls");
                        cout << "\x1B[32mПароль найден!\x1B[37m" << endl;
                        cout << endl << simvol[i] + simvol[j] + simvol[t] + simvol[k] << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "\x1B[31mПароль не найдет :(\x1B[37m";
}
void choice(bool *d) {
    vector <string> menu = { "Цифры", "Буквы", "Заглавные буквы", "Символы", "\nПринять" };
    int n = menu.size(), m = 0;
    bool e = true;
    do {

        system("cls");
        cout << "Есть ли в вашем пароле:\n\n";
        for (int i = 0; i < n; i++) {
            if (i == m) cout << "\x1B[31m" << menu[i] << "\x1B[37m" << endl;
            else if (d[i]) cout << "\x1B[32m" << menu[i] << "\x1B[37m" << endl;
            else cout << menu[i] << endl;
        }
        switch (_getch()) {
        case(72): m--; break;
        case(80): m++; break;
        case(13): {
            if (m == n - 1) return;
            if (!d[m]) d[m] = true;
            else d[m] = false;
        }break;
        }
        if (m > n - 1) m = 0;
        if (m < 0) m = n - 1;

    } while (e);
}
int main(){
    setlocale(LC_ALL, "RUS");
    string password;
    cout << "Введите пароль из 4 (латинских)символов\n";
    cout << "\x1B[31m!Если введёте больше, будут считаться только первые 4!\x1B[37m\n\n";
    cin >> password;
    password = password.substr(0, 4);
    bool d[] = { 0, 0, 0, 0 };
    choice(d);

    vector <string> Us_Simvols;
    if (d[0]) Us_Simvols.insert(end(Us_Simvols), begin(numbers), end(numbers));
    if (d[1]) Us_Simvols.insert(end(Us_Simvols), begin(letters), end(letters));
    if (d[2]) Us_Simvols.insert(end(Us_Simvols), begin(Cletters), end(Cletters));
    if (d[3]) Us_Simvols.insert(end(Us_Simvols), begin(simvols), end(simvols));

    enumeration(password, Us_Simvols);

    return 0;
}
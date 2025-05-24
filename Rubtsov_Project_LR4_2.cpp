#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    int K = 0, D = 0, choice;

    while (true) {
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод!\n";
            continue;
        }

        switch (choice) {
        case 1:
            K = inputNaturalK();
            cout << "Число K сохранено: " << K << endl;
            break;

        case 2:
            D = inputDigitD();
            cout << "Цифра D сохранена: " << D << endl;
            break;

        case 3:
            if (K == 0 || D == 0) {
                cout << "Сначала введите K и D!\n";
            }
            else {
                K = addDigitToRight(K, D);
                cout << "Результат: " << K << endl;
            }
            break;

        case 4:
            if (K == 0 || D == 0) {
                cout << "Сначала введите K и D!\n";
            }
            else {
                K = addDigitToLeft(K, D);
                cout << "Результат: " << K << endl;
            }
            break;

        case 5:
            cout << "Выход из программы.\n";
            return 0;

        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }
}

void showMenu() {
    cout << "\nМеню функций:\n"
        << "1. Ввести число K\n"
        << "2. Ввести цифру D\n"
        << "3. Добавить D справа к K\n"
        << "4. Добавить D слева к K\n"
        << "5. Выход\n"
        << "Выберите действие: ";
}

int inputDigitD() {
    int D;
    while (true) {
        cout << "Введите цифру D (1-9): ";
        if (cin >> D && D >= 1 && D <= 9) {
            return D;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка! ";
    }
}
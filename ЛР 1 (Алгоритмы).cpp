#include <iomanip>
#include <string>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;

//type float
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int num = 0;
    int n;
    float el;
    float el1;
    List list;
    while (true) {
        cout << "|-------МЕНЮ-------|\n";
        cout << "1. Сформувати список\n";
        cout << "2. Додати елемент до списку\n";
        cout << "3. Вилучити вказаний елемент зі списку\n";
        cout << "4. Визначити кількість елементів у списку\n";
        cout << "5. Поміняти два сусідні елементи місцями\n";
        cout << "6. Очистити список\n";
        cout << "7. Вивести дані\n";
        cout << "8. Записати дані у файл (List2.txt)\n";
        cout << "9. Записати дані з файлу(List1.txt)\n";
        cout << "10. Вихід\n";
        cin >> num;
        switch (num) {
        case 1:
            cout << "1. Сформувати список\n";
            cout << "Введіть кількість елементів для створення: ";
            cin >> n;
            list.make_List(n);
            list.display();
            break;
        case 2:
            cout << "2. Додати елемент до списку\n";
            cout << "Введіть елемент: ";
            cin >> el;
            while (1) {
                cout << "Оберіть спосіб додавання елементу: 1 - на початок списку, 2 - у кінець списку\n";
                cin >> n;
                if (n == 1) {
                    list.push_front(el);
                    break;
                }
                else if (n == 2) {
                    list.push_back(el);
                    break;
                }
                else {
                    cout << "ERROR!\n";
                    cin.clear();
                    cin.ignore();
                    continue;
                }
            }
            list.display();
            break;
        case 3:
            cout << "3. Вилучити вказаний елемент зі списку\n";
            cout << "Введіть елемент: ";
            cin >> el;
            list.delete_one_el(el);
            list.display();
            break;
        case 4:
            cout << "4. Визначити кількість елементів у списку\n";
            list.display();
            list.num_of_el();
            break;
        case 5:
            cout << "5. Поміняти два сусідні елементи місцями\n";
            cout << "Введіть перший елемент: ";
            cin >> el;
            cout << "Введіть другий елемент: ";
            cin >> el1;
            list.swap_el(el, el1);
            list.display();
            break;
        case 6:
            cout << "6. Очистити список\n";
            list.clear();
            list.display();
            break;
        case 7:
            cout << "7. Вивести дані\n";
            list.display();
            break;
        case 8:
            cout << "8. Записати дані у файл(txt)\n";
            list.save_to_file("List2.txt");
            break;
        case 9:
            cout << "9. Записати дані з файлу\n";
            list.load_from_file("List1.txt");
            break;
        case 10:
            cout << "Програму завершено!\n";
            return 0;
        default:
            cout << "ERROR!\n";
            cin.clear();
            cin.ignore();
            continue;
        }
    }
}
#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;
void displayMenu() {
    std::cout << "" << std::endl;
    std::cout << "Меню:" << std::endl;
    std::cout << "1.Слово выводится задом наперед" << std::endl;
    std::cout << "2.Вывести слово без гласных." << std::endl;
    std::cout << "3.Вывести слово без согласных." << std::endl;
    std::cout << "4. Рандомно раскидывать буквы заданного слова" << std::endl;
    std::cout << "5. Выход" << std::endl;
    

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    
    int choice = 0;


    string a = "aeiouyAEIOUYуеыаоэяиюУЕЫАОЯИЭЮ";
    string sogl= "qwrtpsdfghjklzxcvbnmQWRTPSDFGHJKLZXCVBNMйцкнгшщзхфввпрлджчсмтбЙЦКНГШЩЗХФВПРЛДЖЧСМТБ";
    do {

        displayMenu();
        std::string word = "";
        std::cout << "Напишите слово: ";
        std::cin >> word;
        std::cout << "" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> choice;

 

        switch (choice) {

        case 1:
            std::reverse(word.begin(), word.end());;
            std::cout << word;
            
            break;

        case 2:
            for (int i = 0; i < word.length(); i++) {
                for (int j = 0; j < a.length(); j++) {
                    if (word[i] == a[j]) {
                        word.erase(word.begin() + i);
                    }
                }
            }
            cout << word;

            break;

        case 3:
            for (int i = 0; i < word.length(); i++) {
                for (int j = 0; j < sogl.length(); j++) {
                    if (word[i] == sogl[j]) {
                        word.erase(word.begin() + i);
                    }
                }
            }
            cout << word;
            break;

        case 4:
            random_shuffle(word.begin(), word.end());
            cout << word << endl;

            break;

        case 5:

            std::cout << "Завершение работы." << std::endl;
            break;

        default:
            std::cout << "Извините, но такого условия нет, попробуйте еще раз" << std::endl;

        }

    } while (choice != 5);

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

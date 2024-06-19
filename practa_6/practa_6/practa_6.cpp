#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

class Book {
public:
    string title;
    string author;
    string genre;
    string description;
    bool reserved;

    Book(string t, string a, string g, string d) : title(t), author(a), genre(g), description(d), reserved(false) {};

    void reserveBook() {
        reserved = true;
    }

    void cancelReservation() {
        reserved = false;
    }
};

class LibraryCatalog {
private:
    vector<Book> books;

public:
    void addBook(string title, string author, string genre, string description) {
        Book newBook(title, author, genre, description);
        books.push_back(newBook);
    }

    vector<Book> searchBooksByCriteria(string criteria) {
        vector<Book> foundBooks;
        for (const auto& book : books) {
            if (book.title.find(criteria) != string::npos ||
                book.author.find(criteria) != string::npos ||
                book.genre.find(criteria) != string::npos) {
                foundBooks.push_back(book);
            }

        }
        return foundBooks;
    }

    void displayBookInfo(const Book& book) {
        cout << "Название: " << book.title << endl;
        cout << "Автор: " << book.author << endl;
        cout << "Жанр: " << book.genre << endl;
        cout << "Описание: " << book.description << endl;
        cout << "Зарезервирована: " << (book.reserved ? "Да" : "Нет") << endl;
    }

    void reserveBook(const string& title) {
        for (Book& book : books) {
            if (book.title == title) {
                book.reserveBook();
                cout << "Книга \"" << title << "\" успешно зарезервирована." << endl;
                return;
            }
        }
        cout << "Книга с названием \"" << title << "\" не найдена." << endl;
    }

    vector<Book> getReservedBooks() {
        vector<Book> reservedBooks;
        for (const auto& book : books) {
            if (book.reserved) {
                reservedBooks.push_back(book);
            }
        }
        return reservedBooks;
    }

    bool isBookReserved(const string& title) {
        for (const Book& book : books) {
            if (book.title == title) {
                return book.reserved;
            }
        }
        cout << "Книга с названием \"" << title << "\" не найдена." << endl;
        return false;
    }

    bool removeBook(const string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->title == title) {
                books.erase(it);
                cout << "Книга с названием \"" << title << "\" была успешно удалена." << endl;
                return true;
            }
        }
        cout << "Книга с названием \"" << title << "\" не найдена." << endl;
        return false;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    LibraryCatalog catalog;
    catalog.addBook("Название книги 1", "Автор 1", "Фантастика", "Описание первой книги");

    int choice = 0;

    do {
        cout << "Меню библиотечного каталога:" << endl;
        cout << "1. Добавить книгу" << endl;
        cout << "2. Поиск книг" << endl;
        cout << "3. Отобразить подробную информацию о книге" << endl;
        cout << "4. Зарезервировать книгу" << endl;
        cout << "5. Просмотреть зарезервированные книги" << endl;
        cout << "6. Удалить книгу" << endl;
        cout << "7. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string title, author, genre, description;
            cout << "Введите название: ";
            cin.ignore();
            getline(cin, title);
            cout << "Введите автора: ";
            getline(cin, author);
            cout << "Введите жанр: ";
            getline(cin, genre);
            cout << "Введите описание: ";
            getline(cin, description);

            catalog.addBook(title, author, genre, description);
            break;
        }
        case 2: {
            string criteria;

            cout << "Введите критерий поиска: ";

            cin.ignore();

            getline(cin, criteria);


            vector<Book> foundBooks = catalog.searchBooksByCriteria(criteria);

            if (foundBooks.empty()) {

                cout << "Книги по вашему критерию не найдены." << endl;

            }
            else {

                cout << "Найденные книги:" << endl;

                for (const auto& book : foundBooks) {

                    catalog.displayBookInfo(book);

                    cout << "------------------" << endl;

                }

            }


            break;
        }
        case 3: {
            string title;
            cout << "Введите название книги для отображения подробной информации: ";
            cin.ignore();
            getline(cin, title);

            vector<Book> foundBooks = catalog.searchBooksByCriteria(title);
            if (!foundBooks.empty()) {
                catalog.displayBookInfo(foundBooks[0]);
            }
            else {
                cout << "Книга не найдена." << endl;
            }
            break;
        }
        case 4: {
            string title;
            cout << "Введите название книги для резервирования: ";
            cin.ignore(); // Очистка буфера ввода
            getline(cin, title);
            catalog.reserveBook(title);
            break;
        }
        case 5: {
            vector<Book> reservedBooks = catalog.getReservedBooks();


            if (reservedBooks.empty()) {

                cout << "Нет зарезервированных книг." << endl;

            }

            else {

                cout << "Список зарезервированных книг:" << endl;

                for (const auto& book : reservedBooks) {

                    catalog.displayBookInfo(book);

                    cout << "------------------" << endl;

                }

            }

            break;
        }
        case 6: {
            string title;
            cout << "Введите название книги для удаления: ";
            cin.ignore();
            getline(cin, title);
            catalog.removeBook(title);
            break;
        }
        case 7: {
            cout << "Выход..." << endl;
            break;
        }
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
        }
    } while (choice != 7);

    return 0;
}

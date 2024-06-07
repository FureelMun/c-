#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>

class BankAccount {
private:
    int accountNumber;//this номер счета
    double balance;//this баланс
    double interestRate;//this процентная ставка

public:
    //this конструктор класса BankAccount(присваеваем ему основные переменные)
    BankAccount(int accNumber, double initialBalance) {
        accountNumber = accNumber;
        balance = initialBalance;
        interestRate = 0.0;
    }

    //this внесение средств на счет
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Внесено: " << amount << " на счет " << accountNumber << std::endl;
        }
    }

    //this снятие средств со счета
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Снято: " << amount << " со счета " << accountNumber << std::endl;
        }
        else {
            std::cerr << "Ошибка: Недостаточно средств" << std::endl;
        }
    }

    //this вывод баланса
    double getBalance() {
        return balance;
    }

    //this расчет баланса исходя из процентов
    double getInterest() {
        return balance * interestRate * (1 / 12);
    }

    //this обновиление процентной ставки
    void setInterestRate(double newRate) {
        interestRate = newRate;
    }

    //this получение номера банковского счёта
    int getAccountNumber() {
        return accountNumber;
    }

    //this перевлд средств с одного счета на другой
    friend bool transfer(BankAccount& accFrom, BankAccount& accTo, double amount) {
        if (amount <= accFrom.balance) {
            accFrom.balance -= amount;
            accTo.balance += amount;
            std::cout << "Переведено: " << amount << " со счета " << accFrom.accountNumber << " на счет " << accTo.accountNumber << std::endl;
            return true;
        }
        else {
            std::cerr << "Ошибка: Недостаточно средств для перевода" << std::endl;
            return false;
        }
    }

};

void displayMenu() {

    std::cout << "Меню:" << std::endl;
    std::cout << "1. Внести средства" << std::endl;
    std::cout << "2. Снять средства" << std::endl;
    std::cout << "3. Вывести баланс" << std::endl;
    std::cout << "4. Перевод средств" << std::endl;
    std::cout << "5. Выход" << std::endl;

}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    int choice;

    BankAccount acc1(10000, 1000.4);
    BankAccount acc2(10001, 2000.3);
    BankAccount acc3(10002, 3000.2);
    BankAccount acc4(10003, 4000.1);

    do {

        displayMenu();

        std::cout << "Выберите действие: ";
        std::cin >> choice;

        double amount;

        switch (choice) {

        case 1:
            std::cout << "Введите сумму для внесения: ";
            std::cin >> amount;
            acc1.deposit(amount);

            break;

        case 2:
            std::cout << "Введите сумму для снятия: ";
            std::cin >> amount;

            acc1.withdraw(amount);

            break;

        case 3:
            std::cout << "Баланс счета " << acc1.getAccountNumber() << ": " << acc1.getBalance() << std::endl;

            break;

        case 4:
            std::cout << "Введите сумму для перевода: ";
            std::cin >> amount;

            
            transfer(acc1, acc2, amount);

            break;

        case 5:
            std::cout << "Завершение работы." << std::endl;
            break;

        default:
            std::cout << "Извините, но такого условия нет, попробуйте еще раз" << std::endl;

        }

    } while (choice != 5);

    return 0;
}

/*Примечания:
* Процентная ставка по кредитной карте — это плата за пользование заемными средствами банка, 
выраженная в процентах от суммы фактической задолженности.

!!СПРОСИТЬ!!
*/
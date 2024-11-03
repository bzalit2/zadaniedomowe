#include <iostream>
#include <string>

class BankAccount {
private:
    // Prywatna zmienna przechowuj�ca saldo konta - tylko klasa BankAccount ma do niej dost�p
    double balance;
    
public:
    // Konstruktor ustawiaj�cy pocz�tkowe saldo
    BankAccount(double initial_balance) {
        if (initial_balance >= 0) {
            balance = initial_balance;
        } else {
            balance = 0;
            std::cout << "Saldo nie mo�e by� ujemne. Ustawiono saldo na 0.\n";
        }
    }

    // Getter - metoda publiczna zwracaj�ca bie��ce saldo
    double getBalance() const {
        return balance;
    }

    // Setter - metoda publiczna ustawiaj�ca nowe saldo
    void setBalance(double new_balance) {
        if (new_balance >= 0) {
            balance = new_balance;
        } else {
            std::cout << "Saldo nie mo�e by� ujemne!\n";
        }
    }

    // Metoda do wp�acania pieni�dzy na konto
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Wp�acono " << amount << ". Nowe saldo: " << balance << "\n";
        } else {
            std::cout << "Kwota do wp�aty musi by� dodatnia!\n";
        }
    }

    // Metoda do wyp�acania pieni�dzy z konta
    void withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Brak wystarczaj�cych �rodk�w na koncie!\n";
        } else if (amount <= 0) {
            std::cout << "Kwota do wyp�aty musi by� dodatnia!\n";
        } else {
            balance -= amount;
            std::cout << "Wyp�acono " << amount << ". Nowe saldo: " << balance << "\n";
        }
    }
};

int main() {
    // Tworzymy obiekt klasy BankAccount z pocz�tkowym saldem 1000
    BankAccount account(1000);

    // Wy�wietlamy saldo pocz�tkowe
    std::cout << "Saldo pocz�tkowe: " << account.getBalance() << "\n";

    // Wp�acamy 500 na konto
    account.deposit(500);

    // Pr�bujemy wyp�aci� 300
    account.withdraw(300);

    // Pr�bujemy ustawi� saldo na warto�� ujemn�
    account.setBalance(-500);

    // Wy�wietlamy saldo ko�cowe
    std::cout << "Saldo ko�cowe: " << account.getBalance() << "\n";

    return 0;
}


#include <iostream>
#include <string>

class BankAccount {
private:
    // Prywatna zmienna przechowuj¹ca saldo konta - tylko klasa BankAccount ma do niej dostêp
    double balance;
    
public:
    // Konstruktor ustawiaj¹cy pocz¹tkowe saldo
    BankAccount(double initial_balance) {
        if (initial_balance >= 0) {
            balance = initial_balance;
        } else {
            balance = 0;
            std::cout << "Saldo nie mo¿e byæ ujemne. Ustawiono saldo na 0.\n";
        }
    }

    // Getter - metoda publiczna zwracaj¹ca bie¿¹ce saldo
    double getBalance() const {
        return balance;
    }

    // Setter - metoda publiczna ustawiaj¹ca nowe saldo
    void setBalance(double new_balance) {
        if (new_balance >= 0) {
            balance = new_balance;
        } else {
            std::cout << "Saldo nie mo¿e byæ ujemne!\n";
        }
    }

    // Metoda do wp³acania pieniêdzy na konto
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Wp³acono " << amount << ". Nowe saldo: " << balance << "\n";
        } else {
            std::cout << "Kwota do wp³aty musi byæ dodatnia!\n";
        }
    }

    // Metoda do wyp³acania pieniêdzy z konta
    void withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Brak wystarczaj¹cych œrodków na koncie!\n";
        } else if (amount <= 0) {
            std::cout << "Kwota do wyp³aty musi byæ dodatnia!\n";
        } else {
            balance -= amount;
            std::cout << "Wyp³acono " << amount << ". Nowe saldo: " << balance << "\n";
        }
    }
};

int main() {
    // Tworzymy obiekt klasy BankAccount z pocz¹tkowym saldem 1000
    BankAccount account(1000);

    // Wyœwietlamy saldo pocz¹tkowe
    std::cout << "Saldo pocz¹tkowe: " << account.getBalance() << "\n";

    // Wp³acamy 500 na konto
    account.deposit(500);

    // Próbujemy wyp³aciæ 300
    account.withdraw(300);

    // Próbujemy ustawiæ saldo na wartoœæ ujemn¹
    account.setBalance(-500);

    // Wyœwietlamy saldo koñcowe
    std::cout << "Saldo koñcowe: " << account.getBalance() << "\n";

    return 0;
}


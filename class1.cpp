// class1.cpp 
//Автор: Караев Л.П. ИВТ-23
#include <iostream> 
#include <string>
#include <cassert>

using namespace std;
// Аккаунт пльзователя букмекерской компании 
class Account { //private - доступны только внутри класса 
private: // Поля класса
	string Phone_Number;   //Номер телефона
	string Email_Address; //почта
	double Balance;   //баланс
	string password; //пароль

//public - доступны извне класса 
public: string Name; //Имя пользователя 

// Конструктор для инициализации полей 
// передаем значения по ссылки (&) для уменьшения занимаемой памяти 
// const - для не изменяемых значений 
//u_Name - Имя пользователя, p_Number - Номер телефона, e_Address - почта, a_Balance - баланс, passw - пароль
Account(const string& u_Name, const string& p_Number, const string& e_Address, const string& passw, const double& a_Balance) {
	Name = u_Name;
	Phone_Number = p_Number;
	Email_Address = e_Address;
	password = passw;
	Balance = a_Balance;
}
// Геттер для имени пользователя
string getName() const {
    return Name;
}
// Геттер для номера телефона
string getPhone_Number() const {
    //const - контроль постоянства
    return Phone_Number;
}
// Геттер для почты
string getEmail_Address() const {
    return Email_Address;
}
// Геттер для пароля
string getpassword() const {
    return password;
}
// Геттер для баланса
double getBalance() const {
    return Balance;
}

//// Сеттер для имени пользователя
//void setUsername(string u_Name) {
//    Name = u_Name;
//}

// Сеттер для номера телефона
void setPhone_Number(const string p_Number) {
    Phone_Number = p_Number;
}
// Сеттер для почты
void setEmail_Address(const string e_Address) {
    Email_Address = e_Address;
}

// Метод для изменения пароля
void changePassword(string newPassword) {
    password = newPassword;
    cout << "Пароль успешно изменен!" << endl;
}

// Метод для пополнения баланса
void deposit(const double amount) {
    if (amount > 0) {
        Balance += amount;
        cout << "Баланс успешно пополнен на " << amount << "!" << endl;
    }
    else {
        cout << "Сумма пополнения должна быть положительной!" << endl;
    }
}

// Метод для списания средств
void withdraw(const double amount) {
    if (amount > 0 && amount <= Balance) {
        Balance -= amount;
        cout << "Списано " << amount << " с баланса." << endl;
    }
    else if (amount > Balance) {
        cout << "Недостаточно средств на счете!" << endl;
    }
    else {
        std::cout << "Сумма списания должна быть положительной!" << std::endl;
    }
}

string to_string() const {
    string s;
    s = Name + "" + Phone_Number + "" + Email_Address + "" + std::to_string(Balance);
    return s;
}

//Вывод всех данных, кроме пароля
void print_all() {
    cout << "Name: " << Name << "\nPhone_Number: " << Phone_Number << endl;
    cout << "Email_Address: " << Email_Address << "\nBalance: " << Balance << "$\n" << endl;
}

};

int main() {
    setlocale(LC_ALL, "Russian"); 
    string Name, Phone_Number, Email_Address, password;
    double a_Balance;

    //Проверка
    //Account user(Name, Phone_Number, Email_Address, password, a_Balance);
    Account user("Иван Иванов", "1234567890", "ivan@example.com", "password123", 100.0);
    // Проверяем начальные значения
    assert(user.getName() == "Иван Иванов");
    assert(user.getPhone_Number() == "1234567890");
    assert(user.getEmail_Address() == "ivan@example.com");
    assert(user.getpassword() == "password123");
    assert(user.getBalance() == 100.0);

    // Тестируем изменение пароля
    user.changePassword("newpassword");
    assert(user.getpassword() == "newpassword");

    // Проверяем неправильное изменение пароля
    user.changePassword("anotherpassword");
    assert(user.getpassword() == "newpassword"); // Пароль не должен измениться

    // Тестируем пополнение баланса
    user.deposit(50.0);
    assert(user.getBalance() == 150.0);

    // Проверяем пополнение с отрицательной суммой
    user.deposit(-20.0);
    assert(user.getBalance() == 150.0); // Баланс не должен измениться

    // Тестируем снятие средств
    user.withdraw(30.0);
    assert(user.getBalance() == 120.0);

    // Проверяем снятие больше, чем на балансе
    user.withdraw(200.0);
    assert(user.getBalance() == 120.0); // Баланс не должен измениться

    /*// Запрашиваем данные у пользователя
    cout << "Введите имя пользователя: ";
    getline(cin, Name);

    cout << "Введите введите номер телефона: ";
    getline(cin, Phone_Number);

    cout << "Введите электронную почту: ";
    getline(cin, Email_Address);

    cout << "Введите пароль: ";
    getline(cin, password);

    cout << "Введите начальный баланс: ";
    cin >> a_Balance;

    // Создаем объект класса Account с введенными данными
    //Account my1User(Name, Phone_Number, Email_Address, password, a_Balance);*/

    // Вызываем методы объекта
    //user.print_all();
    user.print_all();
    //user.changePassword(password);
    //user.deposit(a_Balance);
    //user.withdraw(a_Balance);
    //user.to_string();
    //user.print_all();

    return 0;
}
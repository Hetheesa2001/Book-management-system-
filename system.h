#include <iostream>
#include <cstring>
using namespace std;

class Book {
    int book_no;
    char book_name[20];
    char author_name[20];
    int price;  

public:
    int Insert(Book *p, int n) {  
        cout << "Enter Book No       : ";    
        cin >> p[n].book_no;
        cout << "Enter Book Name      : ";
        cin.ignore(); // to ignore leftover newline from previous input
        cin.getline(p[n].book_name, 20);
        cout << "Enter Author Name   : ";  
        cin.getline(p[n].author_name, 20);  
        cout << "Enter the price      : ";  
        cin >> p[n].price;  
        cout << "\nBook Inserted...\n";
        n++;
        return n;
    }

    void Display() const {
        cout << book_no << "\t" << book_name << "\t" << author_name << "\t" << price << "\n";
    }

    int Del(Book *p, int n, int roll) {
        int j = 0, k, flag = 0;  
        for (j = 0; j < n; j++) {
            if (p[j].book_no == roll) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            for (k = j; k < n - 1; k++) {
                p[k] = p[k + 1];
            }
            cout << "\nBook Deleted.\n";
            return n - 1;
        } else {
            cout << "\nBook Not Found\n";
            return n;
        }
    }

    int Update(Book *p, int roll, int n) {
        int i, ch1;  
        for (i = 0; i < n; i++) {
            if (p[i].book_no == roll) {
                while (true) {
                    cout << "\n!!===OPTIONS IN UPDATE===!!\n";
                    cout << "\n1. Update book name";
                    cout << "\n2. Update author name";
                    cout << "\n3. Update Book no";
                    cout << "\n4. Return to main Menu";
                    cout << "\n\nEnter Your Choice: ";
                    cin >> ch1;
                    cin.ignore(); // to ignore leftover newline from previous input
                    switch (ch1) {
                        case 1:
                            cout << "Book Name    : ";
                            cin.getline(p[i].book_name, 20);
                            cout << "Record Updated...\n";
                            break;
                        case 2:
                            cout << "Author Name  : ";
                            cin.getline(p[i].author_name, 20);
                            cout << "Record Updated...\n";
                            break;
                        case 3:
                            cout << "Book No      : ";
                            cin >> p[i].book_no;
                            cin.ignore(); // to ignore leftover newline from previous input
                            cout << "Book Name    : ";
                            cin.getline(p[i].book_name, 20);
                            cout << "Author Name  : ";
                            cin.getline(p[i].author_name, 20);
                            cout << "Price        : ";
                            cin >> p[i].price;
                            cin.ignore(); // to ignore leftover newline from previous input
                            cout << "Record Updated...\n";
                            break;
                        case 4:
                            return n;
                        default:
                            cout << "!! Wrong Key !!";
                            break;
                    }
                }
                break;
            }
        }
        if (p[i].book_no != roll) {
            cout << "\nRecord Not Found\n\n";
        }
        return n;
    }
};

int main() {
    int a, b, c;
    string username, password;
    Book books[10];
    int bookCount = 0;

    cout << "\t\t\t\t\t***** GENIUS BOOKS *****\t\t\t\t\t" << endl;
    cout << "\t\t\t\t--------------------------------------\t\t\t\t" << endl;
    cout << "\t\t 1.   login" << endl;
    cout << "\t\t 2.   View Books" << endl;
    cout << "\tEnter the option : ";
    cin >> a;
    cin.ignore(); // to ignore leftover newline from previous input
    cout << endl;

    if (a == 1) {
        cout << "\t\t\t\t Login Form \t\t\t\t" << endl;
        cout << "\t\t\t  *************************** \t\t\t\n" << endl;
        cout << "\t\t Enter the username   : ";
        cin >> username;
        cout << "\t\t Enter the password   : ";
        cin >> password;
        cin.ignore(); // to ignore leftover newline from previous input
        cout << endl;

        if (username == "admin" && password == "admin") {
            cout << "\t\t\t\t Welcome to GENIUS BOOKS \t\t\t\t" << endl;
            cout << "\t\t\t  -----------------------------------------\t\t\t \n" << endl;
            cout << "\t\t 1.   Insert Details" << endl;
            cout << "\t\t 2.   Update Details" << endl;
            cout << "\t\t 3.   Delete Details" << endl;
            cout << "\t\t 4.   Display Details" << endl;
            cout << "\t\t 5.   Exit" << endl;
            cout << "\t Enter the option : ";
            cin >> b;
            cin.ignore(); // to ignore leftover newline from previous input
            cout << endl;

            switch (b) {
                case 1:
                    bookCount = books[0].Insert(books, bookCount);
                    break;
                case 2:
                    cout << "Enter the Book No For Data Update: ";
                    cin >> c;
                    cin.ignore(); // to ignore leftover newline from previous input
                    bookCount = books[0].Update(books, c, bookCount);
                    break;
                case 3:
                    cout << "Enter the Book No to Delete: ";
                    cin >> c;
                    cin.ignore(); // to ignore leftover newline from previous input
                    bookCount = books[0].Del(books, bookCount, c);
                    break;
                case 4:
                    cout << "Book No\t Book Name\t Author Name\t Price\n==============================================\n";
                    for (int i = 0; i < bookCount; i++) {
                        books[i].Display();
                    }
                    break;
                case 5:
                    exit(0);
                default:
                    cout << "Wrong Key!!" << endl;
                    break;
            }
        } else {
            cout << "Invalid username or password" << endl;
        }
    } else if (a == 2) {
        cout << "View Books" << endl;
    }

    return 0;
}

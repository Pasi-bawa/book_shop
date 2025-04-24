#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Book {
    string id;
    string name;
    string author;
    int quantity;  
    double price;
};

struct Order {
    string bookId;
    string customerName;
    string deliveryAddress;
    int quantity;
    double totalPrice;
};

vector<Book> books;
vector<Order> orders;

void displayMainMenu();
void Manager_login();
void Customer_login();
void Customer_register();
void customerMenu();
void managerMenu();
void addBook();
void deleteBook();
void updateBook();
void viewAvailableBooks();
void CusviewAvailableBooks();
void placeOrder();
void viewOrders();
void viewServices();

int main() {
    displayMainMenu();
    return 0;
}
// Function to display menu options
void displayMainMenu() {
    int choice;
    system("cls");

    cout << "\t\t\t|[Nethra BookShop Kandy]|\n";
  


    cout << "1. Manager Login" << endl;
    cout << "2. User Login" << endl;
    cout << "3. User Register" << endl;
    cout << "4. Exit" << endl;
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
    	case 1:
    		Manager_login();
    		break;
        case 2:
            Customer_login();
            break;
        case 3:
            Customer_register();
            break;
        case 4:
            cout << "\nThanks for using this program\n";
            break;
        default:
            system("cls");
            cout << "\t>>>>> You've made a mistake, give it a try again <<<<<\n\n\n"
                 << endl;
            displayMainMenu();
    }
}
// Function to display manager login options
void Manager_login() {
    string username, password;
    cout << "\nManager Login\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username == "Nethra" && password == "1234") {
        system("cls");
        managerMenu();
    } else {
        cout << "\nWrong username or password. Please Try again.\n\n";
        system("pause");
        Customer_login();  
    }
}
// Function to display Customer login options
void Customer_login() {
      int count;
        string user, pass, u, p;
        cout << "\n";
        cout << "Username :";
        cin >> user;
        cout << "Password :";
        cin >> pass;

        ifstream input("database.txt");
        while (input >> u >> p)
        {
            if (u == user && p == pass)
            {
                count = 1;
            }
        }

        if(count==1){
            system("cls");
            customerMenu();
        }
        else{
            cout<< "\n\nwrong user name and password. Please try again \n\n";
            system("pause");
            main();

        }
}

void Customer_register() {
    string reguser, regpass, ru, rp;
    cout << "Enter the username : ";
    cin >> reguser;
    cout << "Enter the password : ";
    cin >> regpass;

    ofstream reg("database.txt", ios::app);
    reg << reguser << ' ' << regpass << endl;

    cout << "\n\nRegistration Successful\n\n";
    system("pause");
    main();
}
   // Function to display customer menu
void customerMenu() {
    int choice;
    system("cls");

    cout << "\t\t\t|[User Panel]|\n";

    cout << "1. View Available Books" << endl;
    cout << "2. Place Order" << endl;
    cout << "3. View Available Services" << endl;
    cout << "4. Logout" << endl;
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            CusviewAvailableBooks();
            break;
        case 2:
            placeOrder();
            break;
        case 4:
            displayMainMenu();
            break;
        default:
            system("cls");
            cout << "\t>>>>> You've made a mistake, give it a try again <<<<<\n"
                 << endl;
            customerMenu();
    }
}
 // Function to display Books data(price/Id/Author/...)
void CusviewAvailableBooks() {
 system("cls");
        fstream file;
        int quntity;
        int price;
        string name,id, author;
        cout << "\n\n\t\t\t\t\tAll BOOKS DETAILS";

        file.open("bookData.txt", ios::in);
        if (!file)
        {
            cout << "\n\n File Opening Error!\n\n";
            system("pause");
            cout<<"\n\n\n";
            managerMenu();

        }
        else
        {

                cout << "\n\n\nBook ID\t\tBook Name"
                     << "\t\t  Book Author\t    Books Quntity\t   Book Price\n\n";

                file >> id>> name>> author >> quntity >> price  ;

                while (!file.eof())
                {

                        cout << "  " << id
                             << "\t\t " << name
                             << "\t\t\t  " << author
                             << "\t\t\t" << quntity
                             << "\t\t\t" << price
                             << "\n\n";
                        file >> id >> name>> author >> quntity >> price;
                }

                cout<<"\n\n\n";
                system("pause");
                cout<<"\n\n\n";

                file.close();
                customerMenu();
        }
}
// Function to manage books (view, add, search)
void managerMenu() {
    int choice;
    system("cls");

    cout << "\t\t\t|[Manager Panel]|\n";

    cout << "1. Add Books" << endl;
    cout << "2. Delete Book" << endl;
    cout << "3. Update Book" << endl;
    cout << "4. View Orders" << endl;
    cout << "5. View books" << endl;
    cout << "6. Logout" << endl;
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
        	//new books
            addBook();
            break;
        case 2:
            deleteBook();
            break;
        case 3:
            updateBook();
            break;
        case 4:
            viewOrders();
            break;
        case 5:
        	viewAvailableBooks();// //Display  books
        	break;
        case 6:
            displayMainMenu();
            break;
        default:
            system("cls");
            cout << "\t>>>>> You've made a mistake, give it a try again <<<<<\n"
                 << endl;
            managerMenu();
    }
}

void addBook() {
	 system("cls");
        ofstream file("bookData.txt", ios::out | ios::app);
    if (!file.is_open()) {
        cout << "Error opening file!\n";
        return;
    }

    Book book;//add a new book

    cout << "\n\n\t\t\t\tADD NEW BOOKS";
    cout << "\n\nBook ID : ";
    cin >> book.id;
    cout << "\nBook Name : ";
    cin >> book.name;
    cout << "\nAuthor : ";
    cin >> book.author;
    cout << "\nQuantity : ";
    cin >> book.quantity;
    cout << "\nPrice : ";
    cin >> book.price;

    file << book.id << " " << book.name << " " << book.author << " " << book.quantity << " " << book.price << "\n";
    file.close();

    system("cls");
    cout << "\n\n\n >>> Book added successfully <<< \n\n\n";
        managerMenu();

}

void deleteBook() {
	system("cls");
        ifstream inFile("bookData.txt");
    ofstream outFile("bookData1.txt", ios::app | ios::out);

    if (!inFile.is_open()) {
        cout << "\n\nFile Opening Error...\n\n";
        system("pause");
        return;
    }

    int count = 0;
    string id, idd, name, author;
    int price, quantity;
//remove book
    cout << "\n\n\t\t\t\t Delete a Book";
    cout << "\n\nBook ID : ";
    cin >> id;

    while (inFile >> idd >> name >> author >> price >> quantity) {
        if (id == idd) {
            cout << "\n\n\n\n";
            cout << "\t\t\t >>> Book Delete Successfully <<< \n\n\n\n\n\n\n";
            count++;
        } else {
            outFile << " " << idd << " " << name << " " << author << " " << price << " " << quantity << "\n\n";
        }
    }

    if (count == 0) {
        cout << "\n\n\t\t\t >>> Book Not Found Sorry! <<< \n\n\n\n\n\n\n";
    }

    inFile.close();
    outFile.close();

    remove("bookData.txt");
    rename("bookData1.txt", "bookData.txt");

    system("pause");
        managerMenu();
}
// ADD a new book or Update  
void updateBook() {
system("cls");
         ifstream inFile("bookData.txt");
    ofstream outFile("bookData1.txt", ios::app | ios::out);

    if (!inFile.is_open()) {
        cout << "\n\nFile Opening Error...\n\n";
        system("pause");
        return;
    }

    int count = 0;
    string id, idd, name, author;
    int price, quantity;

    cout << "\n\n\t\t\t\t Update a Book";
    cout << "\n\nBook ID : ";
    cin >> id;

    while (inFile >> idd >> name >> author >> price >> quantity) {
        if (id == idd) {
            cout << "\nBook Name : ";
            cin >> name;
            cout << "\nAuthor : ";
            cin >> author;
            cout << "\nQuantity : ";
            cin >> quantity;
            cout << "\nPrice : ";
            cin >> price;

            outFile << " " << id << " " << name << " " << author << " " << price << " " << quantity << "\n\n";
            count++;
        } else {
            outFile << " " << idd << " " << name << " " << author << " " << price << " " << quantity << "\n\n";
        }
    }

    if (count == 0) {
        cout << "\n\n\t\t\t >>> Book Not Found Sorry! <<< \n\n\n\n\n\n\n";
    }

    inFile.close();
    outFile.close();

    remove("bookData.txt");
    rename("bookData1.txt", "bookData.txt");

    system("pause");
        managerMenu();
		}
//Display all books
void viewAvailableBooks() {
 system("cls");
        fstream file;
        int quntity;
        int price;
        string name,id, author;
        cout << "\n\n\t\t\t\t\tAll BOOKS DETAILS";

        file.open("bookData.txt", ios::in);
        if (!file)
        {
            cout << "\n\n File Opening Error!\n\n";
            system("pause");
            cout<<"\n\n\n";
            managerMenu();

        }
        else
        {

                cout << "\n\n\nBook ID\t\tBook Name"
                     << "\t\t  Book Author\t    Books Quntity\t   Book Price\n\n";

                file >> id>> name>> author >> quntity >> price  ;

                while (!file.eof())
                {

                        cout << "  " << id
                             << "\t\t " << name
                             << "\t\t\t  " << author
                             << "\t\t\t" << quntity
                             << "\t\t\t" << price
                             << "\n\n";
                        file >> id >> name>> author >> quntity >> price;
                }

                cout<<"\n\n\n";
                system("pause");
                cout<<"\n\n\n";

                file.close();
                managerMenu();
        }
}
// oder book
void placeOrder() {
	 system("cls");
        fstream file, file1,file2;
        int price;
        int quntity;
        int no_copy, count = 0,qua;
        string id, idd, name, author;
        string na,a_na,pri;
        string address,number;


        cout << "\n\n\t\t\t\t Place the oder";

        file1.open("bookData1.txt",
                   ios::app | ios::out);
        file.open("bookData.txt",
                  ios::in);

        if (!file)
                {
                    cout << "\n\n File Opening Error!\n\n";
                    system("pause");
                    customerMenu();
                }
        else
        {

                cout << "\n\nBook ID : ";
                cin >> id;
                file >>idd>> name>> author >>price>>quntity;
                while (!file.eof())
                {

                        if (id == idd)
                        {

// customer details
                            cout << "\n Delivery Adress : ";
                            cin >> address;
                            cout << "\n Phone Number : ";
                            cin >> number;
                            cout << "\n Quntity : ";
                            cin >> qua;

                            file2.open("oderData.txt",ios::out | ios::app);
                            file2 << " " << id << " "<< name << " "<< address << " " << number<< " " << qua<<" "<< price*qua<< "\n\n";
                            count++;

                        }
                        else
                        {


                                file1 << " " << idd<< " " << name<< " " << author<< " " << price<< " " << quntity<< "\n\n";
                        }

                        file >> idd >> name>> author>>price>>quntity;
                }

                if (count == 0)
                {

                    cout <<"\n\n\t\t\t >>> Not available! <<< \n\n\n\n\n\n\n";
                }
        }

        file.close();
        file1.close();
        file2.close();

        system("pause");
        customerMenu();
}
// Function to manage oder
void viewOrders() {
	  fstream file;
        int quntity;
        int price;
        string name,id, address,number;
        cout << "\n\n\t\t\t\t\tAll BOOKS DETAILS";

        file.open("oderData.txt", ios::in);
        if (!file)
        {
            cout << "\n\n File Opening Error!\n\n";
            system("pause");
            cout<<"\n\n\n";
            managerMenu();

        }
        else
        {

                cout << "\n\n\n Book ID \tBook Name \t  Delivary address \t   Phone number \t    Books Quntity \t     Total Price\n\n\n\n";

                file >> id>> name>> address >>number>> quntity >> price  ;

                while (!file.eof())
                {

                        cout << "  " << id
                             << "\t\t " << name
                             << "\t\t\t  " << address
                             << "\t\t\t" << number
                             << "\t\t\t" << quntity
                             << "\t\t\t" << price
                             << "\n\n";
                        file >> id>> name>> address >>number>> quntity >> price  ;
                }

                cout<<"\n\n\n";
                system("pause");
                cout<<"\n\n\n";

                file.close();
                managerMenu();
        }
}
void viewServices() {
	 cout << "\n\n\n\t\t Available Services \n\n\n";

    cout << " 1. Rs.200/= Gift voucher\n";
    

    cout << " 2. Your Offers\n";
    
      cout << " 0. Exit\n\n";
      
      int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch (choice) {
        case 1:
            cout << "\n\nGo to our store and get your voucher. Thank you for staying with us!\n";
            break;
        case 2:
            cout << "\n\nThere are no offers for you today. stay tuned for upcoming events!\n";
            break;
        case 3:
            cout << "\n\nExiting Main Menu.\n";
 }

    if (choice != 0) {
        cout << "\n\n";
        system("pause");
        cout << "\n\n\n";
        customerMenu();
    }
}
    


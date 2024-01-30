#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

// AUTHERIZATION AND AUTHENTICATION
class User
{
public:
    static int studentCounter;  // for counting the overall student's log in this system
    static int employeeCounter; // for counting the overall eployee's log in this system
    string employeeName;
    string employeeId;
    string jobTittle;
    string employeeEmail;
    string employeePhone;

    string userId;
    string userName;
    string userFatherName;
    string userGender;
    string userSection;
    string userDegree;
    string userEmail;
    string userPhoneNumber;

    // Setting employee info
    void setEmployeeInfo()
    {
        cout << "Enter Employee ID: ";
        cin >> employeeId;

        cout << "Enter Employee name: ";
        cin >> employeeName;

        cout << "Enter Employee job: ";
        cin >> jobTittle;

        cout << "Enter Employee email: ";
        cin >> employeeEmail;

        cout << "Enter Employee Phone NUmber: ";
        cin >> employeePhone;
    }

    // setting student info
    void setStudentInfo()
    {

        cout << "Enter Student ID: ";
        cin >> userId;

        cout << "Enter Student name: ";
        cin >> userName;

        cout << "Enter Father name: ";
        cin >> userFatherName;

        cout << "Enter Gender : ";
        cin >> userGender;

        cout << "Enter Section : ";
        cin >> userSection;

        cout << "Enter Degree : ";
        cin >> userDegree;

        cout << "Enter Email: ";
        cin >> userEmail;

        cout << "Enter  phone number: ";
        cin >> userPhoneNumber;
    }
    void saveStudentInofrmation() // saving all the info in the file
    {
        ofstream savingSTD;

        savingSTD.open("Student.txt", ios::app);

        if (!savingSTD.is_open())
        {
            cout << " Error in opening student, file! " << endl;
        }
        // file

        savingSTD << "Student No. = " << studentCounter << endl;

        savingSTD << "Information................... " << endl;
        savingSTD << userId << endl;
        savingSTD << "Name: " << userName << endl;
        savingSTD << "Father Name: " << userFatherName << endl;
        savingSTD << "Degree: " << userDegree << endl;
        savingSTD << "Section: " << userSection << endl;
        savingSTD << "Email: " << userEmail << endl;
        savingSTD << "Phone Number: " << userPhoneNumber << endl;
        savingSTD << "Gender: " << userGender << endl;
        studentCounter++;                                                // for increasing
        savingSTD << "Updated Student No. = " << studentCounter << endl; // Update the counter in the file
        savingSTD.close();                                               // for closing the file
    }

    void saveEmployeeInofrmation() // saving all the info in the file
    {
        ofstream empptr;

        empptr.open("Employee.txt", ios::app);

        if (!empptr.is_open())
        {
            cout << "Error in opening employee file! " << endl;
        }
        // file

        empptr << "Emplooyee No. = " << employeeCounter << endl;
        empptr << "Information................... " << endl;
        empptr << "Emplooyee Nmae = " << employeeName << endl;
        empptr << employeeId << endl;
        empptr << "Job Level: " << jobTittle << endl;
        empptr << "Email: " << employeeEmail << endl;
        empptr << "Phone Number: " << employeePhone << endl;
        employeeCounter++;                                              // for increasing
        empptr << "Updated Employee No. = " << employeeCounter << endl; // Update the counter in the file
        empptr.close();                                                 // for closing the file
    }

    // void studentInfoCard( User &stud)
    void studentInformation()
    {
        ifstream studentPtr("Student.txt");

        if (!studentPtr.is_open())
        {
            cout << "Error opening file." << endl;
            return;
        }

        string line;

        while (getline(studentPtr, line))
        {
            cout << line << endl;
        }

        studentPtr.close();
    }

    void EmployeeInformation()
    {
        ifstream employeePtr;
        employeePtr.open("Employee.txt");

        if (!employeePtr.is_open())
        {
            cout << "Error opening file." << endl;
            return;
        }

        string line;

        while (getline(employeePtr, line))
        {
            cout << line << endl;
        }

        employeePtr.close();
    }

    void setPassword() {}
};
int User::studentCounter; // Initialize static member variables
int User::employeeCounter;

// STOCK { BOOK } MANAGEMENT //

class Books // Category
{
public:
    static int bookCounter; // total books remaining
    static int borrowersNo; //  the which boorrow the books from library
    static int shelfBooks;  //  for book remaining in a shelf

    string shelfCode; // code of shelf containing books
    string *authors;  // dynaic
    int numAuthors;
    int Quantity;

    // for iLending the books
    User *issuedTo;
    string borrowerName;
    string borrowerId;
    string borrowerEmail;
    string lendDate;
    string borrowerPhoneNumber;
    string returnerID;
    string returnerName;
    string returnerPhoneNumber;
    string returnDate;

    int lendCopies;
    int returnCopies;
    float fineReturn;
    double totalFine;

    Books(string scode, string *authersee, int numAuther, int qauntity)
        : shelfCode(scode), Quantity(qauntity), fineReturn(0), returnCopies(0)
    {
        authors = new string[numAuther];
        numAuthors = numAuther;
        for (int i = 0; i < numAuther; ++i)
        {
            authors[i] = authersee[i];
        }

        bookCounter += Quantity;
        borrowersNo += 1;
        shelfBooks += Quantity;
    }
    // to free dynamically allocated memory
    ~Books()
    {
        delete[] authors;
    }
    // settting info about borrowewr
    void setBorrowerInfo()
    {
        cout << "Enter borrower ID: ";
        cin >> borrowerId;

        cout << "Enter borrower name: ";
        cin >> borrowerName;

        cout << "Enter borrower email: ";
        cin >> borrowerEmail;

        cout << "Enter borrower phone number: ";
        cin >> borrowerPhoneNumber;

        cout << "Enter Date to lend copies: ";
        cin >> lendDate;

        // lendCopies(0)
        cout << "Enter Number of lend copies: ";
        cin >> lendCopies;
    }

    // settting info about borrowewr
    void setReturerInfo()
    {
        cout << "Enter returner ID: ";
        cin >> returnerID;

        cout << "Enter returner name: ";
        cin >> returnerName;

        cout << "Enter Date: ";
        cin >> returnDate;

        cout << "Enter Number of copies you want to return: ";
        cin >> returnCopies;
    }

    // for  the  information about the overall books and also Saving it in the file
    void saveBooksInFile(string shelfCode) // for 1st time , adding new books
    {
        ofstream shelfPtr;
        shelfPtr.open(shelfCode + ".txt", ios::app);
        if (!shelfPtr.is_open())
        {
            cout << "Error in opening file! " << endl;
        }
        // cout << "Shelf code. = " << shelfCode << endl;

        // cout << "Book No. : " << bookCounter << endl;
        shelfPtr << "Book No. : " << bookCounter << endl;

        shelfPtr << "Quantity: " << Quantity << endl;
        // cout << "Quantity: " << Quantity << endl;

        // cout << "Authers name";
        // for (int i = 0; i < numAuthors; ++i)
        // {
        //     cout << authors[i] << ", ";
        // }
        shelfPtr << "Authers name";
        for (int i = 0; i < numAuthors; ++i)
        {
            shelfPtr << authors[i] << ", ";
        }
        shelfBooks += Quantity;               // for incrementig books in the shelf
        bookCounter = bookCounter + Quantity; // for getting the actual no. of Books
        shelfPtr.close();
    }

    // for showing all the records
    void showShelfStock(string shelfCode)
    {
        cout << "------------------- Showing shelf info -----------------" << endl;
        ifstream inFile;
        inFile.open(shelfCode + ".txt");

        if (!inFile.is_open())
        {
            cout << "Error opening file." << endl;
            return;
        }

        string line; // for storing the extracted line from the file

        while (getline(inFile, line))
        {

            cout << line << endl;
        }

        // closing from file
        inFile.close();
    }

    void showLibraryInfo()
    {
        cout << "Total books: " << bookCounter << endl;
        cout << "Total Person who Borrowed books: " << borrowersNo << endl;
    }

    // saving the lended books record  in file
    void lendBooksFile(User *issuedTo, int lendCopies)
    {
        ofstream findBook;
        findBook.open("Borrowers.txt", ios::app);

        if (!findBook.is_open())
        {
            cout << "Error in opening file! " << endl;
            return;
        }

        cout << "Number of books in this shelf: " << shelfBooks << endl;
        cout << "No. of Books lend to the User: " << lendCopies << endl;

        if (lendCopies <= shelfBooks)
        {
            // file
            findBook << "Borrower ID. = " << issuedTo->userId;

            findBook << "Borrower Name " << issuedTo->userName << endl;

            findBook << "Phone Number: " << issuedTo->userPhoneNumber << endl;

            findBook << " total  no. of lend copies: " << lendCopies << endl;

            shelfBooks -= lendCopies;
            bookCounter -= lendCopies;
            borrowersNo += 1;
            cout << "Number of books remaining in this shelf: " << shelfBooks << endl;
        }
        else
        {
            cout << "Error! Lend copies cannot be greater than total books in a shelf " << endl;
            findBook.close();
            return;
        }

        // Close files outside t
        findBook.close();
    }

    double calculateFine()
    {
        double fines;
        int diff;
        cout << "Lend date is : "<< lendDate << endl;
        cout << "Return date is : "<< returnDate << endl;
        cout << "enter the no of days between dates: "<< endl;
        cin >> diff;
        if (diff > 15)
        {
            diff = diff - 15;
            fines = diff * 10.0;
        }
        return fines;
    }

    // for saving returner's info in file
    void ReturnerInfoFile()
    {
        ofstream returnerPtr;
        returnerPtr.open("Returner.txt", ios::app);
        if (!returnerPtr.is_open())
        {
            cout << "Error in opening file! " << endl;
            return;
        }
        // file
        returnerPtr << "Returner ID. = " << returnerID << endl;

        returnerPtr << "Name " << returnerName << endl;

        returnerPtr << "Phone Number: " << returnerPhoneNumber << endl;
        returnerPtr << " Date: " << returnDate << endl;
        returnerPtr << " Number of returned books: " << returnCopies << endl;

        totalFine = calculateFine();

        returnerPtr << "Total Fine: " << totalFine << endl;

        bookCounter = bookCounter + returnCopies; // for incrementing the total boooks in this librrary due to returning of lended books
        shelfBooks = shelfBooks + returnCopies;   // for incrementing the total boooks in this shelf due to returning of lended books
        borrowersNo -= 1;                         // for incrementing the total No. Of borrowers
        returnerPtr << "Number of books remainig in this shelf: " << shelfBooks << endl;
        returnerPtr.close();
    }
    void showReturnnersInfo(string returnerID)
    {
        ifstream returnPtr;
        returnPtr.open("Returner.txt");

        if (!returnPtr.is_open())
        {
            cout << "Error opening file." << endl;
            return;
        }

        string line; // for storing the extracted line from the file

        while (getline(returnPtr, line))
        {
            istringstream iss(line);
            string word;

            while (iss >> word)
            {
                if (word == returnerID)
                {
                    cout << line << endl;
                    for (int i = 0; i < 3; i++) // for getting the other information
                    {
                        getline(returnPtr, line);
                        cout << line << endl;
                    }

                    break; // Stop checking the rest of the words in the line
                }
            }
        }

        // closing from file
        returnPtr.close();
    }
};

int Books::bookCounter;
int Books::borrowersNo;
int Books::shelfBooks;

int main()
{
    int quan, choice1, choice2, choice3, choice4, choice5, choice6;
    string shelfCode, scode, stid, returnerid, emID, auther[3];
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "-                              Built-In                                    -" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "- Enter the shelf code:                                                    -"; // for  built in
    cin >> shelfCode;
    cout << "- Enter the Quantity:                                                      -"; // for  built in
    cin >> quan;
    cout << "- Enter the authors' names:                                                -";
    for (int i = 0; i < 3; i++)
    {
        cin >> auther[i];
    }
    cout << "----------------------------------------------------------------------------" << endl;
    Books bookstocks(shelfCode, auther, 3, quan);
    bookstocks.saveBooksInFile(shelfCode);

    User user_no_student;

    while (true)
    {
        cout << "----------------------------------------------------------------------------" << endl;
        cout << "-                              Main Menu                                   -" << endl;
        cout << "----------------------------------------------------------------------------" << endl;

        cout << "- Enter '1' for entering a student:                                        -" << endl
             << "- Enter '2' for entering a Employee:                                       -" << endl
             << "- Enter '3' for entering a Boorower of a books:                            -" << endl
             << "- Enter '4' for entering a book returner:                                  -" << endl
             << "- Enter '5' for displaying all the books:                                  -" << endl
             << "- Enter '6' for displaying all the Students:                               -" << endl
             << "- Enter '7' for displaying all the Employees:                              -" << endl
             << "- Enter '8' for displaying all returners and borrowers info                -" << endl
             << "- Enter '9' for Exiting this menu                                          -" << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        cin >> choice1;

        if (choice1 == 1)
        {
            user_no_student.setStudentInfo();
            cout << endl;
            cout << "----------------------------------------------------------------------------" << endl;
            cout << "- if you want to store this you can , press '1' :                          -" << endl;
            cin >> choice2;
            if (choice2 == 1)
            {
                user_no_student.saveStudentInofrmation();
                cout << "----------------------------------------------------------------------------" << endl;
            }
            else
            {
                cout << "- Ok                                                                       -" << endl;
                cout << "----------------------------------------------------------------------------" << endl;
            }
        }
        else if (choice1 == 2)
        {
            user_no_student.setEmployeeInfo();
            cout << endl;
            cout << "---------------------------------------------------------------------------" << endl;
            cout << "- if you want to store this you can , press '1' :                         -" << endl;
            cin >> choice3;
            if (choice3 == 1)
            {
                user_no_student.saveEmployeeInofrmation();
                cout << "----------------------------------------------------------------------------" << endl;
            }
            else
            {
                cout << "- Ok                                                                       -" << endl;
                cout << "----------------------------------------------------------------------------" << endl;
            }
        }
        else if (choice1 == 3)
        {
            bookstocks.setBorrowerInfo();
            cout << endl;
            cout << "----------------------------------------------------------------------------" << endl;
        }
        else if (choice1 == 4)
        {
            bookstocks.setReturerInfo();

            cout << endl;
            cout << "---------------------------------------------------------------------------" << endl;
            cout << "- if you want to store this you can , press '1' :                         -" << endl;
            cin >> choice5;
            if (choice5 == 1)
            {
                bookstocks.ReturnerInfoFile();
                cout << "----------------------------------------------------------------------------" << endl;
            }
            else
            {
                cout << "- Ok                                                                       -" << endl;
                cout << "----------------------------------------------------------------------------" << endl;
            }
        }
        else if (choice1 == 5)
        {
            bookstocks.showShelfStock(shelfCode);

            cout << endl;
            cout << "---------------------------------------------------------------------------" << endl;
            cout << "- if you want to store this you can , press '1' :                         -" << endl;
            cin >> choice2;

            cout << "----------------------------------------------------------------------------" << endl;
        }
        else if (choice1 == 6)
        {
            user_no_student.studentInformation();
            cout << endl;
            cout << "---------------------------------------------------------------------------" << endl;
        }
        else if (choice1 == 7)
        {
            user_no_student.EmployeeInformation();
            cout << endl;
            cout << "---------------------------------------------------------------------------" << endl;
        }
        else if (choice1 == 8)
        {
            cout << "- Enter '1' to see returners or '2' for borrowers                         -" << endl;
            cin >> choice6;
            if (choice6 == 1)
            {
                cout << "- enter the returner id :                                                 -" << endl;
                cin >> returnerid;
                bookstocks.showReturnnersInfo(returnerid);
                cout << endl;
                cout << "---------------------------------------------------------------------------" << endl;
            }
            else if (choice6 == 2)
            {
                cout << "- Form Which shelf you want to take the book, Enter code :                - ";
                cin >> scode;
                bookstocks.lendBooksFile(&user_no_student, 4);
                cout << "---------------------------------------------------------------------------" << endl;
            }
            else
            {
                cout << "- Wrong input!                                                            -" << endl;
                cout << "---------------------------------------------------------------------------" << endl;
            }
        }
        else if (choice1 == 9)
        {
            cout << "---------------------------------------------------------------------------" << endl;
            break;
        }
    }
    return 0;
}
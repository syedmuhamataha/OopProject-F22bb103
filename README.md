# OopProject
# F22BB103 (Afternoo-b)
# Library Management System
This is a simple console-based Library Management System implemented in C++. The system allows for the management of students, employees, and books. It supports functionalities such as adding new students, adding new employees, adding new books, lending books to borrowers, and returning books.

##Features
###User Management:

Add new students with relevant information such as ID, name, father's name, gender, section, degree, email, and phone number.
Add new employees with information such as ID, name, job title, email, and phone number.
### Book Management:

Add books to the system by specifying the shelf code, quantity, authors, and other details.
Display information about all books in a specific shelf.
Borrowing and Returning Books:

Borrow books by entering borrower information, including ID, name, email, phone number, lend date, and the number of copies to be borrowed.
Return books by entering returner information, including ID, name, return date, and the number of copies to be returned.
Calculate fines for overdue books.
Record Keeping:

Save information about students, employees, books, borrowers, and returners in separate files.
Display information about students, employees, and returners from the saved records.
## Usage
### Add Built-in Books:

During startup, the system prompts for the shelf code, quantity, and authors of built-in books.
Built-in books are added to the system automatically.
### Main Menu:

The main menu allows users to navigate through various functionalities such as adding students, employees, books, borrowing, and returning books.
### Saving Information:

Users are prompted to save entered information, and they can choose to do so by pressing '1' when prompted.
### Viewing Information:

Information about books, students, employees, borrowers, and returners can be displayed through the main menu.
File Structure
Student.txt: Stores information about students.
Employee.txt: Stores information about employees.
Borrowers.txt: Records information about borrowers and the books they borrowed.
Returner.txt: Records information about returners and the books they returned.
How to Run
Compile the code using a C++ compiler.
Run the executable.
Follow the prompts in the console to perform various actions in the library management system.

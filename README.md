# Contact_Managent_System
📞 Contact Management System


📌 Project Overview

The Contact Management System is a simple yet powerful C-based console application that allows users to store, search, edit, delete, and view contacts.
This project demonstrates:

File handling

Structures in C

Searching algorithms

CRUD operations

Data persistence

Menu-driven programming

It is an excellent beginner-to-intermediate level project for students learning C programming and file operations.

🚀 Features
✔ 1. Add New Contact

Add new contacts with Name, Phone, and Email

Validated input

Automatically stored in a binary file (contacts.dat)

✔ 2. View All Contacts

Displays every saved contact

Shows them in a clean format

✔ 3. Search Contact

Search by Name (case-insensitive)

Displays matching contact details

✔ 4. Edit Contact

Modify an existing contact’s name, phone, or email

Directly updates the file using fseek

✔ 5. Delete Contact

Deletes a contact safely using a temporary file

Ensures data integrity

✔ 6. Data is Permanently Stored

Contacts remain available even after the program closes

Uses binary file handling

✔ 7. Simple User Interface

Menu-driven

Beginner-friendly

No crashes or overflow issues

🛠️ Technologies Used
Component	Details
Language	C Programming
Storage	Binary Files (.dat)
Concepts	Structures, File Handling, CRUD, Loops, Strings
📂 File Structure
Contact-Management-System/
│
├── contacts.dat     -> Auto-created database file
├── contact.c        -> Main source code
└── README.md        -> Documentation

👨‍💻 How to Run the Project
1. Save the code

Create a file named contact.c and paste the program.

2. Compile

Use GCC:

gcc contact.c -o contact

3. Run
./contact


(on Windows → contact.exe)

🧠 Concepts Covered

This project helps you learn:

Structures

File I/O (fwrite, fread, fopen, fclose)

Searching algorithms

Updating binary files using fseek

Deleting records using temporary files

String handling

Menu-driven application logic

📊 Example Output
===============================
     CONTACT MANAGEMENT
===============================
1. Add Contact
2. View All Contacts
3. Search Contact
4. Edit Contact
5. Delete Contact
6. Exit
Enter your choice: 1

Enter Name: Mahi
Enter Phone: 9876543210
Enter Email: mahi@gmail.com

Contact added successfully!


Author   :  Mahesh Babu Baswani

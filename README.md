# 🏦 Bank Management System – OOP Version (C++)

This is a beginner-to-intermediate level project that simulates a simple banking management system using Object-Oriented Programming (OOP) in C++. It is part of my learning journey in software development.

---

## 🌟 Project Goal

* Transform a previous Functional Programming (FP)-style bank project into an OOP-structured version.
* Apply real OOP principles like inheritance, encapsulation, and separation of concerns.
* Improve code readability and maintainability.
* Learn project structure, file organization, and GitHub version control.

---

## 🧱 Project Structure

### 👥 Classes

* `Person`: Base class for people in the system.
* `Client`: Inherits from `Person`, represents bank clients with data like balance, account number, etc.
* `User`: Represents system users with login credentials, encrypted passwords, roles, and permissions.

### 🖥️ UI Screens

* `Screen`: Base class for all screen components.
* `MainScreen`: Inherits from `Screen`, shows the main dashboard and navigation menu.
* `TransactionsScreen`: Handles all transaction-related operations:

  * Deposit
  * Withdraw
  * Show total balances
  * Transfer money between accounts
  * View transfer logs
  * Return to main menu
* `ManageUsersScreen`: Manages system users, including:

  * Show list of users
  * Add user
  * Delete user
  * Update user
  * Find user
  * Return to main menu
* `LoginScreen`: Handles the login process with username and password input, displaying up to 3 attempts before system denial.
* `LoginRegisterScreen`: Displays login records with username, login time, and date.
* Every screen shows the current date/time and the active user's name in the header.

### ⚙️ Business Logic (Non-UI)

* `BankingOperations` or `BusinessLogic`: Contains the actual implementation for deposit, withdraw, transfer, and related logic. It has no UI and focuses only on the core functionality of the system.

---

## ✅ Implemented Features

### 👤 Client Management

* Show list of clients
* Add new client
* Delete client
* Update client
* Find client

### 💰 Banking Transactions

* Deposit money
* Withdraw money
* Transfer money between accounts
* Show total balances
* View transfer logs (with sender, receiver, amount, both balances after transfer, date, and time)

### 👥 User Management

* Show list of users
* Add user
* Delete user
* Update user
* Find user
* Assign permissions using bitwise AND operations and binary flags
* Logout functionality

### 🔐 Authentication & Security

* Login system with username and encrypted password stored in a file
* Decryption is handled inside the system during login
* 3 login attempts allowed before access is denied
* Login records saved with timestamp
* Encrypted password storage (even when shown in logs)

### 🤭 Navigation

* Main dashboard and navigation menu
* All screens show:

  * Active user’s username
  * Current date and time

---

## ⚖️ In Progress

* Advanced permission roles and audit logging features.

---

## 🛠️ Technologies Used

* **Language:** C++
* **Paradigm:** Object-Oriented Programming (OOP)
* **Platform:** Console-based
* **Tools:** Visual Studio Community
* **Version Control:** Git + GitHub

---

## 🧠 What I Learned

* The practical difference between Functional Programming and Object-Oriented Programming.
* How to design and structure a real-world program using classes and inheritance.
* Importance of separating UI from business logic.
* File encryption and secure authentication methods.
* Permission management using bitwise operations.
* Git and GitHub usage to document, track, and share projects publicly.

---

## ▶️ How to Run

1. Clone the repository:

   ```bash
   git clone https://github.com/Yusuf200526/BankProjectOOPCourse11.git
   ```
2. Open the project in **Visual Studio Community**.
3. Build and run the project from the `main.cpp` file.
4. Follow the instructions on the console-based interface.

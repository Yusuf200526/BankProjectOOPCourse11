# 🏦 Bank Management System – OOP Version (C++)

This is a beginner-to-intermediate level project that simulates a simple banking management system using Object-Oriented Programming (OOP) in C++. It is part of my learning journey in software development.

---

## 🎯 Project Goal

- Transform a previous Functional Programming (FP)-style bank project into an OOP-structured version.
- Apply real OOP principles like inheritance, encapsulation, and separation of concerns.
- Improve code readability and maintainability.
- Learn project structure, file organization, and GitHub version control.

---

## 🧱 Project Structure

### 👥 Classes

- `Person`: Base class for people in the system.
- `Client`: Inherits from `Person`, represents bank clients with data like balance, account number, etc.
- `User`: *(under development)* Represents system users with login credentials and permission roles.

### 🖥️ UI Screens

- `Screen`: Base class for all screen components.
- `MainScreen`: Inherits from `Screen`, shows the main dashboard and navigation menu.
- `TransactionsScreen`: Handles all transaction-related operations:
  - Deposit
  - Withdraw
  - Show total balances
  - Return to main menu
- `ManageUsersScreen`: Manages system users, including:
  - Show list of users
  - Add user
  - Delete user
  - Update user
  - Find user
  - Return to main menu

### ⚙️ Business Logic (Non-UI)

- `BankingOperations` or `BusinessLogic`: Contains the actual implementation for deposit, withdraw, and related logic. It has no UI and focuses only on the core functionality of the system.

---

## ✅ Implemented Features

### 👤 Client Management

- Show list of clients  
- Add new client  
- Delete client  
- Update client  
- Find client  

### 💰 Banking Transactions

- Deposit money  
- Withdraw money  
- Show total balances  

### 📋 User Management

- Show list of users  
- Add user  
- Delete user  
- Update user  
- Find user  
- Return to main menu  

### 🧭 Navigation

- Main dashboard and navigation menu

---

## 🚧 In Progress

- `User` class authentication system (login, permissions, roles)

---

## 🛠️ Technologies Used

- **Language:** C++  
- **Paradigm:** Object-Oriented Programming (OOP)  
- **Platform:** Console-based  
- **Tools:** Visual Studio Community  
- **Version Control:** Git + GitHub

---

## 🧠 What I Learned

- The practical difference between Functional Programming and Object-Oriented Programming.  
- How to design and structure a real-world program using classes and inheritance.  
- Importance of separating UI from business logic.  
- Git and GitHub usage to document, track, and share projects publicly.

---

## ▶️ How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/Yusuf200526/BankProjectOOPCourse11.git

# Clinic Management System (C)

A robust, command-line interface (CLI) Clinic/Hospital Management System implemented in C. This project demonstrates the practical application of fundamental Data Structures and Algorithms (DSA) to efficiently manage patient records, doctor profiles, and medical appointments.

## 🚀 Features

### 1. Patient Management
* **Add Patient:** Register new patients with their Name, Age, and Gender. Auto-generates a unique Patient ID.
* **Search Patient:** Look up existing patients in the system.
* **Display Records:** View a complete, formatted list of all registered patients.
* **Delete Patient:** Safely remove a patient's record from the database.
* **Data Persistence:** Automatically save and load patient data using local file storage (`data/patients.txt`).

### 2. Doctor Management
* **Add Doctor:** Register doctors with their Name and a unique ID.
* **Search Doctor:** Fast lookup by Doctor ID.
* **List Doctors:** View all doctors sorted by their IDs.
* **Delete Doctor:** Remove a doctor from the system by their name.
* **Data Persistence:** Save and load doctor data using local file storage (`data/doctors.txt`).

### 3. Appointment Management
* **Book Appointment:** Schedule visits by linking a Patient ID, Doctor ID, datetime, and purpose.
* **Queue Processing:** Process appointments in a First-In-First-Out (FIFO) order based on medical queue logic.
* **Time-Range Queries:** Find all appointments scheduled within a specific time range.

---

## 🧠 Core Data Structures Used

This project leverages several classic data structures to optimize performance and memory usage:

* **Singly Linked List (`patient.c`):** Manages patient records, allowing dynamic scaling without fixed memory limits.
* **Binary Search Tree - BST (`doctor.c`):** Stores doctor records by ID, enabling fast average time complexity for rapid searching, insertion, and deletion.
* **Dynamic Array / Vector (`doctor.c`):** Acts as a flexible buffer for doctor records during file I/O and batch processing.
* **Queue & BST (`appointment.c`):** Uses a Queue to maintain the exact order of daily medical appointments (FIFO) and a BST to efficiently query appointments by datetime.

---

## 📂 Project Structure

\`\`\`text
.
├── src/
│   ├── main.c           # Program entry point and CLI menu
│   ├── patient.c        # Patient logic (Linked List)
│   ├── patient.h        # Patient headers
│   ├── doctor.c         # Doctor logic (BST & Vector)
│   ├── doctor.h         # Doctor headers
│   ├── appointment.c    # Appointment logic (BST & Queue)
│   ├── appointment.h    # Appointment headers
│   ├── utils.c          # Utility functions (ID generation)
│   └── utils.h          
├── data/
│   ├── patients.txt     # Local storage for patients
│   └── doctors.txt      # Local storage for doctors
└── README.md
\`\`\`

---

## 🛠️ Compilation and Execution

### Prerequisites
Ensure you have a standard C compiler installed (e.g., GCC for Linux/macOS or MinGW for Windows).

### Build Instructions
Open your terminal in the project directory and run the following command to compile all source files into a single executable:

\`\`\`bash
gcc main.c patient.c doctor.c appointment.c utils.c -o clinic_system
\`\`\`

### Running the Application
**Important:** Create a `data` folder in the root directory before running the program, so the system can successfully save and load the `.txt` database files.

**Windows:**
\`\`\`cmd
mkdir data
clinic_system.exe
\`\`\`

**Linux / macOS:**
\`\`\`bash
mkdir data
./clinic_system
\`\`\`

---

## 📋 Interactive Menu Options

Upon launching the application, you can navigate the system using the following numerical choices:
1. Add a patient
2. Search a patient
3. Display the patient's information
4. Delete a patient
5. Load doctors from file
6. List Doctor
7. Save doctor to file
8. Delete a doctor
9. Add doctor
10. Load patient from file
11. Save patient to file
12. Search a doctor through their ID
13. Exit

---

## 👤 Author
* **Nguyễn Huy Long** - *Electrical Engineering, VinUniversity*
<img width="1000" height="450" alt="Image" src="https://github.com/user-attachments/assets/5c8b71b7-72ba-4300-a208-f047ac0177b1" />

## 📂 Project Structure

```text
.
├── src/
│   ├── main.c           # Entry point and interactive CLI menu
│   ├── patient.c        # Patient logic (Linked List)
│   ├── patient.h        # Patient structure definition
│   ├── doctor.c         # Doctor logic (BST & Vector)
│   ├── doctor.h         # Doctor structure definition
│   ├── appointment.c    # Appointment logic (BST & Queue)
│   ├── appointment.h    # Appointment structure definition
│   ├── utils.c          # Helper functions (ID generation)
│   └── utils.h          
├── data/
│   ├── patients.txt     # Local database for patients
│   └── doctors.txt      # Local database for doctors
└── README.md


# MediTrack---Hospital-Management-System
The program operates through a text-based interface and stores its data locally using file I/O, making it suitable for low-resource environments or offline systems. This implementation is especially useful in academic contexts to demonstrate mastery of data structures (like Linked Lists, Queues, and Binary Search Trees) and file operations in C.


# Clinic Management System (C)

A command-line based Clinic/Hospital Management System written in C. This project demonstrates the practical application of various fundamental Data Structures and Algorithms (DSA) to manage patients, doctors, and medical appointments efficiently.

## 🚀 Features

### 1. Patient Management
* **Add new patient:** Stores basic information (Name, Age, Gender) and auto-generates a unique Patient ID.
* **Search patient:** Look up a patient by their name.
* **Display records:** View a complete list of all registered patients.
* **Delete patient:** Remove a patient from the system by name.
* **Data Persistence:** Save to and load from `data/patients.txt`.

### 2. Doctor Management
* **Add new doctor:** Register a doctor with a Name and ID.
* **Search doctor:** Fast lookup by Doctor ID.
* **Display records:** View all doctors in ascending order of their IDs.
* **Delete doctor:** Remove a doctor's record from the system.
* **Data Persistence:** Save to and load from `data/doctors.txt`.

### 3. Appointment Management (Core Backend Implemented)
* **Book appointment:** Schedule a visit specifying the patient, doctor, timestamp, and purpose.
* **Queue processing:** Fetch the next appointment in line based on a First-In-First-Out (FIFO) medical queue.
* **Time-range queries:** Find all appointments within a specific start and end time.

---

## 🧠 Data Structures Utilized

This project is built heavily around core data structures to optimize specific operational needs:

* **Singly Linked List (`patient.c`):** Used for storing patient records. Allows dynamic memory allocation without a fixed capacity.
* **Binary Search Tree - BST (`doctor.c`):** Doctors are stored in a BST based on their IDs, allowing for $O(\log n)$ average time complexity for searching, insertion, and deletion.
* **Dynamic Array / Vector (`doctor.c`):** Used as an auxiliary structure to hold doctor records in memory for batch processing and file I/O operations.
* **BST & Queue (`appointment.c`):** * *BST:* Used to query appointments rapidly by datetime.
    * *Queue:* Used to process daily appointments in the exact order they were booked.

---

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

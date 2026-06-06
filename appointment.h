#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <time.h>

#define MAX_PURPOSE_LEN 100

typedef struct {
    int appointment_id;
    int patient_id;
    int doctor_id;
    time_t datetime;
    char purpose[MAX_PURPOSE_LEN];
} Appointment;

// BST thoi gian
typedef struct BSTNode {
    Appointment data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

// Queue process order benh nhan
typedef struct QueueNode {
    Appointment data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    BSTNode* bst_root;
    QueueNode* queue_front;
    QueueNode* queue_rear;
    int count;
} AppointmentSystem;

void init_appointment_system(AppointmentSystem* system);
int book_appointment(AppointmentSystem* system, int patient_id, int doctor_id, 
                    time_t datetime, const char* purpose);
Appointment* get_next_appointment(const AppointmentSystem* system);
void find_appointments_in_range(const AppointmentSystem* system,
    time_t start,
    time_t end,
    const Appointment** results,  // Keep const here
    int* count);

void free_appointment_system(AppointmentSystem* system);
void display_appointment(const Appointment* appt);


#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "appointment.h"
//BST
void init_appointment_system(AppointmentSystem* system) {
    system->bst_root = NULL;
    system->queue_front = NULL;
    system->queue_rear = NULL;
    system->count = 0;
}
//new node
static BSTNode* new_bst_node(Appointment appt) {
    BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
    if (node) {
        node->data = appt;
        node->left = node->right = NULL;
    }
    return node;
}
//process appointment theo thu tu
static QueueNode* new_queue_node(Appointment appt) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    if (node) {
        node->data = appt; //appointment trong node
        node->next = NULL; //pointer tiep theo la NULLO
    }
    return node;
}

//book appointment
int book_appointment(AppointmentSystem* system, int patient_id, int doctor_id, 
                    time_t datetime, const char* purpose) {
    Appointment appt;
    appt.appointment_id = system->count + 1; //tao ID cho appointment
    appt.patient_id = patient_id;
    appt.doctor_id = doctor_id;
    appt.datetime = datetime; //store datetime appointment
    strncpy(appt.purpose, purpose, MAX_PURPOSE_LEN - 1);
    appt.purpose[MAX_PURPOSE_LEN - 1] = '\0';
//them appointment vao BST
    BSTNode** current = &(system->bst_root);
    while (*current != NULL) {
        if (datetime < (*current)->data.datetime) {
            current = &((*current)->left); //left neu appointment time is earlier
        } else if (datetime > (*current)->data.datetime) {
            current = &((*current)->right); //right neu muon hon
        } else {
            return 0;
        }
    }
    *current = new_bst_node(appt);
    if (*current == NULL) return 0;
//queue node cho appointment 
    QueueNode* q_node = new_queue_node(appt);
    if (q_node == NULL) return 0;
    
    if (system->queue_rear == NULL) {
        system->queue_front = system->queue_rear = q_node;
    } else {
        system->queue_rear->next = q_node;
        system->queue_rear = q_node;
    }

    system->count++;
    return 1;
}
//tim appointment tiep theo neu la cai phia truoc cua queue
Appointment* get_next_appointment(const AppointmentSystem* system) {
    if (system->queue_front == NULL) return NULL;
    return &(system->queue_front->data);
}
//tim moi appointment trong 1 range bang BST
static void range_query(const BSTNode* node, 
    time_t start, 
    time_t end, 
    const Appointment** results,
    int* index) {

if (node == NULL) {
return;
}

if (node->data.datetime > start) {
range_query(node->left, start, end, results, index);
}

if (node->data.datetime >= start && node->data.datetime <= end) {
results[(*index)++] = &node->data;
}

if (node->data.datetime < end) {
range_query(node->right, start, end, results, index);
}
}

//tim all appointments trong 1 thoi gian nao do
void find_appointments_in_range(const AppointmentSystem* system,
    time_t start,
    time_t end,
    const Appointment** results, 
    int* count) {
*count = 0; //result neu co
range_query(system->bst_root, start, end, results, count);
}

void display_appointment(const Appointment* appt) {
    if (appt == NULL) return;
    printf("Appt #%d: Patient %d with Dr. %d\n", appt->appointment_id, 
           appt->patient_id, appt->doctor_id);
    printf("Time: %s", ctime(&appt->datetime));
    printf("Purpose: %s\n", appt->purpose);
}
//free memory
static void free_bst(BSTNode* node) {
    if (node) {
        free_bst(node->left);
        free_bst(node->right);
        free(node);
    }
}

void free_appointment_system(AppointmentSystem* system) {
    free_bst(system->bst_root);
    
    while (system->queue_front) {
        QueueNode* temp = system->queue_front;
        system->queue_front = system->queue_front->next;
        free(temp);
    }
    
    system->bst_root = NULL;
    system->queue_front = system->queue_rear = NULL;
    system->count = 0;
    
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include "patient.h"
#include "doctor.h"
#include "utils.h"
#include "appointment.h"
Vector v;
int main() {
    int choice;
    init_doctor(&v);
    int t = 1;
    while (t) {
        printf("\n");
        printf("1. Add a patient\n");
        printf("2. Search a patient\n");
        printf("3. Display the patient's information\n");
        printf("4. Delete a patient\n");
        printf("5. Load doctors from file\n");
        printf("6. List Doctor\n");
        printf("7. Save doctor to file\n");
        printf("8. Delete a doctor\n");
        printf("9. Add doctor\n");
        printf("10. Load patient from file\n");
        printf("11. Save patient to file\n");
        printf("12. Search a doctor through their ID\n");
        printf("13. \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                add_patient();
                break;
            case 2:
                search_patient();
                break;
            case 3:
                display_patient_info();
                break;
            case 4:
                delete_patient();
                break;
            case 5:
                load_doctor_from_file(&v);
                break;
            case 6:
                list_doctor(&v);
                break;
            case 7:
                save_doctor_to_file(&v);
                break;
            case 8: 
                delete_doctor_by_name(&v);
                break;
            case 9:
                add_doctor(&v);
                break;
            case 10:
                load_patient_from_file();
                break;
            case 11:
                save_patient_to_file();
                break;
            case 12:
                search_doctor(&v);
                break;
            default:
                t = 0;
                break;
        }

        
    }
    return 0;

}
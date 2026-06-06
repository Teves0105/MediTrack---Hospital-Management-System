#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int count = 0;

int generate_patient_id() {
    count++;
    return count;
}   
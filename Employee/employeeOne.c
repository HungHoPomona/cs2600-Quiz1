#include "Employee.h"
#include <stdio.h>
#include <string.h>

PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber) {
    const PtrToConstEmployee endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++) {
        if (ptr->IDnumber == targetNumber) // Fixed field name
            return (PtrToEmployee)ptr;
    }
    return NULL;
}

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, const char *targetName) {
    const PtrToConstEmployee endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++) {
        if (strcmp(ptr->name, targetName) == 0)
            return (PtrToEmployee)ptr;
    }
    return NULL;
}

PtrToEmployee searchEmployeeByPhoneNumber(PtrToConstEmployee ptr, int tableSize, const char *targetPhoneNumber) {
    const PtrToConstEmployee endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++) {
        if (strcmp(ptr->phoneNumber, targetPhoneNumber) == 0)
            return (PtrToEmployee)ptr;
    }
    return NULL;
}

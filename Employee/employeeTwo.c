#include <string.h>
#include "employee.h"
// NOTE: 5 functions have been defined below
// ptr - points to table to be searched
// tableSize - size of the table
// targetPtr - points to value that will be searched for in table
// functionPtr - points to a comparison function below and will perform the comparison

// What does setting a function to static do?? 
// functionPtr is the address of the function, just use the name
// ()(The second set of parentheses is the arguments of the function)

static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void *targetPtr, int (*functionPtr)(const void *, PtrToConstEmployee)) {
    PtrToConstEmployee endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++) {
        if ((*functionPtr)(targetPtr, ptr) == 0)
            return (PtrToEmployee)ptr;
    }
    return NULL;
}

// The functionPtr will point to one of these comparison functions
static int compareEmployeeNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr) {
    return *(const long *)targetPtr != tableValuePtr->IDnumber;
}

static int compareEmployeeName(const void *targetPtr, PtrToConstEmployee tableValuePtr) {
    return strcmp((const char *)targetPtr, tableValuePtr->name);
}

// Add implementation for searchEmployeeBySalary
PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetSalary) {
    PtrToConstEmployee endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++) {
        if (ptr->salary == targetSalary)
            return (PtrToEmployee)ptr;
    }
    return NULL;
}


#include "exception.h"

using namespace std;

const char* No_Parent_Exception:: what() const throw() {
    return "Parent is NULL!";
}

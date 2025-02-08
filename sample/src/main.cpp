#include "TestVector.h"
#include "TestArray.h"
#include "TestMatrix.h"
#include "TestList.h"
#include "testIntrusiveList.h"
#include "testNDimVector.h"

int main() {
    mylib::testVector::runTests(); 
    mylib::testArray::runTests();
    mylib::testMatrix::runTests();
    mylib::testList::runTests();               
    mylib::testIntrusiveList::runTests();
    mylib::testNDimVector::runTests();
    return 0;
}

#include "TestVector.h"
#include "TestArray.h"
#include "TestMatrix.h"
#include "TestList.h"
#include "testNDimVector.h"

int main() {
    mylib::testVector::runTests();          
    /*mylib::testArray::runTests();           good */
    /*mylib::testMatrix::runTests();*/
    /*mylib::testList::runTests();            not good */ 
    /*mylib::testNDimVector::runTests();*/
    return 0;
}

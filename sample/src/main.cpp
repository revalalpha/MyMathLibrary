#include "TestVector.h"
#include "TestArray.h"
#include "TestMatrix.h"
#include "TestList.h"
#include "testNDimVector.h"

int main() {
    /*mylib::testVector::runTests();          good */
    /*mylib::testArray::runTests();           good */
    /*mylib::testMatrix::runTests();          good */
    mylib::testList::runTests();
    /*mylib::testNDimVector::runTests();*/
    return 0;
}

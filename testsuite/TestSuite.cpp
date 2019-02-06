
#include <cppunit/ui/text/TestRunner.h>
#include "AnimationFileBinaryTest.hpp"

int main(int argc, char* argv[])
{  
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();

    runner.addTest( registry.makeTest() );
    runner.run();
    return 0;
}
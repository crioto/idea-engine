#include <cppunit/extensions/HelperMacros.h>

class AnimationFileBinaryTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( AnimationFileBinaryTest );
    CPPUNIT_TEST( testMarshal );
    CPPUNIT_TEST( testUnmarshal );
    CPPUNIT_TEST_SUITE_END();

    public:
    void tearUp();
    void tearDown();
    void testMarshal();
    void testUnmarshal();
};
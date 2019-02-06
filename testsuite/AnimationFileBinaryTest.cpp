#include <cppunit/extensions/TestFactoryRegistry.h>

#include "AnimationFileBinaryTest.hpp"

#include "AnimationFileBinary.hpp"

void AnimationFileBinaryTest::tearUp()
{

}

void AnimationFileBinaryTest::tearDown()
{

}

void AnimationFileBinaryTest::testUnmarshal()
{

}

void AnimationFileBinaryTest::testMarshal()
{
    std::vector<IdeaEngine::Frame> v;
    v.push_back({0, 100, 100, 20, 20});
    v.push_back({1, 130, 100, 22, 21});
    v.push_back({2, 160, 100, 24, 23});
    v.push_back({3, 200, 100, 26, 25});
    v.push_back({4, 230, 100, 28, 27});
    v.push_back({5, 260, 100, 30, 29});
    v.push_back({6, 300, 100, 32, 31});
    v.push_back({7, 330, 100, 34, 33});
    

    IdeaEngine::AnimationFileBinary t("");
    t.marshal(v);
}

CPPUNIT_TEST_SUITE_REGISTRATION( AnimationFileBinaryTest );
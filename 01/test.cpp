#include <iostream>

#include <gtest/gtest.h>


class TestPhonetic : public ::testing::Test
{
    void SetUp()
    {
        std::cout << "Set up" << std::endl;
    }

    void TearDown()
    {
        std::cout << "Tear down" << std::endl;
    }
};

TEST_F(TestPhonetic, test_phonetic)
{
    {
        std::string expected{"H400"};
        ASSERT_EQ(expected, convertTextToSound("hello"));
    }
    {
        std::string expected{"T235"};
        ASSERT_EQ(expected, convertTextToSound("testing"));
    }
    {
        std::string expected{"A261"};
        ASSERT_EQ(expected, convertTextToSound("Ashcraft"));
    }
}

TEST_F(TestUtils, test_dummy)
{
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include <gtest/gtest.h>
#include "../include/FileEncryptor.h"

#include <string>

TEST(FileEncryptor, Encryption) {
    const std::string source_path = "../data/encrypt.txt";
    // key is 5;
    EXPECT_EQ(FileEncryptor::encrypt(source_path), "Mjqqt\\twqi&");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
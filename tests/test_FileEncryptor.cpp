#include <gtest/gtest.h>
#include "../include/FileEncryptor.h"

#include <string>

TEST(FileEncryptor, Encryption) {
    const std::string source_path = "../data/text.txt";
    EXPECT_EQ(FileEncryptor::encrypt(source_path, 5), "Mjqqt\\twqi&");
}

TEST(FileEncryptor, Decrypt) {
    const std::string encrypted_path = "../data/encrypted.txt";
    EXPECT_EQ(FileEncryptor::decrypt(encrypted_path, 5), "HelloWorld!");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
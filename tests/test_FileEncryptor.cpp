#include <gtest/gtest.h>
#include "../include/FileEncryptor.h"

#include <string>

TEST(FileEncryptor, Encryption) {
    const std::string source_path = "../data/text.txt";
    const std::istringstream simulated_input("5"); // redirect the standard input to read from simulated_input
    std::cin.rdbuf(simulated_input.rdbuf());
    EXPECT_EQ(FileEncryptor::encrypt(source_path), "Mjqqt\\twqi&");
}

TEST(FileEncryptor, Decrypt) {
    const std::string encrypted_path = "../data/encrypted.txt";
    const std::istringstream simulated_input("5");
    std::cin.rdbuf(simulated_input.rdbuf());
    EXPECT_EQ(FileEncryptor::decrypt(encrypted_path), "HelloWorld!");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
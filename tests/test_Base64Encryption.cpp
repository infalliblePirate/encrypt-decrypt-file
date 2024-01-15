#include <gtest/gtest.h>
#include "../include/Base64Encryption.h"

TEST(Base64Enctyption, Encrypt) {
  const std::string source_path = "../data/text.txt";
  EXPECT_EQ(base64::Base64Encryption::encode(source_path), "SGVsbG8gV29ybGQh");
}

TEST(Base64Encryption, Decrypt) {
  const std::string encrypted_path = "../data/encrypted.txt";
  EXPECT_EQ(base64::Base64Encryption::decode(encrypted_path), "Hello World!");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
#include <iostream>
#include "../include/FileEncryptor.h"

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cout << "Example: ./encryptor path_to_file key (1 - encrypt || 0 - decrypt)" << std::endl;
    return -1;
  }

  std::string source_path = argv[1];
  int key = atoi(argv[2]);
  int encryption_flag = atoi(argv[3]);

  if (encryption_flag) {
    std::cout << FileEncryptor::encrypt(source_path, key) << std::endl;
  } else {
    std::cout << FileEncryptor::decrypt(source_path, key) << std::endl;
  }

  return 0;
}

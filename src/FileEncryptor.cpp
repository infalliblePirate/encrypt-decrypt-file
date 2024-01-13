#include "../include/FileEncryptor.h"
#include <fstream>

std::string FileEncryptor::encrypt(const std::string& source_path) {
  int key = 5;

  std::fstream fin, fout;
  fin.open(source_path, std::fstream::in);
  fout.open("encrypted.txt", std::fstream::out);

  std::string encrypted_txt;
  char c;
  while(fin >> c) {
    int temp = c + key;

    fout<< static_cast<char>(temp);
    encrypted_txt += static_cast<char>(temp);
  }

  return encrypted_txt;
}

std::string FileEncryptor::decrypt(const std::string &encrypted_path) {

  return "";
}

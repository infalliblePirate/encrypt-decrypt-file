#include "../include/FileEncryptor.h"
#include <fstream>

std::string FileEncryptor::encrypt(const std::string &source_path) {
  int key = 5;

  std::fstream fin, fout;
  fin.open(source_path, std::fstream::in);
  fout.open("../data/encrypted.txt", std::fstream::out);

  std::string encrypted_txt;
  char c;
  while (fin >> c) {
    int temp = c + key;

    fout << static_cast<char>(temp);
    encrypted_txt += static_cast<char>(temp);
  }

  fin.close();
  fout.close();
  return encrypted_txt;
}

std::string FileEncryptor::decrypt(const std::string &encrypted_path) {
  int key = 5;

  std::fstream fin, fout;
  fin.open("../data/encrypted.txt", std::fstream::in);
  fout.open("decrypted.txt", std::fstream::out);

  std::string decrypted_txt;
  char c;
  while(fin >> c) {
    int temp = c - key;

    fout << static_cast<char>(temp);
    decrypted_txt += static_cast<char>(temp);
  }

  fin.close();
  fout.close();
  return decrypted_txt;
}

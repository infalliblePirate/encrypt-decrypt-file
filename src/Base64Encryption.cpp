#include "../include/Base64Encryption.h"

#include <bitset>
#include <fstream>
#include <iostream>

namespace base64 {
  const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
      "abcdefghijklmnopqrstuvwxyz"
      "0123456789+/";
  const int CHUNK_SIZE = 3;
  const int BITS_PER_BYTE = 8;
  const int BASE64_BITS = 6;
  const char PADDING_CHAR = '=';
  const int BITS_MASK = 0x3F;

  std::string Base64Encryption::encode(const std::string &source_path) {
    std::string result;
    std::ifstream fin;

    fin.open(source_path, std::fstream::in);
    if (!fin.is_open()) {
      std::cerr << "Could not open the input file" << std::endl;
      return "";
    }

    int remaining;
    char buffer[CHUNK_SIZE];
    while (fin.read(buffer, sizeof(buffer)) || fin.gcount() > 0) {
      // extracts 3 bytes and stores 'em in the buffer

      remaining = fin.gcount();// in case in fin there are 1 or 2 chars, read from buffer till the 1 or 2 char respectively
      std::bitset<CHUNK_SIZE * BITS_PER_BYTE> bits; // fixed-size sequence of 24 bits
      for (size_t i = 0; i < remaining; ++i) {
        bits |= static_cast<unsigned char>(buffer[i]) << (BITS_PER_BYTE * (CHUNK_SIZE - 1 - i)); // left-shifts by these many positions
      }

      for (size_t i = 0; i < remaining + 1; ++i) {
        result += base64_chars[(bits >> (BASE64_BITS * (CHUNK_SIZE - i))).to_ulong() & BITS_MASK];
        // right-shifts + intersects with 00111111 so that only last 6 bits are considered
      }
      /*Example:
       * i = 0; right-shift by 18
       * 11011010 01100001 01010101 >>18: 0000000 00000000 00110110, AND 00111111 =
       *    00000000 00000000 00110110
       *AND 00000000 00000000 00111111
       *  = 00000000 00000000 00110110 = 54, result += base64_chars[54];
       */
    }

    // padding
    if (remaining != 0)
      for (size_t i = 0; i < CHUNK_SIZE - remaining; ++i) {
        result += PADDING_CHAR;
      }
    fin.close();

    std::ofstream fout("../data/encrypted.txt");
    if (fout.is_open()) {
      fout << result;
      fout.close();
    } else {
      std::cerr << "Could not open the output file." << std::endl;
      return "";
    }

    return result;
  }

  std::string Base64Encryption::decode(const std::string &encrypted_path) {
    return "";
  }
}

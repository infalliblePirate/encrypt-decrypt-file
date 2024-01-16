#include "../include/Base64Encryption.h"

#include <bitset>
#include <fstream>
#include <iostream>

namespace base64 {
  const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
      "abcdefghijklmnopqrstuvwxyz"
      "0123456789+/";

  std::string Base64Encryption::encode(const std::string &source_path) {
    std::string result;
    std::fstream fin, fout;

    fin.open(source_path, std::fstream::in);
    fout.open("../data/encrypted.txt", std::fstream::out);
    if (!fin.is_open() || !fout.is_open()) {
      std::cerr << "Could not open files." << std::endl;
      return "";
    }

    bool can_continue = true;
    int remaining;
    while (can_continue) {
      char buffer[3];
      fin.read(buffer, sizeof(buffer)); // extracts 3 bytes and stores 'em in the buffer

      remaining = fin.gcount();
      if (remaining == 0) break;
      if (remaining < 3) can_continue = false;
      // in case in fin there are 1 or 2 chars, read from buffer till the 1 or 2 char respectively

      std::bitset<24> bits; // fixed-size sequence of 24 bits
      for (size_t i = 0; i < remaining; ++i) {
        bits |= static_cast<unsigned char>(buffer[i]) << (8 * (2 - i)); // left-shifts by these many positions
      }

      for (size_t i = 0; i < remaining + 1; ++i) {
        result += base64_chars[(bits >> (6 * (3 - i))).to_ulong() & 0x3F];
        // right-shifts + intersects with 00111111 so that only last 6 bits are considered
        fout << base64_chars[(bits >> (6 * (3 - i))).to_ullong() & 0x3F];
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
      for (size_t i = 0; i < 3 - remaining; ++i) {
        fout << '=';
        result += '=';
      }

    fin.close();
    fout.close();
    return result;
  }

  std::string Base64Encryption::decode(const std::string &encrypted_path) {
    return "";
  }
}

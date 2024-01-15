#ifndef BASE64ENCRYPTION_H
#define BASE64ENCRYPTION_H

#include <string>

namespace base64 {
  class Base64Encryption {
  public:
    static std::string encode(const std::string &source_path);

    static std::string decode(const std::string &encrypted_path);
  };
}


#endif //BASE64ENCRYPTION_H

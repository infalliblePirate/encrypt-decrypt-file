#ifndef FILEENCRYPTOR_H
#define FILEENCRYPTOR_H

#include <string>

class FileEncryptor {
public:
  static std::string encrypt(const std::string& source_path);

  static std::string decrypt(const std::string& encrypted_path);
};


#endif //FILEENCRYPTOR_H

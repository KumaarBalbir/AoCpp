#include <iostream>
#include <openssl/evp.h>
#include <iomanip>
#include <sstream>
#include <string>

std::string md5Hash(const std::string &message) {
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digestLength;

    EVP_MD_CTX *context = EVP_MD_CTX_new();  // Create a new digest context
    if (!context) {
        std::cerr << "Failed to create EVP_MD_CTX" << std::endl;
        return "";
    }

    if (EVP_DigestInit_ex(context, EVP_md5(), nullptr) != 1 ||
        EVP_DigestUpdate(context, message.c_str(), message.size()) != 1 ||
        EVP_DigestFinal_ex(context, digest, &digestLength) != 1) {
        std::cerr << "MD5 computation failed" << std::endl;
        EVP_MD_CTX_free(context);
        return "";
    }

    EVP_MD_CTX_free(context);  // Free the context

    // Convert digest to hex string
    std::ostringstream oss;
    for (unsigned int i = 0; i < digestLength; ++i) {
        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(digest[i]);
    }

    return oss.str();
}

int main() {
    std::string message = "yzbqklnj";
    int ans = 0;
    for(int i=1; i< INT_MAX; i++)
      {
	std::string str = std::to_string(i);
	std::string newM = message+str;
    std::string hash = md5Hash(newM);
    std::string subst = hash.substr(0,5);
    if(subst == "00000")
      {
	ans = i;
	break;
      }
      }
    // std::cout << "MD5(\"" << message << "\") = " << hash << std::endl;
    std::cout<<"ans "<<ans<<std::endl;
    return 0;
}

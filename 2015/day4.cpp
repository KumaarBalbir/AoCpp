#include <iostream>
#include <openssl/evp.h>
#include <iomanip>
#include <sstream>
#include <string>

// inefficient - converts binary digest to hex string and then check 6 zeros
// binary digest (16 bytes here) to hex string is O(n) where n is no of bytes
// constant 16 here played a significant role in slowing down the executing.
// Removing this factor, works fine for part II problem.
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

//efficient approach - only check if first 3 bytes of binary digest are zeros or not 
bool check_md5_six_zeros(const std::string &input) {
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    if (!ctx) return false;

    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digest_len;

    bool success = false;
    if (EVP_DigestInit_ex(ctx, EVP_md5(), nullptr) &&
        EVP_DigestUpdate(ctx, input.data(), input.size()) &&
        EVP_DigestFinal_ex(ctx, digest, &digest_len)) {
    success = (digest[0] == 0 && digest[1] == 0 && digest[2] == 0);// 6 hex zero, 24 bits(3 bytes) digest zero
    }

    EVP_MD_CTX_free(ctx);
    return success;
}


int main() {
    std::string message = "yzbqklnj";
    int ans = 0;
    for(int i=1; i< INT_MAX; i++)
      {
	std::string str = std::to_string(i);
	std::string newM = message+str;
	// std::string hash = md5Hash(newM);
	bool isOkay = check_md5_six_zeros(newM);

	//std::string subst = hash.substr(0,6);
	//if(subst == "00000")
	//{
	//ans = i;
	//break;
	// }

	if(isOkay)
	  {
	    ans = i;
	    break;
	  }
      }
    // std::cout << "MD5(\"" << message << "\") = " << hash << std::endl;
    std::cout<<"ans "<<ans<<std::endl;
    return 0;
}

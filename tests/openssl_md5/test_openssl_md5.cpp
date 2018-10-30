#include <openssl/md5.h>
#include <cstring>
#include <iostream>
#include <gtest/gtest.h>

class md5_helper {
public:
    md5_helper() { MD5_Init(&m_ctx); }

    int calc_md5(char *data, int len, unsigned char *output) {
        MD5_Update(&m_ctx, data, len);
        return MD5_Final(output, &m_ctx);
    }

private:
    MD5_CTX m_ctx;
};

TEST(openssl, md5) {
    char str[] = "happy";
    unsigned char s[MD5_DIGEST_LENGTH] = {0};
    char md5[33] = {0};

    md5_helper h;

    h.calc_md5( str, strlen(str), s);

    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(&md5[i * 2], "%02x", (unsigned int)s[i]);
    }
    EXPECT_EQ("56ab24c15b72a457069c5ea42fcfc640", std::string(md5));
}

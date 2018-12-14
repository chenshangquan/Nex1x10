#ifndef HEADER_GMSSL_H
# define HEADER_GMSSL_H

# include <openssl/ssl.h>


#ifdef  __cplusplus
extern "C" {
#endif

# define GMSSL1_VERSION                    0x0101

# define GMSSL1_VERSION_MAJOR              0x01
# define GMSSL1_VERSION_MINOR              0x01


# define GMSSL1_CK_ECDHE_SM1_SM3           0x0300E001
# define GMSSL1_CK_ECC_SM1_SM3             0x0300E003
# define GMSSL1_CK_IBSDH_SM1_SM3           0x0300E005
# define GMSSL1_CK_IBC_SM1_SM3             0x0300E007
# define GMSSL1_CK_RSA_SM1_SM3             0x0300E009
# define GMSSL1_CK_RSA_SM1_SHA1            0x0300E00A

# define GMSSL1_CK_ECDHE_SM4_SM3           0x0300E011
# define GMSSL1_CK_ECC_SM4_SM3             0x0300E013
# define GMSSL1_CK_IBSDH_SM4_SM3           0x0300E015
# define GMSSL1_CK_IBC_SM4_SM3             0x0300E017
# define GMSSL1_CK_RSA_SM4_SM3             0x0300E019
# define GMSSL1_CK_RSA_SM4_SHA1            0x0300E01A


# define GMSSL1_TXT_ECDHE_SM1_SM3          "ECDHE-SM1-SM3"
# define GMSSL1_TXT_ECC_SM1_SM3            "ECC-SM1-SM3"
# define GMSSL1_TXT_IBSDH_SM1_SM3          "IBSDH-SM1-SM3"
# define GMSSL1_TXT_IBC_SM1_SM3            "IBC-SM1-SM3"
# define GMSSL1_TXT_RSA_SM1_SM3            "RSA-SM1-SM3"
# define GMSSL1_TXT_RSA_SM1_SHA1           "RSA-SM1-SHA1"

# define GMSSL1_TXT_ECDHE_SM4_SM3          "ECDHE-SM4-SM3"
# define GMSSL1_TXT_ECC_SM4_SM3            "ECC-SM4-SM3"
# define GMSSL1_TXT_IBSDH_SM4_SM3          "IBSDH-SM4-SM3"
# define GMSSL1_TXT_IBC_SM4_SM3            "IBC-SM4-SM3"
# define GMSSL1_TXT_RSA_SM4_SM3            "RSA-SM4-SM3"
# define GMSSL1_TXT_RSA_SM4_SHA1           "RSA-SM4-SHA1"


__owur const SSL_METHOD *GMSSL1_method(void);
__owur const SSL_METHOD *GMSSL1_server_method(void);
__owur const SSL_METHOD *GMSSL1_client_method(void);

#ifdef  __cplusplus
}
#endif

#endif /** HEADER_GMSSL_H */



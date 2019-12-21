#if defined(WIN32)
#  if defined(_WIN64)
#    include "openssl/win64/opensslconf.h"
#  else
#    include "openssl/win32/opensslconf.h"
#  endif
#elif defined(__linux__) && !defined(__ANDROID__)
/** linux not android */
#  if defined(__i386__)
#    include "openssl/linux/opensslconf.h"
#  elif defined(__x86_64__)
#    include "openssl/linux_x86_64/opensslconf.h"
#  else
#    error "your OS kdssl version is not tested now"
#  endif
#elif defined(__linux__) && defined(__ANDROID__)
#  include "openssl/android/opensslconf.h"
#elif defined(__APPLE__) && defined(__MACH__)
/** Apple OSX and iOS (Darwin). ------------------------------ */
#  if defined (__arm__) || defined(__arm)
#    include "openssl/ios_armv7/opensslconf.h"
#  elif defined (__arm64__) ||  defined(__arm64)
#    include "openssl/ios_arm64/opensslconf.h"
#  elif defined(__x86_64__) || defined(__x86_64)
#    include "openssl/ios_x86_64/opensslconf.h"
#  else
#    error "your OS kdssl version is not tested now"
#  endif
#else
#  error "your OS kdssl version is not tested now"
#endif

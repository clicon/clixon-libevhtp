#
# ***** BEGIN LICENSE BLOCK *****
# 
# Copyright (C) 2021 Olof Hagsand
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Alternatively, the contents of this file may be used under the terms of
# the GNU General Public License Version 3 or later (the "GPL"),
# in which case the provisions of the GPL are applicable instead
# of those above. If you wish to allow use of your version of this file only
# under the terms of the GPL, and not to allow others to
# use your version of this file under the terms of Apache License version 2, 
# indicate your decision by deleting the provisions above and replace them with
# the notice and other provisions required by the GPL. If you do not delete
# the provisions above, a recipient may use your version of this file under
# the terms of any one of the Apache License version 2 or the GPL.
#
# ***** END LICENSE BLOCK *****
#

# To rebuild the `configure' script from this, execute the command
# 	autoconf
# in the directory containing this script.
#

AC_INIT(libevhtp-config.h.in)

# Default CFLAGS and INSTALLFLAGS unless set by environment
: ${CFLAGS="-O2 -Wall"}
: ${INSTALLFLAGS="-s"}
: ${LINKAGE=dynamic}

# where autotool scripts are: install-sh, config.sub, config.guess
AC_CONFIG_AUX_DIR(aux)

LIB_VERSION_MAJOR="5"
LIB_VERSION_MINOR="1"

# Check CLIgen
if test "$prefix" = "NONE"; then
	CLIGEN_PREFIX="$ac_default_prefix"
else
	CLIGEN_PREFIX="$prefix"
fi

AC_CONFIG_HEADERS([libevhtp-config.h])

# AC_SUBST(var) makes @var@ appear in makefiles.
AC_SUBST(LIB_VERSION_MAJOR)
AC_SUBST(LIB_VERSION_MINOR)

AC_MSG_RESULT(LIB version is ${LIB_VERSION_MAJOR}.${LIB_VERSION_MINOR})

AC_CANONICAL_TARGET

AC_SUBST(CC)
AC_SUBST(CFLAGS)
AC_SUBST(LDFLAGS)
AC_SUBST(INCLUDES)
AC_SUBST(CPPFLAGS)
AC_PROG_INSTALL
AC_SUBST(INSTALL)
AC_SUBST(INSTALL_DATA)
AC_SUBST(INSTALL_PROGRAM)
AC_SUBST(INSTALLFLAGS)
AC_SUBST(LIBS)
AC_SUBST(SH_SUFFIX)
AC_SUBST(LINKAGE)
#
AC_PROG_CC()
AC_PROG_CPP

AC_DEFINE_UNQUOTED(TARGET_CPU, $target_cpu, [AUTOCONF target cpu])

CPPFLAGS="-DHAVE_CONFIG_H ${CPPFLAGS}"

AC_MSG_RESULT(compiler is $CC)	
# Debug flag
AC_ARG_ENABLE(debug, AS_HELP_STRING([--enable-debug],[Build with debug symbols, default: no]),[
	  if test "$enableval" = no; then
	      ac_enable_debug=no
	  else	      
	      ac_enable_debug=yes
          fi
        ],
	[ ac_enable_debug=no])

AC_MSG_RESULT(debug is $ac_enable_debug)	
if test "$ac_enable_debug" = "yes"; then
   CFLAGS="-g -Wall -Werror"
   INSTALLFLAGS=""	
fi

AC_MSG_RESULT(CPPFLAGS is $CPPFLAGS)	
AC_MSG_RESULT(CFLAGS is $CFLAGS)
AC_MSG_RESULT(INSTALLFLAGS is $INSTALLFLAGS)	

if test "$prefix" = "NONE"; then
     prefix=${ac_default_prefix}
fi

SH_SUFFIX=".so"


AC_CHECK_LIB(event, event_init,, AC_MSG_ERROR([libevent missing]))
AC_CHECK_LIB(event_openssl, bufferevent_openssl_socket_new,, AC_MSG_ERROR([libevent_openssl missing]))
AC_CHECK_LIB(ssl, OPENSSL_init_ssl ,, AC_MSG_ERROR([libssl missing]))
AC_CHECK_LIB(crypto, AES_encrypt,, AC_MSG_ERROR([libcrypto missing])) 

AC_CHECK_LIB(socket, socket)

#AC_CHECK_FUNCS(inet_aton sigaction sigvec strlcpy strsep strndup)

AH_BOTTOM([#include <libevhtp-custom.h>])

AC_OUTPUT(Makefile
)


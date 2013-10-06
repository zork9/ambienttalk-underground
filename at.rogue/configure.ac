#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([at_rogue], [0.1], [roguedemon6@gmail.com])
AC_CONFIG_SRCDIR([src/routines.h])
AM_INIT_AUTOMAKE

AC_CONFIG_HEADERS([config.h])
# Checks for programs.
AC_PROG_CC
# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h])
AC_CHECK_HEADERS([pondyparser/parser.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
##AC_INCLUDES_DEFAULT([-I/usr/include,
AC_CHECK_FILE(/usr/lib/libpondyparser.so, [], [
	AC_CHECK_FILE(/usr/local/lib/libpondyparser.so, [], [
        echo "Could not find libpondyparser. "
	echo "*************************************************"
	echo "Download libpondyparser at :   "
	echo "https://sourceforge.net/projects/libpondyparser/ "
	echo "You need a version >= 0.6.0                      " 
	echo "(put it in /usr/lib/)                            "
	echo "*************************************************"
        exit -1
        ])])

#AC_CHECK_LIB(pondyparser, , [], [
#        echo "Could not find libpondyparser. "
#	echo "*************************************************"
#	echo "Download libpondyparser at :   "
#	echo "https://sourceforge.net/projects/libpondyparser/ "
#	echo "You need a version >= 0.6.0                                 "
#	echo "*************************************************"
#        exit -1
#        ])

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT

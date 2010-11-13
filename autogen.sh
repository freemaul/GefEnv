#! /bin/sh
#generation des fichier de configuration et de compilation
echo "AUTOGEN :"
aclocal || { exit 1; }
libtoolize || { exit 1; }
autoconf || { exit 1; }
autoheader || { exit 1; }
automake --add-missing || { exit 1; }
echo "AUTOGEN - COMPLETED"


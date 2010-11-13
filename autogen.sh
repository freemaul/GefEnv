#! /bin/sh
#generation des fichier de configuration et de compilation
aclocal
libtoolize
autoconf
autoheader
automake --add-missing


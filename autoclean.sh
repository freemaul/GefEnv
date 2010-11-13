#! /bin/bash
# supression des fichiers générés par autogen

files_to_rm=
dir_to_rm=

if [ "$1" = "-v" ]
then
	display=1
else
	display=0
	echo "autoclean.sh -v pour mode verbose"
fi

files_to_rm+="	aclocal.m4"
dir_to_rm+="	autom4te.cache"
files_to_rm+="	config.guess"
files_to_rm+="	config.h.in"
files_to_rm+="	config.h.in~"
files_to_rm+="	config.sub"
files_to_rm+="	configure"
files_to_rm+="	install-sh"
files_to_rm+="	ltmain.sh"
dir_to_rm+="	m4"
files_to_rm+="	missing"
files_to_rm+="	COPYING"
files_to_rm+="	INSTALL"
files_to_rm+="	Makefile"
files_to_rm+="	Makefile.in"
files_to_rm+="	config.h"
files_to_rm+="	config.log"
files_to_rm+="	config.status"
files_to_rm+="	libtool"
files_to_rm+="	stamp-h1"
files_to_rm+="	depcomp"

#info
dir_to_rm+="		srcdir/info/.deps/"
files_to_rm+="		srcdir/info/GEF-info"
files_to_rm+="		srcdir/info/Makefile"
files_to_rm+="		srcdir/info/Makefile.in"
files_to_rm+="		srcdir/info/*.o"

#make-project
files_to_rm+="	srcdir/make-project/Makefile"
files_to_rm+="	srcdir/make-project/Makefile.in"
dir_to_rm+="	srcdir/make-project/.deps"
files_to_rm+="	srcdir/make-project/*.o"
files_to_rm+="	srcdir/make-project/GEF-make-project"


echo "AUTOCLEAN :"

for f in $files_to_rm
do
	if [ "$display" = 1 ]
	then
		echo "rm -f $f"
	fi
	rm -f "$f"
done

for d in $dir_to_rm
do
	if [ "$display" = 1 ]
	then
		echo "rm $d -dir -f"
	fi
	rm "$d" -dir -f
done

echo "AUTOCLEAN - COMPLETED"


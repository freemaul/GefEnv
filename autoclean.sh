#! /bin/bash
# supression des fichiers générés par autogen

files_to_rm=
dir_to_rm=


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


for f in $files_to_rm
do
	echo "rm -f $f"
	rm -f "$f"
done

for d in $dir_to_rm
do
	echo "rm $d -dir -f"
	rm "$d" -dir -f
done


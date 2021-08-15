#! /bin/bash

usage() {
  cat << EOF >&2
Usage: $0 [-v] filename
EOF
  exit 1
}

verbose=false;
file=$1;

while getopts v:verbose o; do
  case $o in
    (v) verbose=true ; file=$2 ;;
    (*) usage
   esac
done

if [[ "$file" = *.c ]]
then
  echo "Wrong argument format, should be 'filename' not 'filename.c'.";
  usage;
fi

if [[ "$file" = *-  ]]
then
  echo "Wrong argument format.";
  usage;
fi

if [[ ! -f "$file.c" ]]
then
  echo "File $file.c not found.";
  usage;
fi

if [ $verbose = true ] 
then
  echo "> cat $file.c"
  cat $file.c
fi

echo "> gcc-11 -fopenmp $file.c -o $file";
gcc-11 -fopenmp $file.c -o $file
echo "> ./$file"; 
./$file;

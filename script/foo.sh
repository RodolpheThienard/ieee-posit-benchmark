#!/bin/bash

RED='\033[0;91m\033[1m'
GREEN='\033[0;92m\033[1m'
LEXIC='\033[0;95m\033[1m'
GRAY='\033[0;90m\033[1m'
NC='\033[0m' # No Color


print_info() {
echo -e "${LEXIC}INFO :${NC}"
echo -e "  ${LEXIC}SYNTAX${NC} : Comparaison de la syntaxe générée avec celui du lab1"
echo -e "  ${LEXIC}COMPIL${NC} : Vérification de la compilation en asm"
echo -e "     ${LEXIC}RUN${NC} : Exécution et vérification du code de sortie (42)"
echo -e "   ${RED}ERROR${NC} : Le test échoue"
echo -e "      ${GREEN}OK${NC} : Le test réussi"
echo -e "  ${GRAY}ESCAPE${NC} : Le test n'est pas effectué \n"
printf "%17s\t%6s\t%6s\t%6s\n" "TEST FILE NAME" "SYNTAX" "COMPIL" "RUN"
printf '_%.0s' {1..50}
printf '\n'
}

check_binaries(){
  if [ ! -d "omp_bin" ]
  then
  echo -e "Compilation x86 tests"
  cmake -DENABLE_OMP_COMPILE=ON ..
  make
  echo -e "Compilation ${GREEN}Successfull${NC}\n"
  fi
}

name(){
    name_file=$(echo "$name" | cut -f 2 -d "/")
    # printable_name=$(echo "${name_file}" |cut -c -10)
    printf "%25s\t" $name_file
    # echo -e -n "$printable_name \t"
}

ok(){
    echo -e -n "${GREEN}OK${NC}\t"
}
error(){
    echo -e -n "${RED}ERROR${NC}\t"
}
escaper(){
    echo -e -n "${GRAY}ESCAPE${NC}\t"
}


check_binaries
for file in omp_bin/*
do
        if [ -f $file ]
        then
        name=${file%.*}
        name
          ./$file 100 1 > /tmp/err
          if [ $? == 0 ]
          then
            ok
          else
            error
            printf "\n ${RED}ERROR ACCURACY :\n ${NC}" 
            cat /tmp/err
          fi
        else
          echo -e "${RED}INVALID"
        fi
        echo -e ""
    let file_amount++
done



#!/bin/bash
RESET="\033[0m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"

BOLDBLACK="\033[1m\033[30m"
BOLDRED="\033[1m\033[31m"
BOLDGREEN="\033[1m\033[32m"
BOLDYELLOW="\033[1m\033[33m"
BOLDBLUE="\033[1m\033[34m"
BOLDMAGENTA="\033[1m\033[35m"
BOLDCYAN="\033[1m\033[36m"
BOLDWHITE="\033[1m\033[37m"

function init()
{
	printf $GREEN" 
  _  _ ___                    _        _                   _            _            
 | || |__ \                  | |      (_)                 | |          | |           
 | || |_ ) |   ___ ___  _ __ | |_ __ _ _ _ __   ___ _ __  | |_ ___  ___| |_ ___ _ __ 
 |__   _/ /   / __/ _ \| '_ \| __/ _  | | '_ \ / _ \ '__| | __/ _ \/ __| __/ _ \ '__|
    | |/ /_  | (_| (_) | | | | || (_| | | | | |  __/ |    | ||  __/\__ \ ||  __/ |   
    |_|____|  \___\___/|_| |_|\__\__,_|_|_| |_|\___|_|     \__\___||___/\__\___|_|   
                                                                                     
                                                                                    $RESET\n"
	header_copy
	printf $BOLDYELLOW"Compiling init program...$RESET\n"
	clang++ -Wall -Werror -Wextra init.cpp -o init
	if [[ ! -e init ]]
	then
		printf $BOLDRED"Compilation of init program failed !$RESET\n"
		exit 0
	fi
	printf $BOLDGREEN"Compilation of init program was successfull !$RESET\n"
	printf $BOLDYELLOW"Launching init program...$RESET\n"
	./init
	rm header.txt
	rm init
	printf $BOLDYELLOW"Init program execution status: $BOLDGREEN DONE$RESET\n\n"
}

function header_copy()
{
	rm -rf ft_container std_container copied_hpp_file
	mkdir copied_hpp_file
	printf $BOLDYELLOW"Copy hpp file...$RESET\n"
	cp ../include/*.hpp copied_hpp_file  >/dev/null 2>&1
	ls copied_hpp_file/*.hpp > header.txt
	HEADER=$(<header.txt)
	printf $BOLDYELLOW"Found file:$RESET\n"
	printf $YELLOW"${HEADER}$RESET\n\n"
}

function compil()
{
	printf $BOLDYELLOW"Starting compilation of $1...$RESET\n"
	#make re >/dev/null 2>&1
	clang++ $1 -Wall -Werror -Wextra -D ACCESS=ft -o ft_container
	clang++ $1 -Wall -Werror -Wextra -D ACCESS=std -o std_container
	chmod 755 ft_container >/dev/null 2>&1
	chmod 755 std_container >/dev/null 2>&1
	if [[ ! -e ft_container ]] || [[ ! -e std_container ]]
	then
		printf $BOLDRED"Compilation failed ! Dont forget you have to clone this folder in the root of your project$RESET\n"
		exit 0
	fi
	printf $BOLDYELLOW"Compilation was succesfull !$RESET\n"
	sleep 1
}

function exec()
{
	compil $1
	printf $BOLDBLUE"Starting execution of $1...$RESET\n"
	./ft_container > ft.txt ; ./std_container > std.txt
	diff ft.txt std.txt > diff.txt

if [[ -s diff.txt ]]
then
	printf $BOLDBLUE"Diff: $BOLDRED"
	cat diff.txt
	rm ft.txt std.txt diff.txt
else
    printf $BOLDGREEN"ALL GOOD"
	rm ft.txt std.txt diff.txt
fi
	printf "$RESET\n\n"
}

if [[ $# -ne 0 ]] 
then
    printf $BOLDRED"Wrong number of elements !\nUsage = \"bash container_test.sh\" for all test \n$RESET"
    exit 0
fi
init
exec "main_file/intra_test.cpp"
exec "main_file/big_vector.cpp"
exec "main_file/oob_vector.cpp"

printf $BOLDGREEN"ALL TEST DONE!$RESET\n\n"
rm -rf ft_container std_container copied_hpp_file
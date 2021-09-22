#! /bin/zsh
read -p 'input a number:' n
a=$[$n%2]
case $a in 
1) 
	echo 'odd';;
0)
	echo 'even';;
*)
	echo 'not a number';;
esac


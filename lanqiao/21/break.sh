#! /bin/zsh
for file in `ls`;do
  echo $file
  if [ "$file" == "test1.cpp" ];then
     echo "$file"
  else
     echo ok
     break
  fi
done

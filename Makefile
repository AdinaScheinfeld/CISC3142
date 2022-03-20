# target to build file_in.cpp
lab1:
# g++ lab1_files/file_in.cpp -o lab1_files/main && lab1_files/main
	g++ lab1_files/main.cpp lab1_files/functions.cpp -o lab1_files/main && lab1_files/main

lab2:
	g++ -std=c++14 lab2_files/main.cpp lab2_files/functions.cpp -o lab2_files/main && lab2_files/main
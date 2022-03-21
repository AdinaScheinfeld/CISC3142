# target to build and run lab 1
lab1:
	g++ lab1_files/main.cpp lab1_files/functions.cpp -o lab1_files/main && lab1_files/main

# target to build and run lab 2
lab2:
	g++ -std=c++14 lab2_files/main.cpp lab2_files/functions.cpp -o lab2_files/main && lab2_files/main
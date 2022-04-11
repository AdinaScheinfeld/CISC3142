# target to build and run lab 1
lab1:
	g++ lab1_files/main.cpp lab1_files/functions.cpp -o lab1_files/main && lab1_files/main

# target to build and run lab 2
lab2:
	g++ -std=c++14 lab2_files/main.cpp lab2_files/functions.cpp -o lab2_files/main && lab2_files/main

# target to build and run lab 3
lab3:
#g++ -std=c++14 lab3_files/src/main.cpp lab3_files/src/readAndWrite.cpp lab3_files/src/aggFunctions.cpp -o lab3_files/src/main && ./lab3_files/src/main
	g++ -std=c++14 lab3_files/src/main.cpp lab3_files/src/readAndWrite.cpp lab3_files/src/aggFunctions.cpp -o lab3_files/src/main && ./lab3_files/src/main lab3_files/data/allFiles/1115.csv lab3_files/data/allFiles/3115.csv lab3_files/data/allFiles/3130.csv
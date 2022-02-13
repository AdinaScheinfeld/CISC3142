## Lab 1

### Problem Description

Given sample code that compiles but contains logical errors rendering it useless.  
Task:
- Successfully read in all lines of the input file (a CSV file including rows of data with metrics such as sku, brand, category, year, and price).
- Write the data to an output file.
- Calculate the average price per brand and the average price per category and write the results to the output file. 
- Write the SKUs for each year and a count of the number of SKUs for each year to the output file. 

### Tech Used

All code compiles in C++98 standard.

### Problem Solving Techniques

- All data is read in using ```ifstream``` and parsed using ```stringstream```. Each SKU is pushed onto the vector ```vSKU```, each brand is pushed onto the vector ```vBrand```, each category is pushed onto the vector ```vCategory```, each year is pushed onto the vector ```vYear```, and each price is pushed onto the vector ```vPrice```. 
- Data is printed to the output file using ```ofstream```.
- The function ```pricePerBrand()``` calculates the price for each brand. Each brand is stored in a map, and the sum and count of the prices for each brand are used to calculate the average for each brand and add it to the map. Each brand and its average price is then printed to the output file. 
- The function ```pricePerCategory``` calculates the price for each category. Each category is stored in a map, and the sum and count of the prices for each category are used to calculate the average for each category and add it to the map. Each category and its average price is then printed to the output file. 
- The function ```skusPerYear``` counts the number of SKUs for each year. Each year is stored in a map with a list of its associated SKUs. The length of the list of SKUs associated with each year is calculated and the SKUs and count of SKUs for each year are printed to the output file. 

### Articulation of the Solution

- A map was the chosen data structure for the ```pricePerBrand()``` feature and the ```pricePerCategory()``` feature since a map enables each unique brand/category to be a unique key associated with that brand's/category's average price. 
- A map was the chosen data structure for the ```skusPerYear``` feature since a map enables each unique year to be a unique key associated with a list of the SKUs associated with that year allowing for quick calculation of the number of SKUs associated with each year. 

### How to use?

- Input: A CSV file with rows of data corresponding to metrics including sku, brand, category, year, and price.
- Output: A text file containing the data from the input file, a list of brands with each brand's associated average price, a list of categories with each brand's associated average price, and a list of years with each year's associated SKUs and a count of the SKUs associated with each year. 
- All code runs from the project root under the default ```main``` branch with the command ```make lab1```.

### Testing

Code was tested on 5 input files.
1. [data.csv](data.csv) - The original input file; produces [output.txt](output.txt).
2. [data1.csv](data1.csv) - An input file containing random skus, brands, categories, years, and prices; produces [output1.txt](output1.txt).
3. [data2.csv](data2.csv) - An input file containing random skus, brands, categories, years, and prices, where all the brands are the same; produces [output2.txt](output2.txt).
4. [data3.csv](data3.csv) - An input file containing random skus, brands, categories, years, and prices, where all the categories are the same; produces [output3.txt](output3.txt). 
5. [data4.csv](data4.csv) - An input file containing random skus, brands, categories, years, and prices, where all the years are the same; produces [output4.txt](output4.txt).
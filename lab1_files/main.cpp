// Adina Scheinfeld
// CISC 3142

/*
  This code reads in data from a CSV file, data.csv, and outputs the data to an output file, output.txt.
  The data file contains rows of data with metrics including sku, brand, category, year, and price.
  The code also calculates and prints to the output file the average price per brand and the average price per category.
  Additionally, the code prints all the skus for each year and the count of the skus for each year to the output file. 
  The code in this file compiles in C++98 using the command make lab1.
*/

// include required libraries
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <map>
#include <iterator>
#include <typeinfo>
#include <algorithm>
#include "header_file.h"
//#include "functions.cpp"

// define namespace
using namespace std;

// main function
int main()
{
  // declare variables
  string sku, brand, category, year, price;
  vector<int> vSKU;
  vector<string> vBrand;
  vector<string> vCategory;
  vector<int> vYear;
  vector<float> vPrice;

  int iSKU;
  string sBrand;
  string sCategory;
  int iYear;
  float fPrice;

  // open the input file 
  ifstream in_stream;
  in_stream.open("lab1_files/data.csv");

  // open the output file
  FILE *fptr = fopen("lab1_files/output.txt", "w");

  // if the file is open
  if (!in_stream.fail())
  {
    // declare variable to contain the current line
    string line;

    // ignore the header line when reading in the data
    getline(in_stream, line);

    // while the end of the file has not been reached
    while (getline(in_stream, line))
    {
      // replace commas with spaces
      replace(line.begin(), line.end(), ',', ' ');

      // parse the data
      stringstream ss(line);
      ss >> iSKU;
      ss >> sBrand;
      ss >> sCategory;
      ss >> iYear;
      ss >> fPrice;

      // add the data to vectors
      vSKU.push_back(iSKU);
      vBrand.push_back(sBrand);
      vCategory.push_back(sCategory);
      vYear.push_back(iYear);
      vPrice.push_back(fPrice);
    }

    // close the file
    in_stream.close();
  }

  // if the file cannot be opened, print an error message to the console
  else
  {
    // out_stream << "Unable to open file";
    fprintf(fptr, "%s", "Unable to open file.");
  }

  // write the header values to the output file
  fprintf(fptr, "%s\t%s\t%s\t\t%s\t%s\n", "SKU", "Brand", "Category", "Year", "Price");


  // write the data values to the output file
  for (int j=0; j<vSKU.size(); j++)
  {
    fprintf(fptr, "%i\t%s\t\t\t%s\t\t\t%i\t%4.2f\n", 
    vSKU[j], vBrand[j].c_str(), vCategory[j].c_str(), vYear[j], vPrice[j]);
  }

  // print a blank line
  fprintf(fptr, "\n");

  // call pricePerBrand function
  pricePerBrand(vBrand, vPrice, fptr);


  // call pricePerCategory function
  pricePerCategory(vCategory, vPrice, fptr);


  // call skusPerYear function
  skusPerYear(vYear, vSKU, fptr);

  // close the output file
  fclose(fptr);

  // indicate successful completion
  return (0);
}
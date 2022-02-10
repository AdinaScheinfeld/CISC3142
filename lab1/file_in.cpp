// Adina Scheinfeld
// CISC 3142

// This file shows basic functions of reading in a CSV file using C++98
// Please add your name to your code!

/* Homework Objective: fix this program to match the requirements listed:
  1. successfully reads all lines of the input file
  2. calculate the average price per brand, average price per category
  3. writes to an output file
  4. for each unique year, list the count of skus and also print out the skus as a list i.e. 2000 (3): 111, 211, 311 and make a new line per year.

All programs must be able to compile in C++98 standard (the default version on Linux Machine). That means you cannot use the new features of C++11! :(

*/

// include required libraries
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

// define namespace
using namespace std;

int main()
{
  // define vector variables
  string sku, brand, category, year, price;
  vector<int> vSKU;
  vector<string> vBrand;
  vector<string> vCategory;
  vector<int> vYear;
  vector<float> vPrice;

  // open the file
  ifstream in_stream;
  in_stream.open("data.csv");

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
      // declare variables to hold the data in each column
      int iSKU;
      string sBrand;
      string sCategory;
      int iYear;
      float fPrice;

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
    // close the file cout << "Number of entries: " << i-1 << endl;
    in_stream.close();
  }

  else
  {
    cout << "Unable to open file";
  }

  // output header values to the console
  cout << "SKU"
       << "\t"
       << "Brand"
       << "\t"
       << "Category"
       << "\t"
       << "Year"
       << "\t"
       << "Price" << endl;

  // output data values to the console
  for (int j = 0; j < vSKU.size(); j++)
  {
    cout << vSKU[j] << "\t" << vBrand[j] << "\t   " << vCategory[j] << "\t\t" << vYear[j] << "\t" << vPrice[j] << endl;
  }

  cout << endl;
}

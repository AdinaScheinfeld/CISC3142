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
#include <map>
#include <iterator>

// define namespace
using namespace std;

// declare pricePerBrand function
void pricePerBrand(vector<string> brands, vector<float> prices);

// declare pricePerCategory function
void pricePerCategory(vector<string> categories, vector<float> prices);

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

  // print a blank line
  cout << '\n';

  // call pricePerBrand function
  pricePerBrand(vBrand, vPrice);

  // call pricePerCategory function
  pricePerCategory(vCategory, vPrice);

  cout << endl;
}

// function to calculate price per brand
void pricePerBrand(vector<string> brands, vector<float> prices)
{
  // declare map to hold the average per brand
  map<string, float> averages;

  // add each brand to the map
  for (int i = 0; i < brands.size(); i++)
  {
    averages.insert(pair<string, float>(brands[i], 0));
  }

  // iterate through the map
  map<string, float>::iterator itr;
  for (itr = averages.begin(); itr != averages.end(); ++itr)
  {
    string b = itr->first;
    float sum = 0;
    int count = 0;

    // calculate the sum and count for each brand
    for (int j = 0; j < brands.size(); j++)
    {
      if (brands[j] == b)
      {
        sum += prices[j];
        count++;
      }
    }

    // add the average for each brand to the map
    map<string, float>::iterator it = averages.find(b);
    if (it != averages.end())
      it->second = sum / count;
  }

  // print the average for each brand to the console
  cout << "\tBrand\tAverage\n";
  for (itr = averages.begin(); itr != averages.end(); ++itr)
  {
    cout << '\t' << itr->first << '\t' << itr->second << '\n';
  }
  cout << endl;
}

// function to calculate price per category
void pricePerCategory(vector<string> categories, vector<float> prices)
{
  // declare map to hold the average per category
  map<string, float> averages;

  // add each category to the map
  for (int i = 0; i < categories.size(); i++)
  {
    averages.insert(pair<string, float>(categories[i], 0));
  }

  // iterate through the map
  map<string, float>::iterator itr;
  for (itr = averages.begin(); itr != averages.end(); ++itr)
  {
    string b = itr->first;
    float sum = 0;
    int count = 0;

    // calculate the sum and count for each category
    for (int j = 0; j < categories.size(); j++)
    {
      if (categories[j] == b)
      {
        sum += prices[j];
        count++;
      }
    }

    // add the average for each category to the map
    map<string, float>::iterator it = averages.find(b);
    if (it != averages.end())
      it->second = sum / count;
  }

  // print the average for each category to the console
  cout << "\tCategory\tAverage\n";
  for (itr = averages.begin(); itr != averages.end(); ++itr)
  {
    cout << '\t' << itr->first << '\t' << '\t' << itr->second << '\n';
  }
  cout << endl;
}

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
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <map>
#include <iterator>

// define namespace
using namespace std;

// declare pricePerBrand function
void pricePerBrand(vector<string> brands, vector<float> prices, ofstream& out_stream);

// declare pricePerCategory function
void pricePerCategory(vector<string> categories, vector<float> prices, ofstream& out_stream);

// declare skusPerYear function
void skusPerYear(vector<int> years, vector<int> skus, ofstream& out_stream);

int main()
{
  // define vector variables
  string sku, brand, category, year, price;
  vector<int> vSKU;
  vector<string> vBrand;
  vector<string> vCategory;
  vector<int> vYear;
  vector<float> vPrice;

  // open the input file file
  ifstream in_stream;
  in_stream.open("data.csv");

  // open the output file
  ofstream out_stream;
  out_stream.open("output.txt");

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

    // close the file
    in_stream.close();
  }

  else
  {
    out_stream << "Unable to open file";
  }

  // write the header values to the output file
  out_stream << "SKU"
       << "\t"
       << "Brand"
       << "\t"
       << "Category"
       << "\t\t"
       << "Year"
       << "\t"
       << "Price" << endl;

  // write the data values to the output file
  for (int j = 0; j < vSKU.size(); j++)
  {
    out_stream << vSKU[j] << "\t" << vBrand[j] << "\t   " << vCategory[j] << "\t\t" << vYear[j] << "\t" << vPrice[j] << endl;
  }

  // print a blank line
  out_stream << '\n';

  // call pricePerBrand function
  pricePerBrand(vBrand, vPrice, out_stream);

  // call pricePerCategory function
  pricePerCategory(vCategory, vPrice, out_stream);

  // call skusPerYear function
  skusPerYear(vYear, vSKU, out_stream);

  out_stream << endl;

  out_stream.close();
}

// function to calculate price per brand
void pricePerBrand(vector<string> brands, vector<float> prices, ofstream& out_stream)
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

  // write the average for each brand to the output file
 out_stream << "\tBrand\tAverage\n";
  for (itr = averages.begin(); itr != averages.end(); ++itr)
  {
   out_stream << '\t' << itr->first << '\t' << itr->second << '\n';
  }
  out_stream << endl;
}

// function to calculate price per category
void pricePerCategory(vector<string> categories, vector<float> prices, ofstream& out_stream)
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

  // write the average for each category to the output file
  out_stream << "\tCategory\t\tAverage\n";
  for (itr = averages.begin(); itr != averages.end(); ++itr)
  {
    out_stream << '\t' << itr->first << '\t' << '\t' << itr->second << '\n';
  }
  out_stream << endl;
}

// function to count SKUs per year
void skusPerYear(vector<int> years, vector<int> skus, ofstream& out_stream)
{
  // declare map to hold the years and skus
  map<int, vector<int> > skuMap;

  // add each year to the map
  for (int i = 0; i < years.size(); i++)
  {
    skuMap.insert(pair<int, vector<int> >(years[i], vector<int>()));
  }

  // iterate through the map
  map<int, vector<int> >::iterator itr;
  for (itr = skuMap.begin(); itr != skuMap.end(); ++itr)
  {
    // set y to be the year currently being iterated over
    int y = itr->first;

    // calculate the count for each year and add the skus to the vector in the map
    for (int j = 0; j < years.size(); j++)
    {
      if (years[j] == y)
      {
        itr->second.push_back(skus[j]);
      }
    }
  }

  // write the years, the skus, and the count for each year to the output file
  out_stream << "\tYear\tSkus\n";
  for (itr = skuMap.begin(); itr != skuMap.end(); ++itr)
  {
    int count = 0;

    // write each year to the output file
    out_stream << '\t' << itr->first << '\t';

    // write the skus for each year to the output file
    for (int i = 0; i < itr->second.size(); i++)
    {
      out_stream << itr->second.at(i) << ' ';
      count++;
    }
    // write the count to the output file
    out_stream << ' ' << "(Count: " << count << ")\n";
  }
  out_stream << endl;
}

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
#include "header_file.h"

// define namespace
using namespace std;

// main function
int main()
{
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


// function to calculate price per brand
void pricePerBrand(vector<string> brands, vector<float> prices, FILE *fptr)
{
  // declare map to hold the average price per brand
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
  fprintf(fptr, "%s\t%s\n", "Brand", "Average");
  for (itr = averages.begin(); itr != averages.end(); ++itr)
  {
   fprintf(fptr, "%s\t\t%4.2f\n", itr->first.c_str(), itr->second);
  }

  // print a new line
  fprintf(fptr, "\n");
}


// function to calculate average price per category
void pricePerCategory(vector<string> categories, vector<float> prices, FILE *fptr)
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
  fprintf(fptr, "%s\t%s\n", "Category", "Average");
  for (itr = averages.begin(); itr != averages.end(); ++itr)
  {
    fprintf(fptr, "%s\t\t\t%4.2f\n", itr->first.c_str(), itr->second);
  }

  // print a new line
    fprintf(fptr, "\n");
}


// function to count SKUs per year
void skusPerYear(vector<int> years, vector<int> skus, FILE *fptr)
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
  fprintf(fptr, "Year\tSkus\n");
  for (itr = skuMap.begin(); itr != skuMap.end(); ++itr)
  {
    int count = 0;

    // write each year to the output file
    fprintf(fptr, "%i\t", itr->first);

    // write the skus for each year to the output file
    for (int i = 0; i < itr->second.size(); i++)
    {
      // add padding zeros so skus are all 3 digits long
      fprintf(fptr, "%03i ", itr->second.at(i));
      count++;
    }

    // write the count to the output file
    fprintf(fptr, "(Count: %i)", count);

    // print a new line
    fprintf(fptr, "\n");
  }
}

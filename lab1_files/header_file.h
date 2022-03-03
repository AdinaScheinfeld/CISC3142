#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <map>
#include <iterator>

using namespace std;


// // declare variables
// string sku, brand, category, year, price;
// vector<int> vSKU;
// vector<string> vBrand;
// vector<string> vCategory;
// vector<int> vYear;
// vector<float> vPrice;

// int iSKU;
// string sBrand;
// string sCategory;
// int iYear;
// float fPrice;


// declare pricePerBrand function
void pricePerBrand(vector<string> brands, vector<float> prices, FILE *fptr);

// declare pricePerCategory function
void pricePerCategory(vector<string> categories, vector<float> prices, FILE *fptr);

// declare skusPerYear function
void skusPerYear(vector<int> years, vector<int> skus, FILE *fptr);


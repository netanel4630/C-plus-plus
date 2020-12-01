#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <conio.h>

using std::cout;
using std::setfill;
using std::setw;
using std::endl;
using std::left;
using std::right;

const int title_width{ 20 };
const int country_width{ 20 };
const int city_width{ 20 };
const int population_width{ 15 };
const int price_width{ 15 };

struct City {
	std::string name;
	long population;
	double cost;
};

// Assume each country has at least 1 city
struct Country {
	std::string name;
	std::vector<City> cities;
};

struct Tours {
	std::string title;
	std::vector<Country> countries;
};


void create_tours(Tours &tours) {
	tours =
	{ "Tour Ticket Prices from Miami",
		{
			{
				"Colombia", {
					{ "Bogota", 8778000, 400.98 },
					{ "Cali", 2401000, 424.12 },
					{ "Medellin", 2464000, 350.98 },
					{ "Cartagena", 972000, 345.34 }
				},
			},
			{
				"Brazil", {
					{ "Rio De Janiero", 13500000, 567.45 },
					{ "Sao Paulo", 11310000, 975.45 },
					{ "Salvador", 18234000, 855.99 }
				},
			},
			{
				"Chile", {
					{ "Valdivia", 260000, 569.12 },
					{ "Santiago", 7040000, 520.00 }
			},
		},
			{ "Argentina", {
				{ "Buenos Aires", 3010000, 723.77 }
			}
		},
	}
	};
}



void print_titles(const Tours &tours) {
	int ruler{ 10 };
	int ruler_length{ 7 };
	int i, j;
    

	for (i = 0; i < ruler_length; i++) {
		for (j = 1; j < ruler; j++) {
			cout << j;
		}
		std::cout  << 0 ;
	}
	cout << endl << endl;

	cout << setw(title_width) << "" << tours.title << endl << endl;

	cout << setw(country_width) << left << "Country" << setw(city_width) << left << "City"
		 << setw(population_width)  << right << "Population" << setw(price_width) << right << "Price" << endl;

	std::cout << std::setfill('-') << std::setw(ruler * ruler_length) << "" << endl;
	std::cout << std::setfill(' '); // reset setfill to blank spaces
	

}

void print_tours(const Tours &tours) {
	for (auto country : tours.countries) {   // loop through the countries
		cout << setw(country_width) << left << country.name;
		for (int i = 0; i < country.cities.size() ; i++) {       // loop through the cities for each country
			cout << setw(i == 0 ? 0 : country_width) << "";
			cout << setw(city_width) << left << country.cities.at(i).name
				<< setw(population_width) << right << country.cities.at(i).population
				<< setw(price_width) << right << country.cities.at(i).cost
				<< std::endl;
		}
	}
}

int main()
{
	Tours tours;
	create_tours(tours);
	print_titles(tours);
	print_tours(tours);

	_getch();
	return 0;
}
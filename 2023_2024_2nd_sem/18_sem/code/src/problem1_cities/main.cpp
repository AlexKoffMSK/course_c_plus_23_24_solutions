#include <iostream>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>

//     Main task - to implement the function fillCountries to put countries into a container]
// (vector<Country> or map<std::string, Country>).

//     Intermediate steps:
//     1. Define operator< for both Cities and Countries based on their names.
//     2. Read cities as pairs <City, name of the country>.
//     3. Use the name of the country to find if there is such country in the container.
//     4. Add a country to the container or a city to an existing country.
#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm> // For std::sort

struct Coordinate {
    double latitude;
    double longitude;
};

struct City {
    std::string name;
    int population;
    Coordinate coordinates;

    bool operator<(const City& other) const {
        return population > other.population; 
    }
};

struct Country {
    std::string name;
    std::set<City> cities;

    bool operator<(const Country& other) const {
        return name < other.name;
    }
};

std::ostream& operator<<(std::ostream& os, const Coordinate& coord) {
    os << "(" << coord.latitude << ", " << coord.longitude << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const City& city) {
    os << "(city = " << city.name << ", population = " << city.population
       << ", coordinates = " << city.coordinates << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Country& country) {
    os << "Country: " << country.name << "\nCities:\n";
    for (const auto& city : country.cities) {
        os << "  - " << city << "\n";
    }
    return os;
}

void fillCountries(std::istream& inFile, std::vector<Country>& countries) {
    std::string line;
    while (getline(inFile, line)) {
        std::istringstream iss(line);
        std::string countryName, cityName;
        int population;
        double lat, lon;

        getline(iss, cityName, ',');
        getline(iss, countryName, ',');
        iss >> population >> lat >> lon;

        Coordinate coords{lat, lon};
        City newCity{cityName, population, coords};

        auto it = std::find_if(countries.begin(), countries.end(), [&countryName](const Country& c) { return c.name == countryName; });

        if (it != countries.end()) {
            it->cities.insert(newCity);
        } else {
            Country newCountry{countryName, {newCity}};
            countries.push_back(newCountry);
        }
    }
}

int main() {
    const std::string FILENAME = "../../../data/problem1_cities/cities.csv";
    std::ifstream inputFile(FILENAME);
    if (!inputFile) {
        std::cerr << "Could not open the file: " << FILENAME << std::endl;
        return 1;
    }

    std::vector<Country> countries;
    fillCountries(inputFile, countries);

    for (const auto& country : countries) {
        std::cout << country << std::endl;
    }

    return 0;
}

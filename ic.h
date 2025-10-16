#pragma once
#include <string>
#include <map>
#include <chrono>
#include <string.h>

enum class Sex {
    Male,
    Female
};

struct StateInfo {
    std::string name;
    std::string region;
};

struct date {
    int year;
    int month;
    int day;
};

const std::string toString(Sex sex);

const std::map<int, StateInfo> stateCodeMap = {
    // Malaysian states (including alternate and extended codes)
    // 00 is unused/undefined
    // 01–16: main states
    {1,  {"Johor", "Malaysia"}},
    {2,  {"Kedah", "Malaysia"}},
    {3,  {"Kelantan", "Malaysia"}},
    {4,  {"Malacca", "Malaysia"}},
    {5,  {"Negeri Sembilan", "Malaysia"}},
    {6,  {"Pahang", "Malaysia"}},
    {7,  {"Penang", "Malaysia"}},
    {8,  {"Perak", "Malaysia"}},
    {9,  {"Perlis", "Malaysia"}},
    {10, {"Selangor", "Malaysia"}},
    {11, {"Terengganu", "Malaysia"}},
    {12, {"Sabah", "Malaysia"}},
    {13, {"Sarawak", "Malaysia"}},
    {14, {"Federal Territory of Kuala Lumpur", "Malaysia"}},
    {15, {"Federal Territory of Labuan", "Malaysia"}},
    {16, {"Federal Territory of Putrajaya", "Malaysia"}},

    // 17–20: unused/undefined

    // 21–24: Johor
    {21, {"Johor", "Malaysia"}},
    {22, {"Johor", "Malaysia"}},
    {23, {"Johor", "Malaysia"}},
    {24, {"Johor", "Malaysia"}},

    // 25–27: Kedah
    {25, {"Kedah", "Malaysia"}},
    {26, {"Kedah", "Malaysia"}},
    {27, {"Kedah", "Malaysia"}},

    // 28–29: Kelantan
    {28, {"Kelantan", "Malaysia"}},
    {29, {"Kelantan", "Malaysia"}},

    // 30: Malacca
    {30, {"Malacca", "Malaysia"}},

    // 31: Negeri Sembilan
    {31, {"Negeri Sembilan", "Malaysia"}},

    // 32–33: Pahang
    {32, {"Pahang", "Malaysia"}},
    {33, {"Pahang", "Malaysia"}},

    // 34–35: Penang
    {34, {"Penang", "Malaysia"}},
    {35, {"Penang", "Malaysia"}},

    // 36–39: Perak
    {36, {"Perak", "Malaysia"}},
    {37, {"Perak", "Malaysia"}},
    {38, {"Perak", "Malaysia"}},
    {39, {"Perak", "Malaysia"}},

    // 40: Perlis
    {40, {"Perlis", "Malaysia"}},

    // 41–44: Selangor
    {41, {"Selangor", "Malaysia"}},
    {42, {"Selangor", "Malaysia"}},
    {43, {"Selangor", "Malaysia"}},
    {44, {"Selangor", "Malaysia"}},

    // 45–46: Terengganu
    {45, {"Terengganu", "Malaysia"}},
    {46, {"Terengganu", "Malaysia"}},

    // 47–49: Sabah
    {47, {"Sabah", "Malaysia"}},
    {48, {"Sabah", "Malaysia"}},
    {49, {"Sabah", "Malaysia"}},

    // 50–53: Sarawak
    {50, {"Sarawak", "Malaysia"}},
    {51, {"Sarawak", "Malaysia"}},
    {52, {"Sarawak", "Malaysia"}},
    {53, {"Sarawak", "Malaysia"}},

    // 54–57: Federal Territory of Kuala Lumpur
    {54, {"Federal Territory of Kuala Lumpur", "Malaysia"}},
    {55, {"Federal Territory of Kuala Lumpur", "Malaysia"}},
    {56, {"Federal Territory of Kuala Lumpur", "Malaysia"}},
    {57, {"Federal Territory of Kuala Lumpur", "Malaysia"}},

    // 58: Federal Territory of Labuan
    {58, {"Federal Territory of Labuan", "Malaysia"}},

    // 59: Negeri Sembilan
    {59, {"Negeri Sembilan", "Malaysia"}},

    // Foreign-born (ASEAN)
    {60, {"Brunei", "ASEAN"}},
    {61, {"Indonesia", "ASEAN"}},
    {62, {"Cambodia", "ASEAN"}},
    {63, {"Laos", "ASEAN"}},
    {64, {"Myanmar", "ASEAN"}},
    {65, {"Philippines", "ASEAN"}},
    {66, {"Singapore", "ASEAN"}},
    {67, {"Thailand", "ASEAN"}},
    {68, {"Vietnam", "ASEAN"}},
    // {69, {"Abroad (Unspecified)", "International"}},
    // {70, {"Abroad (Unspecified)", "International"}},

    // Pre-2001 foreign-born Malaysian registrations
    {71, {"Foreign (Pre-2001)", "International"}},
    {72, {"Foreign (Pre-2001)", "International"}},
    // {73, {"Abroad (Unspecified)", "International"}},

    // Specific foreign countries
    {74, {"China", "Asia"}},
    {75, {"India", "Asia"}},
    {76, {"Pakistan", "Asia"}},
    {77, {"Saudi Arabia", "Middle East"}},
    {78, {"Sri Lanka", "Asia"}},
    {79, {"Bangladesh", "Asia"}},
    // {80, {"Abroad (Unspecified)", "International"}},
    // {81, {"Abroad (Unspecified)", "International"}},

    // 82: Unknown state
    {82, {"Unknown State", "International"}},

    // 83: Asia-Pacific (list of countries)
    {83, {"Asia-Pacific", "Oceania"}},

    // 84: South America (list of countries)
    {84, {"South America", "Americas"}},

    // 85: Africa (list of countries)
    {85, {"Africa", "Africa"}},

    // 86: Western Europe (list of countries)
    {86, {"Western Europe", "Europe"}},

    // 87: Britain / Great Britain / Ireland
    {87, {"Britain/Ireland", "Europe"}},

    // 88: Middle East (list of countries)
    {88, {"Middle East", "Middle East"}},

    // 89: Far East (Japan, Korea, Taiwan)
    {89, {"Far East", "Asia"}},

    // 90: Caribbean (list of countries)
    {90, {"Caribbean", "Americas"}},

    // 91: North America (list of countries)
    {91, {"North America", "Americas"}},

    // 92: Eastern Europe (list of countries)
    {92, {"Eastern Europe", "Europe"}},

    // 93: Other/Rest of World (list of countries)
    {93, {"Other/Rest of World", "International"}},

    // 94–97: unused/undefined
    {94, {"Abroad (Unspecified)", "International"}},
    {95, {"Abroad (Unspecified)", "International"}},
    {96, {"Abroad (Unspecified)", "International"}},
    {97, {"Abroad (Unspecified)", "International"}},

    // 98: Stateless
    {98, {"Stateless", "Unspecified"}},

    // 99: Mecca / Neutral Zone / No Info / Refugee / UN / Unspecified Nationality
    {99, {"Unspecified/Refugee/UN", "Unspecified"}}
};


// The main IC structure to hold all relevant information
class IC {
public:
    IC(); // Default constructor
    IC(const std::string& ic_number); // Construct with information

    // Getters
    const std::string getRawNumber() const;
    const std::string getFormattedNumber() const;
    Sex getSex() const;
    StateInfo getState() const;
    std::string getName() const;
    std::string getAddress() const;
    std::chrono::system_clock::time_point getDobUnixTime() const;
    const date& getDob() const;
    bool isValid() const;

    std::string getNote() const;

    // Setters (optional, only if you want to allow modification)
    void setName(const std::string& name);
    void setAddress(const std::string& address);

private:
    // Store as a fixed-size char array for efficiency and easy serialization
    std::array<char, 13> raw_number; // 12 digits + null terminator
    std::array<char, 15> formatted_number; // "YYMMDD-SS-XXXX" + null terminator
    Sex sex;
    StateInfo state;

    std::string name;
    std::string address;

    std::chrono::system_clock::time_point unix_time_dob; // Date of Birth as Unix time (time_point)
    date dob; // Date of birth as struct date

    bool validity = false;         // Flag for validation status

    std::string note;              // Additional notes or comments
};

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>

struct FootballTeam {
    std::string name;
    std::string city;
    std::string stadium;
    double level;
    int points = 0;
    int wins = 0;
    int draws = 0;
    int losses = 0;

    FootballTeam(const std::string& name, const std::string& city, const std::string& stadium, double level) 
        : name(name), city(city), stadium(stadium), level(level) {}

    void addWin() { wins++; points += 3; }
    void addDraw() { draws++; points += 1; }
    void addLoss() { losses++; }
};

struct Match {
    FootballTeam& localTeam;
    FootballTeam& visitorTeam;
    std::string stadium;
    int localGoals = 0;
    int visitorGoals = 0;

    Match(FootballTeam& localTeam, FootballTeam& visitorTeam) : localTeam(localTeam), visitorTeam(visitorTeam), stadium(localTeam.stadium) {}

    void play() {
        std::random_device rd;
        std::mt19937 gen(rd());
        int goalDiff = ceil(abs(localTeam.level - visitorTeam.level)) * 10;
        std::uniform_int_distribution<> dis(0, goalDiff);

        int k = dis(gen);
        int goals[k];
        for (int& goal : goals) {
            goal = dis(gen) - localTeam.level + visitorTeam.level;
            if (goal < 0) localGoals++;
            else visitorGoals++;
        }

        if (localGoals > visitorGoals) {
            localTeam.addWin();
            visitorTeam.addLoss();
        } else if (visitorGoals > localGoals) {
            visitorTeam.addWin();
            localTeam.addLoss();
        } else {
            localTeam.addDraw();
            visitorTeam.addDraw();
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Match& match) {
        os << "(localTeam=" << match.localTeam.name << ", visitorTeam=" << match.visitorTeam.name
           << ", stadium=" << match.stadium << ", result=" << match.localGoals << "-" << match.visitorGoals << ")";
        return os;
    }
};
void parseLineTeam(const std::string& line, std::string& name, std::string& city, std::string& stadium, double& level)
{
    size_t posName = line.find(',');
    name = line.substr(0, posName);
    
    size_t posCity = line.find(',', posName + 1);
    city = line.substr(posName + 1, posCity - posName - 1);
    
    size_t posStadium = line.find(',', posCity + 1);
    stadium = line.substr(posCity + 1, posStadium - posCity - 1);
    
    size_t posLevel = line.size() - 1;
    std::string levelString = line.substr(posStadium + 1, posLevel - posStadium);
    std::stringstream ss(levelString);
    ss >> level;
    
}

void loadTeams(std::istream& in, std::vector<FootballTeam>& teams)
{
    std::string buffer;
    std::getline(in, buffer);
    while(std::getline(in, buffer))
    {
        std::string name;
        std::string city;
        std::string stadium;
        double level;
        parseLineTeam(buffer, name, city, stadium, level);
        std::cout << "name = " << name << "\n";
        std::cout << "city = " << city << "\n";
        std::cout << "stadium = " << stadium << "\n";
        std::cout << "level = " << level << "\n\n";
    }
}
struct Tournament {
    std::vector<FootballTeam> teams;
    int round = 0;

    void loadTeams(std::istream& in) {
        std::string line;
        while (std::getline(in, line)) {
            std::istringstream iss(line);
            std::string name, city, stadium;
            double level;
            parseLineTeam(line, name, city, stadium, level);
            teams.emplace_back(name, city, stadium, level);
        }
    }

    void simulateRound() {
        size_t n = teams.size();
        for (size_t i = 0; i < n / 2; ++i) {
            Match match(teams[i], teams[n - i - 1]);
            match.play();
            std::cout << match << std::endl;
        }
        std::rotate(teams.begin() + 1, teams.begin() + 2, teams.end());
        round++;
    }
};

int main() {
    const std::string FILENAME = "../../../data/problem2_matches/football.csv";
    std::ifstream inputFile(FILENAME);

    if (!inputFile) {
        std::cerr << "Could not open the file: " << FILENAME << std::endl;
        return 1;
    }

    Tournament tournament;
    tournament.loadTeams(inputFile);

    tournament.simulateRound();

    std::sort(tournament.teams.begin(), tournament.teams.end(), [](const FootballTeam& a, const FootballTeam& b) {
        return a.points > b.points; 
    });

    for (const auto& team : tournament.teams) {
        std::cout << team.name << " - Points: " << team.points << ", Wins: " << team.wins << ", Draws: " << team.draws << ", Losses: " << team.losses << std::endl;
    }

    return 0;
}

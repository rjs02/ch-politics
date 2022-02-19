#include <iostream>
#include <vector>
#include <string>
#include <Eigen/Dense>

#include "loadCSV.hpp"
#include "projections.hpp"

int main() {

    // read in csv into matrix
    Eigen::MatrixXi parolen;
    std::vector<Vote> votes;
    std::vector<std::string> parties;
    std::string path = "../data/abst-parolen.CSV";
    
    load_csv(path, parolen, votes, parties);
    
    unsigned int i = 0, ind;
    std::cout << "| ";
    for(auto &s : parties) {
        std::cout << i++ << " " << s << " | ";
    }
    std::cout << "\nEnter index to compute score by projection: ";
    std::cin >> ind;

    Eigen::VectorXd scores;
    computeScore(parolen, scores, ind);

    // Output
    i = 0;
    std::cout << "---------------\n\n"
              << "Comparing " << parties[ind] << " to:\n";
    for(auto x : scores) {
        std::cout << parties[i++] << ":   " << x << "\n";
    }



    return 0;
}
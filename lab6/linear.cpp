#include <cmath>
#include <matplot/matplot.h>

using namespace std;
using namespace matplot;

int main(){
    std::ifstream csv("gpa_sat.csv");
    std::vector<double> gpa_x;
    std::vector<double> sat_y;
    double sum_x  = 0;
    double sum_y = 0;

    //parse the data
    std::string line; 
    getline(csv,line); //grabs the header line
    while( csv >> line) {
        line.replace(line.find_first_of(','),1," ");
        std::stringstream ss(line);
        double x,y; 
        ss >> x >> y;

        sum_x += x;
        sum_y += y;
        
        gpa_x.push_back(x);
        sat_y.push_back(y);
    }
    //all the data is loaded into the vectors

    //mean of the x and y values
    double mean_gpa = sum_x/100;
    double mean_sat = sum_y/100;

    double betaNum = 0.0;
    double betaDenom = 0.0;

    //uses those values to calculate beta
    for(int i = 0; i < gpa_x.size();i++) {
        betaNum += (gpa_x[i] - mean_gpa)*(sat_y[i]-mean_sat);
        betaDenom += pow((gpa_x[i] - mean_gpa),2);
    }
    //calculate beta 
    double beta = betaNum/betaDenom;
    cout << "beta " << beta << endl;

    //calculate alpha
    double alpha = mean_sat - (beta*mean_gpa);
    cout << "alpha " << alpha << endl;
    //using model find the pnts
    vector <double> fiPoints;
    for(int i = 0 ; i< gpa_x.size();i++) {
        double fi = alpha + beta* gpa_x[i];
        fiPoints.push_back(fi);
    }
    //ss res 
    double ssRes = 0.0;
    double ssTot = 0.0;
    for(int i = 0; i< fiPoints.size();i++) {
        ssRes += pow((sat_y[i]-fiPoints[i]),2);
        ssTot += pow((sat_y[i]-mean_sat),2);
    }
    // r-squared value

    double rSquared = 1 - (ssRes/ssTot);

    //print out the linear regression equation
    cout << "SAT Score = " << alpha << " + " << beta << "*GPA" << endl;
    cout << "R-squared: " << rSquared << endl;

return 0;
}


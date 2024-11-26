#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <matplot/matplot.h>

using namespace matplot;

int main() {
	//std::vector<double> x = linspace(0, 10);
	
	std::ifstream ifile("atmosphere.txt");
	std::string line;
	
	std::vector<double> p, h, t;
	double pres, height, temp;

	//call getline 4 times-- remove the first four lines
	getline(ifile,line);
	getline(ifile,line);
	getline(ifile,line);
	getline(ifile,line);

	while(getline(ifile,line)) { 
		// make a stringstream to get individual values
		std::stringstream ss(line);
		ss >> pres >> height >> temp;
		
		p.push_back(pres);
		h.push_back(height);
		t.push_back(temp);
		//push values into vector
	}
	double t_min = *std::min_element(t.begin(), t.end());
	double t_max = *std::max_element(t.begin(), t.end());		

	//Pressure and height
	matplot::plot(p,h,"-xr"); 
	xlabel("Pressure(hPa)");
	ylabel("Height(m)");
	show(); //
	save("task2a.png");// to see the other graph we must comment this out

	hold(on);
	plot(h,t, "-rx")->use_y2(true);
	y2lim({t_min, t_max});
	y2label("Temperature(Celsius)");
	show();
	save("task2b.png");


return 0;
}

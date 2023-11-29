#include <iostream>
#include <vector>
#include <random>
#include <math.h>

using namespace std;

double randomParam()
{
    random_device rd; //seed
    mt19937 gen(rd()); // random engine gen(erator)
    uniform_real_distribution<double> dis(0.0, 10.0);
    return dis(gen);
}


struct dataPair
{
    int input;
    int output;
};

vector<dataPair> t_data = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8},
    {5, 10},
};

double cost(double param, double bias)
{
// ouput = input * parametar + bias
    double cost = 0.00;
    for (size_t i = 0; i < t_data.size(); i++)
    {
        double t_out = t_data[i].input * param + bias;
        double diff = t_out - t_data[i].output;
        cost += diff * diff;
    }
    cost /= t_data.size();
    return cost;
}

double costAndPrint(double param, double bias)
{
// ouput = input * parametar + bias
    double cost = 0.00;
    cout << "\nParam value is: " << param << ", Bias value: " << bias << endl;
    for (size_t i = 0; i < t_data.size(); i++)
    {
        double t_out = t_data[i].input * param + bias;
        cout << "Model prediction is this: " << t_out << ", Actuall value is: " << t_data[i].output << endl;
        double diff = t_out - t_data[i].output;
        cost += diff * diff;
    }
    cost /= t_data.size();
    return cost;
}

void train(int amount, double& param, double &bias)
{
    double eps = 1e-3;
    double rate = 1e-3;

    for (size_t it= 0; it < amount; it++)
    {
        double c = cost(param, bias);

        double dparam = (cost(param + eps, bias) - c ) / eps; 
        double dbias = (cost(param , eps + bias) - c ) / eps;

        param -= rate * dparam;
        bias  -= rate * dbias;
    }
}


int main()
{
    double param = randomParam();
    double bias = randomParam();

	while(true)
	{
		cout << "\n\nTraining process is about to start.\nEnter the number of itterations (100+).";
		int amount;
		cin >> amount;
	    
		train(amount, param, bias);	
	    
	    cout << "\nAfter training Cost:" << costAndPrint(param, bias) << endl;
	    
	}
	
    return 0;
}





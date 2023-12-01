
#include <iostream>
#include <vector>
#include <random>

using namespace std;

const int NEURONS_COUNT = 3;

double randomParam()
{
    random_device rd; //seed
    mt19937 gen(rd()); // random engine gen(erator)
    uniform_real_distribution<double> dis(-2.5, 2.5);
    return dis(gen);
}

double sigmoid(double x)
{
    return 1.0 / (1.0 + std::exp(-x));
}

//

struct Neuron
{
    double P1;
    double P2;
    double B;
};
struct Model
{   // First neuron is OR gate, Second NAND, Third AND (or at least we hope so)
    Neuron neurons[NEURONS_COUNT];
};

void RandomiseModel(Model& model)
{
    for (size_t i = 0; i < NEURONS_COUNT; i++)
    {
        model.neurons[i].P1 = randomParam();
        model.neurons[i].P2 = randomParam();
        model.neurons[i].B = randomParam();
    }
}

void PrintModel(Model& model)
{
    cout << "Model weights:\n";
    for (size_t i = 0; i < NEURONS_COUNT; i++)
    {
        printf("   model.neurons[%d].P1 = %f;\n", i, model.neurons[0].P1);
        printf("   model.neurons[%d].P2 = %f;\n", i, model.neurons[0].P2);
        printf("   model.neurons[%d].B  = %f;\n", i, model.neurons[0].B);
    }
}

//

struct DataRow
{
    int bit1;
    int bit2;
    int outBit;
};

vector<DataRow> t_dataXOR =
{
    { 0, 0, 0},
    { 0, 1, 1},
    { 1, 0, 1},
    { 1, 1, 0}
};

//

double forward(const Model& model, double inpBit1, double inpBit2)
{
    //input layer 
    double outOr = sigmoid(model.neurons[0].P1 * inpBit1 + model.neurons[0].P2 * inpBit2 + model.neurons[0].B);
    double outNand = sigmoid(model.neurons[1].P1 * inpBit1 + model.neurons[1].P2 * inpBit2 + model.neurons[1].B);
        
    //second layer 
    double outAnd = sigmoid(model.neurons[2].P1 * outOr + model.neurons[2].P2 * outNand + model.neurons[2].B);
    
    //third (output) layer
    return outAnd;
}

double cost(const Model& model)
{
    double cost = 0.00;

    for (size_t i = 0; i < t_dataXOR.size(); i++)
    {
        double m_out = forward(model, t_dataXOR[i].bit1, t_dataXOR[i].bit2);
        double diff = m_out - t_dataXOR[i].outBit;
        cost += diff * diff;
    }
    cost /= t_dataXOR.size();
    //cout << "//Cost: " << std::fixed << cost << endl;
    return cost;
}

void train(Model& model, int itterations)
{
    double eps = 1e-2;
    double rate = 1e-1;

    // this is called finite difference (simple version of derivation)
    for (size_t j = 0; j < itterations; j++)
    {
        if(!(j%20)) cout << ".\n";
        
        for (size_t i = 0; i < NEURONS_COUNT; i++)
        {
            double c = cost(model);
            model.neurons[i].P1 += eps;
            double learn = (cost(model) - c) / eps;
            model.neurons[i].P1 -= eps;
            model.neurons[i].P1 -= learn * rate;

            c = cost(model);
            model.neurons[i].P2 += eps;
            learn = (cost(model) - c) / eps;
            model.neurons[i].P2 -= eps;
            model.neurons[i].P2 -= learn * rate;

            c = cost(model);
            model.neurons[i].B += eps;
            learn = (cost(model) - c) / eps;
            model.neurons[i].B -= eps;
            model.neurons[i].B -= learn * rate;
        }
    }
}


void testModel(Model& model)
{
    for (size_t i = 0; i < t_dataXOR.size(); i++)
    {
        double t_out = forward(model, t_dataXOR[i].bit1, t_dataXOR[i].bit2);
        cout << "Model prediction: " << t_out << ", Correct value: " << t_dataXOR[i].outBit << endl;
    }
}

int main()
{
    Model model;
    RandomiseModel(model);
    PrintModel(model);
    cout << "Models' Cost function: " << cost(model) << "\n\n";
    testModel(model);


    while (true)
    {
        int itterations;
        cout << "\nEnter training itteration amount(1000+): " << endl;
        cin >> itterations;
        train(model, itterations);
       
        PrintModel(model);

        testModel(model);  

        cout << "Models' Cost function: " << std::fixed << cost(model) << endl;
    }
 
    return 0;
}


// MODEL PARAMETER WEIGHTS
/*
* //Cost: 0.000001
model.neurons[0].P1 = 6.234007;
model.neurons[0].P2 = 6.228276;
model.neurons[0].B  = -9.541721;
model.neurons[1].P1 = 8.139920;
model.neurons[1].P2 = 8.115377;
model.neurons[1].B  = -3.774236;
model.neurons[2].P1 = -15.928453;
model.neurons[2].P2 = 15.280782;
model.neurons[2].B  = -7.346068;
*/

/*
//Cost: 0.000020
model.neurons[0].P1 = 5.372916;
model.neurons[0].P2 = 5.360791;
model.neurons[0].B  = -8.244135;
model.neurons[1].P1 = 7.427843;
model.neurons[1].P2 = 7.373250;
model.neurons[1].B  = -3.384545;
model.neurons[2].P1 = -12.766423;
model.neurons[2].P2 = 12.026503;
model.neurons[2].B  = -5.680481;
*/

/*
//Cost: 0.000105
model.neurons[0].P1 = 4.779449;
model.neurons[0].P2 = 4.781541;
model.neurons[0].B  = -7.354289;
model.neurons[1].P1 = 7.355715;
model.neurons[1].P2 = 7.368997;
model.neurons[1].B  = -3.317785;
model.neurons[2].P1 = -11.307899;
model.neurons[2].P2 = 10.421020;
model.neurons[2].B  = -4.824705;
*/

/*
//Cost: 0.000293
 model.neurons[0].P1 = 4.653326;
 model.neurons[0].P2 = 4.634190;
 model.neurons[0].B = -7.262662;
 model.neurons[1].P1 = 6.546970;
 model.neurons[1].P2 = 6.469307;
 model.neurons[1].B = -2.854630;
 model.neurons[2].P1 = -10.353566;
 model.neurons[2].P2 = 9.469316;
 model.neurons[2].B = -4.437411;
*/


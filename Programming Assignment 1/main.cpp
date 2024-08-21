using namespace std;

#include <iostream>
#include <fstream>
#include <vector>

void readData(const string &filename, vector<double> &fpangles, vector<double> &liftCoefficients);
double interpolation(double userIN, const vector<double> &fpangles, const vector<double> &liftCoefficients);
bool isOrdered(const vector<double> &fpangles);
void reorder(vector<double> &fpangles, vector<double> &liftCoefficient);

int main(int argc, char *argv[])
{
    vector<double> fpangles;
    vector<double> liftCoefficients;
    string fileName = argv[1];
    //string fileName = "tunnel3.dat";

    readData(fileName, fpangles, liftCoefficients);
    

    if (!isOrdered(fpangles))
    {
        reorder(fpangles, liftCoefficients);
    }
    /* debug print vector elements after reordering
    for (unsigned int i = 0; i < fpangles.size(); ++i)
    {
        cout << fpangles.at(i) << " " << liftCoefficients.at(i) << endl;
    }*/
    
    
    string userResponse = "yes";
    while (userResponse == "Yes" or userResponse == "yes")
    {
        double userFpangle;
        cout << "Enter your flight-path angle: ";
        cin >> userFpangle;
        cout << endl;
        if (userFpangle < fpangles.at(0) || userFpangle > fpangles.at(fpangles.size() - 1))
        {    
        }
        else
        {
            cout << interpolation(userFpangle, fpangles, liftCoefficients) << endl;
        }
        
        cout << "do you want to enter another flight path angle (yes/no): " ;
        cin >> userResponse;
        cout << endl;
    }
    
   return 0;

}

void readData(const string &filename, vector<double> &fpangles, vector<double> &liftCoefficients)
{
    ifstream inFS;
    inFS.open(filename);
    if (!inFS.is_open())
    {
        cout << "Error opening " << filename << endl;
        exit(1);
    }
    
    double angle;
    double lC;
    while (inFS >> angle >> lC)
    {
        fpangles.push_back(angle);
        liftCoefficients.push_back(lC); 
    }
    /* zybooks angry at the f() for some reason
     for (unsigned int i = 0; i < fpangles.size(); ++i)
    {
        cout << fpangles.at(i) << " " << liftCoefficients.at(i) << endl;
    }*/
   


}
double interpolation(double userIN, const vector<double> &fpangles, const vector<double> &liftCoefficients)
{
    unsigned int i = 0;
    for (i = 0; i < fpangles.size(); ++i)
    {
        if (userIN == fpangles.at(i))
        {
            return liftCoefficients.at(i);
        }
    }
    double a;
    double c;
    for (i = 0; i < fpangles.size() - 1; ++i)
    {
        if (fpangles.at(i) < userIN && userIN < fpangles.at(i + 1))
        {
            a = i;
            c = i + 1;

        }
    }

    double Fb = liftCoefficients.at(a) + 
        (((userIN - fpangles.at(a)) / (fpangles.at(c) - fpangles.at(a))) * (liftCoefficients.at(c) - liftCoefficients.at(a)));

    return Fb;

}

bool isOrdered(const vector<double> &fpangles)
{
    if (fpangles.size() == 0)
    {
        return true;
    }
    for (unsigned int i = 0; i < fpangles.size() - 1; ++i)
    {
        if (!(fpangles.at(i) <= fpangles.at(i + 1)))
        {
            return false;
        }
    }
    return true;
}

void swap (int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}


void reorder(vector<double> &fpangles, vector<double> &liftCoefficient)
{
    //selection sort
    //int i = 0;
    //int j = 0;
    if (fpangles.size() > 1 && fpangles.at(0) > fpangles.at(1)) {
        swap(fpangles.at(0), fpangles.at(1));
        swap(liftCoefficient.at(0), liftCoefficient.at(1));
    }
    if (fpangles.size() == 0 || liftCoefficient.size() == 0)
    {
    }
    else 
    {
        for (unsigned int i = 0; i < (fpangles.size() - 1); ++i)
    {
        unsigned int min = i;
        for (unsigned int j = i + 1; j < fpangles.size(); ++j)
        {
            if (fpangles.at(j) < fpangles.at(min))
            {
                min = j;
            }
        }
        //swap step also swaps lift coefficients whenever necessary
        swap(fpangles.at(min), fpangles.at(i));
        swap(liftCoefficient.at(min), liftCoefficient.at(i));
    }
    }
    

}

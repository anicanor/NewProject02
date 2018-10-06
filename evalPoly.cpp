//Aaron Nicanor

//Header Files
#include "Node.h"
#include "Polynomial.h"
//Libraries
#include<iostream>
#include<utility>
#include<sstream>
#include<vector>
#include<string>

using namespace std;

//function to seperate numbers from user input
vector<int> split(const string& s, char delimiter)
{
        vector<int> tokens;            // vector that will store each individual number
        int token;                     // will represend the number
        istringstream tokenStream(s);

        //Will seperate each number from tokenStream and store them as their own number in the vector
        while(tokenStream >> token)
                tokens.push_back(token);

        return tokens;
}

int main()
{
        string coeff, xVal;
        char delimiter = ' ';
        
        //This Loop will continue so long as there are inputs. In addition, it saves the coeffiencts we're going to use
        while(getline(cin, coeff))
        {
                //This grabs each x values for the polynomial
                getline(cin, xVal);
                
                //Declares list of items. Uses that pair function to have the Node hold more than one
                //value. first for the coefficent, and second for the power.
                Polynomial< pair<double, unsigned> > equate;

                //As each coefficent is added, it will add another to the power counter.
                vector<int> listOfInputs = split(coeff, delimiter);
                for(auto val : listOfInputs)
                {
                    unsigned power = 0;
                    pair<double, unsigned> value((int) val, (int) power);
                    equate.insert(value);
                    power++;
                    cout<<val<<" "<<endl;
                }

                //Equates our polynomial with each given x value. It will also print our values
                listOfInputs = split(xVal, delimiter);
                for(auto val : listOfInputs)
                {
                    equate.evaluate(val);
                }
                cout << endl;
        }
        return 0;
}

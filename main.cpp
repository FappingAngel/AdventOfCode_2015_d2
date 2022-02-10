#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;



vector<int> split (string s, char delimiter){

    vector<int> result;
    stringstream ss (s);
    string item;
    while (getline (ss, item, delimiter)) {
        int zahl = stoi(item);
        result.push_back (zahl);

    }
    return result;
}


int main() {
    int ribbon = 0;
    int ergebnis = 0;
    string line;
    ifstream myfile ("./2015_d2.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            int z1, z2, z3, k1, k2, k3;
            vector<int> zahlen = split(line, 'x');
            z1 = zahlen.at(0);
            z2 = zahlen.at(1);
            z3 = zahlen.at(2);

            int seite1= z1*z2;
            int seite2= z2*z3;
            int seite3= z3*z1;

            if(z1 <= z2 && z1 <= z3){
                k1 = z1;
                if(z2<= z3){
                    k2 = z2;
                    k3 = z3;
                }else{
                    k2 = z3;
                    k3 = z2;
                }
            }else if(z2 <= z1 && z2 <= z3){
                k1= z2;
                if(z1 <= z3){
                    k2 = z1;
                    k3 = z3;
                }else{
                    k2 = z3;
                    k3 = z1;
                }
            }else{
                k1 =z3;
                if(z1 <= z2){
                    k2 = z1;
                    k3 = z2;
                }else{
                    k2 = z2;
                    k3 = z3;
                }
            }
            ergebnis += 2*seite1 + 2*seite2 + 2*seite3;

            if(seite1 <= seite2 && seite1 <= seite3){
                ergebnis += seite1;
            }
            else if(seite2 <= seite3 && seite2 <= seite1) {
                ergebnis += seite2;

            }else {
                ergebnis += seite3;
            }
            ribbon += 2*k1 + 2*k2;
            ribbon += z1 * z2 * z3;
        }
        cout << ergebnis << endl;
        cout << ribbon << endl;
        myfile.close();

    }

    else cout << "Unable to open file";
    return 0;
}

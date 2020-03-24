#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int GCF(int m, int n)
{
    if (n == 0)
        return m;

    else
        return GCF(n, m % n);
}

void printGCF(vector<int> &first, vector<int> &second)
{
    cout << left << setw(10) << "First #" << setw(10) << "Second #" << setw(5) <<"GCF" <<endl;
    cout << left << setw(10) << "=======" << setw(10) <<"========" << setw(5) << "===" <<endl;
    for(int i = 0; i <first.size(); i++)
    {
        cout<< left << setw(10) << first.at(i)<< setw(10) << second.at(i)<<setw(5)<< GCF(first.at(i),second.at(i))<<endl;
    }
}

int main()
{
    vector<int> first;
    vector<int> second;

    do{
    
    int m, n;
    char ch;
    cout<< "Would you like to enter two numbers? ";
    cin >> ch;

    if(ch == 'Y' || ch == 'y' ){
    cout << "Please enter two numbers " <<endl;
    cin >> m >> n;

    first.push_back(m);
    second.push_back(n);
    }

    else
    {
        break;
    }
    
    }while (true);

    printGCF(first, second);

    return 0;

}
#include<iostream> 
#include<string>
#include<iomanip>
using namespace std; 
  
//This function is to return the minimum of the 3 arguments
int min(int x, int y, int z) 
{ 
    return min(min(x, y), z); //take the min of x and y and then between x and y, whichever is the min
                                //take the min of that and z.
} 
//the best edit distance is the lowest cost

void printRow(char a, char b, int cost) { //this is for the dash, use it to add a character and make it match
    cout << setw(3) << a << setw(3) << b << setw(5) << cost <<endl; //stating what the cost is, not making a change
}

//The matrix is turned around, mirrored
void editDistance(string str1, string str2, int m, int n) 
{ 
    int opt[m+1][n+1]; //n and m are the strings and we add plus 1 for the white space at the end if they are not the same length
 
    for (int i=0; i<=m; i++) // i goes over m+1 string1
    { 
        for (int j=0; j<=n; j++) //j goes over n+1 string2
        { 
            if (i==0) 
            {
                opt[i][j] = j * 2; //if you compare 2 strings, and string1 is longer than string2
                                    // then you do 2 * length of the remaining characters
            }
            else if (j==0) 
            {
                opt[i][j] = i * 2; //if you compare 2 strings, and string2 is longer than string1
                                    // then you do 2 * length of the remaining characters
            }
            else if (str1[m - i] == str2[n - j]) //TRICKY.....i = 1 is the last character of the variable str1
            {                                   //and i = m is the first
                opt[i][j] = opt[i-1][j-1]; 
            }
            else 
            {
                opt[i][j] = min(opt[i][j-1] + 2,
                                opt[i-1][j] + 2,  
                                opt[i-1][j-1]+ 1);
            }
        } 
    } 
    // print the matrix for testing.
    // cout << "Edit distance Matrix" << endl;
    // for (int i=m; i>=0; i--) 
    // { 
    //     for (int j=n; j>=0; j--) 
    //     { 
    //         cout << setw(3) << opt[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // print the actual output.
    
    cout << "Edit distance = " << opt[m][n] << endl;

    //Recover the trace through opt.
    int i = m;
    int j = n;
    while(i>=0 && j>=0) {
        char x = str1[m -i];
        char y = str2[n -j];
        if (j-1 >=0 && i-1 >=0 && opt[i][j] == opt[i-1][j-1] && x == y) {
            // characters matched without gap
            printRow(x, y, 0);
            i--; j--;
        } else if (j-1 >=0 && i-1 >=0 && opt[i][j] == opt[i-1][j-1] + 1 && x != y) {
            // characters matched without gap
            printRow(x, y, 1);
            i--; j--;
        } else if (i-1 >=0 && opt[i][j] == opt[i-1][j] + 2) {
            // gap on the right
            printRow(x, '-', 2);
            i--;
        } else if (j-1 >=0 && opt[i][j] == opt[i][j-1] + 2) {
            // gap on the left           
            printRow('-', y, 2);
            j--;
        } else if (i==0 && j==0) {
            // special case; do nothing.
            break;
        } else {
            cout << "error x: " << x << " y " << y << endl;            
            cout << "i " << i << " j " << j << " opt " << opt[i][j] << endl;
            break;
        }
    }
} 

//The test function wants two strings and the length of the twi strings, and since i can get the string 
//length directlyy from the sring, i wrote a version that takes two strings so that i dont have to count 
//how many characters there are on the test strings. 

//run methods allows me to pass two methods instead of four

void run(string str1, string str2) {
    editDistance(str1, str2, str1.length(), str2.length()); // m is str1 length and n is str2 length
}

/*void test_inputs() {
    //open files, copy strings, print file names and run(function)
    cout << "example10.txt" << endl;
    run("AACAGTTACC", "TAAGGTCA");

    cout << "endgaps7.txt" << endl;
    run("atattat", "tattata");

    cout << "bothgaps20.txt" << endl;
    run("abcdefghizzzzjklmnop", "azzbcdefghijklmnop");

    cout << "lastxgaps9.txt" << endl;
    run("atattat", "atattatag");

    cout << "lastygaps9.txt" << endl;
    run("atattataa", "atattat");
}*/

int main() 
{ 
    //test_inputs();

    string str1, str2;
    cout << "Enter String 1: ";
    cin >> str1;
    cout << "Enter String 2: ";
    cin >> str2;
    run(str1, str2); //call the function to test the strings
        
    return 0; 
} 

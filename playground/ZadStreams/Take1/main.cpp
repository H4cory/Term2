#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    fstream textFile;
    string input;

    textFile.open("test.txt");
    if (!textFile)
    {
        cerr << "\nFile was not oppen!";
    }
    else
    {
        while (true)
        {
            cout << "Input: ";
            getline(cin, input);
            if (input == "stop" || input == "Stop")
            {
              
                textFile.close();
                break;
            }
            else
                textFile << input << "\n";
        }
    }
    textFile.open("test.txt");
    if (!textFile)
    {
        cerr << "\nFile was not oppen!";
    }
    else
    {
        while (!textFile.eof())
        {
            getline(textFile,input);
            cout<<input<<endl;
        }
    }
    return 0;
}
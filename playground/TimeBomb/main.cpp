/*

*/
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void getTime(int &hour, int &min)
{
    string input;
    cout << "\nhh:mm\n->";
    getline(cin, input);
    hour = stoi(input.substr(0, 2));
    min = stoi(input.substr(3, 2));
}
int main()
{
    bool check = true;
    int hour = 0, min = 0, sec = 0, result = 0;
    string input;
    time_t t = time(0);
    tm *now = localtime(&t);

    while (check)
    {
        cout << "\n1.Timer shutdown";
        cout << "\n2.Set shutdown";
        cout << "\n3.Abort";
        cout << "\ns.Exit";
        cout << "\n->";

        getline(cin, input);
        switch (input[0])
        {
        case '1':

            getTime(hour, min);
            result += hour * 3600;
            result += min * 60;

            cout << "\n1.Shutdown\n2. Restart\n->";
            getline(cin, input);
            if (input[0] == '1')
            {
                input = "shutdown -s -t " + to_string(result);
                const char *a = input.c_str();
                system(a);
                // cout << "\n System will shutdown at " << now->tm_hour + hour << ":" << now->tm_min + min << endl;
                cout << "\n System will shutdown at " ;
                if(now->tm_hour + hour >= 24){
                    cout<<now->tm_hour + hour -24<< ":" << now->tm_min + min << endl;
                }
                else 
                cout<<now->tm_hour + hour << ":" << now->tm_min + min << endl;
            }
            else if (input[0] == '2')
            {
                input = "shutdown -r -t " + to_string(result);
                const char *a = input.c_str();
                system(a);
               cout << "\n System will shutdown at " ;
                if(now->tm_hour + hour > 24){
                    cout<<now->tm_hour + hour -24<< ":" << now->tm_min + min << endl;
                }
                else 
                cout<<now->tm_hour + hour << ":" << now->tm_min + min << endl;
            }
            else
                cout << "\nWrong input!";

            result = 0;
            hour = 0;
            min = 0;
            break;

        case '2':
            getTime(hour, min);
            if (hour - now->tm_hour < 0)
            {
                hour = hour + (24 - now->tm_hour);
            }
            else
            {
                hour = hour - now->tm_hour;
            }
            min = min - now->tm_min;
            result += hour * 3600;
            result += min * 60;

            cout << "\n1.Shutdown\n2. Restart\n->";
            getline(cin, input);
            if (input[0] == '1')
            {

                input = "shutdown -s -t " + to_string(result);
                const char *a = input.c_str();
                system(a);
                cout << "\n System will shutdown at " << now->tm_hour + hour - 24 << ":" << now->tm_min + min << endl;
            }
            else if (input[0] == '2')
            {

                input = "shutdown -r -t " + to_string(result);
                const char *a = input.c_str();
                system(a);
                cout << "\n System will restart at " << now->tm_hour + hour - 24 << ":" << now->tm_min + min << endl;
            }
            else
                cout << "\nWrong input!";

            result = 0;
            hour = 0;
            min = 0;
            break;
        case '3':

            system("shutdown -a");
            cout << "\nDone!\n";
            break;

        case 's':
            check = false;
            break;

        default:
            cout << "\nWrong input!!\n";
        }
    }

    return 0;
}
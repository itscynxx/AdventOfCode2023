#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// There are 1,000 lines in the file provided in the day 1 puzzle 1 input, so this array is 1,000 long
int numberList[1000];

int lineCount = 0;
int slot = 0;
int total = 0;

// returns the next empty slot of the list of numbers
int NextAvailableSlot()
{
    for (int i = 0; i < sizeof(numberList); i++)
    {
        if (numberList[i] == 0)
        {
            return i;
        }
        else continue;
    }

    return 0;
}

void CheckText(string data)
{
    slot = NextAvailableSlot();
    string TempString;
    const char* str = data.c_str();
    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) {
            TempString += str[i];
        }
    }

    if (TempString.length() == 1) {
        TempString += TempString[0];
        CheckText(TempString);
    }

    else if (TempString.length() > 2) {
        TempString.erase(1, 1);
        cout << "Temp string is " << TempString << endl;
        CheckText(TempString);
    }

    else {
        numberList[slot] = stoi(TempString);
    }
}

void AddNumbers()
{
    // for some reason, using 'sizeof(numberList)' for the number resulted in 3 additional entires?
    // probably user error, manually defined to "fix"
    for (int i = 0; i < 1000; i++)
    {
        if (numberList[i] == 0) break;
        
        else {
            int num = numberList[i];
            cout << "num" << i << " is " << numberList[i] << endl;
            total += num;
        }
    }

    cout << endl << "The total is " << total << "." << endl;
}

int main()
{
    fstream InputFile;

    InputFile.open("input.txt", ios::in);

    while (InputFile.is_open())
    {
        string data;
        while(getline(InputFile, data)) 
        {
            lineCount++;
            CheckText(data);
        }
        InputFile.close();
    }

    AddNumbers();

    return 0;
}
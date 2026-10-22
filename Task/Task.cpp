
#define TERMCOLOR_USE_ANSI_ESCAPE_SEQUENCES
#include <iostream>
#include <cmath>
#include <windows.h>
#include "termcolor.hpp"
#include <conio.h>
#include <string>
#include <fstream> 
using namespace std;
using namespace termcolor;

string previous_results = "";
bool has_data = false;



int Menu()
{
    char choice = 0;
    system("cls");
    cout << "===================================================" << endl;
    cout << "                                                   " << endl;
    cout << green << "           Formula calculation program          " << reset << endl;
    cout << "                                                   " << endl;
    cout << "===================================================" << endl;
    cout << "                                                   " << endl;
    cout << "                                                   " << endl;
    cout << "        Welcome to the formula calculating         " << endl;
    cout << "                     program.                      " << endl;
    cout << "                                                   " << endl;
    cout << "        Press 1 to go to the Main menu             " << endl;
    cout << "                                                   " << endl;
    cout << "     *Read `Help` before starting the program*     " << endl;
    cout << "                                                   " << endl;
    cout << "===================================================" << endl;
	cin >> choice;
    if (choice != '1')
    {
        cout << "Invalid input. Please try again." << endl;
        system("pause");
        return Menu();
    }
    return 1;
}

int MainMenu()
{
        char choice = 0;
        system("cls");
        cout << "===================================================" << endl;
        cout << "                                                   " << endl;
        cout << green << "                     Main menu          " << reset << endl;
        cout << "                                                   " << endl;
        cout << "===================================================" << endl;
        cout << "                                                   " << endl;
        cout << "                                                   " << endl;
        cout << "            1. Run calculations                    " << endl;
        cout << "                                                   " << endl;
        cout << "            2. Management of data                  " << endl;
        cout << "                                                   " << endl;
        cout << "            3. Help                                " << endl;
        cout << "                                                   " << endl;
        cout << "            4. Exit the program                    " << endl;
        cout << "                                                   " << endl;
        cout << "===================================================" << endl;
        cout << "                                                   " << endl;
        cout << "            select an option: ";
        cin >> choice;

        if (choice < '1' || choice > '4')
        {
            cout << "Invalid input. Please try again." << endl;
            system("pause");
            return MainMenu();
        }

        return choice - '0';
}

int CalculationsMenu()
{
    char choice = 0;
    system("cls");
    cout << "===================================================" << endl;
    cout << "                                                   " << endl;
    cout << green << "               Run calculations          " << reset << endl;
    cout << "                                                   " << endl;
    cout << "===================================================" << endl;
    cout << "                                                   " << endl;
    cout << "                                                   " << endl;
    cout << "            1. Input from a file                    " << endl;
    cout << "                                                   " << endl;
    cout << "            2. Input from a keyboard               " << endl;
    cout << "                                                   " << endl;
    cout << "                                                   " << endl;
    cout << "      ---------------------------------            " << endl;
    cout << "                                                   " << endl;
    cout << "     press 3 to return to the Main menu            " << endl;
    cout << "                                                   " << endl;
    cout << "===================================================" << endl;
    cout << "                                                   " << endl;
    cout << "            select an option : ";
    cin >> choice;

    if (choice == '3')
    {
        return '3';
    }

    if (choice < '1' || choice > '2')
    {
        cout << "Invalid choice. Please try again." << endl;
        system("pause");
        return CalculationsMenu();
    }
 return choice;
}

char askToSaveFile() 
{
    if (previous_results == "")
    {
        return 0;
    }
    cout << endl;
    cout << endl;
    cout << "       Do you want to save the result in a file?" << endl << endl;
    cout << endl;
    cout << "                     1. Yes" << endl;
    cout << "                     2. No" << endl;
	cout << endl;
    cout << "-------------------------------------------------" << endl;
    cout << endl;
    cout << "       Press 3 to return to the Main menu" << endl;
    cout << endl;
    cout << "=================================================" << endl;
    cout << endl;
    cout << "              select an option: ";

    char choice;
    cin >> choice;
    
    if (choice == '1')
    {
        system("cls");
        string outFileName = "results.txt";
        ofstream outFile(outFileName);
        if (outFile.is_open())
        {
            outFile << previous_results;
            outFile.close();

            cout << "==========================================" << endl << endl;
            cout << cyan << "File \"" << outFileName << "\" saved successfully!"<< reset << endl<<endl;
            cout << "------------------------------------------" << endl;
            cout << endl;
            cout << "Press any key to return to the previous menu..." << endl;
            cout << endl;
            cout << "==========================================" << endl;
            system("pause > nul");
        }
        else
        {
            cout << endl;
            cout << "Error: Could not save the file!" << endl;
            cout << endl;
        }
    }
    else if (choice == '2') 
    {
        return '2';
    }
    else if (choice == '3') 
    {
        system("cls");
 
        return '3';
    }
    return 0;
}


char runFileCalculations() 
{
    previous_results = "";
    has_data = true;
    system("cls");
    cout << "===================================================" << endl;
    cout << endl;
    cout << "       Select a file from your device" << endl;
    cout << "      (supported formats .txt, .csv, .xlsx)" << endl;
    cout << endl;
    cout << "---------------------------------------------------" << endl;
    cout << endl;
    cout << "    Press q to return to the previous menu    " << endl;
    cout << endl;
    cout << "---------------------------------------------------" << endl<< endl;
    cout << "    Press 3 to return to the Main menu" << endl<< endl;
    cout << "===================================================" << endl<< endl;
    cout << "    Enter file name (e.g. data.txt) or other option: ";

    string filename;
    cin >> filename;

    if (filename == "3") 
    {
        return '3';
    }
    if (filename == "q" || filename == "Q")
    {
        return 'q';
    }

    ifstream file(filename);
    if (!file.is_open()) 
    {
		cout << endl;
        cout << red << "Error: Could not open file! File might not exist." << reset << endl;
        system("pause");
        return runFileCalculations(); 
    }

    unsigned int n;
    float a, b, x, h;

    if (!(file >> n))
    {
        cout << endl << red << "Error in file: Invalid 'n' parameter! (Must be an integer >= 7, no letters/symbols)" << reset << endl;
        file.close(); system("pause");
        return 0;
    }
    if (n < 7)
    {
        cout << endl << red << "Error in file: 'n' parameter must be >= 7 (Got: " << n << ")" << reset << endl;
        file.close(); system("pause");
        return 0;
    }
    if (!(file >> h))
    {
        cout << endl << red << "Error in file: Invalid 'h' step! (Must be a number > 0, no letters/symbols)" << reset << endl;
        file.close(); system("pause");
        return 0;
    }
    if (h <= 0)
    {
        cout << endl << red << "Error in file: 'h' step must be > 0 (Got: " << h << ")" << reset << endl;
        file.close(); system("pause");
        return 0;
    }
    if (!(file >> a))
    {
        cout << endl << red << "Error in file: Invalid 'a' lower bound! (Must be a number, no letters/symbols)" << reset << endl;
        file.close(); system("pause");
        return 0;
    }
    if (!(file >> b))
    {
        cout << endl << red << "Error in file: Invalid 'b' upper bound! (Must be a number, no letters/symbols)" << reset << endl;
        file.close(); system("pause");
        return 0;
    }
    if (a > b)
    {
        cout << endl << red << "Error in file: Lower bound 'a' cannot be greater than upper bound 'b' (a <= b)" << reset << endl;
        file.close(); system("pause");
        return 0;
    }
 
    file.close(); 

    system("cls");
    cout << "====================================================" << endl << endl;
    cout << cyan << "File \"" << filename << "\" added successfully!" << reset<< endl<< endl;
    cout << "Processing the data..." << endl << endl;
    cout << "----------------------------------------------------" << endl;
    cout << endl << endl << endl;
    cout << "Results for data from " << filename << ":" << endl << endl;

    for (x = a; x <= b; x += h)
    {
        float y = 0.0;
        float product = 1.0;
        if (x < 0) {
            for (int i = 4; i <= (int)n - 3; i++) { product *= (i + x); }
            y = 13 - product;
        }
        else {
            for (int j = 1; j <= n; j++) {
                float sum = 0.0;
                for (int i = 1; i <= (int)n + 3; i++) {
                    sum += pow(i, 2) * (j + (2 - x) / (i + 4));
                }
                product *= sum;
            }
            y = product;
        }
        cout << "x = " << x << "  |  y = " << y << endl;
        previous_results += "x = " + to_string(x) + "  |  y = " + to_string(y) + "\n";

    }
   return askToSaveFile();
}


int DataMenu()
{
    char choice = 0;
    system("cls");
    cout << "===================================================" << endl;
    cout << "                                                   " << endl;
    cout << green << "              Management of data             " << reset << endl;
    cout << "                                                   " << endl;
    cout << "===================================================" << endl;
    cout << "                                                   " << endl;
    cout << "                                                   " << endl;
    cout << "         1. Show the previous result               " << endl;
    cout << "                                                   " << endl;
    cout << "         2. Clear previous data                    " << endl;
    cout << "                                                   " << endl;
    cout << "                                                   " << endl;
    cout << "      ---------------------------------            " << endl;
    cout << "                                                   " << endl;
    cout << "     press 3 to return to the Main menu            " << endl;
    cout << "                                                   " << endl;
    cout << "===================================================" << endl;
    cout << "                                                   " << endl;
    cout << "            select an option : ";

    cin >> choice;

    if (choice == '1' || choice == '2' || choice == '3')
    {
        return choice - '0';
    }
    else
    {
        cout << "Invalid choice. Please try again." << endl;
        system("pause");
        return DataMenu();
    }
}
   

int clearData() 
{
    system("cls");
    cout << "=======================================" << endl;
    cout << endl;
    cout << "Are you sure you want to clear the data?" << endl;
    cout << endl;
    cout << red << "!Warning: This action will delete your"<< endl << "    results permanently!" << reset << endl;
    cout << endl;
    cout << "              1. Yes" << endl;
    cout << "              2. No" << endl;
	cout << endl;
    cout << "=======================================" << endl;
    cout << endl;
    cout << "          select an option: ";
   
    char choice;
    cin >> choice;
    if (choice == '1')
    {
        system("cls");
        cout << "-----------------------------------" << endl;
        cout << endl;
        cout << "      Deleting the data..." << endl;
        cout << endl;

        previous_results = "";
        has_data = false;

        cout << cyan << "     Data cleared successfully!" << endl << reset;   
    }
    else if (choice == '2')
    {
        return 0;
    }
    else 
    {
        cout << "Invalid input. Please try again." << endl;
        system("pause");
        return clearData();
    }
    cout << "-----------------------------------" << endl;
    cout << endl;
    cout << "      Press any key to return..." << endl;
    cout << endl;
    cout << "=======================================" << endl;
    system("pause > nul");
	return 0;
}

int HelpMenu()
{
    char choice = 0;
    system("cls");
    cout << "========================================================================" << endl;
    cout << "                                                            " << endl;
    cout << green << "                                   Help                             " << reset << endl;
    cout << "                                                            " << endl;
    cout << "========================================================================" << endl;
    cout << "PURPOSE OF THE PROGRAM:                                     " << endl;
    cout << "   This program is designed to calculate the values of a    " << endl;
    cout << "   function according to formulae for a given range of data." << endl;
    cout << endl;
    cout << "1. DATA INPUT OPTIONS:                                      " << endl;
    cout << "   - keyboard                                               " << endl;
    cout << "   - file                                                   " << endl;
    cout << endl;
    cout << "2. DATA MANAGEMENT OPTIONS:                                 " << endl;
    cout << "   - View: See the calculated results directly on the screen" << endl;
    cout << "   - Save: Store your results into an output file           " << endl;
    cout << "   - Delete: Clear previous calculation data                " << endl;
    cout << endl;
    cout << "MATHEMATICAL FORMULAE:                                      " << endl;
    cout << "   Depending on 'x' value, the program uses two variants:   " << endl;
    cout << endl;
    cout << "   1) If x < 0:" << endl;
    cout << "      Math form: y = 13 - P_{i=4}^{n-3} (i + x)             " << endl;
    cout << endl;
    cout << "   2) If x >= 0:" << endl;
    cout << "      y = P_{j=1}^{n} [ S_{i=1}^{n+3} (i^2 * (j + (2 - x) / (i + 4))) ]" << endl;
    cout << "=======================================================================" << endl;
    cout << endl;
    cout << "         press 3 to return to the Main menu                  " << endl;

    cin >> choice;
   if (choice == '3')
    {
        return '3';
    }
 return 0;
}

int ExitMenu()
{
    char choice = 0;
    system("cls");
    cout << "=======================================" << endl;
    cout << endl;
    cout << "     Are you sure you want to exit?    " << endl;
    cout << endl;
    cout << "         1. Yes (1)" << endl;
    cout << "         2. No (2)" << endl;
	cout << endl;
    cout << "---------------------------------------" << endl;
    cout << endl;
    cout << "Press 3 to return to the Main menu     " << endl;
    cout << endl;
    cout << "=======================================" << endl;
    cout << endl;
    cout << "      select an option:";

    cin >> choice;

    if (choice == '1')
    {
        system("cls");
        cout << endl;
		cout << "-----------------------------------" << endl;
		cout << endl;
        cout << "     Exiting the program..." << endl << endl;
		cout << "-----------------------------------" << endl;
        return 1;
    }
    if (choice == '2')
    {
        return 0;
    }
        
    if (choice == '3')
    {
       return 0;
    }
    cout << "Invalid input. Please try again." << endl;
    system("pause");
    return ExitMenu();
}
char runCalculations()
{
    previous_results = "";
    char choice = 0;
    has_data = true;
    system("cls");
    unsigned int n;
    float a, b, x, h;
    cout << endl;
    cout << cyan << "                                  MATHEMATICAL FORMULAE                       " << reset << endl;
    cout << endl;
    cout << endl;
    cout << "   Depending on 'x' value, the program uses two variants:   " << endl;
    cout << endl;
    cout << "   1) If x < 0:" << endl;
    cout << "      Math form: y = 13 - P_{i=4}^{n-3} (i + x)             " << endl;
    cout << endl;
    cout << "   2) If x >= 0:" << endl;
    cout << "      y = P_{j=1}^{n} [ S_{i=1}^{n+3} (i^2 * (j + (2 - x) / (i + 4))) ]" << endl;
    cout << endl;
	cout <<         "-----------------------------------------------------------------------" << endl;
	cout << endl;
    cout << "                   Press q to return to the previous menu    " << endl;
    cout << endl;
    cout << endl << "-----------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "                   Press 3 to return to the Main menu        " << endl;
    cout << endl;
    cout << endl << "-----------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "                   Press any key to start calculations    " << endl;
    cout << endl;
    cout << endl << "-----------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "select an option:";
    cin >> choice;
    cout << endl;

	
    if (choice == '3')
    {
        return '3';
    }
	else if (choice == 'q'||choice == 'Q')
	{
		return 'q';
	}
    else
    {
        system("pause > nul");
    }
    cout << "=======================================================================" << endl;

    do
    {
        cout << endl;
        cout << "Input n - parameter (n>=7): ";
        cin >> n;
        if (cin.fail())
        {
            cin.clear(); 
            cin.ignore(10000, '\n');
            cout << red << "Error: Please enter a valid number!" << reset << endl;
            n = 0; 
        }
    } while (n < 7);
    do
    {
        cout << "Input h - step (h>0): ";
        cin >> h;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << red << "Error: Please enter a valid number!" << reset << endl;
            h = 0.0f;
        }
    } while (h <= 0);
    do
    {
        cout << "Input a - lower bound of the interval: ";
        cin >> a;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << red << "Error: Invalid input for 'a'!" << reset << endl;
            a = 1; b = 0;
            continue;
        }
        cout << "Input b - upper bound of the interval(a <= b): ";
        cin >> b;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << red << "Error: Invalid input for 'b'!" << reset << endl;
            a = 1; b = 0;
            continue;
        }
        cout << endl;
    } while (a > b);
    cout << "=======================================================================" << endl;
    for (x = a; x <= b; x += h)
    {
        float y = 0.0;
        float product = 1.0;
        if (x < 0)
        {
            for (int i = 4; i <= n - 3; i++)
            {
                product *= (i + x);
            }
            y = 13 - product;
        }
        else
        {
            for (int j = 1; j <= n; j++)
            {
                float sum = 0.0;
                for (int i = 1; i <= n + 3; i++)
                {
                    sum += pow(i, 2) * (j + (2 - x) / (i + 4));
                }
                product *= sum;
            }
            y = product;
        }
        cout << endl << "x= " << x << "\ny= " << y << endl;
        previous_results += "x = " + to_string(x) + "  |  y = " + to_string(y) + "\n";
    }
    return askToSaveFile(); 
}

int main()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    Menu();
    bool running = true;
    while (running)
    {
        switch (MainMenu())
        {
        case 1:
            while (true)
            {
                char calc = CalculationsMenu();
                if (calc == '3')
                {
                    break;
                }
                if (calc == '1')
                {
                    char result = runFileCalculations();
                    if (result == '3')
                    {
                        break;
                    }
                    if (result == 'q' || result == 'Q')
                    {
                        continue;
                    }
                }
                else if (calc == '2')
                {
                    char result = runCalculations();
                    if (result == '3')
                    {
                        break;
                    }
                    if (result == 'q' || result == 'Q')
                    {
                        continue;
                    }
                   
                }
            }
            break;
        case 2:
            while (true)
            {
                int dataman = DataMenu();
                if (dataman == 3)
                {
                    break;
                }
                if (dataman == 1)
                {
                    system("cls");
                    cout << "================================================" << endl;
                    cout << endl;
                    if (!has_data || previous_results == "")
                    {
                        cout << "No previous data found. Run calculations first!" << endl;
                        cout << endl;
                        cout << "------------------------------------------------" << endl;
                        cout << endl;
                        cout << "Press any key to return...";
                        system("pause > nul");
                    }
                    else
                    {
                        cout << previous_results;
                        char result = askToSaveFile();
                        if (result == '3')
                        {
                            break;
                        }
                    }
                }
                else if (dataman == 2)
                {
                     clearData();
				}
            }
            break;
        case 3:
            HelpMenu();
            break;
        case 4:
            if (ExitMenu() == 1)
            {
                running = false;
            }
            break;

        }
       
    }
    return 0;
}
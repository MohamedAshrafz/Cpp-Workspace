#include <iostream>

using namespace std;

int main()
{
    while (true) {

        cout << "Enter the number of cents you want to convert: ";

        int num_cents{}, balance{}, dollars{}, quarters{}, dimes{}, nickels{}, pennies{};
        cin >> num_cents;

        
        dollars = num_cents/100;
        balance = num_cents % 100;

        
        quarters = balance / 25;
        balance %= 25;

      
        dimes = balance / 10;
        balance %= 10;

 
        nickels = balance / 5;
        balance %= 5;

        pennies = balance;

        cout << "dollars= " << dollars << endl
            << "quarters= " << quarters << endl
            << "dimes= " << dimes << endl
            << "nickels= " << nickels << endl
            << "pennies= " << pennies << endl;
    }

    return 0;
}


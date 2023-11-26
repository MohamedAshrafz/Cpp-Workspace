#include <iostream>
using namespace std;

int main()
{
    while (true) {
        cout << "Enter the number of cents you want to convert: ";
        int num_cents{};
        cin >> num_cents;

        int dollars{};
        dollars = num_cents / 100;
        num_cents -= (dollars * 100);

        int quarters{};
        quarters = (num_cents / 25);
        num_cents -= (quarters * 25);

        int dimes{};
        dimes = (num_cents / 10);
        num_cents -= (dimes * 10);

        int nickels{};
        nickels = (num_cents / 5);
        num_cents -= (nickels * 5);

        int pennies = num_cents;

        cout << "dollars= " << dollars << endl
            << "quarters= " << quarters << endl
            << "dimes= " << dimes << endl
            << "nickels= " << nickels << endl
            << "pennies= " << pennies<<endl;
    }
    return 0;
}


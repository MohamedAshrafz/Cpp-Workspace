#include <iostream>
#include <vector>
using namespace std;

int main()
{

	vector<int> nums{};

	char selection{};


	do {
		cout << "P - Print numbers" << endl
			<< "A - Add number" << endl
			<< "M - for the mean value of the numbers" << endl
			<< "S - for the smallest number" << endl
			<< "L - for the largest number" << endl
			<< "C - To clear the list" << endl
			<< "Q - Quit" << endl;
		cin >> selection;

		switch (selection) {

		case 'P':
		case 'p': {
			if (nums.size() == 0)
				cout << "[] - The list is empty";
			else {
				cout << "[ ";
				for (auto num : nums)
					cout << num << ' ';
				cout << ']';
			}
			break;

		}
		case 'A':
		case 'a': {
			int num_added{};
			bool check{ false };

			while (true) {
				cout << "The number is? ";
				cin >> num_added;
				//chech duplication
				for (unsigned int i{}; i < nums.size(); i++) {
					check = (num_added == nums.at(i));
					if (check == 1)
						break;
				}
				if (check == 0) {
					nums.push_back(num_added);
					cout << num_added << " was added";
					break;
				}
				else
					cout << "duplicate entries aren't allowed - try another number" << endl;
			}
			break;
		}
		case 'M':
		case'm': {
			if (nums.size() == 0)
				cout << "Can't be calculated - The list is empty";
			else {
				double mean_value{};
				int total{};

				for (auto num : nums) {
					total += num;
				}
				mean_value = (double)total / nums.size();
				cout << "The mean value is: " << mean_value;
			}
			break;
		}
		case'S':
		case's': {
			if (nums.size() == 0)
				cout << "The list is empty";
			else {
				int smallest_num{};
				bool check{ false };
				for (size_t i{}; i < nums.size(); i++) {
					for (size_t k{}; k < nums.size(); k++) {
						check = nums.at(i) <= nums.at(k);
						if (check == 0)
							break; //if the value of check is false at anytime get out of the loop
					}
					if (check == 1) { // if you get only "one" true final value of the check condition that's enough
						smallest_num = nums.at(i);
						break;
					}
				}
				cout << "The smallest number is: " << smallest_num << endl;
			}
			break;
		}
		case'L':
		case'l': {
			if (nums.size() == 0)
				cout << "The list is empty";
			else {
				int largest_num{};
				bool check{ false };
				for (size_t i{}; i < nums.size(); i++) {
					for (size_t k{}; k < nums.size(); k++) {
						check = nums.at(i) >= nums.at(k);
						if (check == 0)
							break; //if the value of check is false at anytime get out of the loop
					}
					if (check == 1) { // if you get only "one" true final value of the check condition that's enough
						largest_num = nums.at(i);
						break;
					}
				}
				cout << "The largest number is: " << largest_num << endl;
			}
			break;
		}
		case'C':
		case'c': {
			nums.clear();
			cout << "The list is cleared";
			break;
		}
		case 'Q':
		case 'q': {
			break;
		}
		default:
			cout << "Illegal entry";
			break;
		}
		cout << endl << endl;
	} while (selection != 'q' && selection != 'Q');
}
#include <iostream>
#include <vector>

using namespace std;

void menu(char& selection);
void print(const vector<int>&);
void add_nums(vector<int>&);
void mean(const vector<int>&);
void largest_num(const vector<int>&);
void smallest_num(const vector<int>&);
void handle_find(const vector<int>&);
bool find_num(const vector<int>&, int);
void clear_func(vector<int>&);

int main()
{
	vector<int> nums{};
	char selection{};

	do {
		menu(selection);
		
		switch (selection) {

		case'p': {
			print(nums);
			break;
		}
		case'a': {
			add_nums(nums);
			break;
		}
		case'm': {
			mean(nums);
			break;
		}
		case's': {
			smallest_num(nums);
			break;
		}
		case'l': {
			largest_num(nums);
			break;
		}
		case'c': {
			clear_func(nums);
			break;
		}
		case'f': {
			handle_find(nums);
			break;
		}
		case'q': {
			break;
		}
		default:
			cout << "Illegal entry";
			break;
		}
		cout << endl << endl;
	} while (selection != 'q');
}

void menu(char& selection) {
	cout << "P - Print numbers" << endl
		<< "A - Add number" << endl
		<< "M - for the mean value of the numbers" << endl
		<< "S - for the smallest number" << endl
		<< "L - for the largest number" << endl
		<< "F - to find a number in the list" << endl
		<< "C - To clear the list" << endl
		<< "Q - Quit" << endl;
	cin >> selection;
	selection = tolower(selection);
}

void print(const vector<int>& nums) {

	if (nums.size() == 0)
		cout << "[] - The list is empty";
	else {
		cout << "[ ";
		for (auto num : nums)
			cout << num << ' ';
		cout << ']';
	}
}

void add_nums(vector<int>& nums) {

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
}

void mean(const vector<int>& nums) {

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
}

void smallest_num(const vector<int>& nums) {

	if (nums.size() == 0)
		cout << "The list is empty";
	else {
		int smallest_num{};
		bool check{ false };
		for (unsigned int i{}; i < nums.size(); i++) {
			for (unsigned int k{}; k < nums.size(); k++) {
				if (k == 0) { //first 
					check = nums.at(i) <= nums.at(k);
					if (check == 0)
						break; //the final value can't be true if any false accured
				}
				else if (k != i) {
					check = check && (nums.at(i) <= nums.at(k));
					if (check == 0)
						break; //if the value of check is false at anytime get out of the loop
				}
			}
			if (check == 1) { // if you get only "one" true final value of the check condition that's enough
				smallest_num = nums.at(i);
				break;
			}
		}
		cout << "The smallest number is: " << smallest_num ;
	}
}

void largest_num(const vector<int>& nums) {

	if (nums.size() == 0)
		cout << "The list is empty";
	else {
		int largest_num{};
		bool check{ false };
		for (unsigned int i{}; i < nums.size(); i++) {
			for (unsigned int k{}; k < nums.size(); k++) {
				if (k == 0) {
					check = nums.at(i) >= nums.at(k);
					if (check == 0)
						break; //if the value of check is false at anytime get out of the loop
				}
				else if (k != i) {
					check = check && (nums.at(i) >= nums.at(k));
					if (check == 0)
						break; //if the value of check is false at anytime get out of the loop
				}
			}
			if (check == 1) { // if you get only "one" true final value of the check condition that's enough
				largest_num = nums.at(i);
				break;
			}
		}
		cout << "The largest number is: " << largest_num ;
	}
}

void handle_find(const vector<int>& nums) {
	int num_find;
	cout << "the number to find is? ";
	cin >> num_find;
	if (find_num(nums, num_find))
		cout << "the number is in the list";
	else
		cout << "the number is't in the list";
}

bool find_num(const vector<int>& nums, int num_find) {
	bool check{};
	for (auto num : nums) {
		if (num == num_find) {
			check = true;
			break;
		}
	}
	return check;
}

void clear_func(vector<int>& nums) {

	nums.clear();
	cout << "The list is cleared";
}
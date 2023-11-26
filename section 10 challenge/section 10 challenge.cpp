#include<iostream>
#include<string>
using namespace std;

int main() {

	const string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	const string key{ "XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr" };

	string s1{}, s2{};

	


	while (true) {

		cout << "Enter your message: ";
		getline(cin, s1);
		s2.resize(s1.size());

		for (size_t i{}; i < s1.size(); i++) {
			if (isalpha(s1.at(i))) {
				for (size_t k{}; k < alphabet.size(); k++) {
					if (s1.at(i) == alphabet.at(k)) {
						s2.at(i) = key.at(k);
							break;
					}
				}
			}
			else
				s2.at(i) = s1.at(i);

		}
		cout << "encrypted message: " << s2 << endl;
		cout << "decrypted message: " << s1 << endl<< endl;
	}

	return 0;
}
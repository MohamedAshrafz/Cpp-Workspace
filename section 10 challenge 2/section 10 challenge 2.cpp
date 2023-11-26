#include<iostream>
#include<string>
using namespace std;

int main() {

	const string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	const string key{ "XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr" };

	string input_str{}, encrypted_str{}, decrypted_str{};
	char n{};
	do {
		cout << "Enter your massage: ";
		getline(cin, input_str);

		encrypted_str.resize(input_str.size());
		decrypted_str.resize(input_str.size());
		if(input_str!="exit") {
			for (size_t i{}; i < input_str.size(); i++) {
				if (isalpha(input_str.at(i))) {
					size_t pos = alphabet.find(input_str.at(i));    //position in the key for corresponding alphabet position
					char new_char = key.at(pos);
					encrypted_str.replace(i, 1, 1, new_char);
				}
				else
					encrypted_str.at(i) = input_str.at(i);
			}
			cout << "encrypted massage: " << encrypted_str << endl;
			for (size_t i{}; i < encrypted_str.size(); i++) {
				if (isalpha(encrypted_str.at(i))) {
					size_t pos = key.find(encrypted_str.at(i)); //position in the key for corresponding alphabet position
					char new_char = alphabet.at(pos);
					decrypted_str.replace(i, 1, 1, new_char);
				}
				else
					decrypted_str.at(i) = encrypted_str.at(i);
			}
			cout << "decrypted massage: " << decrypted_str << endl << endl;
		}
	} while (input_str != "exit");
	

	
	return 0;
}
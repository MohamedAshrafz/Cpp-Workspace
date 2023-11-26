//// Online C++ compiler to run C++ program online
//#include <iostream>
//#include <string>
//#include <fstream>
//#include <cstring>
//#include <cstdint>
//#include <sstream>  
//#include <vector>
//using namespace std;
//
//#pragma warning(disable : 4996)
//
//typedef unsigned long long u64;
//typedef unsigned long u32;
//
//// Tables
//int premutation_choice1_table[56] = {
//	57, 49, 41, 33, 25, 17, 9,
//	1, 58, 50, 42, 34, 26, 18,
//	10, 2, 59, 51, 43, 35, 27,
//	19, 11, 3, 60, 52, 44, 36,
//	63, 55, 47, 39, 31, 23, 15,
//	7, 62, 54, 46, 38, 30, 22,
//	14, 6, 61, 53, 45, 37, 29,
//	21, 13, 5, 28, 20, 12, 4 };
//
//int premutation_choice2_table[48] = {
//	14, 17, 11, 24, 1, 5,
//	3, 28, 15, 6, 21, 10,
//	23, 19, 12, 4, 26, 8,
//	16, 7, 27, 20, 13, 2,
//	41, 52, 31, 37, 47, 55,
//	30, 40, 51, 45, 33, 48,
//	44, 49, 39, 56, 34, 53,
//	46, 42, 50, 36, 29, 32 };
//
//int initial_permutation_table[64] = {
//	58, 50, 42, 34, 26, 18, 10, 2,
//	60, 52, 44, 36, 28, 20, 12, 4,
//	62, 54, 46, 38, 30, 22, 14, 6,
//	64, 56, 48, 40, 32, 24, 16, 8,
//	57, 49, 41, 33, 25, 17, 9, 1,
//	59, 51, 43, 35, 27, 19, 11, 3,
//	61, 53, 45, 37, 29, 21, 13, 5,
//	63, 55, 47, 39, 31, 23, 15, 7 };
//
//int expansion_table[48] = {
//	32, 1, 2, 3, 4, 5, 4, 5,
//	6, 7, 8, 9, 8, 9, 10, 11,
//	12, 13, 12, 13, 14, 15, 16, 17,
//	16, 17, 18, 19, 20, 21, 20, 21,
//	22, 23, 24, 25, 24, 25, 26, 27,
//	28, 29, 28, 29, 30, 31, 32, 1 };
//
//int s_box[8][4][16] =
//{ {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
//  0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
//  4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
//  15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13},
// {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
//  3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
//  0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
//  13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9},
// {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
//  13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
//  13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
//  1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12},
// {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
//  13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
//  10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
//  3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14},
// {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
//  14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
//  4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
//  11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3},
// {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
//  10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
//  9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
//  4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13},
// {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
//  13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
//  1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
//  6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12},
// {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
//  1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
//  7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
//  2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11} };
//
//int permutation_table[32] = {
//	16, 7, 20, 21, 29, 12, 28, 17,
//	1, 15, 23, 26, 5, 18, 31, 10,
//	2, 8, 24, 14, 32, 27, 3, 9,
//	19, 13, 30, 6, 22, 11, 4, 25 };
//
//int inverse_permutation_table[64] = {
//	40, 8, 48, 16, 56, 24, 64, 32,
//	39, 7, 47, 15, 55, 23, 63, 31,
//	38, 6, 46, 14, 54, 22, 62, 30,
//	37, 5, 45, 13, 53, 21, 61, 29,
//	36, 4, 44, 12, 52, 20, 60, 28,
//	35, 3, 43, 11, 51, 19, 59, 27,
//	34, 2, 42, 10, 50, 18, 58, 26,
//	33, 1, 41, 9, 49, 17, 57, 25 };
//
//
//u64 round_keys[16];
//
//// Plain to hex and vice verca
//string plain_to_hex(string plain)
//{
//	string s = "";
//	unsigned char x = 0;
//	unsigned char right_digit, left_digit;
//	for (int i = 0; i < plain.size(); i++)
//	{
//		x = plain[i];
//		left_digit = x / 16;
//		right_digit = x % 16;
//		switch (left_digit)
//		{
//		case 0:
//		{
//			s += '0';
//
//			break;
//		}
//		case 1:
//		{
//			s += '1';
//
//			break;
//		}
//		case 2:
//		{
//			s += '2';
//
//			break;
//		}
//		case 3:
//		{
//			s += '3';
//			break;
//		}
//		case 4:
//		{
//			s += '4';
//			break;
//		}
//		case 5:
//		{
//			s += '5';
//			break;
//		}
//		case 6:
//		{
//			s += '6';
//			break;
//		}
//		case 7:
//		{
//			s += '7';
//			break;
//		}
//		case 8:
//		{
//			s += '8';
//			break;
//		}
//		case 9:
//		{
//			s += '9';
//			break;
//		}
//		case 10:
//		{
//			s += 'A';
//			break;
//		}
//		case 11:
//		{
//			s += 'B';
//			break;
//		}
//		case 12:
//		{
//			s += 'C';
//			break;
//		}
//		case 13:
//		{
//			s += 'D';
//			break;
//		}
//		case 14:
//		{
//			s += 'E';
//			break;
//		}
//		case 15:
//		{
//			s += 'F';
//			break;
//		}
//
//		}
//		switch (right_digit)
//		{
//		case 0:
//		{
//			s += '0';
//
//			break;
//		}
//		case 1:
//		{
//			s += '1';
//
//			break;
//		}
//		case 2:
//		{
//			s += '2';
//
//			break;
//		}
//		case 3:
//		{
//			s += '3';
//			break;
//		}
//		case 4:
//		{
//			s += '4';
//			break;
//		}
//		case 5:
//		{
//			s += '5';
//			break;
//		}
//		case 6:
//		{
//			s += '6';
//			break;
//		}
//		case 7:
//		{
//			s += '7';
//			break;
//		}
//		case 8:
//		{
//			s += '8';
//			break;
//		}
//		case 9:
//		{
//			s += '9';
//			break;
//		}
//		case 10:
//		{
//			s += 'A';
//			break;
//		}
//		case 11:
//		{
//			s += 'B';
//			break;
//		}
//		case 12:
//		{
//			s += 'C';
//			break;
//		}
//		case 13:
//		{
//			s += 'D';
//			break;
//		}
//		case 14:
//		{
//			s += 'E';
//			break;
//		}
//		case 15:
//		{
//			s += 'F';
//			break;
//		}
//
//		}
//	}
//	return s;
//}
//string hex_to_plain(string hex)
//{
//	string plain = "";
//	unsigned char right_digit = '0', left_digit = '0', c = '0';
//	for (int i = 0; i < hex.size(); i++)
//	{
//		switch (hex[i])
//		{
//		case '0':
//		{
//			left_digit = 0;
//			break;
//		}
//		case '1':
//		{
//			left_digit = 1;
//			break;
//		}
//		case '2':
//		{
//			left_digit = 2;
//			break;
//		}
//		case '3':
//		{
//			left_digit = 3;
//			break;
//		}
//		case '4':
//		{
//			left_digit = 4;
//			break;
//		}
//		case '5':
//		{
//			left_digit = 5;
//			break;
//		}
//		case '6':
//		{
//			left_digit = 6;
//			break;
//		}
//		case '7':
//		{
//			left_digit = 7;
//			break;
//		}
//		case '8':
//		{
//			left_digit = 8;
//			break;
//		}
//		case '9':
//		{
//			left_digit = 9;
//			break;
//		}
//		case 'A':
//		case 'a':
//		{
//			left_digit = 10;
//			break;
//		}
//		case 'B':
//		case 'b':
//		{
//			left_digit = 11;
//			break;
//		}
//		case 'C':
//		case 'c':
//		{
//			left_digit = 12;
//			break;
//		}
//		case 'D':
//		case 'd':
//		{
//			left_digit = 13;
//			break;
//		}
//		case 'E':
//		case 'e':
//		{
//			left_digit = 14;
//			break;
//		}
//		case 'F':
//		case 'f':
//		{
//			left_digit = 15;
//			break;
//		}
//
//		}
//		switch (hex[++i])
//		{
//		case '0':
//		{
//			right_digit = 0;
//			break;
//		}
//		case '1':
//		{
//			right_digit = 1;
//			break;
//		}
//		case '2':
//		{
//			right_digit = 2;
//			break;
//		}
//		case '3':
//		{
//			right_digit = 3;
//			break;
//		}
//		case '4':
//		{
//			right_digit = 4;
//			break;
//		}
//		case '5':
//		{
//			right_digit = 5;
//			break;
//		}
//		case '6':
//		{
//			right_digit = 6;
//			break;
//		}
//		case '7':
//		{
//			right_digit = 7;
//			break;
//		}
//		case '8':
//		{
//			right_digit = 8;
//			break;
//		}
//		case '9':
//		{
//			right_digit = 9;
//			break;
//		}
//		case 'A':
//		case 'a':
//		{
//			right_digit = 10;
//			break;
//		}
//		case 'B':
//		case 'b':
//		{
//			right_digit = 11;
//			break;
//		}
//		case 'C':
//		case 'c':
//		{
//			right_digit = 12;
//			break;
//		}
//		case 'D':
//		case 'd':
//		{
//			right_digit = 13;
//			break;
//		}
//		case 'E':
//		case 'e':
//		{
//			right_digit = 14;
//			break;
//		}
//		case 'F':
//		case 'f':
//		{
//			right_digit = 15;
//			break;
//		}
//
//		}
//		c = left_digit * 16 + right_digit;
//		plain += c;
//	}
//	return plain;
//}
//
//
//// Utility Functions
//void Swap(u64& a, u64& b)
//{
//	u64 temp_A = a;
//	a = b;
//	b = temp_A;
//}
//
//// Function to do a Left circular shift by 1
//u32 left_circular_shift(u32 number, u32 times)
//{
//	return ((number << times) | (number >> (28 - times))) & 0x0FFFFFFF;
//}
//
//void generate_round_keys(u64 key)
//{
//	// applying Premutaion Choice 1 to generate the effective DES key
//	u64 Premutation_Choice1_Key = 0;
//	for (int i = 0; i < 56; i++)
//	{
//
//		Premutation_Choice1_Key |= (key >> (64 - premutation_choice1_table[56 - 1 - i]) & 1) << i;
//	}
//	//We divide the 56bit effective DES key into 28bits left and 28bits right
//	u32 left = u32((Premutation_Choice1_Key >> 28) & 0x0FFFFFFF);
//	u32 right = u32(Premutation_Choice1_Key & 0x0FFFFFFF);
//
//	//Then we make left circular shift to both left part and right part
//	for (int i = 0; i < 16; i++)
//	{
//		// For rounds number [1, 2, 9, 16] the shift bits is one.
//		if (i == 0 || i == 1 || i == 8 || i == 15)
//		{
//			// Shift Once
//			left = left_circular_shift(left, 1);
//			right = left_circular_shift(right, 1);
//		}
//		// For the rest rounds, the shift bits are two.
//		else
//		{
//			// Shift Twice
//			left = left_circular_shift(left, 2);
//			right = left_circular_shift(right, 2);
//		}
//
//		// Combining right and left
//		u64 combined_key = u64(u64(left) << 28 | u64(right));
//
//		/*We take this combined key "56bit output key of left circular shift" and apply
//		 Premutation_Choice2 on it to generate the round key*/
//		u64 Round_key = 0;
//		for (int j = 0; j < 48; j++)
//		{
//
//			Round_key |= (combined_key >> (56 - premutation_choice2_table[48 - 1 - j]) & 1) << j;
//
//		}
//		// Now the 48bit Round key is ready
//		round_keys[i] = Round_key;
//	}
//}
//
//// in Decryption, we reverse the key orders
//void Keys_reverse()
//{
//	// string round_keys[16];
//	u64 newKeys[16];
//	for (int i = 0; i < 16; i++)
//	{
//		newKeys[i] = round_keys[15 - i];
//	}
//
//	for (int i = 0; i < 16; i++)
//	{
//		round_keys[i] = newKeys[i];
//	}
//}
//
//u64 Apply_DES(u64 plainText, u64 key)
//{
//
//	// Apply initial permutation
//	u64 initial_permutation_output = 0;
//	for (int i = 0; i < 64; i++)
//	{
//		initial_permutation_output |= (plainText >> (64 - initial_permutation_table[64 - 1 - i]) & 1) << i;
//	}
//
//	// Then we divide it to 32bits in left and 32bits in right
//
//	u64 left = u64((initial_permutation_output >> 32) & 0xFFFFFFFF);
//	u64 right = u64(initial_permutation_output & 0xFFFFFFFF);
//
//
//	// We have 16 rounds
//	for (int i = 0; i < 16; i++)
//	{
//		// Applying Fiestel Function "Right-side part"
//
//		// Expansion
//		u64 right_expanded = 0;
//		for (int j = 0; j < 48; j++)
//		{
//			// right_expanded is 48 bits
//			right_expanded |= (right >> (32 - expansion_table[48 - 1 - j]) & 1) << j;
//		}
//
//		// XOR
//		u64 inner_XOR = (right_expanded ^ round_keys[i]);
//
//
//		// S-Box
//		u64 S_Box_Result = 0;
//		for (int j = 0; j < 8; j++)
//		{
//			// for each s-box
//
//			// Extracting needed 6 bits
//			u64 working_bits = (inner_XOR & (0xFC0000000000 >> (j * 6))) >> ((7 - j) * 6);
//
//			// Concatenating bits
//
//			u32 row_bits = working_bits & 0x21; // & 100001 to take row position
//			u32 first_bit = row_bits & 1; // holding first bit
//
//			u32 row = (row_bits >> 4) | first_bit;
//			u32 col = (working_bits & 0x1E) >> 1; // & 011110 to take col position
//
//
//
//			u32 val = s_box[j][row][col];
//
//			// emptying place for newcoming value
//			S_Box_Result = S_Box_Result << 4;
//
//			// appending new value
//			S_Box_Result |= val;
//		}
//
//		// Permutation
//		u64 permutated = 0;
//		for (int j = 0; j < 32; j++)
//		{
//			permutated |= (S_Box_Result >> (32 - permutation_table[32 - 1 - j]) & 1) << j;
//		}
//
//		// XOR with left to get new right
//		u64 outer_XOR = (permutated ^ left);
//
//
//		// Adjusting places
//		left = right;
//		right = outer_XOR;
//
//	}
//
//	// Apply 32bit Swap and combine
//
//	Swap(left, right);
//
//	u64 combined_text = u64((left << 32) | right);
//
//	// Finally Apply inverse initial permutation output 64
//	u64 Cipher = 0;
//	for (int i = 0; i < 64; i++)
//	{
//		Cipher |= (combined_text >> (64 - inverse_permutation_table[64 - 1 - i]) & 1) << i;
//	}
//
//	return Cipher;
//}
//u64 string_to_hex(char* buffer) {
//	u64 data = 0;
//	int i = 0;
//	u64 value;
//	for (i; i < 16; ++i) {
//		if (buffer[i] <= 57)
//		{
//			value = (buffer[i] - 48);
//			data |= (value << ((16 - i) * 4) - 4);
//		}
//		else if (buffer[i] <= 70)
//		{
//			value = (buffer[i] - 55);
//			data |= (value << ((16 - i) * 4) - 4);
//		}
//		else
//		{
//			value = (buffer[i] - 87);
//			data |= (value << ((16 - i) * 4) - 4);
//		}
//	}
//	return data;
//}
//
//u64 string_to_hex_for_one_char(char* buffer) {
//	u64 data = 0;
//	int i = 0;
//	u64 value;
//	for (i; i < 1; ++i) {
//		if (buffer[i] <= 57)
//		{
//			value = (buffer[i] - 48);
//			data |= (value << ((1 - i) * 4) - 4);
//		}
//		else if (buffer[i] <= 70)
//		{
//			value = (buffer[i] - 55);
//			data |= (value << ((1 - i) * 4) - 4);
//		}
//		else
//		{
//			value = (buffer[i] - 87);
//			data |= (value << ((1 - i) * 4) - 4);
//		}
//	}
//	return data;
//}
//
//u64 string_to_hex_8(char* buffer) {
//	u64 data = 0;
//	int i = 0;
//	u64 value;
//	for (i; i < 16; ++i) {
//		if (buffer[i] <= 57)
//		{
//			value = (buffer[i] - 48);
//			data |= (value << ((16 - i) * 4) - 4);
//		}
//		else if (buffer[i] <= 70)
//		{
//			value = (buffer[i] - 55);
//			data |= (value << ((16 - i) * 4) - 4);
//		}
//		else
//		{
//			value = (buffer[i] - 87);
//			data |= (value << ((16 - i) * 4) - 4);
//		}
//	}
//	return data;
//}
//
//
//string getFileText(string inputFileName)
//{
//
//	ifstream t(inputFileName.c_str());
//	string str((istreambuf_iterator<char>(t)),
//		istreambuf_iterator<char>());
//
//	//ifstream input(inputFileName.c_str(), ios::binary);
//
//	//// copies all data into buffer
//	//vector<unsigned char> buffer(std::istreambuf_iterator<char>(input), {});
//
//	/*string input = "";
//	char buffer;
//
//	ifstream inputFile;
//	inputFile.open(inputFileName.c_str());
//
//	if (!inputFile)
//	{
//		cout << "Bad file name. Please try again." << endl;
//	}
//
//	while (inputFile.get(buffer))
//		input = input + buffer;
//
//	inputFile.close();*/
//	t.close();
//
//	return str;
//}
//
//void writeToFile(string outputFileName, string text)
//{
//	ofstream output(outputFileName.c_str());
//
//
//	//ofstream outputFile;
//	//outputFile.open(outputFileName.c_str());
//
//	//if (!outputFile)
//	//{
//	//	cout << "Bad file name. Please try again." << endl;
//	//	//system.exit(0); // quit
//	//}
//
//
//	output << text; // write to file
//
//	output.close();
//
//	cout << "File write to " << outputFileName << " complete." << endl;
//
//	return;
//}
//
//string getFileText_key(string inputFileName)
//{
//
//	//ifstream input(inputFileName.c_str(), ios::binary);
//
//	//// copies all data into buffer
//	//vector<unsigned char> buffer(std::istreambuf_iterator<char>(input), {});
//
//	string input = "";
//	char buffer;
//
//	ifstream inputFile;
//	inputFile.open(inputFileName.c_str());
//
//	if (!inputFile)
//	{
//		cout << "Bad file name. Please try again." << endl;
//	}
//
//	while (inputFile.get(buffer))
//		input = input + buffer;
//
//	inputFile.close();
//
//	return input;
//}
//
//unsigned char* hex_to_char(u64 hexVal) {
//	unsigned char returnValLeft = hexVal & 0xffff0000;
//	unsigned char returnValRight = hexVal & 0x0000ffff;
//
//	unsigned char returnVal[] = { returnValLeft, returnValRight };
//
//	return returnVal;
//}
//
//
//int main(int argc, char** argv)
//{
//	int padding; // used to make the input string an even multiple of 8
//	int numrounds; // number of blocks will be needed to transform
//	string argsdebug[] = { "", "decrypt", "cc.text", "key.text", "pp.text" };
//	//string argsdebug [] = { "", "encrypt", "plain_text.text", "key.text", "cc.text" };
//	string str = "";
//	string str_ascii = "";
//	string operation = argsdebug[1];
//	string allinput = getFileText(argsdebug[2]);
//	//if (allinput.size() % 16 != 0)
//	//	padding = 16 - (allinput.size() % 16); // the amount of chars needed to be
//	//											 // divisible by 8.
//	//else
//	//	padding = 0; // the above formula will add 8 0's if its divisible by 8, not needed
//
//
//	//for (int i = 0; i < padding; i++)
//	//	allinput.push_back(0); // pad the string to make it an even multiple of 8
//
//
//	// key generation
//	char* char_array2 = new char[16];
//	string input_key = getFileText_key(argsdebug[3]);
//	//strcpy(char_array2, input_key.c_str());
//	u64 u64_key = string_to_hex(char_array2);
//
//	generate_round_keys(u64_key);
//
//
//	if (operation == "decrypt")
//	{
//		Keys_reverse();
//	}
//
//	stringstream stream;
//	numrounds = allinput.size();
//	//int n = input.length();
//	for (int i = 0; i < numrounds; i++) // start the transformation
//	{
//		// string input_ascii = allinput.substr(i * 16, 16); // get a 64-bit block into temp ascii
//
//		char* char_array = new char[16 + 1];
//
//		// strcpy(char_array, input_ascii.c_str());
//		*char_array = allinput[i];
//
//		u64 u64_data = string_to_hex_for_one_char(char_array);
//
//		u64 result = Apply_DES(u64_data, u64_key);
//
//		unsigned char* cs = hex_to_char(result);
//
//		// add long to the stream
//		// stream << hex << result;
//		// get string object from the stream
//		// string s = stream.str();
//		str += cs[0] + cs[1];
//		//cout<<"ascii"<<str_ascii<<endl;
//		//cout<<endl;                
//		// get string object from the stream
//	}
//	//str_ascii=convert_ascii("492b099be892ff76");
//	writeToFile(argsdebug[4], str);
//	// writetofile(argv[5], str_ascii);
//	// cout << hex << uppercase << str;
//	return 0;
//}
//
////int main(int argc, char** argv)
////{
////	int padding; // used to make the input string an even multiple of 8
////	int numRounds; // number of blocks will be needed to transform
////	// string argsdebug[] = { "", "decrypt", "cc.text", "key.text", "pp.text" };
////	// string argsdebug [] = { "", "encrypt", "plain_text.text", "key.text", "cc.text" };
////	string str = "";
////	string str_ASCII = "";
////	string operation = argv[1];
////	string allinput = getFileText(argv[2]);
////	//if (allinput.size() % 16 != 0)
////	//	padding = 16 - (allinput.size() % 16); // the amount of chars needed to be
////	//											 // divisible by 8.
////	//else
////	//	padding = 0; // the above formula will add 8 0's if its divisible by 8, not needed
////
////
////	//for (int i = 0; i < padding; i++)
////	//	allinput.push_back(0); // pad the string to make it an even multiple of 8
////
////
////	// key generation
////	char* char_array2 = new char[16];
////	string input_key = getFileText_key(argv[3]);
////	//strcpy(char_array2, input_key.c_str());
////	u64 u64_key = string_to_hex(char_array2);
////
////	generate_round_keys(u64_key);
////
////
////	if (operation == "decrypt")
////	{
////		Keys_reverse();
////	}
////
////	stringstream stream;
////	numRounds = allinput.size();
////	//int n = input.length();
////	for (int i = 0; i < numRounds; i++) // start the transformation
////	{
////		// string input_ASCII = allinput.substr(i * 16, 16); // get a 64-bit block into temp ASCII
////
////		char* char_array = new char[16 + 1];
////
////		// strcpy(char_array, input_ASCII.c_str());
////		*char_array = allinput[i];
////
////		u64 u64_data = string_to_hex(char_array);
////
////		u64 result = Apply_DES(u64_data, u64_key);
////
////		// Add long to the stream
////		stream << hex << result;
////		// Get string object from the stream
////		string s = stream.str();
////		str += s;
////		//cout<<"ASCII"<<str_ASCII<<endl;
////		//cout<<endl;                
////		// Get string object from the stream
////	}
////	//str_ASCII=convert_ASCII("492B099BE892FF76");
////	writeToFile(argv[4], str);
////	// writeToFile(argv[5], str_ASCII);
////	// cout << hex << uppercase << str;
////	return 0;
////}
//Sterling Gerard 
// April 10, 2022
// Write a program that reads the content of two text files 
// and compare them in the following ways:

#include<iostream>
#include<fstream>
#include<set>

using namespace std;

// print function
void print(set<string> text)
{
	set<string>::iterator it = text.begin();
	// loop that iterates
	while (it != text.end()) 
	{
		cout << *it;
		++it;
		if (it != text.end()) 
		{
			cout << " , ";
		}
	}
	cout << endl;
}

void printIntersection(set<string> text1, set<string> text2) {
			set<string> temp;
			set<string>::iterator it = text1.begin();
		// add element 
			while (it != text1.end()) {
				if (text2.find(*it) != text2.end()) {
					temp.insert(*it);
				}
				++it;
			}
			print(temp); // resultant set 
}

// print difference 
void printDifference(set<string> text1, set<string> text2)
{
	set<string> temp;
	set<string>::iterator it = text1.begin();
	while (it != text1.end())
	{
		if (text2.find(*it) == text2.end()) {
			temp.insert(*it);
		}
		++it;
	}
	print(temp);
}
//method to print display elements that exist in either the first or second set but not both
void printIfExistsInEitherFileNotBoth(set<string> text1, set<string> text2) {
			set<string> temp;
			set<string>::iterator it = text1.begin();
			while (it != text1.end()) {
				if (text2.find(*it) == text2.end()) {
					temp.insert(*it);
					}
				++it;
			}
			it = text2.begin();
			while (it != text2.end())
			{
				if (text1.find(*it) == text1.end()) 
				{
					temp.insert(*it);
				}
			}
			print(temp);
}

int main()
{

	// opening file1.txt 
	ifstream inFile1("file1.txt");
	if (!inFile1) {
				//failed to open
		cout << "file1.txt not found!" << endl;
		return 0;

	}
	ifstream inFile2("file2.txt");
	if (!inFile2) {
		cout << "file2.txt not found!" << endl;
		return 0;
	}
	set<string> file1Text;
	set<string> file2Text;
	string text;
	while (inFile1 >> text) {
		file1Text.insert(text);
	}
	inFile1.close();
	while (inFile2 >> text) {
		file2Text.insert(text);
	}
	inFile2.close();
	cout << "Unique words in first file: " << endl;
	print(file1Text);
	cout << "Unique words in second file: " << endl;
	print(file2Text);

	// display intersection
	cout << "Words appear in both files: " << endl;
	printIntersection(file1Text, file2Text);

	// display set1 - set2
	cout << "Words appear in the first file, not in the second: " << endl;
	printDifference(file1Text, file2Text);
	cout << "Words appear in the second file, not in the second: " << endl;
	printDifference(file2Text, file1Text);

	// display set1 union set2
	cout << "Words appear in either the first or second file but not both: " << endl;
	printIfExistsInEitherFileNotBoth(file1Text, file2Text);
	


	system("pause");
	return 0;
}
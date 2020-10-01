#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to find the length of Longest Palindromic Subsequence
// of substring X[i..j]
int longestPalindrome(string X, int i, int j)
{
	// base condition
	if (i > j)
		return 0;

	// if string X has only one character, it is palindrome
	if (i == j)
		return 1;

	// if last character of the string is same as the first character
	if (X[i] == X[j])
	{
		// include first and last characters in palindrome
		// and recur for the remaining substring X[i+1, j-1]
		return longestPalindrome(X, i + 1, j - 1) + 2;
	}

	// if last character of string is different to the first character

	// 1. Remove last character and recur for the remaining
	//	substring X[i, j-1]
	// 2. Remove first character and recur for the remaining
	//	substring X[i+1, j]

	// return maximum of the two values
	return max (longestPalindrome(X, i, j - 1),
				longestPalindrome(X, i + 1, j));
}

// Longest Palindromic Subsequence using Dynamic Programming
int main()
{
	string X = "ABBDCACB";
	int n = X.length();

	cout << "The length of Longest Palindromic Subsequence is "
			<< longestPalindrome(X, 0, n - 1);

	return 0;
}
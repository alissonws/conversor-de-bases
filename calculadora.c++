#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool is_binary(long long number)
// This function takes a long long integer and returns true if it's binary and false if it's not
{
    int remainder;

    while (number > 0)
    {
        remainder = number % 10;

        if ((remainder != 0) && (remainder != 1)) // Remainder of a binary number divided by 10 should always be 0 or 1
        {
            return false;
        }
        number = number / 10;

        if (number == 0)
        {
            return true;
        }
    }
    return true;
}

bool is_number(const string &str)
// This function acceps a string and loop for it checking if every char is a digit. Returns true if so
{
    for (char const &c : str)
    {
        if (isdigit(c) == 0)
            return false;
    }
    return true;
}

string ask_encode_type()
// This function prints user instructions for defining a conversion type and processes the input
// It returns the encode type if it's either 'e' or 'd' and returns 'wrong_param' otherwise 
{
    string encode_type;

    const string question = "\
Type 'd' if you want to decode a binary number into a decimal number\n\
Type 'e' if you want to encode a decimal number into a binary number\n\n\
So what will it be? (d/e) ";

    const string wrong_param = "\n\nSorry! Wrong parameter parsed. Try again.\n\n";

    cout << question;
    cin >> encode_type;

    if (encode_type == "e" || encode_type == "d")
    {
        return encode_type;
    }
    else
    {
        cout << wrong_param;

        return "wrong_param";
    }
}

string ask_input_number(string encode_type)
// This function prints user instructions for parsing a number to encode\decode and processes the input string
// It returns the number if the string represents a number and returns 'wrong_param' otherwise 
{
    string input_number;

    const string question = "Next, type a integer number to be processed... ";

    const string wrong_param = "\n\nSorry! Wrong parameter parsed. Try again.\n\n";

    cout << question;

    cin >> input_number;

    if (is_number(input_number))
    {
        return input_number;
    }
    else
    {
        cout << wrong_param;

        return "wrong_param";
    }
}

void decode_binary(string binary_number)
{
    int output_number = 0, number_index = 0;

    // Finish decode algorithm
}

void encode_to_binary(string number_to_encode)
{
    const int binary_const = 2;
    int remainder, division;
    long long num_as_long = stoll(number_to_encode);

    string output_binary_number = "";

    while (division > 0) {
        
        division = num_as_long / binary_const;
        remainder = num_as_long % binary_const;

        output_binary_number += to_string(remainder);

        num_as_long = division;
    }


    cout << output_binary_number;
}

int main()
{
    string encode_type;
    string input_number;

    const string welcome = "Hello! This function encodes and decodes binary numbers into decimals\n\n";

    cout << welcome; // Print welcome message

    while (encode_type == "wrong_param" || encode_type.empty()) // Ask for coding mode until a valid value is parsed
    {
        encode_type = ask_encode_type();
    }

    const string encode_type_name = (encode_type == "e") ? "Encode" : "Decode";

    cout << "\nOk! " + encode_type_name + " mode, right?\n\n"; // Print selected mode

    while (input_number == "wrong_param" || input_number.empty()) // Ask for number to decode/encode until a valid number is parsed
    {
        input_number = ask_input_number(encode_type);
    }

    (encode_type == "e") ? encode_to_binary(input_number) : decode_binary(input_number); // Process input number and print result

    return 0;
}
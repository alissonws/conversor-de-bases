#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool is_binary(long long number)
{
    int num;

    while (number > 0)
    {
        num = number % 10;

        if ((num != 0) && (num != 1))
        {
            cout << "not binary\n";
            return false;
        }
        number = number / 10;

        if (number == 0)
        {
            cout << "is binary\n";
            return true;
        }
    }
    cout << "is binary\n";

    return true;
}

bool is_number(const string &str)
{
    for (char const &c : str)
    {
        if (isdigit(c) == 0)
            return false;
    }
    return true;
}

string ask_encode_type()
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
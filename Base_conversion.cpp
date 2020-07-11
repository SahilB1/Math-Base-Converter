#include <iostream>
#include <iomanip>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::string; 
using std::to_string;
using std::stoi;


// Here we iterate through each element in the string holding the number 
// resembled by the other base and get the integer value of each element 
// by using ASCII math. We then convert that digit to its decimal equivalent
// and add it to the total for the duration of the length of the input value.

int convert_other_base_to_decimal(int value, int base) {
    string str_val = to_string(value);
    int val_length = str_val.length();
    int total = 0;
    for(int i = 0; i < val_length; i++) {
        int digit = ((int)(str_val[i]) - 48);
        total += (digit * pow(base, (val_length - i - 1)));
    }
    return total;
}

// We first determine the exponent needed to start the conversion by
// comparing the value of the other base raised to an exponent to the 
// decimal input value and incrementing the value of the exponent variable.
// From here, we loop from the newly set top bound exponent down to zero while
// adding the converted result to the string that resembles the other base number. 

int convert_decimal_to_other_base(int value, int base) {
    string result = "";
    int exponent = 0;
    while(pow(base, exponent) <= value) {
        exponent++;
    }
    for(int i = exponent; i > 0; i--) {
        if(pow(base, i) >= value && pow(base, i - 1) <= value) {
            int base_i = pow(base, i - 1);
            int add_num = (value / base_i);
            result.append(to_string(add_num));
            value = (value % base_i);
        } else {
            result.append("0");
        }
    }
    int new_base_num = (int)stoi(result);
    return new_base_num;
}

// Here we simply check to see what the math operator is and then use our previously
// created functions to convert the values accordingly and perform the appropriate operation
// using a switch case to account for every possible input operator. 

int math_in_other_base(int other_base_a, int other_base_b, int base, char math_operator) {
    int decimal_val;

    switch (math_operator) {
    case '+':
        decimal_val = convert_other_base_to_decimal(other_base_a, base) + convert_other_base_to_decimal(other_base_b, base);
        break;
    case '-':
        decimal_val = convert_other_base_to_decimal(other_base_a, base) - convert_other_base_to_decimal(other_base_b, base);
        break;
    case '/':
        decimal_val = convert_other_base_to_decimal(other_base_a, base) / convert_other_base_to_decimal(other_base_b, base);
        break;
    case '*':
        decimal_val = convert_other_base_to_decimal(other_base_a, base) * convert_other_base_to_decimal(other_base_b, base);
        break;
    case '%':
        decimal_val = convert_other_base_to_decimal(other_base_a, base) % convert_other_base_to_decimal(other_base_b, base);
        break;
    default:
        decimal_val = 0;
        break;
    }
    
    int result = convert_decimal_to_other_base(decimal_val, base);
    cout << result << endl;
    return result;
}

int main() {
    int other_base_a;
    int other_base_b;
    int base;
    char math_operator;

    cin >> other_base_a;
    cin >> other_base_b;
    cin >> base;
    cin >> math_operator;

    math_in_other_base(other_base_a, other_base_b, base, math_operator);
}

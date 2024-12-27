#include <stdio.h>  
#include <ctype.h>  
#include <stdbool.h>  
#include <math.h>  
  
// Helper function to determine if a character is a valid digit  
bool is_digit(char c) {  
    return c >= '0' && c <= '9';  
}  
  
// Helper function to convert a character to its numeric value  
int char_to_digit(char c) {  
    return c - '0';  
}  
  
// Custom atof implementation  
double my_atof(const char *str) {  
    // Skip leading whitespace  
    while (isspace(*str)) {  
        str++;  
    }  
  
    // Handle optional sign  
    bool is_negative = false;  
    if (*str == '-') {  
        is_negative = true;  
        str++;  
    } else if (*str == '+') {  
        str++;  
    }  
  
    // Parse integer part  
    double result = 0.0;  
    while (is_digit(*str)) {  
        result = result * 10.0 + char_to_digit(*str);  
        str++;  
    }  
  
    // Parse fractional part if present  
    if (*str == '.') {  
        str++;  
        double fraction = 0.0;  
        double scale = 0.1;  
        while (is_digit(*str)) {  
            fraction = char_to_digit(*str);  
            result += fraction * scale;  
            scale *= 0.1;  
            str++;  
        }  
    }  
  
    // Apply sign  
    if (is_negative) {  
        result = -result;  
    }  
  
    return result;  
}  
  
int main() {  
    const char *num_str = " -123.456 ";  
    double num = my_atof(num_str);  
    printf("The converted number is: %f\n", num);  
    return 0;  
}
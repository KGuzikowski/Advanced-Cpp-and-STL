#include <iostream>
#include <regex>
#include <cassert>

using namespace std;

int main() {
    regex valid_hour("^([01]\\d|2[0-3]):([0-5]\\d):?([0-5]\\d)?$");
    assert(regex_match("13:00:00", valid_hour));
    assert(regex_match("09:59", valid_hour));
    assert(!regex_match(":00:24", valid_hour));
    assert(regex_match("23:59:59", valid_hour));
    assert(!regex_match("25:12", valid_hour));

    string s;
    //cout << "Insert hour: ";
    //cin >> s;
    //cout << regex_match(s, valid_hour) << endl;
    
    regex valid_date("^((((0[1-9])|([12][0-9])|31)-(0([13578])|1[02]))|(((0[1-9])|([12][0-9])|30)-((0[469])|11))|(((0[1-9])|(1[0-9])|(2[0-8]))-02))-(\\d{4,})$");
    assert(!regex_match("30-02-1999", valid_date));
    assert(!regex_match("31-11-20509", valid_date));
    assert(regex_match("25-11-20509", valid_date));
    assert(regex_match("31-01-2019", valid_date));
    assert(!regex_match("31-01-201", valid_date));
    //cout << "Insert date: ";
    //cin >> s;
    //cout << regex_match(s, valid_date) << endl;

    regex valid_polish_city("^([A-ZĄĆĘŁŃÓŚŻŹ][a-ząćęłńóśżź]{2,})((-[A-ZĄĆĘŁŃÓŚŻŹ][a-ząćęłńóśżź]{2,})|(( {1,}[A-ZĄĆĘŁŃÓŚŻŹ][a-ząćęłńóśżź]{2,})+))?$");
    assert(regex_match("Gorzów Wielkopolski", valid_polish_city));
    assert(regex_match("Mała-Górka", valid_polish_city));
    assert(!regex_match("Bardzo-Mała-Górka", valid_polish_city));
    assert(regex_match("Wrocław", valid_polish_city));
    assert(!regex_match("Ab", valid_polish_city));
    assert(!regex_match("Gorzów wielkopolski", valid_polish_city));
    assert(regex_match("Aaa Aaa Aaa", valid_polish_city));
    //cout << "Insert polish city name: ";
    //cin >> s;
    //cout << regex_match(s, valid_polish_city) << endl;


    regex valid_complex("( +)?\\(( +)?-?(\\d+)(\\.\\d+)?( +)?[+-]( +)?(\\d+)(\\.\\d+)?[iI]( +)?\\)( +)?");
    assert(regex_match("(3  + 4i)", valid_complex));
    assert(regex_match("(3.59 + 0i)", valid_complex));
    assert(!regex_match("(23)", valid_complex));
    assert(!regex_match("-5 - 10i", valid_complex));
    assert(!regex_match("2 + 3i", valid_complex));
    assert(regex_match("(3.51412 - 3.5i)", valid_complex));
    //cout << "Insert complex number: ";
    //cin >> s;
    //cout << regex_match(s, valid_complex) << endl;

    return 0;
}

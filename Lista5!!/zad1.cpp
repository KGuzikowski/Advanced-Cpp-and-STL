#include <iostream>
#include <queue>
#include <stack>
#include <map>

using namespace std;

bool is_operator(char c) {
    return c == '*' || c == '/' || c == '-' || c == '+' || c == '^' ||
    c == '%'; 
}

void do_when_found_operator(const char &op, stack<char> &st, queue<char> &qu) {
    const static map<char, int> priorities {
        {'+', 0},
        {'-', 0},
        {'*', 1},
        {'/', 1},
        {'%', 1},
        {'^', 2},
    };
    enum Associativity {LEFT, RIGHT};
    const static map<char, Associativity>  asso {
        {'+', LEFT},
        {'-', LEFT},
        {'*', LEFT},
        {'/', LEFT},
        {'%', LEFT},
        {'^', RIGHT},
    };
    while (!st.empty() && is_operator(st.top()) && ((asso.at(op) == LEFT && priorities.at(op) <= priorities.at(st.top())) ||
    (asso.at(op) == RIGHT && priorities.at(op) < priorities.at(st.top())))) {
        qu.push(st.top());
        st.pop();
    }
    st.push(op);    
}

void do_when_found_r_parenthesis(stack<char> &st, queue<char> &qu) {    
    while (st.top() != '(') {
        qu.push(st.top());
        st.pop();
    }
    if (!st.empty())
        st.pop();
}

queue<char> convert_to_rnp(string to_convert) {
    queue<char> answer;
    stack<char> helper;
    for (char &character : to_convert) {
        if (isdigit(character) || isalpha(character)){
            answer.push(character);
            answer.push(' ');
        }
        else if (is_operator(character)){
            do_when_found_operator(character, helper, answer);
            answer.push(' ');
        }
        else if (character == '(')
            helper.push(character);
        else
            do_when_found_r_parenthesis(helper, answer);
    }

    while (!helper.empty()) {
        answer.push(helper.top());
        helper.pop();
    }

    return answer;
}

void print_queue(queue<char> q) {
    while (!q.empty()) {
        cout << q.front();
        q.pop();
    }
    cout << "\n";
}

int main() {
    string test1 = "2^2^2^2";
    queue<char> answer_test1 = convert_to_rnp(test1);

    string test2 = "a+b*c/(d-e)^c";
    queue<char> answer_test2 = convert_to_rnp(test2);

    string test3 = "12+a*(b*c+d/e)";
    queue<char> answer_test3 = convert_to_rnp(test3);
    print_queue(answer_test1);
    print_queue(answer_test2);
    print_queue(answer_test3);
    return 0;
}

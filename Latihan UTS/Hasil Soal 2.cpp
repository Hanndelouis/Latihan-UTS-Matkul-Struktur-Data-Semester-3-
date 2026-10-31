#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct Token {
    string value;
    string type;
};

const int MAX_QUEUE = 100;
Token tokenQueue[MAX_QUEUE];
int q_front = -1;
int q_rear = -1;

void enqueue(Token t) {
    if (q_rear == MAX_QUEUE - 1) return; 
    if (q_front == -1) q_front = 0;
    tokenQueue[++q_rear] = t;
}

Token dequeue() {
    Token emptyToken = {"", ""};
    if (q_front == -1 || q_front > q_rear) return emptyToken; 
    return tokenQueue[q_front++];
}

bool isEmpty() {
    return q_front == -1 || q_front > q_rear;
}

int main() {
    string expr;
    cout << "Input ekspresi: ";
    getline(cin, expr);

    int i = 0, n = expr.length();
    while (i < n) {
        if (isspace(expr[i])) {
            i++;
            continue;
        }
        if (isdigit(expr[i])) {
            string num = "";
            while (i < n && isdigit(expr[i])) {
                num += expr[i];
                i++;
            }
            enqueue({num, "OPERAND"});
        } else {
            enqueue({string(1, expr[i]), "OPERATOR"});
            i++;
        }
    }

    cout << "\nHasil Parsing Antrean FIFO:\n";
    while (!isEmpty()) {
        Token t = dequeue();
        cout << "[" << t.type << "] -> " << t.value << "\n";
    }

    return 0;
}
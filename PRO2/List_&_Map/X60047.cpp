#include <iostream>
#include <list>
using namespace std;

int main() {
    int usr_num;
    string usr_op;
    list<int> first_half, second_half;
    int first_half_size = 0, second_half_size = 0;

    while (cin >> usr_op) {
        if (usr_op == "push_front") {
            cin >> usr_num;
            first_half.push_front(usr_num);
            ++first_half_size;
            if (first_half_size > second_half_size + 1) {
                second_half.push_front(first_half.back());
                first_half.pop_back();
                ++second_half_size;
                --first_half_size;
            }
        } else if (usr_op == "push_back") {
            cin >> usr_num;
            second_half.push_back(usr_num);
            ++second_half_size;
            if (second_half_size > first_half_size) {
                first_half.push_back(second_half.front());
                second_half.pop_front();
                ++first_half_size;
                --second_half_size;
            }
        } else if (usr_op == "pop_front") {
            if (first_half_size + second_half_size == 0) {
                cout << "error" << endl;
            } else {
                if (first_half_size > 0) {
                    first_half.pop_front();
                    --first_half_size;
                } else {
                    second_half.pop_front();
                    --second_half_size;
                }
                if (second_half_size > first_half_size) {
                    first_half.push_back(second_half.front());
                    second_half.pop_front();
                    ++first_half_size;
                    --second_half_size;
                }
            }
        } else if (usr_op == "pop_back") {
            if (first_half_size + second_half_size == 0) {
                cout << "error" << endl;
            } else {
                if (second_half_size > 0) {
                    second_half.pop_back();
                    --second_half_size;
                } else {
                    first_half.pop_back();
                    --first_half_size;
                }
                if (first_half_size > second_half_size + 1) {
                    second_half.push_front(first_half.back());
                    first_half.pop_back();
                    --first_half_size;
                    ++second_half_size;
                }
            }
        } else if (usr_op == "get_mid_value") {
            if ((first_half_size + second_half_size) % 2 == 0) {
                cout << "error" << endl;
            } else {
                if (first_half_size > second_half_size) {
                    cout << first_half.back() << endl;
                } else {
                    cout << second_half.front() << endl;
                }
            }
        }
    }
}

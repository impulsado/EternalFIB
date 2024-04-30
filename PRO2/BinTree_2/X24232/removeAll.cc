#include "removeAll.hh"
using namespace std;

BT removeAll(const string &extension, const BT &t) {
    // Base Case
    if (t.empty()) return BT();

    // General Case
    bool is_file = false;
    if (t.left().empty() and t.right().empty()) is_file = true;

    if (is_file) {
        string file_name = t.value();
        int file_size = file_name.size();
        bool has_the_ext = true;
        int j = 0;
        for (int i = (file_size-extension.size()); i<file_size and has_the_ext; i++) {
            if (file_name[i]!=extension[j]) has_the_ext = false;
            j++;
        }

        if (has_the_ext) return BT();
        else return BT(t.value(), t.left(), t.right());
    }

    BT left_tree = removeAll(extension,t.left());
    BT right_tree = removeAll(extension,t.right());

    return BT(t.value(), left_tree, right_tree);
}
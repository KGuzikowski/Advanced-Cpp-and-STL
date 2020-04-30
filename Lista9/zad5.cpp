#include <iostream>
#include <experimental/filesystem>

using namespace std;
namespace fs = experimental::filesystem;

void get_dir_size(string name, int &dir_size) {
    for (auto &e : fs::directory_iterator(name)) {
        if (fs::is_regular_file(e))
            dir_size += fs::file_size(e);
        else
            get_dir_size(e.path(), dir_size);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        cout << "You should give a directory name!\n";
        return 0;
    }
    
    if (!fs::exists(argv[1])) {
        cout << "This directory does not exists!\n";
        return 0;
    }
    
    if (!fs::is_directory(argv[1])) {
        cout << "This is not a directory!\n";
        return 0;
    }

    int sum = 0;
    get_dir_size(argv[1], sum);
    cout << sum << endl;
    return 0;
}

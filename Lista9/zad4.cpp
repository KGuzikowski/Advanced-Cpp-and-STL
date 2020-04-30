#include <iostream>
#include <experimental/filesystem>

using namespace std;
namespace fs = experimental::filesystem;

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

    for (auto &e : fs::directory_iterator(argv[1]))
        cout << e.path() << endl;
    return 0;
}

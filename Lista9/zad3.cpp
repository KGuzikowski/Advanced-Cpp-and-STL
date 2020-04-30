#include <iostream>
#include <experimental/filesystem>

using namespace std;
namespace fs = experimental::filesystem;

void perms(fs::perms p)
{
    cout << ((p & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
        << ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
        << ((p & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
        << ((p & fs::perms::group_read) != fs::perms::none ? "r" : "-")
        << ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-")
        << ((p & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
        << ((p & fs::perms::others_read) != fs::perms::none ? "r" : "-")
        << ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
        << ((p & fs::perms::others_exec) != fs::perms::none ? "x\n" : "-\n");
}

void status(fs::file_status s)
{
    if(fs::is_regular_file(s))
        cout << "It is a regular file\n";
    if(fs::is_directory(s))
        cout << "It is a directory\n";
    if(fs::is_block_file(s))
        cout << "It is a block device\n";
    if(fs::is_character_file(s))
        cout << "It is a character device\n";
    if(fs::is_fifo(s))
        cout << "It is a named IPC pipe\n";
    if(fs::is_socket(s))
        cout << "It is a named IPC socket\n";
    if(fs::is_symlink(s))
        cout << "It is a symlink\n";
}

void talk_to_me(string name) {
    if (fs::exists(name)) {
        cout << "exists\n";
        status(fs::status(name));
        cout << "canonical path: " << fs::canonical(name) << endl;
        
        auto ftime = fs::last_write_time(name);
        time_t cftime = decltype(ftime)::clock::to_time_t(ftime);
        cout << "last write: " << asctime(localtime(&cftime));

        if (fs::is_regular_file(name)) {
            cout << "file size: " << fs::file_size(name) << endl;
        }

        cout << "permissions: ";
        perms(fs::status(name).permissions());
    }
    else {
        cout << "file/dir not exists\n";
    }
}

int main(int argc, char **argv) {
    if (argc == 1) {
        cout << "Given no files\n";
        return 0;
    }

    for (int i = 1; i < argc; ++i) {
        talk_to_me(argv[i]);
        cout << "========================================================================\n\n";
    }
    return 0;
}

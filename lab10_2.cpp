#include <iostream>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>

using namespace std;
int main(int argc, char* argv[])
{
    int opt{};
    bool countFlag{false};
    bool logFlag{false};
    int count{};
    string logValue;
    bool optErr = true;
    while((opt = getopt(argc, argv, "c:l")) != EOF){
        switch(opt){
            case 'c':
                countFlag = true;
                count = atoi(optarg);
                break;
            case 'l':
                logFlag = true;
                logValue = optarg;
                break;
            default:
                optErr = true;
                break;
        }
    }
    cout << "flags - countFlag: " << countFlag << " logFlag: " << logFlag << endl;

    if(countFlag && logFlag){
        cout << "flags set!" << endl;
        if(logValue.empty() || count == 0){
            optErr = true;
            cout << "option arguments are not set" << endl;
        }
        else{
            optErr = false;
        }
    }
    else{
        cout << "error - flags are nor set" << endl;
        optErr = true;
    }
    
    if(optErr){
        return EXIT_FAILURE;
    }
    cout << "The count is: " << count << " and logfile is: " << logValue << endl;
    cout << "optErr: " << optErr << endl;
    return EXIT_SUCCESS;
    
    /*
    passwd *pws;
    pws = getpwuid(geteuid());
    cout << "user is: "<< pws->pw_name << " userid is: " << pws->pw_uid << endl;

    pid_t pid = getpid();
    string programName = basename(argv[0]);
    cout << "the pid of: " << programName << " is: " << pid << endl;
    cout << "successful run\n";
    */
    return EXIT_SUCCESS;
}

#include <iostream>
#include <string>
#include <map>

static std::map<std::string, std::string> commands = 
{
    {"calc", "./commands/calc"} /* for windows you need chnage path here */
};

int main()
{
    using namespace std;
    string input;

    while (true)
    {
        cout << "Termi> ";
        getline(cin, input);

        auto command = commands.find(input);

        if (command != commands.end())
        {
            system(command->second.c_str());
        }

        else if (input == "help")
        {
            for (auto& x : commands)
            {
                cout << x.first << endl;
            }
        }

        else if (input == "clear" || input == "cls")
        {
            cout << "\033c";
        }

        else if (input == "exit")
        {
            exit(0);
        }

        else if (input.length() == 0) /* enter */
        {
            
        }

        else
        {
            cout << "Wrong command!\n";
        }
    }

    return 0;
}

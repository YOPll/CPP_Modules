#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char *av[])
{
    int f = 0;

    if (ac != 4)
        std::cout << "Usage : ./Sed `filename` `To_be_replaced`  `Replace_with`" << std::endl;
    else
    {
        std::string filename = av[1];
        std::string to_be_r = av[2];
        std::string r_with = av[3];
        std::string outfile;
        std::string tmp = filename;
        std::ifstream in_f(filename);
        if (filename.empty() || to_be_r.empty() || r_with.empty())
            std::cout << "Empty argument , Please Check again" << std::endl;

        if (!in_f.is_open())
            exit(1);
        std::ofstream out_f(tmp.append(".replace"));
        if(in_f.is_open() && out_f.is_open())
        {
            while (std::getline(in_f, outfile))
            {
                f = outfile.find(to_be_r);
                while(f != -1)
                {
                    outfile.erase(f, to_be_r.length());
                    outfile.insert(f, r_with);
                    f =  (outfile).find(to_be_r, f + to_be_r.length() - 1);
                }
                out_f << outfile << std::endl;
            }
        }
        out_f.close();
    }
    return (0);
}
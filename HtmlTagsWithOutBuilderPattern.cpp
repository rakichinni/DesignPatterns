#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class HtmlElement
{
};

int main()
{
    ostringstream s;

    s << "<html>\n";
    s << "<head>\n";
    s << "<title>";
    s << "With out using builder pattern";
    s << "</title>\n";
    s << "<body>\n";
    s << "<h1>";
    s << "Started exploring builder pattern";
    s << "</h1>\n";
    s << "</body>\n";
    s << "</html>";

    cout << s.str() << endl;

}

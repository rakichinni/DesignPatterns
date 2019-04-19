#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class HtmlElement
{
    string tag_name;
    string content;
    vector<HtmlElement*> ve;

public:
    HtmlElement(string name, string text)
    :tag_name (name),
    content(text)
    {
    }

    void insert(HtmlElement* h)
    {
        ve.push_back(h);
    }

    void str(ostringstream& s, int indent = 1);

};

void HtmlElement::str(ostringstream& s, int indent)
{
    s << "\n<" << tag_name << ">";

    if (content.size() > 0)
        s << content;

    for (vector<HtmlElement*>::iterator it = ve.begin(); it != ve.end(); it++)
    {
        (*it)->str(s, indent + 1);
    }
    s << "</" << tag_name << ">\n";
}

int main()
{
    HtmlElement *h = new HtmlElement("html", "");

    HtmlElement *head = new HtmlElement("head","");
    head->insert(new HtmlElement("title","With out using builder pattern"));
    h->insert(head);

    head = new HtmlElement("body", "");
    head->insert(new HtmlElement("h1", "Started exploring builder pattern"));
    h->insert(head);

    ostringstream s;
    h->str(s, 1);
    cout << s.str() << endl;
}

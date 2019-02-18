#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Builder.h"

int main() {
    /**
     * Without builder
     */
    std::string words[] = {"hello", "world"};
    std::ostringstream oss;

    oss << "<ul>";
    for(auto w : words){
        oss << "<li>" << w << "</li>";
    }
    oss << "</ul>";
    std::cout << oss.str();

    /**
     * using builder
     * */
     std::cout << "\n" << "builder: " << "\n";
     HtmlBuilder a("ul");
     a.addChild("li", "hello");
     a.addChild("li", "world");
     std::cout << a.str();

    return 0;
}
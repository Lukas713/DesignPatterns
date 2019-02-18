//
// Created by Korisnik on 18/02/2019.
//

#ifndef DESIGNPATTERNS_BUILDER_H
#define DESIGNPATTERNS_BUILDER_H

#endif //DESIGNPATTERNS_BUILDER_H

/**
 * Utility class for modelling
 */
struct HtmElement {
    std::string name, text;
    std::vector<HtmElement> elements;
    const size_t indentSize = 2;

    HtmElement() {}
    HtmElement(const std::string &name, const std::string &text) : name(name), text(text) {}

    std::string str(int indent = 0) const {
        std::ostringstream oss;
        std::string i(indentSize*indent, ' ');
        oss << i << "<" << name << ">\n";
        if(text.size() > 0)
            oss << std::string(indentSize*(indent+1), ' ') << text << std::endl;
        for(const auto& e : elements)
            oss <<  e.str(indent+1);

        oss << i << "</" << name << ">" << std::endl;
        return oss.str();
    }
};

struct HtmlBuilder {
    HtmElement root;
    HtmlBuilder(std::string name){
        root.name = name;
    }
    void addChild(std::string name, std::string text){
        HtmElement e{name, text};
        root.elements.push_back(e);
    }
    std::string str() {
        return root.str();
    }
};

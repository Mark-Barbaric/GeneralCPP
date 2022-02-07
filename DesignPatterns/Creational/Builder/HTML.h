#pragma once
#include <sstream>
#include <string>
#include <vector>

class HTMLBuilder;

class HTMLElement{

    friend class HTMLBuilder;
    std::string m_tag;
    std::string m_value;
    uint32_t m_indentSize = 4;
    HTMLElement() = default;
    HTMLElement(std::string tag, std::string value):m_tag(std::move(tag)), m_value(std::move(value)){}
    std::vector<HTMLElement> m_children;

public:

    static std::unique_ptr<HTMLBuilder> build(std::string root) {return std::make_unique<HTMLBuilder>(std::move(root));}

    std::string str(int32_t indent = 0) {
        std::ostringstream oss;
        oss << std::string(m_indentSize * indent, ' ') << "<" << m_tag << ">" << std::endl;

        if (m_value.empty()) oss << std::string(m_indentSize * (indent + 1), ' ') << m_value << std::endl;

        for (auto &element : m_children)
            oss << element.str(indent + 1);

        oss << std::string(m_indentSize * indent, ' ') << "</" << m_tag << ">" << std::endl;
        return oss.str();
    }
};


class HTMLBuilder{

    HTMLElement m_root;

public:

    explicit HTMLBuilder(std::string root){ m_root.m_tag = std::move(root);}
    HTMLBuilder* addChild(std::string tag, std::string value) {
        m_root.m_children.emplace_back(HTMLElement(std::move(tag), std::move(value)));
        return this;
    }

    std::string str() {return m_root.str();}
};
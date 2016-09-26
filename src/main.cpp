#include <iostream>
#include <fstream>
#include <string>

#include <pugixml.hpp>

auto main() -> int
{
    std::cout << "Time to fapp!" << std::endl;

    const std::string filename = "data/AS_ROOM_20160925_438f8853-a978-41b2-bdd3-a4c2095a404c.XML";

    std::ifstream stream(filename);

    pugi::xml_document doc;
    auto res = doc.load(stream);

    return 0;
}

#include "jsonFile.hpp"
#include <iostream>

using json = nlohmann::json;

int main()
{
    // test
    json data;
    data["name"] = "qinmo";
    std::cout << data["name"] << std::endl;
    std::cout << data["name"].get<std::string>() << std::endl;
    jsonFile jsonfile("../data/test.json");
    jsonfile.write(data);
    nlohmann::json jsonData = jsonfile.read();
    std::cout << jsonData << std::endl;

    jsonHandle handle;
    nlohmann::json temp = handle.read("../data/test.json");
    std::cout << temp << std::endl;

    // test write when no file has been created
    temp.clear();
    handle.write("../data/test1.json", data);
    temp = handle.read("../data/test1.json");
    std::cout << temp << std::endl;

    // test read when no file has been created
    temp.clear();
    temp = handle.read("../data/test2.json");
    std::cout << temp << std::endl;

    // test read when file data is in disorder
    temp.clear();
    temp = handle.read("../data/test3.json");
    std::cout << temp << std::endl;
    return 0;
}
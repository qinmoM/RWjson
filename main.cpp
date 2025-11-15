#include "jsonFile.hpp"
#include <iostream>

using json = nlohmann::json;

int main()
{
    // usage of jsonFile
    json data;
    data["name"] = "qinmo";
    jsonFile jsonfile("../data/test.json");
    jsonfile.write(data);
    json jsonData;
    jsonfile.read(jsonData);
    std::cout << jsonData << std::endl;

    // usage of jsonHandle
    jsonHandle handle;
    json temp;
    handle.read("../data/test.json", temp);
    std::cout << temp << std::endl;

    // test write when no file has been created
    temp.clear();
    handle.write("../data/test1.json", data);
    handle.read("../data/test1.json", temp);
    std::cout << temp << std::endl;

    // test read when no file has been created
    temp.clear();
    handle.read("../data/test2.json", temp);
    std::cout << temp << std::endl;

    // test read when file data is in disorder
    temp.clear();
    handle.read("../data/test3.json", temp);
    std::cout << temp << std::endl;
    return 0;
}
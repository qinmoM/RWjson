#pragma once

#include "json.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

// jsons handle
class jsonHandle
{
public:
    jsonHandle();
    ~jsonHandle();

public:
    nlohmann::json read(const std::string& file_path) const;
    bool write(const std::string& file_path, const nlohmann::json& json_object) const;

};

// json object
class jsonFile
{
public:
    jsonFile(const std::string& file_path);
    ~jsonFile();

public:
    nlohmann::json read() const;
    bool write(const nlohmann::json& json_object) const;

private:
    std::string file_path_;

};

//          jsonHandle

jsonHandle::jsonHandle() = default;

jsonHandle::~jsonHandle() = default;

nlohmann::json jsonHandle::read(const std::string& file_path) const
{
    std::ifstream ifs(file_path);
    nlohmann::json data;

    if (!ifs.is_open())
    {
        std::cerr << file_path << ", json file cannot be opened!" << std::endl;
        return data;
    }

    std::stringstream buffer;
    buffer << ifs.rdbuf();
    ifs.close();

    try
    {
        return nlohmann::json::parse(buffer.str());
    }
    catch (nlohmann::json::parse_error& e)
    {
        std::cerr << "Json file parse error in " << file_path << " : " << e.what() << '\n';
        return nlohmann::json::object();
    }
}

bool jsonHandle::write(const std::string& file_path, const nlohmann::json& json_object) const
{
    std::ofstream ofs(file_path);
    if (!ofs.is_open())
    {
        std::cerr << file_path << ", json file cannot be opened!" << std::endl;
        return false;
    }
    ofs << json_object.dump(4);
    ofs.close();
    return true;
}

//          jsonFile

jsonFile::jsonFile(const std::string& file_path)
    : file_path_(file_path)
{ }

jsonFile::~jsonFile() = default;

nlohmann::json jsonFile::read() const
{
    std::ifstream ifs(file_path_);
    nlohmann::json data;

    if (!ifs.is_open())
    {
        std::cerr << file_path_ << ", json file cannot be opened!" << std::endl;
        return data;
    }

    std::stringstream buffer;
    buffer << ifs.rdbuf();
    ifs.close();
    
    try
    {
        return nlohmann::json::parse(buffer.str());
    }
    catch (nlohmann::json::parse_error& e)
    {
        std::cerr << "Json file parse error in " << file_path_ << " : " << e.what() << '\n';
        return nlohmann::json::object();
    }
}

bool jsonFile::write(const nlohmann::json& json_object) const
{
    std::ofstream ofs(file_path_);
    if (!ofs.is_open())
    {
        std::cerr << file_path_ << ", json file cannot be opened!" << std::endl;
        return false;
    }
    ofs << json_object.dump(4);
    ofs.close();
    return true;
}

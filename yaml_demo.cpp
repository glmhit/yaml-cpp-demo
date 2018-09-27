#include <yaml-cpp/yaml.h>  //安装yaml-cpp参考google code 主页
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;
int main()  //
{
  {  // 1 basic emitting
    cerr << "\nbasic emitting" << endl;
    YAML::Emitter emitter;
    emitter << "hello world!";
    cout << emitter.c_str() << endl;
  }
  // 2 simple lists
  {
    cerr << "\nyaml simple list" << endl;
    YAML::Emitter out;
    out << YAML::BeginSeq;
    out << "eggs";
    out << "bread";
    out << "milk";
    out << YAML::EndSeq;
    cout << out.c_str() << "\n" << endl;
  }
  // 3 simple map
  {
    std::cerr << "\nyaml simple map" << endl;
    YAML::Emitter out;
    out << YAML::BeginMap;
    out << YAML::Key << "name";
    out << YAML::Value << "Ryan Braun";
    out << YAML::Key << "position";
    out << YAML::Value << "LF";
    out << YAML::EndMap;
    cout << out.c_str() << "\n" << endl;
  }
  // emit to file
  {
    std::ofstream fout("data1.yaml");
    YAML::Emitter out(fout);
    out << YAML::BeginSeq;
    // out << "list1";
    out << YAML::BeginMap;
    out << YAML::Key << "list1";
    out << YAML::Value;
    out << YAML::BeginMap;

    out << YAML::Key << "child";
    out << YAML::Value << 1;
    out << YAML::Key << "child";
    out << YAML::Value << 2;
    out << YAML::Key << "child";
    out << YAML::Value << 3;
    out << YAML::EndMap;
    out << YAML::EndMap;

    out << YAML::BeginMap;
    out << YAML::Key << "list2";
    out << YAML::Value << "10";
    out << YAML::EndMap;
    out << "list3";
    out << YAML::Comment("this is a pure list ");
    out << YAML::EndSeq;
  }
  // parse document
  {
    YAML::Node doc = YAML::LoadFile("config.yaml");
    if (doc["username"])
    {
      std::cout << doc["username"].as<std::string>() << "\n";
    }
    if (doc["lastLogin"])
    {
      std::cout << "Last logged in: " << doc["lastLogin"].as<std::string>() << "\n";
    }
  }
  // parse document
  {
    YAML::Node doc = YAML::LoadFile("data2.yaml");
    for (std::size_t i = 0; i < doc.size(); i++)
    {
      std::cout << "name: " << doc[i]["name"].as<std::string>() << "\n";
      std::cout << "position: " << doc[i]["position"] << "\n";
      std::cout << "powers: " << doc[i]["powers"].as<double>() << "\n";
    }
  }

  {
    YAML::Node lineup = YAML::Load("{1B: Prince Fielder, 2B: Rickie Weeks, LF: Ryan Braun}");
    for (YAML::const_iterator it = lineup.begin(); it != lineup.end(); ++it)
    {
      std::cout << it->first.as<std::string>() << " is " << it->second.as<std::string>() << "\n";
    }

    lineup["RF"] = "Corey Hart";
    lineup["C"] = "Jonathan Lucroy";
    assert(lineup.size() == 5);
    std::ofstream fout("data3.yaml");
    fout << lineup;
  }
  return 0;
}

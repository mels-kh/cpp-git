
#include "httplib.h"
#include <set>
int main(void) {
  using namespace httplib;

  Server svr;

  // https://HWServer.nikolaishieiko.repl.co?text=Hello%20104%20Group
  svr.Get("/", [](const Request &req, Response &res) {
    auto it = req.params.find("text");
    if (it != req.params.end()) {
      res.set_content(it->second, "text/plain");
    } else {
      res.set_content("Hello World!", "text/plain");
    }
  });

 std::set<std::string> cars{"BMW", "Mercedes", "Lada"};

  // https://HWServer.nikolaishieiko.repl.co/cars
  svr.Get("/cars", [&cars](const Request &req, Response &res) {
   
    std::string body{};

    res.set_content(body, "text/plain");
  });
  // https://HWServer.nikolaishieiko.repl.co/cars/remove?mark=BMW
  // https://HWServer.nikolaishieiko.repl.co/cars/remove?mark=Mercedes
  svr.Get("/cars/remove", [&cars](const Request &req, Response &res) {
    auto it = req.params.find("mark");
    if (it == req.params.end()) {
      res.set_content("No mark in your request", "text/plain");
      return;
    }
    cars.erase(it->second);
  });

  svr.Get("/cars/add", [&cars](const Request &req, Response &res) {
    auto it = req.params.find("mark");
    if (it == req.params.end()) {
      res.set_content("No mark in your request", "text/plain");
      return;
    }
    cars.insert(it->second);
  });
  svr.listen("0.0.0.0", 8080);
}
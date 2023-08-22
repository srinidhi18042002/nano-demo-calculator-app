#include "crow_all.h"

crow::response greet()
{
    return crow::response{"Hello world!"};
}
crow::response add(const crow::request &req)
{
    auto input = crow::json::load(req.body);
    auto res = input["first"].i() + input["second"].i();
    return crow::response{"result":res};
}
crow::response subtract(const crow::request &req)
{
    auto input = crow::json::load(req.body);
    auto res = input['first'] - input['second'];
    return crow::response{""};
}
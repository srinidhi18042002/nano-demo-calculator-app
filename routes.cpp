#include "crow_all.h"

crow::response greet()
{
    return crow::response{"Hello world!"};
}

crow::response add(const crow::request &req)
{
    auto input = crow::json::load(req.body);

    if (!input)
    {
        return crow::response(400, "Invalid JSON");
    }
     int result = input["first"].i() + input["second"].i();
     crow::json::wvalue response;
     response["result"] = result;
     return crow::response{response};     

    // int first = input["first"].i();
    // int second = input["second"].i();
    // int result = first + second;

    // crow::json::wvalue response;
    // response["result"] = result;

    // return crow::response{response};
}

crow::response subtract(const crow::request &req)
{
    auto input = crow::json::load(req.body);

    if (!input)
    {
        return crow::response(400, "Invalid JSON");
    }

    int first = input["first"].i();
    int second = input["second"].i();
    int result = first - second;

    crow::json::wvalue response;
    response["result"] = result;

    return crow::response{response};
}
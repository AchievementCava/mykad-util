#include <iostream>
#include "ic.h"
#include <crow.h>

crow::json::wvalue dump(IC ic_obj) {

    crow::json::wvalue ic_json;

    ic_json["raw_number"] = ic_obj.getRawNumber();
    ic_json["formatted_number"] = ic_obj.getFormattedNumber();
    ic_json["sex"] = toString( ic_obj.getSex() );
    ic_json["state"] = ic_obj.getState().name;

    ic_json["name"] = ic_obj.getName();
    ic_json["address"] = ic_obj.getAddress();

    // Nesting the DOB
    crow::json::wvalue dob_json;
    dob_json["day"] = ic_obj.getDob().day;
    dob_json["month"] = ic_obj.getDob().month;
    dob_json["year"] = ic_obj.getDob().year;

    ic_json["dob"] = std::move(dob_json);

    ic_json["validity"] = ic_obj.isValid();

    ic_json["note"] = ic_obj.getNote();

    return ic_json;

}

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/").methods("POST"_method, "GET"_method)
    ([](const crow::request& request){

        // Deny GET requests
        if (request.method == crow::HTTPMethod::Get) {
            return crow::response(405, "MyKad Parser by AchievementCava. \n\n\
Please POST to this endpoint and supply an IC number in \
the form yymmdd-SS-#### via a request field, ic_number. \n\
GET is not supported and will not be. \
Goodbye!");
        }
        
        crow::json::rvalue body = crow::json::load(request.body);

        // Error message if no IC number supplied in POST
        if (!body || !body.has("ic_number")) {
            return crow::response(400, "MyKad Parser by AchievementCava. \n\n\
Please POST to this endpoint and supply an IC number in \
the form yymmdd-SS-#### via a request field, ic_number. \n\
Goodbye!");
        }

        const std::string ic_number = body["ic_number"].s();

        CROW_LOG_INFO << "Disecting " << ic_number << "...";

        return crow::response(dump(IC(ic_number)));
    });

    app.port(8080).multithreaded().run();
}
#include <iostream>

#include "SQLite.h"


int main() {
    // sqlite3* conn = nullptr;

    try {
        Connection utf8("utf8.db");
        Statement stmt;

        stmt.Prepare(utf8, "select 'Hello world 中文' union all select 'sean'");
        for (Row const &row : stmt) {
            std::cout << "the  string is " << row.GetString(0) << std::endl;
        }
//        while (stmt.Step()) {
//            std::cout << "the first string is " << stmt.GetString(0) << std::endl;
//            std::cout << "the second int is " << stmt.GetInt(1) << std::endl;
//        }

        sqlite3_exec(utf8.GetAbi(), "create table users (Name)", nullptr, nullptr, nullptr);
    } catch (Exception const &e) {
        std::cout << e.Message << "(" << e.Result << ")" << std::endl;
    }



//    int result = sqlite3_open(":memory:", connection.Set());
//    if (SQLITE_OK != result) {
//        std::cout << sqlite3_errmsg(connection.Get()) << std::endl;
//      //  sqlite3_close(conn);
//        return result;
//    }
    std::cout << "open success" << std::endl;

//    sqlite3_stmt* query = nullptr;
//    int result = sqlite3_prepare_v2(connection.Get(), "select 'hello sqlite'", -1, &query, nullptr);
//    if (SQLITE_OK != result) {
//        std::cout << sqlite3_errmsg(connection.Get()) << std::endl;
//        // sqlite3_close(conn);
//        return result;
//    }
//
//    while (SQLITE_ROW == sqlite3_step(query)) {
//        std::cout << sqlite3_column_text(query, 0) << std::endl;
//    }
//    sqlite3_finalize(query);
    //  sqlite3_close(conn);
    return 0;
}
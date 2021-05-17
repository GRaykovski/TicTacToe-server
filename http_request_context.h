#ifndef TICTACTOE_SERVER_HTTP_REQUEST_CONTEXT_H
#define TICTACTOE_SERVER_HTTP_REQUEST_CONTEXT_H

#include <string_view>
#include <map>
#include <unordered_map>
#include <utility>
#include <vector>

struct HttpRequestContext {
    const std::multimap<std::string_view, std::string_view> headers;
    const std::unordered_map<std::string_view, std::string_view> path_params;
    mutable std::multimap<std::string_view, std::string_view> query_params;
    const std::string_view fragment;
    const std::string_view body;

    HttpRequestContext(std::multimap<std::string_view, std::string_view> headers,
                       std::unordered_map<std::string_view, std::string_view> pathParams,
                       std::multimap<std::string_view, std::string_view> queryParams,
                       std::string_view fragment, const std::string_view &body) : headers(std::move(headers)),
                                                                                  path_params(std::move(pathParams)),
                                                                                  query_params(std::move(queryParams)),
                                                                                  fragment(fragment),
                                                                                  body(body) {}
};

#endif //TICTACTOE_SERVER_HTTP_REQUEST_CONTEXT_H

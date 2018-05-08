#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <stack>
#include <string>

namespace cpptests_algorithm_dependence_traval {

template <typename T>
struct Entity {
    typedef T type;
    Entity(const T& id, const std::initializer_list<T>& l) : id(id), list(l) {}
    T id;
    std::list<T> list;
};

template <typename T>
std::map<T, Entity<T>> preperData() {}

/**
 *  1      2     4      7
 *  \     /\     /\    /\
 *   \   /  \  /    \/   \
 *     9      5      8    6
 *     \      /      |
 *       \  /        |
 *        10         3
 */
template <>
std::map<std::string, Entity<std::string>> preperData() {
    using E = Entity<std::string>;
    std::map<std::string, E> map;
    map.insert(std::pair<std::string, E>("1", E("1", {})));
    map.insert(std::pair<std::string, E>("2", E("2", {})));
    map.insert(std::pair<std::string, E>("3", E("3", {"8"})));
    map.insert(std::pair<std::string, E>("4", E("4", {})));
    map.insert(std::pair<std::string, E>("5", E("5", {"2", "4"})));
    map.insert(std::pair<std::string, E>("6", E("6", {"7"})));
    map.insert(std::pair<std::string, E>("7", E("7", {})));
    map.insert(std::pair<std::string, E>("8", E("8", {"4", "7"})));
    map.insert(std::pair<std::string, E>("9", E("9", {"1", "2"})));
    map.insert(std::pair<std::string, E>("10", E("10", {"5", "9"})));
    return map;
}

template <typename T>
struct Node {
    typedef Node& reference_type;
    typedef std::shared_ptr<Node> pointer_type;
    std::list<pointer_type> preNodes;
    T value;
    std::list<pointer_type> nextNodes;

    Node(const std::list<pointer_type>& pre, const T& value,
         const std::list<pointer_type>& next)
        : preNodes(pre), value(value), nextNodes(next) {}
};

void showIds(Node<Entity<std::string>>::pointer_type node) {
    std::stack<Node<Entity<std::string>>::pointer_type> stack;
    std::clog << node->value.id << std::endl;
    stack.push(node);
    while (!stack.empty()) {
        Node<Entity<std::string>>::pointer_type s = stack.top();
        stack.pop();
        if (!s->nextNodes.empty()) {
            for (Node<Entity<std::string>>::pointer_type n : s->nextNodes) {
                std::clog << n->value.id << std::endl;
                stack.push(n);
            }
        }
    }
}

TEST(algorithm, dependence_traval) {
    using entity_type = Entity<std::string>;
    using node_type = Node<entity_type>;
    std::map<std::string, entity_type> map = preperData<std::string>();
    std::map<std::string, node_type::pointer_type> hasPreNodes;
    std::list<node_type::pointer_type> headers;
    std::stack<entity_type> stack;
    for (std::pair<std::string, entity_type> e : map) {
        if (e.second.list.empty()) {
            std::shared_ptr<node_type> node(
                new node_type(std::list<node_type::pointer_type>(), e.second,
                              std::list<node_type::pointer_type>()));
            headers.push_back(node);
            hasPreNodes.insert(
                std::pair<std::string, node_type::pointer_type>(e.first, node));
        } else {
            stack.push(e.second);
        }
    }

    while (!stack.empty()) {
        entity_type e = stack.top();
        bool findall = true;
        std::list<node_type::pointer_type> l;
        for (std::string id : e.list) {
            if (hasPreNodes.find(id) == hasPreNodes.end()) {
                findall = false;
                break;
            }
            l.push_back(hasPreNodes.at(id));
        }
        if (findall) {
            hasPreNodes.emplace(
                e.id,
                new node_type(l, e, std::list<node_type::pointer_type>()));
            stack.pop();
        }
    }

    for (std::pair<std::string, node_type::pointer_type> pair : hasPreNodes) {
        for (std::pair<std::string, node_type::pointer_type> secPair :
             hasPreNodes) {
            if (!secPair.second->value.list.empty()) {
                for (std::string id : secPair.second->value.list) {
                    if (pair.first == id) {
                        // sec 的前置list 里面存在 pair, sec 为pair的后继节点
                        node_type::pointer_type nextNode =
                            hasPreNodes.at(secPair.first);
                        node_type::pointer_type curr =
                            hasPreNodes.at(pair.first);
                        curr->nextNodes.push_back(nextNode);
                    }
                }
            }
        }
    }

    for (Node<entity_type>::pointer_type node : headers) {
        std::clog << "===============================" << std::endl;
        showIds(node);
    }
}
}  // namespace cpptests_algorithm_dependence_traval

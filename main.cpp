#include <iostream>
#include <vector>
#include <sstream>
#include <string>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> stack;
        std::istringstream iss(path);
        std::string dir;

        while (std::getline(iss, dir, '/')) {
            if (dir.empty() || dir == ".") {
                continue;
            } else if (dir == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(dir);
            }
        }

        std::string canonicalPath;
        for (const std::string& s : stack) {
            canonicalPath += "/" + s;
        }

        return canonicalPath.empty() ? "/" : canonicalPath;
    }
};

int main() {
    Solution solution;

    std::vector<std::string> inputs = {
        "/home/",
        "/home//foo/",
        "/home/user/Documents/../Pictures",
        "/../",
        "/.../a/../b/c/../d/./"
    };

    for (const std::string& path : inputs) {
        std::string result = solution.simplifyPath(path);
        std::cout << "Input: path = \"" << path << "\"\n";
        std::cout << "Output: \"" << result << "\"\n\n";
    }

    return 0;
}

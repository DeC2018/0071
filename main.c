#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* simplifyPath(char* path) {
    int len = strlen(path);
    
    char* stk = (char*)malloc((len + 1) * sizeof(char));
    int top = 0;
    stk[0] = '/'; 

    for (int i = 1; i < len; i++) {
        
        if (path[i] == '/' && (stk[top] == '/' || path[i + 1] == '\0')) {
            continue;
        }
        
        if (path[i - 1] == '/' && path[i] == '.' && path[i + 1] == '.' && (path[i + 2] == '/' || path[i + 2] == '\0')) {
            if (top > 0) {
                top--; 
                while (top >= 0 && stk[top] != '/') {
                    top--; 
                }
            }
            i += 2; 
        }
        
        else if (path[i - 1] == '/' && path[i] == '.' && (path[i + 1] == '/' || path[i + 1] == '\0')) {
            continue; 
        }
        
        else {
            stk[++top] = path[i];
        }
        stk[top + 1] = '\0'; 
    }

    
    if (top > 0 && stk[top] == '/') {
        top--;
    }
    stk[top + 1] = '\0'; 

    return stk;
}

int main() {
    
    char* inputs[] = {
        "/home/",
        "/home//foo/",
        "/home/user/Documents/../Pictures",
        "/../",
        "/.../a/../b/c/../d/./"
    };
    int num_inputs = sizeof(inputs) / sizeof(inputs[0]);

    for (int i = 0; i < num_inputs; i++) {
        char* result = simplifyPath(inputs[i]);
        printf("Input: path = \"%s\"\n", inputs[i]);
        printf("Output: \"%s\"\n\n", result);
        free(result); 
    }

    return 0;
}

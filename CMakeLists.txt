cmake_minimum_required(VERSION 3.30)
project(Learn)

set(CMAKE_CXX_STANDARD 23)

add_executable(Learn problem/mainCode/main.cpp
        problem/mainCode/main2.cpp
        problem/mainCode/main3.cpp
        problem/mainCode/main4.cpp
        problem/mainCode/main5.cpp)

add_executable(I_Mysterious_Script "Codeforces - April Fools Day Contest 2025/I_Mysterious_Script.cpp")
add_executable(B_Clockwork "problem/CodeForcesOJ/Codeforces - Ethflow Round 1 Codeforces Round 1001 Div 1  Div 2/B_Clockwork.cpp")
add_executable(A_String "problem/CodeForcesOJ/Codeforces - Ethflow Round 1 Codeforces Round 1001 Div 1  Div 2/A_String.cpp")
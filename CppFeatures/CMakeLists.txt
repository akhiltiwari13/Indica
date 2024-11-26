cmake_minimum_required(VERSION 3.10)
project(CPP_FEATURES)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(templates)
add_subdirectory(multithreading)

add_executable(ComptProg ComptProg.cpp)
add_executable(MoveSemantics MoveSemantics.cpp)
# add_executable(RuleOfFive RuleOfFive.cpp)
add_executable(RuleOfThree RuleOfThree.cpp)
add_executable(SmartPointers SmartPointers.cpp)
add_executable(io IO.cpp)
add_executable(ExpFeatures ExpFeatures.cpp)
add_executable(Inheritance Inheritance.cpp)
add_executable(stl stl.cpp)
add_executable(functors_lambda_fptrs functors_lambda_fptrs.cpp)
add_executable(boost_multiindex Boost_multi_index_demo.cpp)
# target_compile_options(functors_lambda_fptrs PRIVATE -E -P)
# target_compile_options(functors_lambda_fptrs PRIVATE -save-temps) #for viewing compiler generated code using clang compiler
# target_compile_options(functors_lambda_fptrs PRIVATE -Xclang -ast-print -fsyntax-only -save-temps) #for viewing compiler generated code using clang compiler
add_executable(constexprGCD ConstexprGCD.cpp)
add_executable(interview_problems interview_problems.cpp)
add_executable(jthreads jthreads.cpp)
add_executable(turing turing.cpp)

target_link_libraries(RuleOfThree PRIVATE ${Boost_LIBRARIES})
target_link_libraries(boost_multiindex PRIVATE ${Boost_LIBRARIES})
# target_link_libraries(RuleOfFive PRIVATE )

# CMakeList.txt: проект CMake для Algebra-of-Polynomials; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
create_executable_project (Algebra-of-Polynomials)
add_depend(Algebra-of-Polynomials lib_SyntaxTree "../libs/Functional/lib_SyntaxTree")
add_depend(Algebra-of-Polynomials lib_Monom "../libs/Functional/lib_Monom")


# TODO: Добавьте тесты и целевые объекты, если это необходимо.

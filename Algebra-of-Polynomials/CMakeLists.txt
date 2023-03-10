# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

# название проекта
project ("Algebra-of-Polynomials")

include(cmake/function.cmake)    # подхватываем функции, реализованные в файле function.cmake
                                 # для простоты мы объединили наборы команд для создания статической библиотеки
								 # и для создания исполняемого проекта в отдельные функции

add_subdirectory ("Algebra-of-Polynomials") # подключаем дополнительный CMakeLists.txt из подкаталога с именем Algebra-of-Polynomials

add_subdirectory ("libs/lib_HashTable")
add_subdirectory ("libs/lib_LinearArrayTable")
add_subdirectory ("libs/lib_LinearListTable")
add_subdirectory ("libs/lib_List")
add_subdirectory ("libs/lib_Monom")
add_subdirectory ("libs/lib_Node")
add_subdirectory ("libs/lib_OrderedTable")
add_subdirectory ("libs/lib_Parser")
add_subdirectory ("libs/lib_Polynom")
add_subdirectory ("libs/lib_SortedArrayTable")
add_subdirectory ("libs/lib_SortedTable")
add_subdirectory ("libs/lib_Stack")
add_subdirectory ("libs/lib_Table")
add_subdirectory ("libs/lib_Tree")
add_subdirectory ("libs/lib_UnorderedTable")
add_subdirectory ("libs/lib_UnsortedTable")
add_subdirectory ("libs/lib_Iterator")

option(BTEST "build test?" OFF) # указываем подключаем ли google-тесты (ON или YES) или нет (OFF или NO)

if(BTEST)                        # если тесты подключены
    add_subdirectory(gtest)      # подключаем дополнительный CMakeLists.txt из подкаталога с именем gtest
    add_subdirectory(tests)      # подключаем дополнительный CMakeLists.txt из подкаталога с именем test
endif()
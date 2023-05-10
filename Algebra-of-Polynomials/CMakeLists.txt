# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

# название проекта
set(CMAKE_CXX_STANDARD 20)
# подключение модуля FetchContent
include(FetchContent)

# скачивания архива гугл тестов
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)


# отключаем возможность изменять параметры компилятора/линковщика родительского проекта
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# гарантируем, что именованные зависимости были заполнены
FetchContent_MakeAvailable(googletest)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project ("Algebra-of-Polynomials")

include(cmake/function.cmake)    # подхватываем функции, реализованные в файле function.cmake
                                 # для простоты мы объединили наборы команд для создания статической библиотеки
								 # и для создания исполняемого проекта в отдельные функции
add_subdirectory ("Algebra-of-Polynomials") # подключаем дополнительный CMakeLists.txt из подкаталога с именем Algebra-of-Polynomials

add_subdirectory("libs/Functional/lib_AVLTree")
add_subdirectory ("libs/Functional/lib_List")
add_subdirectory ("libs/Functional/lib_Monom")
add_subdirectory ("libs/Functional/lib_Node")
add_subdirectory ("libs/Functional/lib_Parser")
add_subdirectory ("libs/Functional/lib_Polynom")
add_subdirectory ("libs/Functional/lib_Stack")
add_subdirectory("libs/Functional/lib_SyntaxTree")
add_subdirectory("libs/Functional/lib_Tree")

add_subdirectory ("libs/Tables/lib_AVLTreeTable")
add_subdirectory ("libs/Tables/lib_ChainMethodTable")
add_subdirectory ("libs/Tables/lib_HashTable")
add_subdirectory ("libs/Tables/lib_LinearArrayTable")
add_subdirectory ("libs/Tables/lib_LinearListTable")
add_subdirectory ("libs/Tables/lib_OpenShuffleTable")
add_subdirectory ("libs/Tables/lib_OrderedTable")
add_subdirectory ("libs/Tables/lib_SortedArrayTable")
add_subdirectory ("libs/Tables/lib_SortedTable")
add_subdirectory ("libs/Tables/lib_Table")
add_subdirectory ("libs/Tables/lib_UnorderedTable")
add_subdirectory ("libs/Tables/lib_UnsortedTable")
add_subdirectory ("tests")
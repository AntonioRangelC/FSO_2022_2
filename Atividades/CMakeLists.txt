cmake_minimum_required(VERSION 3.20)
project(FSO_2022_2 C)

set(CMAKE_C_STANDARD 99)

add_executable(FSO_2022_2 main.c)

add_executable(trabalho2_vetores_identicos trabalho2_vetores_identicos.c)


add_compile_options(-pthread)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(trabalho2_vetores_identicos Threads::Threads)
add_executable(trabalho2_processo_preguicoso trabalho2_processo_preguicoso.c)
add_executable(FIFO_algoritmo_reposicao_paginas FIFO_algoritmo_reposicao_paginas.c)
add_executable(LRU_algoritmo_reposicao_paginas LRU_algoritmo_reposicao_paginas.c)
add_executable(OPT_algoritmo_reposicao_paginas OPT_algoritmo_reposicao_paginas.c)
add_executable(testesFSO testesFSO.c)
add_executable(testeLRU testeLRU.c)
add_executable(arquivosIdenticos arquivosIdenticos.c)
add_executable(timed_mini_shell timed_mini_shell.c)
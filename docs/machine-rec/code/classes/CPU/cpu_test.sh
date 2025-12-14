cd ../
./comp.sh
cd CPU
g++ -Werror -Wextra -Wall -fsanitize=address -o output ../../object-files/cpu.o cpu_test.cpp
./output
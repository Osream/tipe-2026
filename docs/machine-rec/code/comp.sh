# CPU class compiler
cd classes/CPU
g++ -Werror -Wall -Wextra -fsanitize=address -c cpu.cpp -o ../../object-files/cpu.o
cd ../..
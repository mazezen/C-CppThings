# practice-c-cpp

> Learning C and C++

### Sytem

```bash
~ sw_vers
ProductName:		macOS
ProductVersion:		14.6.1
BuildVersion:		23G93
```

## Compiler

> GCC
>

## Compiler GCC

1. Install `gcc` compiler

   ```BASH
   ~ brew install gcc
   ~ which gcc-15
   /opt/homebrew/bin/gcc-15
   ```

2. /opt/homebrew/bin/gcc-15 version

```bash
g++-15 (Homebrew GCC 15.2.0_1) 15.2.0
Copyright (C) 2025 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

3. /opt/homebrew/bin/g++-15 version

```bash
g++-15 (Homebrew GCC 15.2.0_1) 15.2.0
Copyright (C) 2025 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

4. Add the compilation alias to ~/.zshrc (or ~/.bash_profile)

```bash
# C99
echo 'alias gcc15="/opt/homebrew/bin/gcc-15 -std=c99 -Wall -Wextra -g -isysroot $(xcrun --show-sdk-path)"' >> ~/.zshrc

# C23 （suggest）
echo 'alias gcc15="/opt/homebrew/bin/gcc-15 -std=c23 -Wall -Wextra -g -isysroot $(xcrun --show-sdk-path)"' >> ~/.zshrc

# C++17
echo 'alias g++15="/opt/homebrew/bin/g++-15 -std=c++17 -Wall -Wextra -g -isysroot $(xcrun --show-sdk-path)"' >> ~/.zshrc
```

5. Compilation And Debug (Terminal)

```bash
# gcc-15
gcc15 main.c -o main.out

# g++-15
g++15 main.cpp -o main.app
```

6. Debug instructions for Use
   1. start lldb debug (Linux: `lldb` repleace `gdb`

   ```bash
   not arguments
   lldb ./main
   (lldb) b main        # set a breakpoint at the entry of the main function
   (lldb) run           # start run (it will stop at beginning of main)
   (lldb) n             # execute the next line in a single step
   (lldb) p i           # Check the value of variable i (assuming there is an int i)
   (lldb) bt            # view call stack
   (lldb) c             # keep running
   (lldb) q             # quit


-----------------------------------------------------
   have arguments
   lldb ./main
   (lldb) run arg1 arg2           # input arguments
   # or
   lldb -- ./main arg1 arg2


   ```

7. Common lldb debugging commands

   | 功能                                               | lldb 命令                                | 简写              | 说明                                |
   | -------------------------------------------------- | ---------------------------------------- | ----------------- | ----------------------------------- |
   | Set a breakpoint in the main functoin              | `breakpoint set --name main`             | `b main`          | usually                             |
   | Set a breakpoing on a specific line                | `breakpoint set --file main.c --line 20` | `b main.c:20`     | Specify the file and line number    |
   | View all breakpoints                               | `breakpoint list`                        | `br li`           | -                                   |
   | Run the program                                    | `process launch`                         | `run` or `r`      | Run until a breakpoint              |
   | Single step execution(without entering a function) | `thread step-over`                       | `next` or `n`     | Similar to F10                      |
   | Single-setp into function                          | `thread step-in`                         | `step` or `s`     | Similar to F11                      |
   | Single-step out of function                        | `thread step-out`                        | `finish` or `f`   | Similar to Shift+F11                |
   | Continue running                                   | `process continue`                       | `continue` or `c` | Continue to the next breakpoing     |
   | View viriable value                                | `frame variable`                         | `fr v`            | Display all current local variables |
   | View a certain variable                            | `frame variable var_name`                | `p var_name`      | Print variable                      |
   | View Call Stack                                    | `thread backtrace`                       | `bt`              | Display function call stack         |
   | Quit lldb                                          | `quit`                                   | `q`               | -                                   |

# Notes
1. Get a core dump for a segfault
2. Run valgrind -v
3. Run gdb with core
4. Check sysctl -a for all kernel parameter settings
5. Set kernel.core.dump to control where core files are written
6. sysctl -w kernel.core_pattern=/tmp/core-%e.%p.%h.%t6.
7. [git common use cases](https://citizen428.net/10-common-git-problems-and-how-to-fix-them-e8d809299f08)

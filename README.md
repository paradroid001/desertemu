# DESERTEMU
A code analysis platform for emulated embedded devices

## Quick Start
Start the build platform and emulation suite with:
`docker compose -f docker/docker-compose.yml up`

On build platform:
- x86:

  `gcc -o basic.x86 basic.c -g`
- arm (compile static to avoid needing ld-linux-armhf.so.3 and arm's libc at runtime until I know how to install.)

  `arm-linux-gnueabihf-gcc-11 -static -O0 -g -o basic.arm basic.c`

On emulator (run with arg and wait for debugger):
- x86:
  
  `qemu-x86_64-static -g 9000 basic.x86 <first argument>`
- arm:
  
  `qemu-arm-static -g 9000 basic.arm <first argument>`

On build platform (in same dir as basic.x86):
```
  gdb-multiarch -ex "symbol-file basic.<arch>" -ex "target remote desertemu-emulator-1:9000"
  (gdb) break main
  (gdb) display data
  (gdb) continue
```
So this tells gdb to use symbols from basic.x86, connect to the target 'remote', set a breakpoint.

Now step through ([n]ext) and see what happens to `data.buf` vs `data.pwd`


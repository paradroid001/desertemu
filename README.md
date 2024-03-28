# DESERTEMU
A code analysis platform for emulated embedded devices

## Emulation:
- https://www.zerodayinitiative.com/blog/2020/5/27/mindshare-how-to-just-emulate-it-with-qemu
- https://secnigma.wordpress.com/2022/01/18/a-beginners-guide-into-router-hacking-and-firmware-emulation/
- https://en.wikipedia.org/wiki/Comparison_of_platform_virtualization_software
- https://www.attify.com/attifyos

- https://boschko.ca/qemu-emulating-firmware/
- https://medium.com/csg-govtech/- when-you-have-no-money-and-want-to-find-bugs-in-routers-cd9786856bdc

## Reversing:
- https://scottc130.medium.com/introduction-to-reverse-engineering-understanding-basic-compiled-code-69975cf2ef82
- https://tuttlem.github.io/2015/01/12/a-simple-example-with-gcc-and-objdump.html
- https://jaybailey216.com/sh4ll0-walkthrough/

## Misc:
- https://github.com/swisskyrepo/PayloadsAllTheThings/blob/master/Methodology%20and%20Resources/Reverse%20Shell%20Cheatsheet.md


## QEMU:
- https://github.com/qemus/qemu-docker
- https://github.com/qemus/qemu-arm

# Emulated Linux Kernel:
- https://github.com/cirosantilli/linux-kernel-module-cheat#userland-assembly

GDB:
- https://github.com/cyrus-and/gdb-dashboard
- https://github.com/pwndbg/pwndbg
- https://github.com/longld/peda
- https://github.com/hugsy/gef


## Basic Test
On build platform:
- x86:
`gcc -o basic.x86 basic.c -g`
- arm (compile static to avoid needing ld-linux-armhf.so.3 and arm's libc at runtime until I know how to install.)
`arm-linux-gnueabihf-gcc-11 - static -O0 -g -o basic.arm basic.c`

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
So this tells gdb to use symbols from basic.x86, connect to the target 'remote', set a breakpoint
  Now step through ([n]ext) and see what happens to `data.buf` vs `data.pwd`

### Google: router firmware emulator


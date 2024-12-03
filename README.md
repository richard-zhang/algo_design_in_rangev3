## Build
```sh
conan install . --output-folder=build --build=missing
cd build && cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release -GNinja -DCMAKE_EXPORT_COMPILE_COMMANDS=on
```

## Conan Profile

```
[settings]
arch=armv8
build_type=RelWithDebInfo
compiler=apple-clang
compiler.cppstd=gnu23
compiler.libcxx=libc++
compiler.version=15
os=Macos

[conf]
tools.cmake.cmaketoolchain:generator=Ninja
```


## Idea

- Reimplement range library interface but only for one container
  - std::vector
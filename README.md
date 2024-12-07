# RTCG - Run Time Code Generator

### Code generator for new projects of HiAsm IDE and Hion.
This code generator is part of the [HiAsm](http://hiasm.com) and [Hion](https://hiasm.com/ide_online.html) projects.
This type of code generation uses scripts to create optimal program code. Due to the pre-compilation of element scripts, the code generation process itself is very fast. The syntax, designed specifically for generating application code according to a given scheme, is as simple as possible, minimalistic and integrated with the HiAsm architecture.
> HiAsm is developed by a programmer from Russia, and all information + forum is available only in native language.

### Кодогенератор для нового проекта HiAsm IDE и Hion
Кодогенератор является частью проектов [HiAsm](http://hiasm.com) и [Hion](https://hiasm.com/ide_online.html).
Данный тип кодогенерации использует скрипты для создания оптимального кода программы. За счет предварительной компиляции скриптов элементов, сам процесс генерации кода происходит очень быстро. Синтаксис, разработанный специально для генерации кода приложения по заданной схеме, максимально прост, минималистичен и интегрирован с архитектурой HiAsm.
Более полную информацию по данному кодогенератору можно прочитать по следующей [ссылке](https://forum.hiasm.com/wiki/5006).

### Компиляция
Компиляция исходных кодов выполняется с помощью Cmake и проверялась с GCC 14.2.0

Для компиляции требуется:
1. Система сборки Cmake и компилятор GCC
2. Для компиляции на Windows необходим MSYS2 Mingw32

Необходимо выполнить:
1. Зайти в корневую папку с исходным кодом
2. Выполнить, последовательно, команды
```
- cmake -S . -B _build
- cmake --build _build
```
3. Скомпилированная библиотека будет находится в папке _build



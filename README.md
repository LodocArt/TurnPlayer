# TurnPlayer

Simple C++ Audio Player using SoLoud as the audio library. This is a very rough project for testing purposes.

## Dependencies

```sh
sudo apt install build-essential cmake libsdl2-dev
```

## Compilation

First you need to compile the necessary static library for your system. This project was firstly based for Linux systems but it can easily be adapted for Windows. All the options are in src/lib/contrib/Configure.cmake where multiple options can be toggled. Here the default option for Linux compiling are :

```cmake
option (SOLOUD_STATIC "Set to ON to build static SoLoud" ON)
print_option_status (SOLOUD_STATIC "Build static library")

option (SOLOUD_BACKEND_SDL2 "Set to ON for building SDL2 backend" ON)
print_option_status (SOLOUD_BACKEND_SDL2 "SDL2 backend")
```

You can easily change these options to your liking, as building a dynamic library or changing the audio backend to WASAPI / WINMM (Windows), CoreAudio (MacOS) or OpenSLES / XAudio2.

When the Configure.cmake is configured you need to build the library for the main project and move it to the lib folder :

```sh
cd src/lib/build
cmake ../contrib
mv libsoloud.a ../libsoloud.a
```

Finally you can compile the main project :

```sh
# Returning to the root folder, TurnPlayer
cd ../../..
mkdir build
cd build cmake ..
make
```

## Usage

You can play a song with 

```sh
/main path/to/you/file.flac
```

The program will close itself after the ending of the song.
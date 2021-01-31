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

The program can be used with multiples audio files, one folder with audio files (not subdirectories) or a mix of both.

```sh
./main file/to/music1.flac file/to/music2.mp3
./main folder
./main folder file/to/music1.flac file/to/music2.mp3
```

The program will close itself after the ending of the song or the playlist, each songs displays the percentage of the playback.

## Issues

The WavStream class seems to not work well with vectors, leading to "double free detected in tcache 2" errors and strange behaviour as corrupting the WavStream filename. 

I can't make the Queue works, it doesn't make any sounds and returns an Invalid Parameters error. Scanning through the demos, trying specific Bus, I can't get a proper gapless play if Queue is not working and if it's impossible to get a vector for adding more WavStreams. 

This project can't continue with SoLoud, but will stay here as an archive and a POC of a barebone CLI audio player that can play any music files or folder that it receives as arguments.
# NeoWidener

DC Offset Bass Widener - Audio Plugin by NeoMelodist

## Description

NeoWidener is an audio processing plugin designed for bass enhancement and stereo widening effects.

## Features

- DC Offset processing
- Bass enhancement
- Stereo widening
- Real-time processing

## Build Requirements

### Linux
- JUCE 7.0.9+
- CMake 3.15+
- GCC/G++ with C++17 support
- Development libraries:
  - libasound2-dev
  - libfreetype-dev
  - libgtk-3-dev
  - libwebkit2gtk-4.1-dev

### Windows
- Visual Studio 2022
- JUCE 7.0.9+

## Building

### Linux
```bash
cd Builds/LinuxMakefile
make CONFIG=Release
```

### Windows
1. Open `DCOffsetBassWidener.jucer` in Projucer
2. Save project to generate Visual Studio files
3. Open `Builds/VisualStudio2022/DCOffsetBassWidener.sln`
4. Build in Release mode

## Installation

Copy the generated `.vst3` file to your system's VST3 directory:
- Linux: `~/.vst3/`
- Windows: `%COMMONPROGRAMFILES%\VST3\`

## License

[Add your license here]

## Contact

NeoMelodist
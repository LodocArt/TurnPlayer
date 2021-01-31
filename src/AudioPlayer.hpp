#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "Color.hpp"
#include "lib/include/soloud_queue.h"
#include "lib/include/soloud_wavstream.h"
#include "lib/include/soloud_thread.h"

class AudioPlayer {
	public:
		AudioPlayer();
		~AudioPlayer();
		void playSound(std::string filename);
		void printMusicName();
		void printCurrent();
		bool isFinished();


	private:
		SoLoud::Soloud gSoloud;
		SoLoud::WavStream gWaveStream;
		int gMusicHandle;
};
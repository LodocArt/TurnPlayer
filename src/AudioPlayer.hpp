#pragma once

#include <string>
#include "lib/include/soloud.h"
#include "lib/include/soloud_wavstream.h"
#include "lib/include/soloud_thread.h"

class AudioPlayer {
	public:
		AudioPlayer();
		~AudioPlayer();
		void playSound(std::string filename);
		bool isFinished();


	private:
		SoLoud::Soloud gSoloud;
		SoLoud::WavStream gWaveStream;
};
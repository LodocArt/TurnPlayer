#include "AudioPlayer.hpp"

AudioPlayer::AudioPlayer() {
	gSoloud.init();
}

AudioPlayer::~AudioPlayer() {
	gSoloud.deinit();
}

void AudioPlayer::playSound(std::string filename) {
	gWaveStream.load(filename.c_str());
	gSoloud.play(gWaveStream);
	while(!isFinished())
		SoLoud::Thread::sleep(100);
};

bool AudioPlayer::isFinished() {
	return !(gSoloud.getActiveVoiceCount() > 0);
}
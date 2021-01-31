#include "AudioPlayer.hpp"

AudioPlayer::AudioPlayer() {
	gSoloud.init();
}

AudioPlayer::~AudioPlayer() {
	gSoloud.deinit();
}

void AudioPlayer::playSound(std::string filename) {
	gWaveStream.load(filename.c_str());
	printMusicName();
	gMusicHandle = gSoloud.play(gWaveStream);
	while(!isFinished()) {
		printCurrent();
		SoLoud::Thread::sleep(100);
	}
};

void AudioPlayer::printMusicName() {
	std::cout<<Color::Modifier(Color::colorLightBlue);
	std::cout<<gWaveStream.mFilename<<Color::Modifier(Color::colorDefault)<<std::endl;
}

void AudioPlayer::printCurrent() {
	double percent = ((double)(gSoloud.getStreamPosition(gMusicHandle)/gWaveStream.getLength()*100));
	std::cout<<std::fixed<<std::setprecision(2)<<percent<<"%"<<'\r'<<std::flush;
}

bool AudioPlayer::isFinished() {
	return !(gSoloud.getActiveVoiceCount() > 0);
}
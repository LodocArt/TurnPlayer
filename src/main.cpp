#include <algorithm>
#include <iostream>
#include <filesystem>
#include <vector>
#include "AudioPlayer.hpp"
#include "Color.hpp"
#include "lib/include/soloud.h"

using namespace std;
namespace fs = std::filesystem;

void printUI();

int main(int argc, char** argv) {
	printUI();

	if (argc < 2) {
		cout<<Color::Modifier(Color::colorRed)<<"Too few arguments, you need to input one of these three structures :"<<endl;
		cout<<Color::Modifier(Color::colorDefault)<<"./main file/to/music1.flac file/to/music2.mp3"<<endl;
		cout<<"./main folder"<<endl;
		cout<<"./main folder file/to/music1.flac file/to/music2.mp3"<<endl;
		return -1;
	}

	vector<string> filesVector;

	for (int i=1; i<argc; i++) {
		// If the argument is a folder we append all files to a vector then sort it before adding it to the main one.
		if (fs::is_directory(fs::path(argv[i]))) {
			vector<string> folderVector;
			for (const auto& entry : fs::directory_iterator(fs::path(argv[i])))
				folderVector.push_back(entry.path());
			sort(folderVector.begin(), folderVector.end());
			filesVector.insert(filesVector.end(), folderVector.begin(), folderVector.end());
		}
		else
			filesVector.push_back(argv[i]);
	}

	for (auto element : filesVector) {
		AudioPlayer audioPlayer;
		audioPlayer.playSound(element);
	}

	return 0;

}

void printUI() {
	Color::Modifier colorDefault (Color::colorDefault);
	cout<<Color::Modifier(Color::colorGreen)<<"Welcome to TurnPlayer !"<<colorDefault<<endl;
}


/* Test for Queue, can't make it work.
SoLoud::Soloud gSoloud;
gSoloud.init();
SoLoud::Bus gBus;
SoLoud::Queue gQueue;
SoLoud::WavStream wavStream1;
wavStream1.load(argv[1]);

SoLoud::WavStream wavStream2;
wavStream2.load(argv[2]);

SoLoud::WavStream wavStream3;
wavStream3.load(argv[3]);

gQueue.setParamsFromAudioSource(wavStream1);

gQueue.play(wavStream1);
cout<<gSoloud.play(gQueue)<<endl;
cout<<gQueue.isCurrentlyPlaying(wavStream1)<<endl;

while(true);

gSoloud.deinit();
return 0;
*/